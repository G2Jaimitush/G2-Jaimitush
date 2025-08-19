import random

# Tablero inicial
tablero = [' ' for _ in range(9)]
tablero[4] = 'X'  # La máquina siempre empieza en el centro

# Función para mostrar el tablero con números en casillas disponibles
def mostrar_tablero():
    print()
    for i in range(3):
        fila = []
        for j in range(3):
            idx = i * 3 + j
            if tablero[idx] == ' ':
                fila.append(str(idx + 1))  # Muestra el número de la casilla disponible
            else:
                fila.append(tablero[idx])
        print(' ' + ' | '.join(fila))
        if i < 2:
            print("---+---+---")
    print()

# Verifica si alguien ha ganado
def verificar_ganador(tablero, jugador):
    combinaciones = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # horizontales
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # verticales
        [0, 4, 8], [2, 4, 6]              # diagonales
    ]
    for combinacion in combinaciones:
        if all(tablero[i] == jugador for i in combinacion):
            return True
    return False

# Verifica si el tablero está lleno
def tablero_lleno(tablero):
    return all(casilla != ' ' for casilla in tablero)

# Turno del usuario
def turno_usuario():
    while True:
        try:
            movimiento = int(input("Tu turno (1-9): ")) - 1
            if 0 <= movimiento <= 8 and tablero[movimiento] == ' ':
                tablero[movimiento] = 'O'
                break
            else:
                print("Movimiento inválido. Intenta de nuevo.")
        except ValueError:
            print("Entrada inválida. Por favor ingresa un número del 1 al 9.")

# Turno de la máquina
def turno_maquina():
    print("Turno de la máquina...")
    posibles = [i for i in range(9) if tablero[i] == ' ']
    if posibles:
        movimiento = random.choice(posibles)
        tablero[movimiento] = 'X'

# Juego principal
def jugar():
    while True:
        mostrar_tablero()
        if verificar_ganador(tablero, 'X'):
            print("La máquina gana.")
            break
        if tablero_lleno(tablero):
            print("Empate.")
            break

        turno_usuario()
        mostrar_tablero()

        if verificar_ganador(tablero, 'O'):
            print("¡Tú ganas!")
            break
        if tablero_lleno(tablero):
            print("Empate.")
            break

        turno_maquina()

# Inicia el juego
jugar()
