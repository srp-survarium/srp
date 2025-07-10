void __thiscall vostok::buffer_vector<vostok::console_commands::command_token>::push_back(
        vostok::buffer_vector<vostok::console_commands::command_token> *this,
        const vostok::console_commands::command_token *value)
{
  const char *name; // eax
  unsigned int *v4; // [esp+Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v4 = (unsigned int *)operator new(8u, (void *)this->m_end);
  if ( v4 )
  {
    name = value->name;
    *v4 = value->id;
    v4[1] = (unsigned int)name;
  }
  ++this->m_end;
}
