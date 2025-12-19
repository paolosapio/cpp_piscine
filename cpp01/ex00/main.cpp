/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:33:22 by psapio            #+#    #+#             */
/*   Updated: 2025/12/16 15:17:06 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
// zombie en stack con llamada funcion:
    randomChump("Paolo");
    // no llamamos announce (esta ya dentro randomChump)

// zombie en stack
    Zombie stack_zombie("Luca");
    stack_zombie.announce();

// zombie en heap
    Zombie *heap_zombie = newZombie("Sandro");
    heap_zombie->announce();
    delete heap_zombie;
    // auto destructor stack
    return (0);
}

// Creas un zombi en heap usando newZombie()

// Le haces announce

// Llamas randomChump()




/* Aprender

cuándo crear objetos en stack y cuándo en heap,
cómo funciona el destructor,
y cómo organizar tu código en varios archivos.
---
Tienes que crear “zombis” que pueden:

Tener un nombre (eso es una variable privada dentro del objeto).

Anunciarse (una función miembro que hace algo con sus datos).

Vivir en stack o en heap dependiendo de lo que necesites.

Piensa en stack como tu mesa de trabajo: cuando terminas de usar algo, se limpia automáticamente.
Piensa en heap como una caja que dejas en el almacén: si no la borras tú, se queda ocupando espacio.



Tienes que crear una clase Zombie (un tipo de dato con nombre y funciones).

Cada zombi puede anunciarse con un mensaje.

Dependiendo de cómo lo crees:

Stack: desaparece solo al final de la función.

Heap: permanece hasta que tú lo destruyas.



El punto clave del ejercicio no es solo imprimir “BraiiiiiiinnnzzzZ”,
sino distinguir cuándo usar stack y cuándo heap,
y practicar constructores/destructores.



*/

