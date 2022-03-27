CREATE TABLE ACTOR ( 
ACT_ID INT (5) PRIMARY KEY, 
ACT_NAME VARCHAR (20), 
ACT_GENDER CHAR (1));

CREATE TABLE DIRECTOR ( 
DIR_ID INT (5) PRIMARY KEY, 
DIR_NAME VARCHAR (20), 
DIR_PHONE BIGINT); 

CREATE TABLE MOVIES 
(MOV_ID INT (4) PRIMARY KEY, 
MOV_TITLE VARCHAR (50), 
MOV_YEAR INT (4), 
MOV_LANG VARCHAR (20), 
DIR_ID INT (5), 
FOREIGN KEY (DIR_ID) REFERENCES DIRECTOR(DIR_ID)); 

CREATE TABLE MOVIES_CAST ( 
ACT_ID INT (5), 
MOV_ID INT (5), 
ROLE VARCHAR (20), 
PRIMARY KEY (ACT_ID, MOV_ID), 
FOREIGN KEY (ACT_ID) REFERENCES ACTOR (ACT_ID), 
FOREIGN KEY (MOV_ID) REFERENCES MOVIES (MOV_ID));

CREATE TABLE RATING ( 
MOV_ID INT (5) PRIMARY KEY, 
REV_STARS VARCHAR (25), 
FOREIGN KEY (MOV_ID) REFERENCES MOVIES (MOV_ID)); 

 DESC ACTOR; 
 DESC DIRECTOR; 
 DESC MOVIES; 
 DESC MOVIES_CAST;
 DESC RATING; 
  
