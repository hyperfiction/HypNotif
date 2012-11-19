#include <HypSystem.h>
#include <bps/bps.h>
#include <bps/dialog.h>
#include <bps/locale.h>
#include <stdlib.h>

namespace hyperfiction{

	dialog_instance_t loading_dialog = 0;

	const char* get_system_lang( ) {
		char* country = NULL;
    	char* language = NULL;
    	locale_get(&language, &country);

    	bps_free(country);

    	return language;
	}
	
	void show_loading(){
		if( loading_dialog ) {
			return;
		}
	
		if( dialog_create_alert(&loading_dialog) != BPS_SUCCESS ){
			return;
		}

		if( dialog_set_background_alpha(loading_dialog, 0.2) != BPS_SUCCESS ){
			return;
		}

		if( dialog_set_alert_message_text(loading_dialog, "..." ) != BPS_SUCCESS ){
			return;
		}

		if( dialog_set_position(loading_dialog, DIALOG_POSITION_MIDDLE_CENTER ) != BPS_SUCCESS ){
			return;
		}
		
		if (dialog_show(loading_dialog) != BPS_SUCCESS) {
			dialog_destroy(loading_dialog);
			loading_dialog = 0;
		}
	
	}
	
	void hide_loading(){
		if(loading_dialog){
			dialog_destroy(loading_dialog);
			loading_dialog = 0;
		}
	}
}