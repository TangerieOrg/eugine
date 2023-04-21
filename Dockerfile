FROM --platform=$BUILDPLATFORM docker.tangerie.xyz/webraylib:latest as build

WORKDIR /app

COPY . .

RUN ./scripts/generate.sh
RUN ./scripts/build.sh

FROM node:18.3.0

WORKDIR /app

COPY --from=build /app/public /app

EXPOSE 3000
ENTRYPOINT [ "npx", "serve" ]
