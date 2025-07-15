// attributes: thunk
BOOL __thiscall survarium::victory_items_container_core::use_execute(
        survarium::victory_items_container_core *this,
        const survarium::usable_object_user_data *user)
{
  return survarium::victory_items_container_core::can_use(this, user);
}
