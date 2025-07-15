survarium::explosive *__userpurge survarium::grenade_set_core::explosive@<eax>(
        survarium::grenade_set_core *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        survarium::explosive *result)
{
  const void *v4; // esi
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  survarium::player_params_modifiers_container *v8; // ecx
  float v9; // xmm0_4
  survarium::player_params_modifiers_enum v10; // edx
  survarium::player_params_modifiers_container *v11; // ecx

  v4 = (const void *)(a2 + 304);
  v5 = *(_DWORD *)(a2 + 272);
  qmemcpy(result, v4, sizeof(survarium::explosive));
  v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v5 + 376) + 12))(*(_DWORD *)(v5 + 376));
  v7 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(*(_DWORD *)(v6 + 69736) + 448),
         splash_radius_modifier,
         a3,
         result->radius,
         1.0);
  result->radius = v7;
  v9 = survarium::player_params_modifiers_container::apply_modifier(
         v8,
         device_damage_modifier,
         v7,
         result->min_damage,
         1.0);
  result->min_damage = v9;
  result->max_damage = survarium::player_params_modifiers_container::apply_modifier(
                         v11,
                         v10,
                         v9,
                         result->max_damage,
                         1.0);
  return result;
}
