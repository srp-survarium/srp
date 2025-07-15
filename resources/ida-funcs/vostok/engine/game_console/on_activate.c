void __thiscall vostok::engine::game_console::on_activate(vostok::engine::game_console *this)
{
  vostok::ui::window *v2; // eax
  vostok::input::world *m_input_world; // ecx

  v2 = this->m_text_edit->w(this->m_text_edit);
  v2->set_focused(v2, 1);
  m_input_world = this->m_input_world;
  this->m_active = 1;
  m_input_world->add_handler(m_input_world, &this->vostok::engine::console);
}


void __thiscall vostok::engine::game_console::on_activate(char *this)
{
  vostok::engine::game_console::on_activate((vostok::engine::game_console *)(this - 616));
}
