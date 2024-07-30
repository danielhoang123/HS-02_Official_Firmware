#include "Btn_Process.h"
#include "MachTest_SP_IO.h"

OneButton btn_start(BTN_START_PIN, true);
OneButton btn_next(BTN_NEXT_PIN, true);
OneButton btn_previous(BTN_PREVIOUS_PIN, true);

void buttonInit()
{
	btn_start.setClickTicks(200);
	btn_next.setClickTicks(200);
	btn_previous.setClickTicks(200);
	
	btn_next.attachClick(&Up_do_0_Click);
	btn_start.attachClick(&Start_do_2_Click);
	btn_start.attachDoubleClick(&Start_do_1_Click);
	btn_previous.attachClick(&Down_do_0_Click);
}

void buttonLoop()
{
	btn_start.tick();
	btn_next.tick();
	btn_previous.tick();
	yield();
}
