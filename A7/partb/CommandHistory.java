package C322.homework7.partb;

import java.util.Stack;

public class CommandHistory {
    //kind of a redundant class, but we have to follow the UML
    Stack<Command> history;

    public CommandHistory(Stack<Command> history) {
        this.history = history;
    }
    public void push(Command command){
        this.history.push(command);
    }
    public Command pop(){
        return this.history.pop();
    }
    public boolean isEmpty() {
        if (this.history.isEmpty()) {
            return true;
        }
            return false;
        }
    }
