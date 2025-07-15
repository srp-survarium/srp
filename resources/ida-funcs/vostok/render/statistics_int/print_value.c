void __thiscall vostok::render::statistics_int::print_value(
        vostok::render::statistics_int *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  const char *v2; // eax
  vostok::buffer_string *v3; // ecx

  v2 = (const char *)vostok::render::statistics_value<int>::average(this);
  vostok::fs_new::path_string_impl::assignf(out_result, v3, (vostok::buffer_string *)"%d", v2);
}
