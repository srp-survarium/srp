survarium::usable_object_user_data **__thiscall survarium::victory_item_core::cast_to_spottable(
        survarium::victory_item_core *this)
{
  if ( this == (survarium::victory_item_core *)20 )
    return 0;
  else
    return &this->m_usable_object_users.m_first;
}
