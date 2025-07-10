void __thiscall vostok::ui::ui_window::set_position(vostok::ui::ui_window *this, const vostok::math::float2 *pos)
{
  float y; // ecx

  if ( fabs(this->m_position.x - pos->x) >= 0.0000099999997 || fabs(this->m_position.y - pos->y) >= 0.0000099999997 )
  {
    this->m_position.x = pos->x;
    y = pos->y;
    this->m_position.y = y;
    vostok::ui::ui_window::emit_event((vostok::ui::ui_window *)LODWORD(y), (int)this, ev_position_changed, this, 0, 0);
  }
}
