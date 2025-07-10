void __thiscall vostok::ai::behaviour_cook::translate_request_path(
        vostok::ai::behaviour_cook *this,
        const char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  vostok::fs_new::path_string_impl::assignf(new_request, "resources/brain_units/behaviours/%s.behaviour", request);
}
