package C322.homework7.parta;

public class TV {
    //constructor
    TV(State initialstate){
        this.state = initialstate;
    }
    State state;
    State getState(){
        return this.state;
    }
    //just do the opposite
    void pressButton(){
        if(state instanceof On){
            this.state = new Off();
            state.printState();
        }else{
            this.state = new On();
            state.printState();
        }
    }
}
