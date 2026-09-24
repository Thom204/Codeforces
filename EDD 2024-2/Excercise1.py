from collections import deque

def main():
    # Leer entrada
    N, T = map(int, input().split())  # N: número de revendedores, T: boletas disponibles
    compras = []  # Lista de compras (id revendedor, cantidad boletas)
    
    for _ in range(N):
        revendedor_id, cantidad = map(int, input().split())
        compras.append((revendedor_id, cantidad))
    
    boletas_vendidas = 0  # Cantidad de boletas vendidas
    historial_compras = {}  # Diccionario para saber qué compró cada revendedor
    cola_fila = deque()  # Cola de revendedores activos
    contador = 0  # Contador para ver cuántas personas han comprado hasta el momento

    for revendedor_id, cantidad in compras:
        # Verificar si el revendedor ya ha sido vetado
        if revendedor_id in historial_compras and historial_compras[revendedor_id] == -1:
            continue  # Si está vetado, no puede volver a comprar
        
        # Si es un revendedor nuevo o puede volver a comprar
        if revendedor_id in historial_compras:
            # Verificar que compra la misma cantidad o menos que la última vez
            if cantidad > historial_compras[revendedor_id]:
                cantidad = historial_compras[revendedor_id]
        
        # Si hay suficientes boletas, realizar la compra
        if boletas_vendidas + cantidad > T:
            # No hay suficientes boletas
            print("quedaron boletas disponibles")
            return
        
        boletas_vendidas += cantidad
        historial_compras[revendedor_id] = cantidad
        cola_fila.append((revendedor_id, cantidad))
        contador += 1

        # Si hemos llegado a la quinta persona, se le veta
        if contador % 5 == 0:
            # Vetar al revendedor de la quinta posición en la fila
            rev_id, _ = cola_fila.popleft()  # El primero de la cola es el que se veta
            historial_compras[rev_id] = -1  # Marcar al revendedor como vetado

        if boletas_vendidas == T:
            # Si hemos vendido todas las boletas
            print(revendedor_id, cantidad)
            return

    # Si hemos llegado aquí, significa que no vendimos todas las boletas
    print("quedaron boletas disponibles")

if __name__ == "__main__":
    main()