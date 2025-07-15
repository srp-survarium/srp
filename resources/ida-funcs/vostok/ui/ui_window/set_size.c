void __thiscall vostok::ui::ui_window::set_size(vostok::ui::ui_window *this, const vostok::math::float2 *size)
{
  vostok::math::float2 *p_m_size; // edi

  p_m_size = &this->m_size;
  if ( !vostok::math::float2_pod::is_similar(&this->m_size, size) )
  {
    *p_m_size = *size;
    vostok::ui::ui_window::process_event(0, this, 0, 0);
  }
}
