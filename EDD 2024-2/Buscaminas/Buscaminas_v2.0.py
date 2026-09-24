import random
import tkinter as tk
from time import sleep

def romper(evento, cord):
    evento.widget.config(relief = "flat")
    evento.widget.config(text = f' {cord}  ')

def generateMap(rows, coulumns):
    mines= (rows * coulumns)//7
    blanks = (rows * coulumns) - mines
    init = []
    capa_oculta= []
    minas = []

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

    drawGameWindow(capa_oculta, rows, coulumns, mines)
    return

def drawGameWindow(map, rows, cols, minas):
    banderas = minas
    gameWin = tk.Tk()
    label = tk.Label(gameWin, text= f'Banderas: {minas}  minas: {banderas}')
    label.pack()
    grid = tk.Frame(gameWin)
    grid.pack()
    gameWin.title("Buscaminas")
    for i in range(rows):
        for j in range(cols):
            button = tk.Button(grid, text=f"    ")
            button.grid(row=i, column=j, padx=1, pady=1)
            button.bind("<Button>", lambda evt: romper(evt))

    init.destroy()
    gameWin.mainloop()



init = tk.Tk()
init.title("Buscaminas personalizado")
init.geometry("250x350")

label = tk.Label(init, text="Seleccione el numero de filas y columnas de su partida.\n Maximo 27 filas x 100 columnas")
label.pack()
txtrows = tk.Entry(init)
txtrows.pack()
txtcols  =tk.Entry(init)
txtcols.pack()
submit = tk.Button(init, text="iniciar partida", command= lambda: [generateMap(int(txtrows.get()), int(txtcols.get()))])
submit.pack()

init.mainloop()