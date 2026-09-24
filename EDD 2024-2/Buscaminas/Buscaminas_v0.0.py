import random

print("Bienvenido su partida de buscaminas personalizable :>")
print("#####################################################\n")
rows= int(input("Ingrese la cantidad de filas de su tablero (no mas de 100)\n"))
coulumns= int(input("Ingrese la cantidad de columnas de su tablero (no mas de 27)\n"))

#Definicion de variables
colIndex = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
init = []
mines= (rows * coulumns)//7
blanks = (rows * coulumns) - mines
capa_oculta= []
mapa_visible= []
minas= []

#Generar una lista de numeros y minas
for i in range(blanks):
    init.append(0)

for i in range(mines):
    init.append('M')

#Usar libreria random para revolver la lista y que las minas queden en posiciones aleatorias
random.shuffle(init) #Fragmento extraido de stack overflow

#Convertir lista en mapa 2d y crear una capa que va a ser el mapa visible con bloques ■
for i in range(rows):
    capa_oculta.append(init[:coulumns])
    mapa_visible.append(list("■" for _ in range(coulumns))) #Fragmento extraido de stack overflow
    init= init[coulumns:]

#Calcular el numero de minas adyacentes a cada bloque y guardar las posiciones de las minas
for i in range(rows):
    for j in range(coulumns):
        if capa_oculta[i][j] == 'M':
            minas.append([i,j])

            #Calcular limites en caso de que la mina este en un borde
            i_ini = -1
            i_end = 2
            j_ini = -1
            j_end = 2

            #caso la mina esta en el borde superior.
            if i == 0:  
                i_ini = 0

            #caso la mina esta en el borde inferior
            elif i == rows-1: 
                i_end = 1

            #caso la mina esta en el borde derecho.
            if j == 0: 
                j_ini = 0

            #caso, la mina esta en el borde izquierdo.
            elif j == coulumns-1: 
                j_end =1
            
            #logica para aumentar contador
            for _i in range(i_ini,i_end):
                for _j in range(j_ini,j_end):
                    #si encuentra una mina la omite
                    if capa_oculta[i+_i][j+_j] != 'M':
                        capa_oculta[i+_i][j+_j] +=1 

print("\n¡Partida creada con exito!")

choice = int(input("1. Leer reglas\n2. Jugar directamente\n"))

# Inctrucciones del juego
if choice == 1:
    print("\nReglas del juego:\n")
    print("El objetivo del juego es romper todos los bloques que no tengan minas ocultas en ellos")
    print("Cada bloque que no tenga una mina contiene un numero que corresponde a la cantidad de minas en los 8 bloques adyacentes a el")
    print("En cada turno se imprimira a tu consola el estado actual de tu tablero de juego\n")
    print("Los comandos para las jugadas siguen la estructura (clave de comando) (fila) (columna), separados por espacios\n")
    print("Las posibles claves de comando son:")
    print("M: marcar, pone en la celda una bandera representada por el caracter #, los bloques con bandera no se pueden romper, ubicalo donde estes seguro que hay una mina\n")
    print("DM: desmarcar, te equivocaste marcando? no hay problema, este comando deshace el anterior\n")
    print("R: romper, este comando rompe el bloque indicado al ser usado en celdas ocultas")
    print("al ser usado en celdas ya reveladas este rompe los bloques adyacentes que no esten marcados con banderas")
    print("(nota: si la cantidad de banderas adyacentes no coincide con el numero en el bloque el comando es ignorado,")
    print("si el bloque roto no tiene ninguna mina adyacente (su numero es cero) el comando rompe los 8 bloques adyacentes de manera automatica)")
    print("\nEjemplo de comando: R 4 D\nse puede leer como: Romper celda con coordenada (4,D)")
    choice= input("\nPresione cualquier tecla para continuar")

#Iniciar ciclo principal del juego
turno = 0
is_game_over = False

