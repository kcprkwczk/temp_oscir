#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main( void )
{
int status;
void bye( void );
(void) atexit( bye );
switch( fork() )
{
case -1: printf( "...błąd uruchomienia potomnego\n" ); break;
case 0: exit( EXIT_SUCCESS ); break;
default:
wait( &status );
if(status){ printf("...bład powrotu\n"); exit(EXIT_FAILURE); }
}
return EXIT_SUCCESS;
}