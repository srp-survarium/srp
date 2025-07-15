void __thiscall vostok::ui::ui_window::set_parent(vostok::ui::ui_window *this, vostok::ui::window *w)
{
  this->m_parent = w;
  vostok::ui::ui_window::process_event((vostok::ui::ui_window *)4, this, 0, 0);
}