while True:
    is_game_won = True
    #Imprimir informacion de partida

    print("turno:", turno)
    print("banderas:", mines)
    print("    | ",*colIndex[:coulumns])
    print("_ "*(coulumns+4))
    for j in range(rows):
        '''if j<9: print(j+1,"  | ", *capa_oculta[j])
        else: print(j+1," | ", *capa_oculta[j])'''

        #Si hay una mina revelada el jugador pierde
        if 'M' in mapa_visible[j]:
            is_game_over = True
        elif '■' in mapa_visible[j]:
            is_game_won = False

        if j<9:
            print(j+1,"  | ",*mapa_visible[j])
        else:
            print(j+1," | ",*mapa_visible[j])
    
    #Mensaje de game over
    if is_game_won:
        print("Fin del juego")
        print("¡¡¡Has ganado!!!")
        break

    elif is_game_over:
        print("Fin del juego")
        print("Has perdido :<")
        break

    #procesar jugadas
    try:
        jugada = input("ingrese su jugada\n").split()
        j_row = int(jugada[1]) -1
        j_col = colIndex.index(jugada[2])
    except:
        pass
    
    #Logica para marcar
    if jugada[0] == 'M':
        if mapa_visible[j_row][j_col] == "■":
            mapa_visible[j_row][j_col] = "#"
            mines -=1   
    
    #Logica para desmarcar
    elif jugada[0] == 'DM':
        if mapa_visible[j_row][j_col] == "#":
            mapa_visible[j_row][j_col] = "■"
            mines +=1

    #Logica para romper
    elif jugada[0] == 'R':
        #Verifica que no se este intentando romper una bandera
        if mapa_visible[j_row][j_col] != "#":

            #Aumenta el turno y muestra elcontenido de la celda rota
            turno+=1
            mapa_visible[j_row][j_col] = capa_oculta[j_row][j_col]

            #Posibilidad 1, si el contenido de la celda rota es 0
            if capa_oculta[j_row][j_col] == 0:

                #nota: En futuras versiones vale la pena pensar como propagar las rupturas

                #Logica para verificar si estamos en un borde
                i_ini = -1
                i_end = 2
                j_ini = -1
                j_end = 2

                if j_row == 0:  
                    i_ini = 0
                elif j_row == rows-1: 
                    i_end = 1
                if j_col == 0: 
                    j_ini = 0
                elif j_col == coulumns-1: 
                    j_end =1
                

                #logica para romper los bloques adyacentes
                for _i in range(i_ini,i_end):
                    for _j in range(j_ini,j_end):
                        mapa_visible[j_row+_i][j_col+_j] = capa_oculta[j_row+_i][j_col+_j]
            
            #Posibilidad 2, la celda contiene algun otro numero
            else:

                #Verificar si estamos en un borde
                i_ini = -1
                i_end = 2
                j_ini = -1
                j_end = 2

                if j_row == 0:  
                    i_ini = 0
                elif j_row == rows-1: 
                    i_end = 1
                if j_col == 0: 
                    j_ini = 0
                elif j_col == coulumns-1: 
                    j_end =1
                
                #Contar banderas circundantes para verificar validez de la jugada
                bandCtr = 0
                for _i in range(i_ini,i_end):
                    for _j in range(j_ini,j_end):
                        if mapa_visible[j_row+_i][j_col+_j] == '#':
                            bandCtr +=1

                #Si no hay marcadas la misma cantidad de minas circundantes no se puede despejar la celda
                if bandCtr != capa_oculta[j_row][j_col]:
                    print(f"No has marcado las {mapa_visible[j_row][j_col]} minas que hay al rededor.")
                    continue

                #En caso de que el numero coincida se rompen las celdas adyacentes sin marcar
                for _i in range(i_ini,i_end):
                    for _j in range(j_ini,j_end):

                        #Si encuentra una bandera ignora esa celda
                        if mapa_visible[j_row+_i][j_col+_j] != "#":
                            mapa_visible[j_row+_i][j_col+_j] = capa_oculta[j_row+_i][j_col+_j]

                            #Si encuentra una mina el jugador cometió un error marcando y pierde la partida
                            if capa_oculta[j_row+_i][j_col+_j] == 'M':
                                    print("Has perdido :<")
