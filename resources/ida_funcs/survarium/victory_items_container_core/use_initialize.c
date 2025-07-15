char __thiscall survarium::victory_items_container_core::use_initialize(
        survarium::victory_items_container_core *this,
        survarium::usable_object_user_data *user)
{
  if ( this->m_usable_object_users.m_first )
    return 0;
  user->owner->use_victory_items_container(user->owner, this);
  return 1;
}
