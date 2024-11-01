# compile translateLocally with docker

```shell
git clone git@github.com:XapaJIaMnu/translateLocally.git
cd translateLocally
git submodule update --init --recursive
```

```shell
docker build -f docker/24.04/Dockerfile --build-arg BUILD_JOB=4 -t translate-locally:24.04 .
docker create --name translateLocally24.04 translate-locally:24.04
docker cp translateLocally24.04:/app/build/translateLocally .
```

```shell
docker build -f docker/22.04/Dockerfile --build-arg BUILD_JOB=4 -t translate-locally:22.04 .
docker create --name translateLocally22.04 translate-locally:22.04
docker cp translateLocally22.04:/app/build/translateLocally .
```