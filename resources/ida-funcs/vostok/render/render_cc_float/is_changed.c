BOOL __thiscall vostok::render::render_cc_float::is_changed(vostok::render::render_cc_float *this)
{
  return *this->m_prev_value != *this->m_value;
}
