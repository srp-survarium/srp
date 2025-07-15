void __thiscall survarium::victory_item_core::set_user(
        survarium::victory_item_core *this,
        survarium::base_player *user)
{
  this->m_user = user;
  this->m_portable_interactive_object->set_user(this->m_portable_interactive_object, user);
}
