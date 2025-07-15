void __thiscall vostok::ui::ui_window::set_parent(vostok::ui::ui_window *this, vostok::ui::ui_window *w)
{
  this->m_parent = w;
  vostok::ui::ui_window::emit_event(w, (int)this, ev_parent_changed, this, 0, 0);
}
