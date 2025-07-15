int __userpurge survarium::key_binder::get_action_dik@<eax>(
        survarium::game_action_id _action_id@<eax>,
        survarium::key_binder *this,
        int idx)
{
  survarium::key_binding *v3; // eax
  survarium::keyboard_key_descr *v4; // ecx
  survarium::keyboard_key_descr *v6; // eax

  v3 = &this->m_key_bindings[_action_id];
  v4 = v3->m_keyboard[0];
  if ( v4 )
    return v4->dik;
  v6 = v3->m_keyboard[1];
  if ( v6 )
    return v6->dik;
  else
    return 0;
}
