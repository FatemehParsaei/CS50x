select name from people, stars, movies where people.id = stars.person_id and stars.movie_id = movies.id and title = 'Toy Story';

