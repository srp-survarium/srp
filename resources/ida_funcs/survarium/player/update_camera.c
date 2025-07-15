void __thiscall survarium::player::update_camera(survarium::player *this, int time)
{
  survarium::player_input_handler *v3; // ecx
  float v4; // xmm0_4
  double v5; // st7
  float v6; // xmm1_4
  float v7; // xmm0_4
  bool v8; // zf
  int v9; // eax
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float current_transition_time; // [esp+0h] [ebp-5Ch]
  vostok::animation::linear_interpolator v15; // [esp+10h] [ebp-4Ch] BYREF
  float interpolation_time; // [esp+18h] [ebp-44h]
  vostok::math::float4x4 transform; // [esp+1Ch] [ebp-40h] BYREF
  float timea; // [esp+60h] [ebp+4h]

  v3 = *(survarium::player_input_handler **)((char *)&dword_10EF4 + time);
  if ( v3 )
  {
    v4 = *(float *)((char *)&dword_10F18 + time);
    if ( *(float *)((char *)&dword_10F1C + time) == v4 )
    {
      v3->m_fov_factor = v4;
    }
    else
    {
      v5 = (double)(unsigned int)(*(int *)((char *)&dword_10F0C + time) - *(int *)((char *)&dword_10F28 + time)) * 0.001;
      v6 = *(float *)((char *)&dword_10F24 + time);
      interpolation_time = v6;
      timea = v5;
      if ( timea < v6 )
      {
        current_transition_time = v5;
        v15.__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
        v15.m_total_transition_time = v6;
        *(float *)&v15.__vftable = vostok::animation::linear_interpolator::`vftable'(&v15, current_transition_time);
        v4 = (float)((float)(*(float *)((char *)&dword_10F18 + time) - *(float *)((char *)&dword_10F1C + time))
                   * *(float *)&v15.__vftable)
           + *(float *)((char *)&dword_10F1C + time);
        v6 = interpolation_time;
      }
      v3 = *(survarium::player_input_handler **)((char *)&dword_10EF4 + time);
      *(float *)((char *)&dword_10F20 + time) = v4;
      v3->m_fov_factor = v4;
      if ( timea >= v6 )
      {
        v7 = *(float *)((char *)&dword_10F18 + time);
        v8 = v7 == *(float *)&clear_value;
        *(float *)((char *)&dword_10F1C + time) = v7;
        if ( v8 )
        {
          v9 = *(int *)((char *)&dword_10EF4 + time);
          if ( v9 )
            *(float *)(v9 + 76) = satisfaction_equality_tolerance;
        }
      }
    }
    v10 = *(int *)((char *)&dword_10EF4 + time);
    if ( *(_DWORD *)(v10 + 408) )
    {
      v11 = *(float *)((char *)&dword_10DE4 + time);
      v12 = *(float *)((char *)&dword_10DE8 + time);
      v13 = *(float *)((char *)&dword_10DE0 + time) * 1.4;
      qmemcpy((void *)&transform, (char *)&unk_10DD0 + time, sizeof(transform));
      transform.c.x = v13 + transform.c.x;
      transform.c.y = transform.c.y + (float)(v11 * 1.4);
      transform.c.z = transform.c.z + (float)(v12 * 1.4);
      survarium::player_input_handler::update_inverted_view(0, (survarium::player_input_handler *)v10, &transform);
    }
    else
    {
      survarium::player_input_handler::update_inverted_view(
        v3,
        (survarium::player_input_handler *)v10,
        (const vostok::math::float4x4 *)(time + 72));
    }
  }
}
