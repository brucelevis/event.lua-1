#ifndef SOCKET_TCP_H
#define SOCKET_TCP_H

#include "socket_util.h"
#include "ev.h"

#define CONNECT_STATUS_CONNECTED 		0
#define CONNECT_STATUS_CONNECTING 		1
#define CONNECT_STATUS_CONNECT_FAIL		2

struct ev_loop_ctx;
struct ev_listener;
struct ev_connector;
struct ev_session;

typedef void(*listener_callback)(struct ev_listener*, int fd, const char* addr, void *userdata);
typedef void(*connector_callback)(struct ev_connector*, int fd, const char* reason, void *userdata);
typedef void(*ev_session_callback)(struct ev_session*, void *userdata);

struct ev_loop_ctx* loop_ctx_create();
void loop_ctx_release(struct ev_loop_ctx* loop_ctx);
struct ev_loop* loop_ctx_get(struct ev_loop_ctx* loop_ctx);
double loop_ctx_now(struct ev_loop_ctx* loop_ctx);
void loop_ctx_dispatch(struct ev_loop_ctx* loop_ctx);
void loop_ctx_break(struct ev_loop_ctx* loop_ctx);
void loop_ctx_clean(struct ev_loop_ctx* loop_ctx);

struct ev_listener* ev_listener_bind(struct ev_loop_ctx* loop_ctx, struct sockaddr* addr, int addrlen, int backlog, int flag, listener_callback accept_cb, void* userdata);
int ev_listener_fd(struct ev_listener* listener);
int ev_listener_addr(struct ev_listener* listener, char* addr, size_t length, int* port);
void ev_listener_free(struct ev_listener* listener);

struct ev_session* ev_session_bind(struct ev_loop_ctx* loop_ctx, int fd, int min, int max);
int ev_session_connect(struct ev_loop_ctx* loop_ctx, struct sockaddr* addr, int addrlen, int nonblock, connector_callback callback, void* userdata);
void ev_session_free(struct ev_session* ev_session);
void ev_session_setcb(struct ev_session* ev_session, ev_session_callback read_cb, ev_session_callback write_cb, ev_session_callback event_cb, void* userdata);
void ev_session_enable(struct ev_session* ev_session, int ev);
void ev_session_disable(struct ev_session* ev_session, int ev);
int ev_session_fd(struct ev_session* ev_session);
int ev_session_input_full(struct ev_session* ev_session);
size_t ev_session_input_size(struct ev_session* ev_session);
size_t ev_session_output_size(struct ev_session* ev_session);
size_t ev_session_read(struct ev_session* ev_session, char* data, size_t size);
char* ev_session_read_next(struct ev_session* ev_session, size_t* size);
char* ev_session_read_peek(struct ev_session* ev_session, size_t size);
int ev_session_write(struct ev_session* ev_session, char* data, size_t size);

#endif