import java.awt.*;
import javax.swing.*;

public class MemoryGame
{
    public static void main(String[] args)
    {


        JFrame frame = new JFrame("Memory Game");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.getContentPane().add(new MemoryGamePanel());

        frame.setPreferredSize(new Dimension(700, 100));
        frame.setLayout(new GridLayout(1, 3));
        frame.pack();
        frame.setVisible(true);
    }


}
