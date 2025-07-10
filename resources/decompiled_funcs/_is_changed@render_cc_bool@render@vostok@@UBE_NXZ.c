BOOL __thiscall vostok::render::render_cc_bool::is_changed(vostok::render::render_cc_bool *this)
{
  return *this->m_prev_value != *this->m_value;
}
