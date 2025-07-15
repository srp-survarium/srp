void __thiscall survarium::key_binder::unbind_key(survarium::key_binder *this, char *args, int bind_number)
{
  survarium::game_action_descr *v4; // eax
  int id; // eax

  v4 = survarium::key_binder::action_name_to_ptr(this, args);
  if ( v4 )
    id = v4->id;
  else
    id = 73;
  this->m_key_bindings[id].m_keyboard[bind_number] = 0;
}
