void __thiscall vostok::render::statistics_cpu_gpu::print_value(
        vostok::render::statistics_cpu_gpu *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)"%d",
    (const char *)COERCE_UNSIGNED_INT64(this->cpu_time.value),
    (_DWORD)HIDWORD(COERCE_UNSIGNED_INT64(this->cpu_time.value)));
}
