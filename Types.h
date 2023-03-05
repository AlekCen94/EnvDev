#ifndef TYPES_H
#define TYPES_H

enum class envType {
    CONTAINER = 0,

    CONNECT = 1,

    SEARCH_ITEM = 2
};

enum class envBuilderType {
    DOCKER_IMAGE,

    DOCKER_COMPOSE,

    VAGRANT
};

enum class envCommandType {
    DOCKER,

    VAGRANT,

    GIT
};
#endif // TYPES_H
