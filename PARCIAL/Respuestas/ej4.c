1- Declaracion de constantes -> En encontrada y no encontrada en vez de usar int podria usar solo un bool ENCONTRADA = true;
y bool NO_ENCONTRADA = false;

2- Uso de constantes -> En el struct el maximo de la direccion y el nombre estan hardcodeados tendria que crear constantes
#define MAX_DIRECCION 50 y #define MAX_NOMBRE 30 , en la funcion el char nombre quedaria char nombre[MAX_NOMBRE]

3-Pre y post -> Falta precondicion, el cual seria que t este inicializado.

4-Declaracion de variables-> en el for la i no esta declarada podrias o bien hacer int i = 1 en el for o declararlo arriba.

5-Nombres descriptivos -> ya que t en la funcion simboliza el tope deberia cambiarle el nombre a tope.

6-Uso de strings -> despues del if dado que el nombre nombre es un string se deberia comparar con strcmp osea, 
if(strcmp(casas[i].nombre, nombre) == 0){
    
}

7-Firma de la funcion -> Si bien int no esta mal podria ser mas comodo utilizar un bool, quedaria bool encontrar_direccion casa()
Cambiaria tambien las post seria Imprime la direccion y devuelve true si la encontro o false si no.

8-Uso de printf -> En el printf le estas diciendo al usuario la direccion pero estas seleccionando para imprimir el nombre,
se arregla cambiando casas[i].nombre por casas[i].direccion.

9-Uso constantes -> en lugar de hacer return encontrada dentro del for si declaramos un bool ENCONTRADA = false; 
como variable dentro de la funcion podriamos hacer en el for ENCONTRADA = true; y en el final poner return encontrada; ya que si no la encuentra 
va a retornar false que es como se inicializo el bool.

10- Inicializar variables -> En el for i esta inicializado como 1 y deberia estar inicializado como 0 si no no analizaria la
primer posicion del vector
