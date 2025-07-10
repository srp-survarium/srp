const char *__thiscall survarium::victory_item::use_info(
        survarium::victory_item *this,
        survarium::usable_object_user_data *user)
{
  survarium::inventory_holder *v2; // eax

  v2 = user->owner->cast_to_inventory_holder(user->owner);
  if ( !v2 )
    return (const char *)&buf;
  if ( v2->m_inventory.m_object->m_victory_item )
    return "st_cannot_pickup_item";
  return "st_pickup_item";
}
