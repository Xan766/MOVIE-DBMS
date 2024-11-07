#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 10
#define MAX_STRING_LENGTH 200

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Structure to hold movie details
struct Movie {
    char name[MAX_STRING_LENGTH];
    char director[MAX_STRING_LENGTH];
    char cast[MAX_STRING_LENGTH];
    int year;
    char genre[MAX_STRING_LENGTH];
    char plot[MAX_STRING_LENGTH];
    char spoiler[MAX_STRING_LENGTH];  // Added spoiler field
};

// Function to search for movie and display its details
void search_movie(struct Movie movies[], int num_movies, const char *search_name) {
    int found = 0;
    char lower_search_name[MAX_STRING_LENGTH];
    
    // Convert user input to lowercase for case-insensitive comparison
    strcpy(lower_search_name, search_name);
    to_lowercase(lower_search_name);

    for (int i = 0; i < num_movies; i++) {
        char lower_movie_name[MAX_STRING_LENGTH];
        
        // Convert each movie name in the database to lowercase
        strcpy(lower_movie_name, movies[i].name);
        to_lowercase(lower_movie_name);

        if (strcmp(lower_movie_name, lower_search_name) == 0) {
            // Display movie details with funky sentences and emojis
            printf("\n🎬 * Movie Found * 🎬\n");
            printf("🍿 *Movie Name*: %s\n", movies[i].name);
            printf("🎥 *Director*: %s - This person knows how to make magic! ✨\n", movies[i].director);
            printf("👥 *Cast*: %s - The dream team! 💥\n", movies[i].cast);
            printf("📅 *Year of Release*: %d - This is when the magic happened! 🕒\n", movies[i].year);
            printf("🎭 *Genre*: %s - Perfect for movie buffs like you! 🍿\n", movies[i].genre);
            printf("📖 *Plot*: %s - This will blow your mind! 🤯\n", movies[i].plot);
            found = 1;

            // Ask for spoiler alert
            char choice[MAX_STRING_LENGTH];
            printf("\n🤔 *Wanna get the SPOILER of this movie?* (yes/no): ");
            fgets(choice, MAX_STRING_LENGTH, stdin);
            choice[strcspn(choice, "\n")] = '\0';  // Remove newline character

            if (strcmp(choice, "yes") == 0) {
                printf("\n🚨 *SPOILER ALERT* 🚨\n");
                printf("😱 *Spoiler*: %s\n", movies[i].spoiler);
                printf("💥 Mind = blown! 🤯\n");
            } else if (strcmp(choice, "no") == 0) {
                printf("\n🙅‍♂️ *No spoilers?* You're a cool cat! 😎 No spoilers for you. 🕶️\n");
            } else {
                printf("\n🤷‍♂️ *I don't understand that response!* But hey, no spoilers for you! 🙃\n");
            }

            break;
        }
    }

    if (!found) {
        printf("\n😔 *Oops! Movie not found in the database.* 📚\n");
    }
}

