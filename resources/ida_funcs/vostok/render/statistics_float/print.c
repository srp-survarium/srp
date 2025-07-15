void __thiscall vostok::render::statistics_float::print(
        vostok::render::statistics_float *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::fs_new::path_string_impl::assignf(
    out_result,
    "%s: %f (%f..%f)",
    this->m_name.m_begin,
    (double)this->value,
    (double)this->min_value,
    (double)this->max_value);
}
