#!/usr/bin/python3
"""
def validUTF8(data): if a given data set represents a valid UTF-8 encoding
@data: data set
Return: True if data is a valid UTF-8 encoding, else return False
"""
def validUTF8(data):
    # Contador para llevar el seguimiento de los bytes iniciales restantes
    remaining_bytes = 0

    # Recorremos los elementos de la lista data
    for num in data:
        # Convertimos el número a su representación binaria con 8 bits
        binary = format(num, '08b')

        # Si no hay bytes restantes, verificamos si el número comienza con un 0
        if remaining_bytes == 0:
            if binary.startswith('0'):
                continue  # El byte es válido
            elif binary.startswith('110'):  # Comienza con '110', lo que significa que hay 1 byte restante
                remaining_bytes = 1
            elif binary.startswith('1110'):  # Comienza con '1110', lo que significa que hay 2 bytes restantes
                remaining_bytes = 2
            elif binary.startswith('11110'):  # Comienza con '11110', lo que significa que hay 3 bytes restantes
                remaining_bytes = 3
            else:
                return False  # No es un byte válido UTF-8
        else:
            # Verificamos si el número comienza con '10', lo que indica que es un byte siguiente válido
            if binary.startswith('10'):
                remaining_bytes -= 1
            else:
                return False  # No es un byte válido UTF-8

    return True  # Si no hay bytes restantes, todos los bytes fueron válidos
