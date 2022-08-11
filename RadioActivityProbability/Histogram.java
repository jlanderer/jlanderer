import java.util.Scanner;
/**
 * This class takes in the array of the rounds each particle decays.
 * It first determines the largest turn survived for the x bound, then the turn at which most particles died for the y bound.
 *
 * @author (Jacob Landerer)
 * @version (4.12.20)
 */
public class Histogram extends RadioActivityProbability
{
    static Scanner UserInput = new Scanner (System.in);
    public static void GetMaximums(int[] NumRounds){
        //for x axis
        int maxRound = 0;
        for (int i = 1; i < NumRounds.length; i++){
            if (NumRounds[i] > maxRound)
                maxRound = NumRounds[i]; // Determines maximum x value
        }
        int yAxis = RadioActivityProbability.n;
        Print(NumRounds, maxRound, yAxis);
    }

    public static void Print(int[] NumRounds, int xBound, int yBound){
        System.out.println('\u000C');
        for (int i = yBound; i > 0; i--){ // Printing line by line beginning with the numbers on the y axis
            // This block prints the number of occurences of a particle decaying at
            // any given turn, from 1 to the maximum
            if (i < 10)
                System.out.print(i + "  |");
            else if (i >= 10 && i < 100)                             
                System.out.print(i + " |");
            else
                System.out.print(i + "|");
            for (int j = 1; j <= xBound; j++){ // incrementing in the x direction
                System.out.print(DetermineExistence(NumRounds, i, j));
                // This method determines whether to print a data point or a balnk space
                // based on the esistence of a point at the coordinate in question (i,j))
            }
             System.out.print("\n");
        }
        System.out.print("    ");
        for (int k = 1; k <= xBound; k++) {
             System.out.print("____");
        }
        System.out.print("\n");
        System.out.print("       ");
        for (int l = 1; l <= xBound; l++){
            if (l < 10)
                System.out.print(" " +l+ " ");
            else
                System.out.print(" " +l);
        }
        System.out.println("\nIf you would like to run the simulation again, type \"Y\". If not, exit the program.");
        if (UserInput.next().equals("Y"))
            RadioActivityProbability.main();
        else
            System.exit(0);
    }

    public static String DetermineExistence(int[] NumRounds, int currentYLevel, int currentTurn){
        int counter = 0;
        for (int i = 0; i < NumRounds.length; i++){
            if (NumRounds[i] >= currentTurn)
                counter++;  // This counts the number occurences of the current turn
        }
        if (currentTurn < 10){
            if (counter >= currentYLevel) // Compares number of occurences to the current y level (being printed)
                return " * ";
            else 
                return "   ";
        }
        else {
            if (counter >= currentYLevel) // Compares number of occurences to the current y level (being printed)
                return " * ";
            else 
                return "   ";
        }
    }
}