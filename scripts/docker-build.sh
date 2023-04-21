IMAGE_NAME=docker.tangerie.xyz/eugine:latest
ARCH_LIST=linux/arm64/v8,linux/amd64

docker buildx build --platform $ARCH_LIST -t $IMAGE_NAME . 
# docker compose up