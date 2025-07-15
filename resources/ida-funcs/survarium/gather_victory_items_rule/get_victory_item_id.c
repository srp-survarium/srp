unsigned __int8 __fastcall survarium::gather_victory_items_rule::get_victory_item_id(
        survarium::gather_victory_items_rule *this,
        int a2,
        const survarium::victory_item_core *const item)
{
  const survarium::victory_item_core *const *v3; // ecx
  unsigned __int8 result; // al

  v3 = *(const survarium::victory_item_core *const **)(a2 + 272);
  result = 0;
  while ( *v3 != item )
  {
    ++result;
    ++v3;
  }
  return result;
}
