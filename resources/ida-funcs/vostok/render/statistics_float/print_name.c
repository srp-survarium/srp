void __thiscall vostok::render::statistics_float::print_name(
        vostok::render::statistics_float *this,
        vostok::fs_new::virtual_path_string *out_result)
{
  vostok::buffer_string::operator=(&this->m_name, &out_result->m_string);
}
