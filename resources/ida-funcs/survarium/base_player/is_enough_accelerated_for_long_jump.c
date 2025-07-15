BOOL __usercall survarium::base_player::is_enough_accelerated_for_long_jump@<eax>(
        survarium::base_player *this@<ecx>,
        int a2@<esi>)
{
  float value; // xmm0_4

  if ( (*(unsigned __int8 (__stdcall **)(survarium::base_player *))(**(_DWORD **)(a2 + 320) + 68))(this) )
    value = *(float *)(a2 + 444);
  else
    value = *(float *)(a2 + 440);
  return *(float *)(a2 + 756) >= (float)(survarium::player_params_modifiers_container::apply_modifier(
                                           (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066 + a2 + 2)
                                                                                          + 448),
                                           movement_speed_modifier,
                                           value,
                                           value,
                                           value)
                                       * s_long_jump_speed_factor_value);
}
