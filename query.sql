1. List the titles of all movies directed by‘Hitchcock’. 

SELECT MOV_TITLE 
FROM MOVIES 
WHERE DIR_ID IN (SELECT DIR_ID 
FROM DIRECTOR 
WHERE DIR_NAME = 'HITCHCOCK');

2. Find the movie names where one or more actors acted in two or moremovies. 

 SELECT MOV_TITLE 
 FROM MOVIES M,MOVIE_CAST MV 
 WHERE M.MOV_ID=MV.MOV_ID AND ACT_ID IN
 (SELECT ACT_ID 
  FROM MOVIE_CAST 
  GROUP BY ACT_ID 
  HAVING COUNT(ACT_ID)>1) 
  GROUP BY MOV_TITLE HAVING COUNT(*)>1;

3. List all actors who acted in a movie before 2000 and also in a movie after 
2015 (use JOINoperation). 

SELECT ACT_NAME, MOV_TITLE, MOV_YEAR FROM ACTOR A JOIN
MOVIE_CAST C ON A.ACT_ID=C.ACT_ID INNER JOIN MOVIES M
ON C.MOV_ID=M.MOV_ID WHERE M.MOV_YEAR NOT BETWEEN 2000 AND 2015;

4. Find the title of movies and number of stars for each movie that has at least 
one rating and find the highest number of stars that movie received. Sort the 
result by movie title. 

SELECT MOV_TITLE,MAX(REV_STARS) FROM MOVIES M ,RATING R WHERE
M.MOV_ID=R.MOV_ID GROUP BY MOV_TITLE HAVING MAX(REV_STARS)>0 ORDER
BY MOV_TITLE;

5. Update rating of all movies directed by ‘Steven Spielberg’ to5 
KL 

UPDATE RATING R, MOVIES M, DIRECTOR D SET REV_STARS=5 WHERE
R.MOV_ID=M.MOV_ID AND M.DIR_ID=D.DIR_ID AND DIR_NAME='STEVEN
SPIELBERG';
