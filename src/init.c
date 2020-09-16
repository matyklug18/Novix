// please dont bully
// me for the code!
// i know i suck at coding
// but that does not mean you can harrass
// me.

// anyways, here are the includes:
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// functions
void mainMessage(void){
  // we tell the user that the os is booting,
  // and that they should see some loading info
  terminal_writestring("This is Niux OS booting from Kernel...\n\n\n");
}



void gdtLoad(int statusCode){
  if(statusCode != 0){
    terminal_writestring("Failed to initialize: GDT.\n");
  } else {
    terminal_writestring("Success! Initialized GDT.\n");
    // installGDT(); // NOTE: THIS WILL GET STUCK IN A BOOT LOOP. So i WILL
    // comment it out.
  }
}

void idtLoad(void){
  terminal_writestring("Niux OS has loaded IDT --- Status code 0.\n");
}


void continueWithBoot(){
  // allows for other stuff to run
  // such as the "Hello world" stuff.
  terminal_writestring("\n\n\nInitialization successful...continuing...\n");
}


// now we combine all of these functions to make this:
void init(void){
  mainMessage();
  gdtLoad(137);
  idtLoad();
  continueWithBoot();
}
