void __userpurge survarium::body_part_parameters::tick(
        survarium::body_part_parameters *this@<ecx>,
        int a2@<esi>,
        float a3@<xmm0>,
        unsigned int time_delta_ms,
        unsigned int current_time_in_ms)
{
  unsigned int v5; // edi
  survarium::body_part_parameters *v6; // ecx
  float v7; // xmm0_4
  unsigned int v8; // eax
  const char *v9; // ebx
  float v10; // xmm0_4
  survarium::body_part_regeneration_modifier *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  survarium::body_part_parameters *v15; // ecx
  survarium::body_part_regeneration_info v16; // [esp+10h] [ebp-10h] BYREF
  survarium::body_part_regeneration_modifier *next; // [esp+1Ch] [ebp-4h]
  float amount; // [esp+28h] [ebp+8h]

  v5 = time_delta_ms;
  v7 = survarium::player_params_modifiers_container::apply_modifier(
         (survarium::player_params_modifiers_container *)(*(_DWORD *)((char *)&loc_11066
                                                                    + *(_DWORD *)(*(_DWORD *)(a2 + 112) + 1784)
                                                                    + 2)
                                                        + 448),
         health_regeneration_speed_modifier,
         a3,
         *(float *)(a2 + 152),
         1.0);
  v8 = *(_DWORD *)(a2 + 160);
  v9 = *(const char **)(a2 + 116);
  v16.speed = v7;
  v10 = *(float *)(a2 + 156);
  v16.timeout = v8;
  v11 = *(survarium::body_part_regeneration_modifier **)(a2 + 196);
  v16.threshold = v10;
  while ( v11 )
  {
    next = v11->next;
    survarium::body_part_regeneration_modifier::operator()(v11, v9, &v16);
    v11 = next;
  }
  if ( v16.timeout )
  {
    v6 = (survarium::body_part_parameters *)(v16.timeout + *(_DWORD *)(a2 + 164));
    if ( current_time_in_ms <= (unsigned int)v6 )
      return;
    v5 = time_delta_ms
       + (current_time_in_ms - (unsigned int)v6 < time_delta_ms ? current_time_in_ms - (_DWORD)v6 - time_delta_ms : 0);
  }
  v12 = *(float *)(a2 + 144) * v16.threshold;
  v13 = *(float *)(a2 + 148);
  if ( v12 > v13 )
  {
    v14 = v12 - v13;
    amount = (double)v5 * v16.speed * 0.001;
    if ( amount > v14 )
      amount = v14;
    survarium::body_part_parameters::increase_health((survarium::body_part_parameters *)a2, current_time_in_ms, amount);
  }
  survarium::body_part_parameters::update_affects(
    v6,
    (stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *)a2,
    current_time_in_ms);
  survarium::body_part_parameters::check_effects(v15, a2, current_time_in_ms);
}
