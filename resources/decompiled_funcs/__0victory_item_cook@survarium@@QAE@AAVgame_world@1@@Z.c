void __thiscall survarium::victory_item_cook::victory_item_cook(
        survarium::victory_item_cook *this,
        survarium::game_world *game_world)
{
  survarium::victory_item_core_cook::victory_item_core_cook(&s_victory_item_cook);
  s_victory_item_cook.m_game_world = game_world;
  s_victory_item_cook.__vftable = (survarium::victory_item_cook_vtbl *)&survarium::victory_item_cook::`vftable';
}
