void __userpurge survarium::dispersion_calculator::calculate_character_dispersion(
        survarium::dispersion_calculator *this@<ecx>,
        float a2@<ebx>,
        bool a3@<dil>,
        int *a4@<esi>,
        int character_state,
        enum survarium::weapon_user_state_enum is_moving,
        const unsigned __int8 broken_hands_count,
        const bool using_double_handed_weapon,
        float low_stamina_penalty,
        unsigned int current_time_in_ms)
{
  int character_skill_influence; // xmm0_4
  float v11; // edi
  char v12; // dl
  float *v13; // eax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  char v17; // fl
  float v18; // xmm0_4
  float v19; // xmm1_4
  bool v20; // cf
  bool v21; // zf
  char v22; // sf
  char v23; // of
  char v24; // pf
  float v25; // xmm1_4
  unsigned int v26; // [esp+8h] [ebp-Ch]
  float v27; // [esp+10h] [ebp-4h]

  character_skill_influence = survarium::dispersion_calculator::get_character_skill_influence(
                                this,
                                a4,
                                character_state,
                                low_stamina_penalty,
                                is_moving,
                                a3,
                                a2);
  v11 = *(float *)a4;
  a4[13] = character_skill_influence;
  v12 = *(_BYTE *)(LODWORD(v11) + 1108);
  v27 = *(float *)&character_skill_influence;
  if ( !character_state )
  {
LABEL_14:
    v13 = (float *)a4[1];
    if ( (_BYTE)is_moving )
    {
      if ( v12 )
        v14 = v13[3];
      else
        v14 = v13[2];
    }
    else if ( v12 )
    {
      v14 = v13[1];
    }
    else
    {
      v14 = *v13;
    }
    goto LABEL_21;
  }
  if ( character_state != 1 )
  {
    if ( character_state == 2 )
    {
      v13 = (float *)a4[1];
      v14 = v13[4];
      goto LABEL_21;
    }
    if ( character_state == 3 )
    {
      v13 = (float *)a4[1];
      v14 = v13[5];
      goto LABEL_21;
    }
    goto LABEL_14;
  }
  v13 = (float *)a4[1];
  if ( (_BYTE)is_moving )
  {
    if ( v12 )
      v14 = v13[9];
    else
      v14 = v13[8];
  }
  else if ( v12 )
  {
    v14 = v13[7];
  }
  else
  {
    v14 = v13[6];
  }
LABEL_21:
  if ( (float)(v13[12] * low_stamina_penalty) > v14 )
    v14 = v13[12] * low_stamina_penalty;
  if ( !broken_hands_count )
  {
LABEL_29:
    v15 = 0.0;
    goto LABEL_30;
  }
  if ( broken_hands_count == 1 )
  {
    if ( using_double_handed_weapon )
      goto LABEL_26;
    goto LABEL_29;
  }
  if ( using_double_handed_weapon )
  {
LABEL_26:
    v15 = v13[13];
    goto LABEL_30;
  }
  v15 = v13[14];
LABEL_30:
  if ( v12 )
    v16 = *(float *)(LODWORD(v11) + 836);
  else
    v16 = *(float *)(LODWORD(v11) + 832);
  v18 = survarium::player_params_modifiers_container::apply_modifier(
          (survarium::player_params_modifiers_container *)(*(_DWORD *)(*(_DWORD *)(LODWORD(v11) + 8) + 69736) + 448),
          dispersion_modifier,
          (float)(v16 * v14) + v15,
          (float)(v16 * v14) + v15,
          v27);
  v19 = *((float *)a4 + 3);
  v20 = v19 < v18;
  v24 = 0;
  v21 = v19 == v18;
  v22 = 0;
  v23 = 0;
  if ( v19 <= v18 )
    v25 = *(float *)(LODWORD(v11) + 852);
  else
    v25 = *(float *)(LODWORD(v11) + 840);
  survarium::transition_helper::start_transition_with_speed(
    (survarium::transition_helper *)(a4 + 3),
    v17,
    v18,
    v25,
    current_time_in_ms,
    v26);
}
