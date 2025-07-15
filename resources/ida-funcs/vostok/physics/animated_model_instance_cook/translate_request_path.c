void __thiscall vostok::physics::animated_model_instance_cook::translate_request_path(
        vostok::physics::animated_model_instance_cook *this,
        char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  vostok::fs_new::path_string_impl::assignf(
    (int)new_request,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)&stru_801050,
    request);
}
