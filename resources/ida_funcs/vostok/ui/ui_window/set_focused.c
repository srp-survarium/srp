void __thiscall vostok::ui::ui_window::set_focused(vostok::ui::ui_window *this, bool val)
{
  vostok::ui::ui_window *v2; // eax

  v2 = this;
  LOBYTE(this) = val;
  if ( v2->m_b_focused != val )
  {
    v2->m_b_focused = val;
    vostok::ui::ui_window::emit_event(this, (int)v2, ev_focus, v2, val, 0);
  }
}