int main() {
    // Define some movies in the database, including Bollywood and Hindi-language films
    struct Movie movies[MAX_MOVIES] = {
        {"Inception", "Christopher Nolan", "Leonardo DiCaprio, Joseph Gordon-Levitt, Ellen Page (Ariadne)", 2010, "Sci-Fi, Thriller",
         "A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a CEO.",
         "The twist is that Cobb (Leonardo DiCaprio) might still be dreaming, and the totem doesn't help him decide."},
        {"The Dark Knight", "Christopher Nolan", "Christian Bale, Heath Ledger, Aaron Eckhart, Maggie Gyllenhaal (Rachel)", 2008, "Action, Crime, Drama",
         "When the menace known as The Joker emerges from his mysterious past, he wreaks havoc and chaos on the people of Gotham.",
         "The Joker's plan ultimately results in the death of Rachel, and Harvey Dent is turned into the vengeful Two-Face."},
        {"The Shawshank Redemption", "Frank Darabont", "Tim Robbins, Morgan Freeman, Bob Gunton, Clancy Brown", 1994, "Drama",
         "Two imprisoned men bond over a number of years, finding solace and eventual redemption through acts of common decency.",
         "Andy (Tim Robbins) escapes Shawshank using a rock hammer and exposes the corrupt warden."},
        {"The Godfather", "Francis Ford Coppola", "Marlon Brando, Al Pacino, James Caan, Diane Keaton (Kay Adams)", 1972, "Crime, Drama",
         "The aging patriarch of an organized crime dynasty transfers control of his clandestine empire to his reluctant son.",
         "Michael Corleone (Al Pacino) orders the killing of Sollozzo and his own brother-in-law, Carlo, to avenge the family's honor."},
        {"Forrest Gump", "Robert Zemeckis", "Tom Hanks, Robin Wright (Jenny), Gary Sinise", 1994, "Drama, Romance",
         "The presidencies of Kennedy and Johnson, the Vietnam War, the Civil Rights Movement and other historical events unfold from the perspective of an Alabama man with an IQ of 75.",
         "Forrest (Tom Hanks) unknowingly influences key moments in American history, including meeting President Kennedy and running across the country."},
        // Bollywood movies (Hindi language)
        {"Dilwale Dulhania Le Jayenge", "Aditya Chopra", "Shah Rukh Khan (Raj), Kajol (Simran)", 1995, "Romance, Drama",
         "Raj and Simran are two young Indians who meet on a trip to Europe and fall in love, but Simran is promised to another man.",
         "Raj convinces Simran's father that he is the perfect match for her, leading to a climactic resolution in a traditional Indian village."},
        {"Kabhi Khushi Kabhie Gham", "Karan Johar", "Shah Rukh Khan (Rahul), Amitabh Bachchan (Yash), Hrithik Roshan (Rohan), Kajol (Anjali)", 2001, "Drama, Family",
         "A young man is disowned by his wealthy family when he marries a woman from a lower class, leading to a rift that can only be healed by his younger brother.",
         "The family reconciles with love and understanding, overcoming societal barriers and misunderstandings."},
        {"Lagaan", "Ashutosh Gowariker", "Aamir Khan (Bhuvan), Gracy Singh (Gauri)", 2001, "Drama, Sports",
         "In 1893, a group of Indian villagers challenge British officers to a cricket match to avoid paying an oppressive tax.",
         "The villagers, led by Bhuvan (Aamir Khan), defeat the British team, winning their freedom from the tax burden."},
        {"3 Idiots", "Rajkumar Hirani", "Aamir Khan (Rancho), R. Madhavan (Farhan), Sharman Joshi (Raju), Kareena Kapoor (Pia)", 2009, "Comedy, Drama",
         "Three engineering students, inspired by their rebellious friend, strive to challenge the norms of the Indian education system and discover their true passions.",
         "The story concludes with a life-affirming message about following one's dreams and the importance of creativity over rote learning."},
        {"Zindagi Na Milegi Dobara", "Zoya Akhtar", "Hrithik Roshan (Arjun), Farhan Akhtar (Imran), Abhay Deol (Kabir), Katrina Kaif (Laila)", 2011, "Drama, Adventure",
         "Three friends on a road trip across Spain face their personal demons, rediscover their friendship, and learn life lessons along the way.",
         "The journey culminates in self-realization and embracing the beauty of life and relationships."}
    };

    char movie_name[MAX_STRING_LENGTH];

    // Input the name of the movie the user wants to search for
    printf("🎬 *Enter the name of the movie you want to search for!* 🎬\n");
    printf("🤩 Type it in: ");
    fgets(movie_name, MAX_STRING_LENGTH, stdin);
    movie_name[strcspn(movie_name, "\n")] = '\0'; // Remove newline character if present

    // Search and display movie details
    search_movie(movies, MAX_MOVIES, movie_name);

    return 0;
}
