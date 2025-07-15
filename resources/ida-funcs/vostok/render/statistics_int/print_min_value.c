void __thiscall vostok::render::statistics_int::print_min_value(
        vostok::render::statistics_int *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)"%d",
    (const char *)this->min_value);
}
