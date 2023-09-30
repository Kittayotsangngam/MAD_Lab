/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//  char str[] ="QUIT";
//	char ch1 = 'j' ;
//	char ch2[3] =" \n\r";
char init[] = "Display Blinking LED PRESS (1, 2)\n\rDisplay Group Members PRESS m\n\rQuit PRESS q\n\r";
	char inp[] = "\tInput =>";
	char m[] = "64010001\n\rKatanyoo Thanoosin\n\r64010017\n\rKittayot Sangngam\n\r64010309\n\rThanakan Kanphairor\n\r";
	char quit[] = "Quit";
	char uc[] = "Unknown Command\n\r";
	char td[3] =" \n\r";
	char t;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MPU_Initialize(void);
static void MPU_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* MPU Configuration--------------------------------------------------------*/
  MPU_Config();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
   HAL_UART_Transmit(&huart3, (uint8_t*) init, strlen(init),1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	  if(ch1!='q'){
//			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) "Input =>", strlen("Input =>"),1000);
//
//			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE)== RESET){}
//			  HAL_UART_Receive(&huart3, (uint8_t*) &ch1, 1, 1000);
//			  HAL_Delay(100);
//
//			  ch2[0] = ch1;
//
//			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) ch2, 3,1000);
//		  }else{
//			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
//			  HAL_UART_Transmit(&huart3, (uint8_t*) str, strlen(str),1000);
//			  break;
//		  }
	  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
		  HAL_UART_Transmit(&huart3, (uint8_t*) inp, strlen(inp),1000);

		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_RXNE)== RESET){}
		  HAL_UART_Receive(&huart3, (uint8_t*) &t, 1, 1000);
		  HAL_Delay(100);

		  td[0]=t;
		  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
		  HAL_UART_Transmit(&huart3, (uint8_t*) td, strlen(td),1000);

		  if(t=='q'){
			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
			  HAL_UART_Transmit(&huart3, (uint8_t*) quit, strlen(quit),1000);
			  break;
		  }
		  else if(t=='1'){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_Delay(300);

			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_RESET);
			  HAL_Delay(300);

			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_0,GPIO_PIN_RESET);
		  }
		  else if(t=='2'){
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_RESET);
			  HAL_Delay(300);

			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_RESET);
			  HAL_Delay(300);

			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_SET);
			  HAL_Delay(300);
			  HAL_GPIO_WritePin(GPIOD,GPIO_PIN_1,GPIO_PIN_RESET);
		  }
		  else if(t=='m'){
			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
			  HAL_UART_Transmit(&huart3, (uint8_t*) m, strlen(m),1000);
		  }
		  else{
			  while(__HAL_UART_GET_FLAG(&huart3,UART_FLAG_TC)==RESET){}
			  HAL_UART_Transmit(&huart3, (uint8_t*) uc, strlen(uc),1000);
		  }

	/* USER CODE END 3 */
  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* MPU Configuration */

void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct = {0};

  /* Disables the MPU */
  HAL_MPU_Disable();

  /** Initializes and configures the Region and the memory to be protected
  */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.BaseAddress = 0x0;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  /* Enables the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */