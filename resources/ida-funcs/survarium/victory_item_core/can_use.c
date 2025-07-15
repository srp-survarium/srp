bool __thiscall survarium::victory_item_core::can_use(
        survarium::victory_item_core *this,
        const survarium::usable_object_user_data *user)
{
  return user->owner->cast_to_base_player(user->owner)->m_inventory.m_object->m_carried_item == 0;
}
