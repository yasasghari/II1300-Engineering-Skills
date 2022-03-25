#include <stdio.h>
#include <unistd.h>


int time_divider (int, int);

  int HH, MM, SS;
int main ()
{

  int present_time;

  int time_for_alarm;

//User can write 6 integers for the current time 


  printf ("Enter current time:");
  scanf ("%d", &present_time);

//User can write the time for the alarm

  printf ("Enter time for alarm:");
  scanf ("%d", &time_for_alarm);

//As long as the time now is less then the time for the alarm,
//the code should print the time +1 in one second intervals 

  while (present_time != time_for_alarm)
    {
        present_time++;
      HH = time_divider (present_time, 1);
      MM = time_divider (present_time, 2);
      SS = time_divider (present_time, 3);
        present_time=real_clock(present_time);
      printf ("%02d:%02d:%02d\n", HH, MM, SS);
    }
  printf ("ALARM");

  return 0;
}

//Assuming time to be 100 hours, 100 min and 100 sec

int time_divider (int present_time, int unit)
{
  int answer;

  if (unit == 1)
    {
      answer = present_time / 10000;
      return answer;
    }
  else if (unit == 2)
    {
      answer = present_time / 100 % 100;
      return answer;
    }
  else if (unit == 3)
    {
      answer = present_time % 100;
      return answer;
    }
}
real_clock(int present_time){
    if(SS==60){
        present_time = present_time + 40;
        SS = 0;
        MM = MM + 1;
    }
    if(MM==60){
        present_time = present_time + 4000;
        MM = 0;
        HH = HH + 1;
    }
    if(HH>23){
        present_time = 0;
        HH = 0;
    }
    return present_time;
}