#include <assert.h>
#include <bare.h>
#include <jstl.h>

static inline std::string
bare_addon_hello(js_env_t *env, js_receiver_t) {
  std::string hello = "Hello addon";
  return hello;
}

static js_value_t *
bare_addon_exports(js_env_t *env, js_value_t *exports) {
  int err;

  err = js_set_property<bare_addon_hello>(env, exports, "hello");
  assert(err == 0);

  return exports;
}

BARE_MODULE(bare_addon, bare_addon_exports)
