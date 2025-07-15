void __thiscall vostok::ui::ui_window::set_position(vostok::ui::ui_window *this, const vostok::math::float2 *pos)
{
  vostok::math::float2 *p_m_position; // edi

  p_m_position = &this->m_position;
  if ( !vostok::math::float2_pod::is_similar(&this->m_position, pos) )
  {
    *p_m_position = *pos;
    vostok::ui::ui_window::process_event((vostok::ui::ui_window *)1, this, 0, 0);
  }
}
