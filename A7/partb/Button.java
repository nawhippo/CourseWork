package C322.homework7.partb;
    public class Button {
        private final Command command;

        public Button(Command command) {
            this.command = command;
        }

        public void pressButton() {
            command.execute();
        }
    }