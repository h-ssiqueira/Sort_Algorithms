FROM gcc:latest AS builder

WORKDIR /usr/src/app

COPY . .

RUN make

FROM debian:bookworm AS runtime

WORKDIR /usr/src/app

COPY --from=builder /usr/src/app/sort .
ENV TERM=xterm
CMD ["./sort"]
