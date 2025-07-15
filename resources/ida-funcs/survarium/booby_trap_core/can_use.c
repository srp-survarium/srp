BOOL __thiscall survarium::booby_trap_core::can_use(
        survarium::booby_trap_core *this,
        const survarium::usable_object_user_data *user)
{
  survarium::base_player *v3; // eax

  v3 = user->owner->cast_to_base_player(user->owner);
  return !*(_DWORD *)this->gap30 && !v3->m_inventory.m_object->m_carried_item;
}
