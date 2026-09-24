import random

# Crea el mapa para una nueva partida
def generateMap(rows, coulumns, dif):
    mines= int((rows * coulumns)*(dif/10))
    blanks = (rows * coulumns) - mines
    init = []
    capa_oculta= []

    #Generar una lista de numeros y minas
    for i in range(blanks):
        init.append(0)

    for i in range(mines):
        init.append('M')

    #Usar libreria random para revolver la lista y que las minas queden en posiciones aleatorias
    random.shuffle(init) #Fragmento extraido de stack overflow

    #Convertir lista en mapa 2d 
    for i in range(rows):
        capa_oculta.append(init[:coulumns])
        init= init[coulumns:]

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

    return capa_oculta, mines

# Verifica que las jugadas sean validas y maneja la logica para cada caso
def validarJugada(y, x):
    #Posibilidad 1, si el contenido de la celda rota es 0
    if capa_oculta[y][x] == 0:
        r= genRange(y,x)
        romper(r['row'], r['col'], y, x)
        propagar(y, x)
    
    #Posibilidad 2, la celda contiene algun otro numero
    else:
        rango = genRange(y, x)
        #Contar banderas circundantes para verificar validez de la jugada

        bandCtr = 0
        for _i in rango['row']:
            for _j in rango['col']:
                if mapa_visible[j_row+_i][j_col+_j] == '#':
                    bandCtr +=1

        #Si no hay marcadas la misma cantidad de minas circundantes no se puede despejar la celda
        if bandCtr != capa_oculta[y][x]:
            raise Exception(f"Advertencia, No has marcado las {mapa_visible[j_row][j_col]} minas que hay al rededor.")

        #En caso de que el numero coincida se rompen las celdas adyacentes sin marcar
        romper(rango['row'], rango['col'], y, x)
        
# Verifica si estamos en los bordes para evitar errores de fuera de rango
def genRange(row, col):
    #Logica para verificar si estamos en un borde
    i_ini = -1
    i_end = 2
    j_ini = -1
    j_end = 2

    if row == 0:  
        i_ini = 0
    elif row == rows-1: 
        i_end = 1
    if col == 0: 
        j_ini = 0
    elif col == coulumns-1: 
        j_end =1
        
    return {'row': range(i_ini, i_end), 'col': range(j_ini, j_end)}

# Recibe el rango de bloques que puede romper alrededor de la mina y los despeja
def romper(rowRange, colRange, y, x):
    for i in rowRange:
        for j in colRange:
            #Si encuentra una bandera ignora esa celda
            if mapa_visible[y+i][x+j] != "#":
                mapa_visible[y+i][x+j] = capa_oculta[y+i][x+j]
                #Si encuentra una mina el jugador cometió un error marcando y pierde la partida
                if capa_oculta[y+i][x+j] == 'M':
                    raise Exception("Has perdido :<")

# Despeja todos los ceros d euna fila hasta que encuentre un numero o borde.          
def clearFila(y, argx):
    # Inicializa el punto de partida
    x = argx

    # Despeja en la dirección positiva (hacia la derecha).
    while (capa_oculta[y][x] == 0 and x<len(capa_oculta[0])-1):
        mapa_visible[y][x]= capa_oculta[y][x]
        x+=1
    mapa_visible[y][x] = capa_oculta[y][x]

    # Reinicia el punto de partida
    x = argx

    # Despeja en la direccion negativa (hacia la izquierda)
    while capa_oculta[y][x] == 0 and x>0:
        mapa_visible[y][x] = capa_oculta[y][x]
        x-=1
    mapa_visible[y][x] = capa_oculta[y][x]

# Despeja todos los ceros de una columna hasta que encuentre un numero o borde.
def clearColumna(argy, x):
    # Inicia el valor de partida para despejar.
    y = argy

    # Despeja en la direccion positiva (hacia abajo).
    while (capa_oculta[y][x] == 0 and y<len(capa_oculta)-1):
        mapa_visible[y][x]= capa_oculta[y][x]
        y+=1
    mapa_visible[y][x] = capa_oculta[y][x]
    
    # Reinicia el valor de partida.
    y = argy

    # Despeja en la direccion negativa (hacia arriba).
    while capa_oculta[y][x] == 0 and y>0:
        mapa_visible[y][x] = capa_oculta[y][x]
        y-=1
    mapa_visible[y][x] = capa_oculta[y][x]

