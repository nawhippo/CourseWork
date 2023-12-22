package C322.homework7.partb;

public class CopyCommand extends Command {
    public CopyCommand(Editor editor) {
        super(editor);
    }

    @Override
    public void execute() {
        //save a backup for every command's execution so that we can eventually undo it.
        saveBackup();
        editor.copySelectedText();
        editor.getCommandHistory().push(this);
    }
}