void __userpurge survarium::dispersion_calculator::initialize(
        survarium::dispersion_calculator *this@<ecx>,
        int *a2@<eax>,
        unsigned int a3@<edi>,
        float a4@<ebx>,
        survarium::weapon_user_state_enum character_state,
        enum survarium::weapon_user_state_enum is_moving,
        unsigned __int8 broken_hands_count,
        bool using_double_handed_weapon,
        float low_stamina_penalty,
        unsigned int current_time_in_ms)
{
  int v11; // xmm0_4
  int v12; // edi
  char v13; // fl
  int v14; // xmm0_4
  char v15; // cf
  char v16; // zf
  char v17; // sf
  char v18; // of
  bool v19; // pf

  survarium::dispersion_calculator::calculate_character_dispersion(
    this,
    a4,
    a3,
    a2,
    character_state,
    is_moving,
    broken_hands_count,
    using_double_handed_weapon,
    low_stamina_penalty,
    current_time_in_ms);
  a2[7] = -1;
  v11 = a2[5];
  a2[3] = v11;
  a2[4] = v11;
  a2[6] = 0;
  v12 = *a2;
  *(float *)&v14 = survarium::player_params_modifiers_container::apply_modifier(
                     (survarium::player_params_modifiers_container *)(*(_DWORD *)(*(_DWORD *)(*a2 + 8) + 69736) + 448),
                     dispersion_modifier,
                     *(float *)&v11,
                     *(float *)(*a2 + 848),
                     *((float *)a2 + 13));
  if ( *(float *)&v14 <= *(float *)(v12 + 856) )
    v14 = *(int *)(v12 + 856);
  v15 = 0;
  v18 = 0;
  v16 = 0;
  v19 = __SETP__(-1, 0);
  v17 = 1;
  a2[12] = -1;
  a2[8] = v14;
  a2[9] = v14;
  a2[10] = v14;
  a2[11] = 0;
  survarium::transition_helper::start_transition_with_speed(
    (survarium::transition_helper *)(a2 + 8),
    v13,
    0.0,
    *(float *)(*a2 + 840),
    current_time_in_ms,
    a3);
}
