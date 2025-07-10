survarium::base_player *__thiscall survarium::base_player::cast_to_inventory_holder(survarium::base_player *this)
{
  return (survarium::base_player *)((char *)this - 12);
}
