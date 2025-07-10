bool __thiscall survarium::booby_trap_core::can_defuse(survarium::booby_trap_core *this, survarium::base_player *user)
{
  survarium::game_camera *v2; // ecx
  survarium::inventory_item *v3; // ecx
  survarium::inventory *inventory; // eax
  survarium::inventory *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_team_id v7; // esi
  bool v9; // [esp+4h] [ebp-14h]
  survarium::inventory_holder *v10; // [esp+8h] [ebp-10h]
  const survarium::base_player *owner; // [esp+14h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  inventory = survarium::inventory_item::get_inventory(v3, (int)this->m_owner);
  v10 = survarium::inventory::holder(v5, (int)inventory);
  owner = v10->cast_to_base_player(v10);
  survarium::weapon_user_dead_state::finalize(v6);
  v9 = 1;
  if ( user != owner )
  {
    v7 = user->team(user);
    if ( v7 == owner->team((survarium::base_player *)owner) )
      return 0;
  }
  return v9;
}
