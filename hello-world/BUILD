
package(default_visibility = ["//visibility:public"])

load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")

proto_library(
    name = "helloworld_proto",
    srcs = ["helloworld.proto"],
    deps = [
        ":example_proto",
    ],
)

proto_library(
    name = "example_proto",
    srcs = ["example.proto"],
)

cpp_proto_library(
    name = "helloworld",
    deps = [":helloworld_proto"],
)

cpp_proto_library(
    name = "example",
    deps = [":example_proto"],
)

cpp_grpc_library(
    name = "helloworld_grpc",
    deps = [":helloworld_proto"],
)

cc_binary(
    name = "greeter_server",
    srcs = ["greeter_server.cc"],
    deps = [
        ":helloworld_grpc",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

cc_binary(
    name = "greeter_client",
    srcs = ["greeter_server.cc"],
    deps = [
        ":helloworld_grpc",
        "@com_github_grpc_grpc//:grpc++",
    ],
)
