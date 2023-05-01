/*
*****************************************************************************
                  Workshop 1 (Part 1)

Name = Gautam Gandotra
Email = ggandotra@myseneca.ca
Student ID = 164064214
Section = NRA
Date = 15 January 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*****************************************************************************
*/



#ifndef SDDS_MOVIES_H
#define SDDS_MOVIES_H

namespace sdds {

    struct Movie {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };

    bool loadMovies();

    bool hasGenre(const Movie* mvp, const char genre[]);

    void displayMovie(const Movie* mvp);

    void displayMoviesWithGenre(const char genre[]);
}

#endif // !SDDS_FILE_H