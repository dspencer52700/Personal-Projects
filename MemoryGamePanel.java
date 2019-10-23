import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.Random;


public class MemoryGamePanel extends JPanel
{
    JButton submit, reveal, next;
    JTextField entryField;
    JLabel labelF, labelM, labelL;
    JPanel panelMain, panelNames, panelButtons;
    Person[] personList = new Person[15];
    int whichPerson, whichName;


    public MemoryGamePanel()
    {


        FillList(personList);

        submit = new JButton("Submit");
        reveal = new JButton("Reveal");
        next = new JButton("Next Person");

        entryField = new JTextField(12);

        labelF = new JLabel("~~~");
        labelM = new JLabel("~~~");
        labelL = new JLabel("~~~");

        ButtonListener listener = new ButtonListener();
        submit.addActionListener(listener);
        reveal.addActionListener(listener);
        next.addActionListener(listener);

        panelMain = new JPanel();

        panelNames = new JPanel();
        panelNames.add(labelF);
        panelNames.add(Box.createGlue());
        panelNames.add(labelM);
        panelNames.add(Box.createGlue());
        panelNames.add(labelL);
        panelMain.add(panelNames);

        panelMain.add(entryField);

        panelButtons = new JPanel();
        panelButtons.add(submit);
        panelButtons.add(reveal);
        panelButtons.add(next);
        panelMain.add(panelButtons);

        add(panelMain);


    }

    private class ButtonListener implements ActionListener
    {
        public void actionPerformed (ActionEvent e)
        {
            if (e.getSource() == submit)
            {
                String correctAnswer;

                switch(whichName)
                {
                    case 1:
                        correctAnswer = personList[whichPerson].firstName;
                        if (correctAnswer.equals(entryField.getText()))
                        {   entryField.setText("Correct!"); }
                        break;
                    case 2:
                        correctAnswer = personList[whichPerson].middleName;
                        if (correctAnswer.equals(entryField.getText()))
                        {   entryField.setText("Correct!"); }
                        break;
                    case 3:
                        correctAnswer = personList[whichPerson].lastName;
                        if (correctAnswer.equals(entryField.getText()))
                        {   entryField.setText("Correct!"); }
                        break;
                }
            }

            if (e.getSource() == reveal)
            {
                switch(whichName)
                {
                    case 1:
                        labelF.setText(personList[whichPerson].firstName);
                        break;
                    case 2:
                        labelM.setText(personList[whichPerson].middleName);
                        break;
                    case 3:
                        labelL.setText(personList[whichPerson].lastName);
                        break;
                }
            }

            if (e.getSource() == next)
            {
                Random rand = new Random();
                whichName = rand.nextInt(3) + 1;
                whichPerson = rand.nextInt(15) + 1;

                switch(whichName)
                {
                    case 1:
                        labelF.setText("??????????");
                        labelM.setText(personList[whichPerson].middleName);
                        labelL.setText(personList[whichPerson].lastName);
                        break;
                    case 2:
                        labelF.setText(personList[whichPerson].firstName);
                        labelM.setText("??????????");
                        labelL.setText(personList[whichPerson].lastName);
                        break;
                    case 3:
                        labelF.setText(personList[whichPerson].firstName);
                        labelM.setText(personList[whichPerson].middleName);
                        labelL.setText("??????????");
                        break;
                }
            }
        }
    }

    static Person[] FillList(Person list[])
    {

        list[0] = new Person("David", "Shannon", "Spencer");
        list[1] = new Person("Spencer", "Konrad", "Thompson");
        list[2] = new Person("Steven", "Alexander", "Johnson");
        list[3] = new Person("Logan", "Alexander", "Wibberly");
        list[4] = new Person("Riley", "Evan","Barker");
        list[5] = new Person("Vladislav","Dragomir","Nikolic");
        list[6] = new Person("Chris","Toby","Derby");
        list[7] = new Person("Jeffrey","Lane","Keeling");
        list[8] = new Person("Alex","Delgado","Beebe");
        list[9] = new Person("William","Noah","Fletcher");
        list[10] = new Person("Adam","Lee","Eisert");
        list[11] = new Person("Michael","Benjamin","Thompson");
        list[12] = new Person("Richard","Brent","White");
        list[13] = new Person("Cohen","David","McCubbin");
        list[14] = new Person("Landon","Ellis","Brooks");

        return list;
    }
}
