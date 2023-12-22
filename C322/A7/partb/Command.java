package C322.homework7.partb;
    public abstract class Command {
        protected Editor editor;
        private String backup;

        public Command(Editor editor) {
            this.editor = editor;
        }

        public void saveBackup() {
            backup = editor.getSelection();
        }

        public void undo() {
            //just replace the text with the backup
            editor.replaceSelection(0,backup.length(), backup);
        }


        //execution should push it on the command history's stack

        public abstract void execute();
    }