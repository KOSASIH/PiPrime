all: build

build:
    docker-compose build

run:
    docker-compose up

test:
    docker-compose exec api python -m unittest discover -v

clean:
    docker-compose down -v
