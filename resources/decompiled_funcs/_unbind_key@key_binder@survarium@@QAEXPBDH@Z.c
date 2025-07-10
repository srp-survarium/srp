void __thiscall survarium::key_binder::unbind_key(survarium::key_binder *this, const char *args, int bind_number)
{
  survarium::game_action_descr *v4; // eax

  v4 = survarium::key_binder::action_name_to_ptr(this, args);
  if ( v4 )
    *((_DWORD *)&this->m_key_bindings[0].m_keyboard[2 * v4->id] + v4->id + bind_number) = 0;
  else
    *((_DWORD *)&this[1].m_key_bindings[1].m_action + bind_number) = 0;
}
