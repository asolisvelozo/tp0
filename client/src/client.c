#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log * log_create (char *file, char *process_name, bool is_active_console, t_log_level level);
	
	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	
	logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_info(logger, "Hola! soy un log");
	
	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */
	
	config = iniciar_config();
	
	valor = config_get_string_value(config, "CLAVE");
	ip= config_get_string_value(config, "IP");
	puerto= config_get_string_value(config, "PUERTO");
	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config

	log_info(logger, "La clave es:  %s", valor);
	log_info(logger, "El IP es:  %s", ip);
	log_info(logger, "El puerto es: %s", puerto);



	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	
	enviar_mensaje(valor, conexion);


	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente

}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{

	t_config* nuevo_config = config_create("/home/utnso/Desktop/tp0/client/cliente.config");

    if (nuevo_config == NULL) {
        printf("No se pudo leer el archivo de configuración\n");
    }


	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	//leido = readline("> ");

	while (1) {
        leido = readline("Ingrese algo: >");
        if (!leido) {
            break;
        }
        if (leido) {
            add_history(leido);
        }
        if (!strncmp(leido, "exit", 4)) {
            free(leido);
            break;
        }
		if(strcmp(leido,"")==0){
			free(leido);
			break;
		}
        log_info(logger,"%s \n", leido);
        free(leido);
    }
	// El restow, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{	

	log_destroy(logger);
	config_destroy(config);



	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
