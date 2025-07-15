void __userpurge survarium::weapon_core::update_dispersion(
        survarium::weapon_core *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float a4@<ebx>,
        enum survarium::weapon_user_state_enum is_moving,
        unsigned int current_time_in_ms)
{
  int v6; // eax
  float low_stamina_penalty; // [esp+Ch] [ebp-4h]

  if ( *(_BYTE *)(*(_DWORD *)(a2 + 8) + 69896) )
    low_stamina_penalty = (float)(*(float *)(*(_DWORD *)(a2 + 8) + 69812) - *(float *)(*(_DWORD *)(a2 + 8) + 69884))
                        / *(float *)(*(_DWORD *)(a2 + 8) + 69812);
  else
    low_stamina_penalty = 0.0;
  v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 264) + 8))(*(_DWORD *)(a2 + 8) + 264, a3);
  survarium::dispersion_calculator::calculate_character_dispersion(
    (survarium::dispersion_calculator *)*(unsigned __int8 *)(a2 + 1109),
    a4,
    a2,
    (int *)(a2 + 664),
    *(const survarium::weapon_user_state_enum *)(*(_DWORD *)(*(_DWORD *)(a2 + 304) + 24) + 32),
    is_moving,
    *(_BYTE *)(*(_DWORD *)v6 + 1745),
    *(_BYTE *)(a2 + 1109),
    low_stamina_penalty,
    current_time_in_ms);
  survarium::transition_helper::tick((survarium::transition_helper *)(a2 + 676), current_time_in_ms);
  survarium::transition_helper::tick((survarium::transition_helper *)(a2 + 696), current_time_in_ms);
}
