void __thiscall vostok::engine::game_console::on_deactivate(vostok::engine::game_console *this)
{
  vostok::engine::console *v2; // eax

  vostok::console_impl::on_deactivate(this);
  if ( this )
    v2 = &this->vostok::engine::console;
  else
    v2 = 0;
  this->m_input_world->remove_handler(this->m_input_world, v2);
}


void __thiscall vostok::engine::game_console::on_deactivate(char *this)
{
  vostok::engine::game_console::on_deactivate((vostok::engine::game_console *)(this - 616));
}
