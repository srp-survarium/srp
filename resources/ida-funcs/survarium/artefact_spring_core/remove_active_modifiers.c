void __usercall survarium::artefact_spring_core::remove_active_modifiers(
        survarium::artefact_spring_core *this@<ecx>,
        int a2@<eax>)
{
  int v3; // edi

  v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 272) + 376) + 12))(*(_DWORD *)(*(_DWORD *)(a2 + 272) + 376));
  survarium::player_params_modifiers_container::remove_modifier(
    (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066 + v3 + 2) + 448),
    movement_speed_modifier,
    (survarium::player_params_modifier *)(a2 + 516));
  survarium::player_params_modifiers_container::remove_modifier(
    (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066 + v3 + 2) + 448),
    stamina_regenation_speed_modifier,
    (survarium::player_params_modifier *)(a2 + 524));
  survarium::player_params_modifiers_container::remove_modifier(
    (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066 + v3 + 2) + 448),
    stamina_spending_speed_modifier,
    (survarium::player_params_modifier *)(a2 + 532));
}
