int __usercall survarium::key_binder::get_action_dik@<eax>(
        survarium::key_binder *this@<ecx>,
        survarium::game_action_id _action_id@<eax>)
{
  survarium::key_binding *v2; // eax
  survarium::keyboard_key_descr *v3; // ecx
  survarium::keyboard_key_descr *v5; // eax

  v2 = &this->m_key_bindings[_action_id];
  v3 = v2->m_keyboard[0];
  if ( v3 )
    return v3->dik;
  v5 = v2->m_keyboard[1];
  if ( v5 )
    return v5->dik;
  else
    return 0;
}
