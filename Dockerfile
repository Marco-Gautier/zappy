FROM marcogautier/epitest

RUN mkdir -p /app
WORKDIR /app
COPY . /app/

RUN make re

CMD [ "/bin/sh", "-c", "./zappy_server -p 2142" ]
