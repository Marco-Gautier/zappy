FROM epitechcontent/epitest-docker as build

RUN mkdir -p /app
WORKDIR /app
COPY . /app/

RUN dnf -y install lcov

RUN make lcov

FROM nginx:1.16.0-alpine

RUN rm -rf /usr/share/nginx/html/*
COPY ./.dev/nginx.conf /etc/nginx/nginx.conf
COPY --from=build /app/rapport /usr/share/nginx/html
EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]
