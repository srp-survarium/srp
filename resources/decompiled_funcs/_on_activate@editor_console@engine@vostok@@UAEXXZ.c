void __thiscall vostok::engine::editor_console::on_activate(vostok::engine::editor_console *this)
{
  vostok::ui::window *v2; // eax

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 1);
  this->m_active = 1;
}
