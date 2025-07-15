void __thiscall survarium::base_player::set_new_active_item(
        survarium::base_player *this,
        survarium::interactive_object *const item)
{
  this->m_parent_resources.m_size = (unsigned int)item;
}
