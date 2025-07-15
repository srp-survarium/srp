void __thiscall survarium::inventory_item::register_in_game_world(
        survarium::inventory_item *this,
        survarium::game_world_core *w)
{
  this->m_game_world_core = w;
}
