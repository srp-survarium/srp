int __usercall survarium::key_binder::get_binding_group@<eax>(
        survarium::key_binder *this@<ecx>,
        survarium::game_action_id _id@<eax>)
{
  return this->m_key_bindings[_id].m_action->key_group;
}