# Propaga las rupturas cuando se rompe un cero
def propagar(y, x):
    # Inicia los valores con las coordenadas de la ruptura
    _x = x
    _y = y
    
    # Despeja las filas de la columna en direccion positiva (Abajo)
    while capa_oculta[_y][_x] == 0 and _y<len(capa_oculta)-1:
        clearFila(_y,_x)
        _y+=1
    clearFila(_y, _x)

    # Reinicia
    _y = y

    # Despeja las filas de la columna en direccion negativa (Arriba)
    while capa_oculta[_y][_x] == 0 and _y>0:
        clearFila(_y,_x)
        _y-=1
    clearFila(_y, _x) 

    # Reinicia las coordenadas del punto donde se rompió
    _x = x
    _y = y

    # Despeja cada columna de la fila en direccion positiva (Derecha)
    while capa_oculta[_y][_x] == 0 and _x<len(capa_oculta[0])-1:
        clearColumna(_y,_x)
        _x+=1
    clearColumna(_y,_x)

    # Reinicia
    _x = x

    # Despeja cada columna de la fila en direccion negativa (Izquierda)
    while capa_oculta[_y][_x] == 0 and _x>0:
        clearColumna(_y,_x)
        _x-=1
    clearColumna(_y,_x)

# Crea un archivo con la información de la partida (tambien sirve para actualizar la informacion de la partida)
def createSaveFile(file, rows):
    lineas =[]
    for j in range(rows):
        sep1= ":"
        content = str((''.join(map(str, mapa_visible[j]))).replace('■', '%')+sep1+''.join(map(str, capa_oculta[j]))+'\n')
        lineas.append(content)
    file.writelines(lineas)
    
# abre partida guardada localmente
def readFile(file):
    lines = file.readlines()

    # Extrae el numero de filas y columnas
    rows, cols = lines[0].rstrip('\n').split(', ')

    # Inicializa las matrices de mapa visible y capa oculta
    mapa = []
    hidden = []
    mines = 0

    # En cada fila separa la capa visible de la oculta
    for i in range(1, len(lines)):
        linea =lines[i].rstrip('\n').split(':')
        mapLine = linea[0].replace('%', '■')
        hiddenL = [] 
        mapaL = []

        # Extrae los valores de la capa oculta, los convierte al tipo correspondientes y los vuelve una lista
        for m in linea[1]:
            if m in ['0','1','2','3','4','5','6','7','8','9']:
                hiddenL.append(int(m))
            else:
                hiddenL.append(m)
                mines+=1
        
        # Extrae los valores del mapa visible, los convierte al tipo correspondiente y los pone en una lista
        for m in mapLine:
            if m in ['0','1','2','3','4','5','6','7','8','9']:
                mapaL.append(int(m))
            else:
                mapaL.append(m)
        
        # Añade las listas a cada matriz
        mapa.append(mapaL)
        hidden.append(hiddenL)         

    # Retorna todas las variables de estado de la partida
    return int(rows), int(cols), mines, mapa, hidden

hacks = False
colIndex = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

