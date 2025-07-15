const char *__thiscall survarium::victory_item_core::use_info(
        survarium::victory_item_core *this,
        const survarium::usable_object_user_data *user)
{
  bool v2; // zf
  const char *result; // eax

  v2 = ((unsigned __int8 (__thiscall *)(survarium::victory_item_core *, const survarium::usable_object_user_data *))this->register_animations)(
         this,
         user) == 0;
  result = "st_pickup_item";
  if ( v2 )
    return "st_cannot_pickup_item";
  return result;
}
