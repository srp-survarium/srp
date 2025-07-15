void __thiscall survarium::player::update_camera(survarium::player *this, int a2)
{
  int v2; // eax
  int *v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15[16]; // [esp+10h] [ebp-40h] BYREF

  v2 = *(_DWORD *)((char *)&loc_11403 + a2 + 5);
  if ( v2 )
  {
    if ( *(_DWORD *)(v2 + 864) )
    {
      *(float *)(v2 + 148) = s_bm_current_air_resistance;
      *(float *)(*(_DWORD *)((char *)&loc_11403 + a2 + 5) + 140) = satisfaction_equality_tolerance;
      v12 = *(float *)(a2 + 69940);
      v13 = *(float *)(a2 + 69944);
      v14 = *(float *)(a2 + 69936) * 1.4;
      qmemcpy(v15, (char *)&locret_1111E + a2 + 2, sizeof(v15));
      v4 = 0;
      v15[12] = v14 + v15[12];
      v15[13] = v15[13] + (float)(v12 * 1.4);
      v15[14] = v15[14] + (float)(v13 * 1.4);
      v11 = v15;
    }
    else
    {
      v3 = (int *)(a2 + 320);
      if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 320) + 96))(*(_DWORD *)(a2 + 320)) )
      {
        v5 = *v3;
        v6 = *(_DWORD *)(*v3 + 1668);
        if ( v6
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v7 = *(float *)(v6 + 276);
        }
        else
        {
          v7 = *(float *)(v5 + 1052);
        }
        v8 = s_bm_current_air_resistance;
        *(float *)(*(_DWORD *)((char *)&loc_11403 + a2 + 5) + 148) = (float)((float)(v7 - s_bm_current_air_resistance)
                                                                           * *(float *)(v5 + 1124))
                                                                   + s_bm_current_air_resistance;
        v4 = *(_DWORD *)(v5 + 1668);
        if ( v4
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v9 = *(float *)(v4 + 280);
        }
        else
        {
          v9 = *(float *)(v5 + 1056);
        }
        v10 = (float)((float)((float)(v9 - v8) * *(float *)(v5 + 1124)) + v8) * 0.050000001;
      }
      else
      {
        *(float *)(*(_DWORD *)((char *)&loc_11403 + a2 + 5) + 148) = s_bm_current_air_resistance;
        v10 = satisfaction_equality_tolerance;
      }
      *(float *)(*(_DWORD *)((char *)&loc_11403 + a2 + 5) + 140) = v10;
      v11 = (float *)((char *)&loc_11160 + a2);
    }
    survarium::player_input_handler::update_inverted_view(
      (survarium::player_input_handler *)v4,
      *(const vostok::math::float4x4 **)((char *)&loc_11403 + a2 + 5),
      v11);
  }
}
