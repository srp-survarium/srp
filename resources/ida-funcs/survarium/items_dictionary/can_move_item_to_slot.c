char __thiscall survarium::items_dictionary::can_move_item_to_slot(
        survarium::items_dictionary *this,
        const unsigned int item_category_id,
        const void *target_slot_id,
        const void *a4)
{
  vostok::configs::binary_config_value *i; // ebx
  const vostok::configs::binary_config_value *v6; // eax

  if ( a4 == (const void *)100 )
    return 1;
  for ( i = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      *(vostok::configs::binary_config_value **)(*(_DWORD *)(item_category_id + 268)
                                                                                               + 264),
                                                      "slots_restrictions")->data.pointer; ; ++i )
  {
    v6 = vostok::configs::binary_config_value::operator[](
           *(vostok::configs::binary_config_value **)(*(_DWORD *)(item_category_id + 268) + 264),
           "slots_restrictions");
    if ( i == (vostok::configs::binary_config_value *)v6->data.pointer + v6->count )
      break;
    if ( a4 == vostok::configs::binary_config_value::operator[](i, "profile_slot_id")->data.pointer
      && target_slot_id == vostok::configs::binary_config_value::operator[](i, "category_id")->data.pointer )
    {
      return 1;
    }
  }
  return 0;
}
