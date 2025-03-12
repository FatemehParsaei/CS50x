select title from movies, ratings, stars, people where movies.id = ratings.movie_id and
movies.id = stars.movie_id and stars.person_id = people.id and people.name = 'Chadwick Boseman'
order by ratings.rating desc limit 5;


