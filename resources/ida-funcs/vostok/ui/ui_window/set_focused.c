void __thiscall vostok::ui::ui_window::set_focused(vostok::ui::ui_window *this, bool val)
{
  if ( this->m_b_focused != val )
  {
    this->m_b_focused = val;
    vostok::ui::ui_window::process_event((vostok::ui::ui_window *)2, this, val, 0);
  }
}
