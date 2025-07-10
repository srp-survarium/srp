const survarium::flash_text *__thiscall survarium::victory_items_container::use_info(
        survarium::victory_items_container *this,
        survarium::usable_object_user_data *user)
{
  survarium::base_player *v3; // esi
  survarium::inventory_holder *v4; // edi
  int v5; // eax
  survarium::victory_item_core *m_victory_item; // edx
  survarium::game_team_id m_owner_team; // ecx
  const survarium::flash_text *result; // eax

  v3 = user->owner->cast_to_base_player(user->owner);
  v4 = user->owner->cast_to_inventory_holder(user->owner);
  if ( !v3 )
    return &buf;
  v5 = v3->team(v3);
  m_victory_item = v4->m_inventory.m_object->m_victory_item;
  m_owner_team = this->m_owner_team;
  if ( v5 == m_owner_team )
  {
    if ( m_victory_item )
      return (const survarium::flash_text *)"st_put_item";
    if ( v5 == m_owner_team )
      return &buf;
  }
  if ( m_victory_item )
    return &buf;
  result = (const survarium::flash_text *)"st_thief_item";
  if ( !(this->m_victory_items._M_impl._M_finish - this->m_victory_items._M_impl._M_start) )
    return &buf;
  return result;
}
