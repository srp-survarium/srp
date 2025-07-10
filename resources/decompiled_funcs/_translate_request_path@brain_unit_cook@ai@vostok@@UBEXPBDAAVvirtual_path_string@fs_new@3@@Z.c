void __thiscall vostok::ai::brain_unit_cook::translate_request_path(
        vostok::ai::brain_unit_cook *this,
        const char *request,
        vostok::fs_new::virtual_path_string *new_request)
{
  vostok::fs_new::path_string_impl::assignf(new_request, "resources/brain_units/%s.brain_unit", request);
}
