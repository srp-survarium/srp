void __thiscall survarium::game_world::get_available_weapons(
        survarium::game_world *this,
        vostok::ai::npc *owner,
        vostok::vectora<vostok::ai::weapon *> *list_to_be_filled)
{
  survarium::human_npc::get_available_weapons((survarium::human_npc *)list_to_be_filled, (int)owner);
}
