void __thiscall survarium::double_barreled_weapon_core_fire_state::on_animation_end_impl(
        survarium::double_barreled_weapon_core_fire_state *this,
        bool *interrupt_animation_player_tick)
{
  int v2; // ecx

  survarium::weapon_core_fire_state_base::on_animation_end_impl(this, interrupt_animation_player_tick);
  *(_BYTE *)(v2 + 364) = *(_WORD *)(*(_DWORD *)(v2 + 288) + 1102) != 2;
}
