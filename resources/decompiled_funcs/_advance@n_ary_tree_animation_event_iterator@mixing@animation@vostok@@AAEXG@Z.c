void __userpurge vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this@<ecx>,
        int a2@<edi>,
        unsigned __int16 initial_event_types)
{
  int v3; // eax
  int v4; // eax
  __int64 v5; // xmm0_8
  _DWORD *v6; // eax
  int v7; // eax
  float v8; // xmm0_4
  vostok::animation::mixing::animation_interval *v9; // ebp
  int v10; // esi
  unsigned int v11; // eax
  int v12; // ecx
  float m_time_scale; // xmm0_4
  float v14; // xmm0_4
  unsigned int v15; // eax
  int v16; // esi
  int v17; // ecx
  double v18; // st7
  double v19; // st7
  float v20; // xmm0_4
  vostok::animation::mixing::n_ary_tree_animation_event_iterator *v21; // ecx
  vostok::animation::mixing::n_ary_tree_animation_node *v22; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // ecx
  __int16 v26; // ax
  float v27; // xmm0_4
  int v28; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v29; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *m_time_driving_animation; // ecx
  unsigned int v31; // edx
  unsigned int m_current_time_in_ms; // ecx
  __int16 v33; // ax
  float v34; // xmm0_4
  unsigned int v35; // ecx
  _DWORD *v36; // eax
  __int16 v37; // ax
  float v38; // [esp+8h] [ebp-7Ch]
  bool target_animation_time; // [esp+18h] [ebp-6Ch]
  float animation_state_interval_time; // [esp+28h] [ebp-5Ch]
  int event_type; // [esp+2Ch] [ebp-58h] BYREF
  float time_scale; // [esp+30h] [ebp-54h]
  float driving_animation_factor; // [esp+34h] [ebp-50h]
  unsigned int iteration; // [esp+38h] [ebp-4Ch]
  BOOL start_time_may_be_used; // [esp+3Ch] [ebp-48h]
  float new_event_time; // [esp+40h] [ebp-44h]
  float target_time; // [esp+44h] [ebp-40h]
  float v48; // [esp+48h] [ebp-3Ch]
  vostok::animation::mixing::animation_event value; // [esp+4Ch] [ebp-38h]
  vostok::animation::mixing::n_ary_tree_time_scale_calculator time_scale_calculator; // [esp+5Ch] [ebp-28h] BYREF

  LOBYTE(start_time_may_be_used) = initial_event_types & 1;
  if ( !initial_event_types )
  {
    v3 = *(_DWORD *)(a2 + 16);
    if ( *(_DWORD *)(v3 + 68) == 1
      && ((v4 = *(_DWORD *)(v3 + 28)) != 0 && *(_BYTE *)(v4 + 117) || (*(_BYTE *)(a2 + 12) & 8) != 0) )
    {
      value.event_type = 0;
LABEL_7:
      value.event_time_in_ms = -1;
      value.animation_interval_id = -1;
LABEL_8:
      value.animation_interval_time = -4.2170408e37;
      *(_QWORD *)a2 = *(_QWORD *)&value.animation_interval_id;
      value.channel_ids = 0;
      value.domain_data = -1;
      v5 = *(_QWORD *)&value.event_time_in_ms;
      *(_DWORD *)(a2 + 16) = 0;
      *(_QWORD *)(a2 + 8) = v5;
      return;
    }
  }
  v6 = *(_DWORD **)(a2 + 16);
  if ( v6[2] || v6[3] )
  {
    if ( (initial_event_types & 1) != 0 )
      return;
    value.event_type = 0;
    goto LABEL_7;
  }
  v7 = v6[7];
  if ( v7 )
    v8 = *(float *)(v7 + 100);
  else
    v8 = *(float *)(a2 + 4);
  animation_state_interval_time = v8;
  for ( iteration = 0; ; ++iteration )
  {
    v9 = (vostok::animation::mixing::animation_interval *)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 16) + 12 * *(_DWORD *)a2);
    if ( *(float *)(a2 + 4) > vostok::animation::mixing::animation_interval::length(v9) )
      *(float *)(a2 + 4) = vostok::animation::mixing::animation_interval::length(v9);
    if ( iteration )
      animation_state_interval_time = *(float *)(a2 + 4);
    v10 = *(_DWORD *)(*(_DWORD *)(a2 + 16) + 20);
    if ( !v10 )
      v10 = *(_DWORD *)(a2 + 16);
    if ( *(_DWORD *)(v10 + 4)
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v10 + 88) + 12))(*(_DWORD *)(v10 + 88)) )
    {
      v11 = *(_DWORD *)(a2 + 8);
      v12 = *(_DWORD *)(v10 + 88);
      time_scale_calculator.m_previous_animation_time = *(const float *)(a2 + 4);
      time_scale_calculator.m_current_time_in_ms = v11;
      time_scale_calculator.m_previous_time_in_ms = v11;
      time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
      memset((void *)&time_scale_calculator.m_animation, 0, 12);
      memset(&time_scale_calculator.m_time_scale, 0, 12);
      (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_time_scale_calculator *))(*(_DWORD *)v12 + 8))(
        v12,
        &time_scale_calculator);
      m_time_scale = time_scale_calculator.m_time_scale;
    }
    else
    {
      m_time_scale = *(float *)&clear_value;
    }
    time_scale = m_time_scale;
    if ( !initial_event_types && m_time_scale == 0.0 )
    {
      v14 = *(float *)(a2 + 4);
      v15 = *(_DWORD *)(a2 + 8) + 1;
      time_scale_calculator.__vftable = (vostok::animation::mixing::n_ary_tree_time_scale_calculator_vtbl *)&vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
      memset((void *)&time_scale_calculator.m_animation, 0, 12);
      time_scale_calculator.m_current_time_in_ms = v15;
      time_scale_calculator.m_previous_animation_time = v14;
      time_scale_calculator.m_previous_time_in_ms = v15;
      memset(&time_scale_calculator.m_time_scale, 0, 12);
      if ( *(_DWORD *)(v10 + 4)
        && (v16 = *(_DWORD *)(v10 + 88)) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 12))(v16) )
      {
        (*(void (__thiscall **)(int, vostok::animation::mixing::n_ary_tree_time_scale_calculator *))(*(_DWORD *)v16 + 8))(
          v16,
          &time_scale_calculator);
        time_scale = time_scale_calculator.m_time_scale;
        if ( time_scale_calculator.m_time_scale == 0.0 )
        {
          value.animation_interval_id = -1;
          value.event_time_in_ms = -1;
          value.event_type = 0;
          goto LABEL_8;
        }
      }
      else
      {
        time_scale = *(float *)&clear_value;
      }
    }
    v17 = *(_DWORD *)(*(_DWORD *)(a2 + 16) + 20);
    if ( !v17 )
      v17 = *(_DWORD *)(a2 + 16);
    driving_animation_factor = vostok::animation::mixing::animation_interval::length((vostok::animation::mixing::animation_interval *)(*(_DWORD *)(v17 + 16) + 12 * *(_DWORD *)a2));
    v18 = vostok::animation::mixing::animation_interval::length(v9);
    v19 = driving_animation_factor / v18;
    *(_WORD *)(a2 + 12) = initial_event_types;
    value = *(vostok::animation::mixing::animation_event *)a2;
    v20 = *(float *)(a2 + 4);
    driving_animation_factor = v19;
    if ( time_scale < 0.0 )
    {
      target_time = v20;
      if ( v20 > animation_state_interval_time )
        animation_state_interval_time = v20;
      vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
        (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)(a2 + 15),
        (const vostok::animation::mixing::animation_interval *)a2,
        v9,
        target_time,
        0.0,
        (unsigned __int16 *)&event_type,
        (unsigned __int8 *)(a2 + 14),
        (unsigned __int8 *)(a2 + 15),
        start_time_may_be_used);
      v29 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(a2 + 16);
      m_time_driving_animation = v29->m_time_driving_animation;
      v31 = *(_DWORD *)(a2 + 8);
      v48 = v20 * driving_animation_factor;
      if ( m_time_driving_animation )
        v29 = m_time_driving_animation;
      vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
        (vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *)&time_scale_calculator,
        v29,
        event_type,
        v31,
        driving_animation_factor * animation_state_interval_time,
        v48);
      event_type = LOWORD(time_scale_calculator.m_previous_animation_time);
      m_current_time_in_ms = time_scale_calculator.m_current_time_in_ms;
      if ( initial_event_types && time_scale_calculator.m_current_time_in_ms != *(_DWORD *)(a2 + 8) )
        return;
      *(_WORD *)(a2 + 12) |= LOWORD(time_scale_calculator.m_previous_animation_time);
      v33 = *(_WORD *)(a2 + 12);
      v34 = *(float *)&time_scale_calculator.m_interpolator / driving_animation_factor;
      *(_DWORD *)(a2 + 8) = m_current_time_in_ms;
      *(float *)(a2 + 4) = v34;
      if ( (v33 & 4) != 0 )
      {
        if ( !*(_DWORD *)a2
          || (v35 = *(_DWORD *)a2 - 1, v36 = *(_DWORD **)(a2 + 16), *(_DWORD *)a2 = v35, v35 < v36[16]) )
        {
          v36 = *(_DWORD **)(a2 + 16);
          *(_DWORD *)a2 = v36[15] - 1;
        }
        *(float *)(a2 + 4) = vostok::animation::mixing::animation_interval::length((vostok::animation::mixing::animation_interval *)(v36[4] + 12 * *(_DWORD *)a2));
      }
    }
    else
    {
      if ( animation_state_interval_time > v20 )
        animation_state_interval_time = v20;
      target_animation_time = start_time_may_be_used;
      v38 = vostok::animation::mixing::animation_interval::length(v9);
      vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
        v21,
        (const vostok::animation::mixing::animation_interval *)a2,
        v9,
        *(float *)(a2 + 4),
        v38,
        (unsigned __int16 *)&event_type,
        (unsigned __int8 *)(a2 + 14),
        (unsigned __int8 *)(a2 + 15),
        target_animation_time);
      v22 = *(vostok::animation::mixing::n_ary_tree_animation_node **)(a2 + 16);
      v23 = v22->m_time_driving_animation;
      v24 = *(_DWORD *)(a2 + 8);
      new_event_time = v20 * driving_animation_factor;
      if ( v23 )
        v22 = v23;
      vostok::animation::mixing::n_ary_tree_time_in_ms_calculator::n_ary_tree_time_in_ms_calculator(
        (vostok::animation::mixing::n_ary_tree_time_in_ms_calculator *)&time_scale_calculator,
        v22,
        event_type,
        v24,
        driving_animation_factor * animation_state_interval_time,
        new_event_time);
      event_type = LOWORD(time_scale_calculator.m_previous_animation_time);
      v25 = time_scale_calculator.m_current_time_in_ms;
      if ( initial_event_types && time_scale_calculator.m_current_time_in_ms != *(_DWORD *)(a2 + 8) )
        return;
      *(_WORD *)(a2 + 12) |= LOWORD(time_scale_calculator.m_previous_animation_time);
      v26 = *(_WORD *)(a2 + 12);
      v27 = *(float *)&time_scale_calculator.m_interpolator / driving_animation_factor;
      *(_DWORD *)(a2 + 8) = v25;
      *(float *)(a2 + 4) = v27;
      if ( (v26 & 4) != 0 )
      {
        ++*(_DWORD *)a2;
        v28 = *(_DWORD *)(a2 + 16);
        if ( *(_DWORD *)a2 == *(_DWORD *)(v28 + 60) )
          *(_DWORD *)a2 = *(_DWORD *)(v28 + 64);
        *(_DWORD *)(a2 + 4) = 0;
      }
    }
    if ( initial_event_types || *(_DWORD *)(a2 + 8) != value.event_time_in_ms )
      break;
  }
  if ( *(_DWORD *)(*(_DWORD *)(a2 + 16) + 68) == 2 )
  {
    v37 = *(_WORD *)(a2 + 12);
    if ( (v37 & 8) != 0 )
      *(_WORD *)(a2 + 12) = v37 | 2;
  }
}
