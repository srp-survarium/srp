void __thiscall vostok::engine::game_console::on_deactivate(vostok::engine::game_console *this)
{
  vostok::ui::window *v2; // eax
  vostok::ui::window *v3; // eax
  vostok::input::world *m_input_world; // ecx

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 0);
  v3 = this->m_ui_view->w(this->m_ui_view);
  v3->set_focused(v3, 0);
  m_input_world = this->m_input_world;
  this->m_active = 0;
  m_input_world->remove_handler(m_input_world, &this->vostok::engine::console);
}
