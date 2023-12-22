package C322.homework7.partb;

public class PasteCommand extends Command {

    public PasteCommand(Editor editor) {
        super(editor);
    }

    @Override
    public void execute() {
        saveBackup();
        editor.insertText(editor.getClipboard());
        editor.getCommandHistory().push(this);
    }
}