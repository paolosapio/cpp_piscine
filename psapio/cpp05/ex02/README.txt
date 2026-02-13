CPP Module 05 – ex02 "EXCEPCIONES - POLIMORFISMO - ASTRABCION"
AForm y Formularios Derivados
Este ejercicio amplía el trabajo realizado en los ejercicios anteriores.
El objetivo es diseñar una jerarquía de clases que represente distintos tipos de formularios administrativos, todos ellos basados en una clase abstracta común.
El módulo introduce el uso de clases abstractas, herencia, excepciones y relaciones entre objetos.

1. Objetivo del ejercicio
El propósito del ejercicio es:
- Crear una clase abstracta llamada AForm que represente un formulario genérico.
- Implementar tres clases derivadas, cada una con un comportamiento específico.
- Hacer que los objetos Bureaucrat puedan firmar y ejecutar estos formularios.
- Utilizar excepciones para controlar errores de rango, firma y ejecución.
- Garantizar que cada formulario solo pueda ejecutarse si está firmado y si el burócrata tiene el rango adecuado.

2. Clase AForm (abstracta)
2.1. Atributos
La clase AForm debe contener:
- const std::string _name
- bool _isSigned
- const int _gradeToSign
- const int _gradeToExec
Estos atributos representan:
- El nombre del formulario.
- Si está firmado o no.
- El rango mínimo necesario para firmarlo.
- El rango mínimo necesario para ejecutarlo.
2.2. Reglas de validación
En el constructor, se debe comprobar que los rangos estén dentro del intervalo permitido:
- Si gradeToSign < 1 o gradeToExec < 1, lanzar GradeTooHighException.
- Si gradeToSign > 150 o gradeToExec > 150, lanzar GradeTooLowException.
2.3. Métodos obligatorios
- Getters para todos los atributos.
- void beSigned(const Bureaucrat &bureaucrat);
- Firma el formulario si el burócrata tiene rango suficiente.
- Si ya está firmado, lanzar AlreadySignedException.
- Si el rango es insuficiente, lanzar GradeTooLowException.
- virtual void execute(const Bureaucrat &executor) const = 0;
- Método virtual puro.
- Hace que AForm sea una clase abstracta.
- Cada formulario derivado debe implementar su propia acción.
2.4. Método auxiliar recomendado
Aunque no es obligatorio, se recomienda implementar:
void checkExecutable(const Bureaucrat &executor) const;


Este método debe:
- Lanzar NotSignedException si el formulario no está firmado.
- Lanzar GradeTooLowException si el burócrata no tiene rango suficiente.
Los formularios derivados deben llamar a este método al inicio de execute().
2.5. Excepciones internas
AForm debe definir las siguientes excepciones:
- GradeTooHighException
- GradeTooLowException
- AlreadySignedException
- NotSignedException
Cada una debe sobrescribir what().

3. Formularios derivados
Se deben implementar tres clases que hereden de AForm.
Cada una debe tener un atributo std::string _target y un constructor que inicialice correctamente los rangos requeridos.
3.1. ShrubberyCreationForm
Acción en execute():
- Crear un archivo llamado <target>_shrubbery.
- Escribir en él un árbol ASCII.
- Requiere los rangos especificados en el subject.
3.2. RobotomyRequestForm
Acción en execute():
- Imprimir sonidos de taladro.
- Tener un 50% de probabilidad de éxito.
- Si tiene éxito: <target> has been robotomized successfully.
- Si falla: robotomy failed.
3.3. PresidentialPardonForm
Acción en execute():
- Imprimir: <target> has been pardoned by Zaphod Beeblebrox.

4. Relación con la clase Bureaucrat
La clase Bureaucrat debe interactuar con los formularios mediante dos métodos:
4.1. Firmar un formulario
void signForm(AForm &form) const;


Este método:
- Llama a form.beSigned(*this).
- Muestra un mensaje indicando si la firma tuvo éxito o no.
- Utiliza try/catch para capturar excepciones.
4.2. Ejecutar un formulario
void executeForm(const AForm &form) const;


Este método:
- Llama a form.execute(*this).
- Muestra un mensaje indicando si la ejecución tuvo éxito o no.
- Utiliza try/catch para capturar excepciones.

5. Flujo típico de uso
- Crear un burócrata con un rango válido.
- Crear un formulario derivado.
- Intentar firmarlo mediante signForm().
- Intentar ejecutarlo mediante executeForm().
- Manejar excepciones si el rango es insuficiente o el formulario no está firmado.

6. Objetivo pedagógico del ejercicio
Este ejercicio busca que el estudiante:
- Comprenda el uso de clases abstractas y métodos virtuales puros.
- Aplique herencia correctamente.
- Diseñe clases que validan su propio estado.
- Utilice excepciones para controlar errores.
- Evite duplicación de código mediante métodos auxiliares.
- Entienda cómo interactúan objetos complejos entre sí.
