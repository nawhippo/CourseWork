package C322.homework7.partb;
public class Shortcuts {
    private String[] shortcuts;
    private Command[] commands;


    //two arrays for a string and commands
    public Shortcuts(int capacity) {
        shortcuts = new String[capacity];
        commands = new Command[capacity];
    }

    //essentially a hash map,
    public void addShortcut(String shortcut, Command command) {
        for (int i = 0; i < shortcuts.length; i++) {
            if (shortcuts[i] == null) {
                shortcuts[i] = shortcut;
                commands[i] = command;
                return;
            }
        }
        System.out.println("Shortcut aggregation full");
    }

    //deletes a given shortcut by its name
    public void removeShortcut(String shortcut) {
        for (int i = 0; i < shortcuts.length; i++) {
            if (shortcut.equals(shortcuts[i])) {
                shortcuts[i] = null;
                commands[i] = null;
                return;
            }
        }
        System.out.println("Shortcut not found.");
    }

    //executes the respective command at an index.
    public void executeShortcut(String shortcut) {
        for (int i = 0; i < shortcuts.length; i++) {
            if (shortcut.equals(shortcuts[i])) {
                commands[i].execute();
                return;
            }
        }
        System.out.println("Shortcut not found.");
    }
}