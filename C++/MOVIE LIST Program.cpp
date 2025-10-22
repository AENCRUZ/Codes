#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding random number generator
using namespace std;

struct Movie {
    string title;
    string genre;
    bool watched; // true if the movie is marked as watched
};

// Function prototypes
void addMovie(vector<Movie>& wishlist);
void displayMovies(const vector<Movie>& wishlist);
void updateMovie(vector<Movie>& wishlist);
void deleteMovie(vector<Movie>& wishlist);
void pickRandomMovie(const vector<Movie>& wishlist);

int main() {
    vector<Movie> wishlist; // Movie wishlist
    int choice;

    // Seed the random number generator
    srand(time(0));

    do {
        cout << "\n--- Movie Wishlist ---\n";
        cout << "1. Add a Movie\n";
        cout << "2. Display Movies\n";
        cout << "3. Update a Movie (Mark as Watched)\n";
        cout << "4. Delete a Movie\n";
        cout << "5. Pick a Random Movie\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                addMovie(wishlist);
                break;
            case 2:
                displayMovies(wishlist);
                break;
            case 3:
                updateMovie(wishlist);
                break;
            case 4:
                deleteMovie(wishlist);
                break;
            case 5:
                pickRandomMovie(wishlist);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new movie to the wishlist
void addMovie(vector<Movie>& wishlist) {
    Movie newMovie;
    cout << "Enter movie title: ";
    getline(cin, newMovie.title);
    cout << "Enter movie genre: ";
    getline(cin, newMovie.genre);
    newMovie.watched = false; // Initially set as unwatched
    wishlist.push_back(newMovie);
    cout << "Movie added to wishlist!\n";
}

// Function to display all movies in the wishlist
void displayMovies(const vector<Movie>& wishlist) {
    if (wishlist.empty()) {
        cout << "Your movie wishlist is empty.\n";
        return;
    }

    cout << "\n--- Movie Wishlist ---\n";
    for (size_t i = 0; i < wishlist.size(); i++) {
        cout << i + 1 << ". " << wishlist[i].title 
             << " (" << wishlist[i].genre << ") - ";
        cout << (wishlist[i].watched ? "Watched" : "Unwatched") << endl;
    }
}

// Function to update a movie's status to "watched"
void updateMovie(vector<Movie>& wishlist) {
    if (wishlist.empty()) {
        cout << "Your movie wishlist is empty.\n";
        return;
    }

    int index;
    displayMovies(wishlist);
    cout << "Enter the number of the movie to mark as watched: ";
    cin >> index;
    cin.ignore(); // Clear input buffer
    if (index < 1 || index > wishlist.size()) {
        cout << "Invalid movie number!\n";
        return;
    }

    wishlist[index - 1].watched = true;
    cout << "Movie marked as watched!\n";
}

// Function to delete a movie from the wishlist
void deleteMovie(vector<Movie>& wishlist) {
    if (wishlist.empty()) {
        cout << "Your movie wishlist is empty.\n";
        return;
    }

    int index;
    displayMovies(wishlist);
    cout << "Enter the number of the movie to delete: ";
    cin >> index;
    cin.ignore(); // Clear input buffer
    if (index < 1 || index > wishlist.size()) {
        cout << "Invalid movie number!\n";
        return;
    }

    wishlist.erase(wishlist.begin() + index - 1);
    cout << "Movie deleted from wishlist.\n";
}

// Function to pick a random movie from the wishlist
void pickRandomMovie(const vector<Movie>& wishlist) {
    if (wishlist.empty()) {
        cout << "Your movie wishlist is empty.\n";
        return;
    }

    int randomIndex = rand() % wishlist.size(); // Generate a random index
    const Movie& movie = wishlist[randomIndex];
    cout << "Random movie suggestion: " << movie.title 
         << " (" << movie.genre << ") - "
         << (movie.watched ? "Watched" : "Unwatched") << endl;
}
