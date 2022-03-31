//
//  testa motor c
//

#include <stdio.h>
#include "brick.h"
#include <unistd.h>

#define Sleep( msec ) usleep(( msec ) * 1000 ) /* Definerar sleep, Sleep(1000)= 1 sekund */

#define MOTOR_RIGHT        OUTA
#define MOTOR_LEFT        OUTB
#define MOTOR_C            OUTC
#define MOTOR_D            OUTD
#define SENSOR_TOUCH    IN1
#define SENSOR_2        IN2
#define SENSOR_3        IN3
#define SENSOR_4        IN4

#define MOTOR_BOTH         ( MOTOR_LEFT | MOTOR_RIGHT ) /* Bitvis ELLER ger att båda motorerna styrs samtidigt */

int max_hastighet;         /* variabel för max hastighet på motorn */
POOL_T touchSensor;

int main( void )
{
    if ( !brick_init()) return ( 1 ); /* Initialiserar EV3-klossen */
    printf( "*** ( EV3 ) Hello! ***\n" );
    Sleep( 2000 );
    
    if ( tacho_is_plugged( MOTOR_C, TACHO_TYPE__NONE_ )) {  /* TACHO_TYPE__NONE_ = Alla typer av motorer */
        max_hastighet = tacho_get_max_speed( MOTOR_C, 0 );    /* Kollar maxhastigheten som motorn kan ha */
        tacho_reset( MOTOR_C );
    } else {
        printf( "Anslut vänster motor i port A,\n"
        "Anslut höger motor i port B.\n"
        );
          brick_uninit();
        return ( 0 );  /* Stänger av sig om motorer ej är inkopplade */
    }
    
    touchSensor = sensor_search( LEGO_EV3_TOUCH ); // Registrerar en touch sensor på touchSensor-variabeln
    touch_set_mode_touch(touchSensor); // anger vilken "mode" sensorn skall ha

    //tacho_set_speed_sp( MOTOR_BOTH, max_hastighet * (-0.3) );  // Sätter hastigheten på båda motorerna till 30% av maxhastigheten, negativ eftersom den ska bakåt
    
    // ------------------- allt ovanför denna rad -------------------- //
    
    // köra fram
    tacho_set_speed_sp( MOTOR_C, max_hastighet * (0.5) );  // Sätter hastigheten på båda motorerna till 30% av maxhastigheten, positiv eftersom den ska framåt
    tacho_run_forever(  MOTOR_C );
    Sleep( 3000 );
    tacho_stop( MOTOR_C );
    
    // ---- och under denna, är kopierat från exempelMotorTouch.c ---- //
    
    brick_uninit();
    printf( "dying...\n" );
    return ( 0 );
    
}

