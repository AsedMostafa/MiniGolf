#include "rsdl.hpp"
#include "utils.hpp"

bool isClicked(Event ent){
    if(ent.get_type() == Event::LCLICK){
        return true;
    }
    return false;
}

bool isMoving(Event ent){
    if(ent.get_type() == Event::MMOTION){
        return true;
    }
    return false;
}

bool isReleased(Event ent){
    if(ent.get_type() == Event::LRELEASE){
        return true;
    }
    return false;
}

void winingGame(Window* win){
    win->clear();
    //win.stop_music();
    win->show_text("YOU",Point(200,70),WHITE,"./Lato/Lato-BlackItalic.ttf",100);
    win->show_text("WIN!",Point(220,200),WHITE,"./Lato/Lato-BlackItalic.ttf",100);
    win->play_sound_effect("./sounds/wining_sound.wav");
    win->update_screen();
    delay(6000);
    exit(0);
}

void gameOver(Window* win){
    win->clear();
    //win->stop_music();
    win->show_text("GAME",Point(200,70),WHITE,"./Lato/Lato-BlackItalic.ttf",100);
    win->show_text("OVER!",Point(200,200),WHITE,"./Lato/Lato-BlackItalic.ttf",100);
    //win>play_sound_effect("assets/sounds/sound_effects/gameover.wav");
    win->update_screen();
    delay(5000);
    exit(0);
}