# Ciclo para crear partida
while True:
    # Try y catch para hacer el codigo a prueba de errores de usuario 
    try:
        print("\nBUSCAMINAS v1.0\n")
        opciones = input("Opciones:\n1. Iniciar partida nueva\n2. Cargar partida local\n")

        # Activa el modo de debug 
        if opciones == "pongame5":
            hacks = True
            print("Jugando con trucos (modo debug)")
            continue
        
        # Abre un archivo de partida y lo carga
        elif opciones == '2':
            name = input('Ingrese el nombre del archivo a cargar: ')

            # Abre el archivo y asigna la informacion a las variables de estado de la partida
            with open(name+'.txt', 'r') as Gfile:
                rows, coulumns, mines, mapa_visible, capa_oculta = readFile(Gfile)
                print("partida cargda con exito!")
                break
            
        # Crea una partida nueva y crea un archivo con las variables de estado {rows, cols, mines, mapa_visible, capa_oculta}
        elif opciones == '1':

            # Nombre para el archivo de la partida
            name = input("nombre para su partida: ")
            print("Bienvenido su partida de buscaminas personalizable :>")
            print("#####################################################\n")

            # Recibe las filas, columnas y el nivel de dificultad
            rows= int(input("Ingrese la cantidad de filas de su tablero (no mas de 100)\n"))
            coulumns= int(input("Ingrese la cantidad de columnas de su tablero (no mas de 27)\n"))
            dif = int(input("Seleccione una dificultad\n\
                            1. Facil (10% de minas)\n\
                            2. Medio (20% de minas)\n\
                            3. Dificil (30% de minas)\n\
                            4. Muy dificil (40% de minas)\n"
                            ))

            # Verifica la validez de las entradas
            if(rows<0 or coulumns<0 or rows>100 or rows>27 or dif not in [1,2,3,4]):
                raise SyntaxError("Ingrese valores validos para su partida.\n.\n.\n.Reintentando.\n\n\n")
            

            # Definicion de variables
            capa_oculta= []
            mapa_visible= []
            minas= []

            # Genera el mapa visible con bloques ■
            for i in range(rows):
                mapa_visible.append(list("■" for _ in range(coulumns))) #Fragmento extraido de stack overflow

            # Crea el mapa de minas y numeros
            capa_oculta, mines = generateMap(rows, coulumns, dif)

            # Abre un archivo con el nombre seleccionado 
            with open(name+'.txt', 'w') as savegame:
                savegame.write(f'{rows}, {coulumns}\n')
                createSaveFile(savegame, rows)
                savegame.close()    

            print("\n¡Partida creada con exito!")
            break
        
        else:
            raise SyntaxError("Entrada no valida.\n\n\n")

    # Recibe los errores de entrada de datos y de ejecucion.
    except SyntaxError as e:
        print(e)
    except FileNotFoundError as e:
        print("archivo no encontrado")
        print(e)

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
    print("Ingresar una jugada invalida o pulsar enter sin enviar ningun comando guarda la partida y da la opción de terminar el juego")
    print("(nota2: cuando una partida se gana solo puede guardarse hasta el penultimo movimiento)")
    print("(nota3: terminar la partida por otros medios NO garantiza que los cambios mas recientes se guarden)")
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
        #Si hay una mina revelada el jugador pierde
        if 'M' in mapa_visible[j]:
            is_game_over = True
        elif '■' in mapa_visible[j]:
            is_game_won = False

        #Condicional para que los prints sean esteticos
        sep1= " | "
        if j<9:
            sep1 = "  | "
        
        #Si los trucos estan activados imprime tanto la capa visible como la oculta
        if hacks:
            print(j+1,sep1,*mapa_visible[j],"      |      ", *capa_oculta[j])
        else:
            print(j+1,sep1,*mapa_visible[j])
    

    #Mensajes de fin de partida
    if is_game_won:
        print("¡¡¡Has ganado!!!")
        break
    elif is_game_over:
        print("Has perdido :<")
        break


    #procesar jugadas con try para evitar errores fatales.
    try:
        jugada = input("ingrese su jugada\n").split()
        j_row = int(jugada[1]) -1
        j_col = colIndex.index(jugada[2])
    
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
                validarJugada(j_row, j_col)

    #Al aparecer una excepcion se guarda la partida para no perder el progreso y se pregunta al usuario si desea continuar jugando
    except Exception as e:
        with open(name+'.txt', 'w') as gameLog:
            gameLog.write(f'{rows}, {coulumns}\n')
            createSaveFile(gameLog, rows)
        gameLog.close()
        print(e)
        print("partida guardada")
        aviso = input("Desea Terminar la partida?\n\
                      -teminar:  si\n\
                      -continuar: (enter)\n")

        if aviso.lower() == 'si':
            break

print("Fin del juego")