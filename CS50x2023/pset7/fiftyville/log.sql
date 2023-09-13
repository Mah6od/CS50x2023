-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- to get interviws
SELECT * FROM interviews WHERE transcript LIKE "%Bakery%";

-- security logs, exit and entrances
SELECT activity FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 10 LIMIT 10;

-- check license plates
SELECT * FROM bakery_security_logs bsi
JOIN people p  ON p.license_plate = bsi.license_plate
WHERE bsi.year = 2021 AND bsi.month = 7 AND bsi.day = 28 AND bsi.hour = 10 AND bsi.minute BETWEEN 15 AND 25;

-- check ATM
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND year = 2021 AND month = 7 AND day = 28;

-- transactions
SELECT * FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_transactions.atm_location = 'Leggett Street'
AND year = 2021 AND month = 7 AND day = 28 AND atm_transactions.transaction_type = 'withdraw';

-- phone calls
SELECT * FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60;

-- caller names
SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration <= 60;

-- find fiftyville airport id(8)
SELECT * FROM airports;
-- find flight out
SELECT f.*, origin.full_name AS origin_airport, destination.full_name AS destination_airport
FROM flights f
JOIN airports origin ON f.origin_airport_id = origin.id
JOIN airports destination ON f.destination_airport_id = destination.id
WHERE origin.id = 8 AND f.year = 2021 AND f.month = 7 AND f.day = 29
ORDER BY f.hour, f.minute;

-- accourding to our investigates Diana and Bruce names where common in informations
-- now we wanna see who have left the city
SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE passengers.flight_id = 36
AND people.name IN ("Bruce", "Diana");
-- I got Thief! Bruce!
-- who did call him?
SELECT p2.name AS receiver
FROM phone_calls pc
JOIN people p1 ON pc.caller = p1.phone_number
JOIN people p2 ON pc.receiver = p2.phone_number
WHERE p1.name = 'Bruce' AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;
-- Robin Did!!