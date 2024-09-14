#include "led_st.h"
#include "main.h"
extern UART_HandleTypeDef huart2;

/**
 * @brief: Esta función indica los Hz a los que debe funcionar el led.
 *
 * @param data: 1 si la contraseña es incorrecta, 0 de lo contrario.
 *
 * @retval: Ninguno.
 */
void estatus_ld (uint8_t stt){

	static uint16_t tiempo_cambio = 0xFFFF;

	if(HAL_GetTick() > tiempo_cambio){
		if (stt == 1) {
			HAL_UART_Transmit(&huart2, "Entró a incorrecto2\r\n", 22, 10);
			HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
			tiempo_cambio = HAL_GetTick() + 125;

		}else if (stt == 0){
			HAL_UART_Transmit(&huart2, "Entró a correcto2\r\n", 20, 10);
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
			tiempo_cambio = HAL_GetTick() + 125;
		}else if (stt == 30){
			HAL_UART_Transmit(&huart2, "No esta funcionando2\r\n", 22, 10);
			tiempo_cambio = HAL_GetTick() + 125;
		}
	}

	if(stt == 1 && tiempo_cambio == 0xFFFF){
		HAL_UART_Transmit(&huart2, "Entró a incorrecto1\r\n", 22, 10);
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		tiempo_cambio = HAL_GetTick() + 125;
	}else if (stt == 0 && tiempo_cambio == 0xFFFF){
		HAL_UART_Transmit(&huart2, "Entró a correcto1\r\n", 20, 10);
		HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, 0);
		tiempo_cambio = HAL_GetTick() + 125;
	}else if (stt == 30 && tiempo_cambio == 0xFFFF){
		HAL_UART_Transmit(&huart2, "No esta funcionando1\r\n", 22, 10);
		tiempo_cambio = HAL_GetTick() + 125;
	}

}
