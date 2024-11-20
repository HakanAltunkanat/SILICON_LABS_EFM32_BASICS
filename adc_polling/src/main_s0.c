

#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_adc.h"

#define adcFreq   14000000

volatile uint32_t sample;
volatile float millivolts;


void initADC (void)
{
  // Enable ADC0 clock
  CMU_ClockEnable(cmuClock_ADC0, true);

  // structs for adc configuration and single mode configuration
  ADC_Init_TypeDef init = ADC_INIT_DEFAULT;
  ADC_InitSingle_TypeDef initSingle = ADC_INITSINGLE_DEFAULT;
  // precaler value is set wtih desired adc frequency, 0 is used for predefined clock settings
  init.prescale = ADC_PrescaleCalc(adcFreq, 0); // Init to max ADC clock for Series
  initSingle.diff       = false;        // single ended
  initSingle.reference  = adcRef2V5;    //2.5V reference
  initSingle.resolution = adcRes12Bit;  // 12-bit resolution

  // input channel 7 is selected, (PD7)
  initSingle.input = adcSingleInputCh7;


  ADC_Init(ADC0, &init);
  ADC_InitSingle(ADC0, &initSingle);
}

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  CHIP_Init();

  initADC();
  while(1)
  {
    // Start ADC conversion
    ADC_Start(ADC0, adcStartSingle);

    //when the conersion is completed,necessary bits in ADC0->STATUS registers are set
    //_ADC_STATUS_SINGLEDV_MASK is a bit mask whose value is 0x10000
    while(!(ADC0->STATUS & _ADC_STATUS_SINGLEDV_MASK));

    // Get ADC result
    sample = ADC_DataSingleGet(ADC0); //digital result is read

    // Calculate input voltage in mV
    millivolts = (sample * 3.3) / 4096; //analog value is calculated from the taken digital value
  }
}
