const char *__thiscall survarium::victory_items_container_core::use_info(
        survarium::victory_items_container_core *this,
        const survarium::usable_object_user_data *user)
{
  const char *result; // eax
  bool v4; // zf

  if ( !this->can_use(this, user) )
    return uri;
  v4 = this->m_owner_team == *(_DWORD *)(*(_DWORD *)((char *)&loc_11066
                                                   + (unsigned int)user->owner->cast_to_base_player(user->owner)
                                                   + 2)
                                       + 440);
  result = "st_put_item";
  if ( !v4 )
    return "st_thief_item";
  return result;
}
