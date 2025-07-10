void __thiscall vostok::ui::ui_window::set_size(vostok::ui::ui_window *this, const vostok::math::float2 *size)
{
  float y; // ecx

  if ( fabs(this->m_size.x - size->x) >= 0.0000099999997 || fabs(this->m_size.y - size->y) >= 0.0000099999997 )
  {
    this->m_size.x = size->x;
    y = size->y;
    this->m_size.y = y;
    vostok::ui::ui_window::emit_event((vostok::ui::ui_window *)LODWORD(y), (int)this, ev_size_changed, this, 0, 0);
  }
}
