void __thiscall vostok::render::animated_model_instance_cook::translate_request_path(
        vostok::render::animated_model_instance_cook *this,
        const char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  vostok::fs_new::path_string_impl::assignf(
    new_request,
    "resources/animated_model_instances/render_animated_models/%s.render_model",
    request);
}
