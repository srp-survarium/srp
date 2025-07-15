void __thiscall vostok::engine::editor_console::on_deactivate(vostok::engine::editor_console *this)
{
  vostok::ui::window *v2; // eax
  vostok::ui::window *v3; // eax

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 0);
  v3 = this->m_ui_view->w(this->m_ui_view);
  v3->set_focused(v3, 0);
  this->m_active = 0;
}


void __thiscall vostok::engine::editor_console::on_deactivate(char *this)
{
  vostok::engine::editor_console::on_deactivate((vostok::engine::editor_console *)(this - 616));
}
