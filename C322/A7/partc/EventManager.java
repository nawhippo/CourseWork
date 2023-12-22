package C322.homework7.partc;

import java.util.ArrayList;

public class EventManager {
    public EventManager(Editor editor, ArrayList<EventListener> eventListeners) {
        this.editor = editor;
        this.eventListeners = eventListeners;
    }

    Editor editor;
    ArrayList<EventListener> eventListeners;

    //listeners

    void subscribe(EventListener eventListener){
        this.eventListeners.add(eventListener);
    }

    void unsubscribe(EventListener eventListener){
        this.eventListeners.remove(eventListener);
    }

    void notifyListeners(){
        for(EventListener event : eventListeners){
            //if the editor opens a new file, notify all listeners and have them update
            event.update(this.editor.file);
        }
    }
}
