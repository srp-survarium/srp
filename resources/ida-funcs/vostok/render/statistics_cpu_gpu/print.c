void __thiscall vostok::render::statistics_cpu_gpu::print(
        vostok::render::statistics_cpu_gpu *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    (vostok::buffer_string *)this,
    (vostok::buffer_string *)"%s: CPU:%.4f(%.4f..%.4f), GPU:%.4f",
    this->m_name.m_begin,
    this->cpu_time.value,
    this->cpu_time.min_value,
    this->cpu_time.max_value,
    this->gpu_time.value);
}
