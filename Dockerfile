FROM epitechcontent/epitest-docker

RUN mkdir -p /app
WORKDIR /app
COPY . /app/

RUN make

CMD [ "./zappy_server" ]