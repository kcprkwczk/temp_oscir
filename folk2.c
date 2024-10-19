#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main( void )
{
int status;
switch( fork() )
{
case -1: printf( "...błąd uruchomienia procesu potomnego\n" ); break;
case 0:
printf( "*** URUCHOMIENIE PROCESU POTOMNEGO ***\n" );
execl( "/usr/bin/free","-m",'\0' );
//... w gruncie rzeczy nie może się tu znaleźć, ale
printf( "...błąd w procesie potomnym\n" ); exit( -1 );
break; //...oczywiście break w tym miejscu nie ma znaczenia
default: //...kod dla parent
wait( &status );
if( !status ){printf( "potomek zakończył działanie (prawidłowo)\n" )}
else{ printf( "... coś nie tak z potomkiem\n" ); }
}
return 0;
}