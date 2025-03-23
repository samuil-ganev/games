from itertools import permutations
from textwrap import wrap
from random import randint

def pc_can_win(x):
    for i in range(3):
        for j in range(3):
            if x[i][j] == 0:
                x[i][j] = 'x'
                if win(x, 'x'):
                    return [True, [i, j]]
                else:
                    x[i][j] = 0
    return [False]

# проверка дали печели с този код

def win(x, e):
    for i in range(3):
        if x[i][0] == x[i][1] == x[i][2] == e:
            return True

    for j in range(3):
        if x[0][j] == x[1][j] == x[2][j] == e:
            return True

    if x[0][0] == x[1][1] == x[2][2] == e:
        return True
    elif x[0][2] == x[1][1] == x[2][0] == e:
        return True

    return False

# начало на играта

board = [[0 for i in range(3)] for j in range(3)]
# print(board)

player = {1: "Your turn", 2: "Computer's turn"}

game_over = False
turn = randint(1, 2)

variants = [wrap(''.join(el), 3) for el in list(set(permutations(['x'] * (turn + 3) + ['o'] * (6 - turn))))]
variants = [el for el in variants if win(el, 'x') and not win(el, 'o')]
# print(len(variants))
# print(variants)

points = 0

while not game_over:
    if points == 9:
        break
    print(player[turn])
    if turn == 1:
        # TODO:
        x, y = [int(num) for num in input().split()]
        board[x-1][y-1] = 'o'

        #for pc:
        variants = [el for el in variants if el[x-1][y-1] == 'o']
        if win(board, 'o'):
            game_over = True
            print_board = ''.join([str(i) for i in board[0]]) + '\n' + ''.join([str(i) for i in board[1]]) + '\n' + ''.join([str(i) for i in board[2]])
            print(print_board)
            print('You win.')
            break
        turn = 2
    else:
        # TODO:
        oponent_win = False
        select = False

        if pc_can_win(board)[0]:
            select = True
            x, y = pc_can_win(board)[1]
            board[x][y] = 'x'

        for i in range(3):
            if select == True:
                break
            for j in range(3):
                if board[i][j] == 0:
                    board[i][j] = 'o'
                    if win(board, 'o'):
                        board[i][j] = 'x'
                        oponent_win = True
                        select = True
                        break
                    else:
                        board[i][j] = 0
        if not select:
            for i in range(3):
                if select == True:
                    break
                for j in range(3):
                    if board[i][j] == 0:
                        try:
                            if variants[0][i][j] == 'x':
                                board[i][j] = 'x'
                                select = True
                                break
                        except:
                            select = True
                            board[i][j] = 'x'
                            break
        if win(board, 'x'):
            game_over = True
            print_board = ''.join([str(i) for i in board[0]]) + '\n' + ''.join([str(i) for i in board[1]]) + '\n' + ''.join([str(i) for i in board[2]])
            print(print_board)
            print('Computer wins.')
            break
        turn = 1
    print_board = ''.join([str(i) for i in board[0]]) + '\n' + ''.join([str(i) for i in board[1]]) + '\n' + ''.join([str(i) for i in board[2]])
    print(print_board)
    points += 1
# komentar
input('Натисни бутон за да излезеш')
