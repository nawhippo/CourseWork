package C322.homework7.partb;

public class UndoCommand extends Command {
    private Editor editor;

    public UndoCommand(Editor editor) {
        super(editor);
    }

    @Override
    public void execute() {
        //pops off a previous command in the command history in the editor
        saveBackup();
        if (!editor.getCommandHistory().isEmpty()) {
            Command previousCommand = editor.getCommandHistory().pop();
            previousCommand.undo();
        } else {
            System.out.println("No previous command to undo!");
            return;
        }
        editor.getCommandHistory().push(this);
    }
}