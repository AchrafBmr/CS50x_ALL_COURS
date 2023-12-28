-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT year, month, day, description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street'
AND description LIKE '%CS50%';

-- Theft took place around 10:15am in the Humphrey Street bakery.
-- Interviews with 3 witnesses

SELECT year, month, day, transcript
FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE '%thief%';



-- fligjts.id
SELECT flights.id, year, month, day, hour, minute, city
FROM flights
JOIN airports on airports.id = flights.destination_airport_id
JOIN passengers on passengers.flight_id = flights.id
WHERE month = 7 AND day = 29
ORDER BY hour, minute
LIMIT 1;
-- NYC


-- passport
SELECT flights.id, passport_number
FROM passengers
JOIN flights on passengers.flight_id = flights.id
WHERE flights.id IN
    (SELECT flights.id
    FROM flights
    JOIN airports on airports.id = flights.destination_airport_id
    JOIN passengers on passengers.flight_id = flights.id
    WHERE month = 7 AND day = 29
    ORDER BY hour, minute
    LIMIT 1);


-- license plates
SELECT year, month, day, hour, minute, activity, license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';


-- phone numbers  (caller: Bruce, receiver: Robin)
SELECT year, month, day, duration, name, receiver
FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE month = 7 AND day = 28
AND duration <= 60;


-- id
SELECT person_id
FROM bank_accounts
WHERE account_number IN
    (SELECT account_number
    FROM atm_transactions
    WHERE month = 7 AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw');

-- SUSPECTS --

SELECT id, name
FROM people

-- passport
WHERE passport_number IN
    (SELECT passport_number
    FROM passengers
    JOIN flights on passengers.flight_id = flights.id
    WHERE flights.id IN
        (SELECT flights.id
        FROM flights
        JOIN airports on airports.id = flights.destination_airport_id
        JOIN passengers on passengers.flight_id = flights.id
        WHERE month = 7 AND day = 29
        ORDER BY hour, minute
        LIMIT 1)
    )

-- license plate
AND license_plate IN

    (SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
    AND activity = 'exit')

-- phone number
AND phone_number IN

    (SELECT caller
    FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration <= 60)

-- id
AND id IN

    (SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE month = 7 AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw')
    );

