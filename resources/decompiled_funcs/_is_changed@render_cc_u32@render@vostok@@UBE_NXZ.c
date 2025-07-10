BOOL __thiscall vostok::render::render_cc_u32::is_changed(vostok::render::render_cc_u32 *this)
{
  return *this->m_prev_value != *this->m_value;
}
