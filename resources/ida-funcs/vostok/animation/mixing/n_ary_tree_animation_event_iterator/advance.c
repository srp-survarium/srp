void __thiscall vostok::animation::mixing::n_ary_tree_animation_event_iterator::advance(
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this,
        int initial_event_types,
        __int16 disabled_channel_ids_at_start_time,
        unsigned __int8 *a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  int v11; // edi
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // esi
  float v15; // xmm0_4
  int v16; // esi
  int v17; // eax
  float v18; // xmm1_4
  bool v19; // cf
  float v20; // xmm0_4
  _BYTE *v21; // esi
  unsigned int v22; // eax
  float v23; // xmm0_4
  __int16 v24; // dx
  int v25; // eax
  unsigned int time_in_ms; // eax
  float v27; // xmm0_4
  unsigned int v28; // ecx
  _DWORD *v29; // eax
  bool v30; // zf
  __int16 v31; // ax
  unsigned int v32; // [esp+18h] [ebp-64h]
  struct vostok::animation::mixing::n_ary_tree_animation_node *v33; // [esp+1Ch] [ebp-60h]
  _BYTE v34[28]; // [esp+24h] [ebp-58h] BYREF
  float v35; // [esp+40h] [ebp-3Ch]
  int v36; // [esp+4Ch] [ebp-30h]
  int v37; // [esp+50h] [ebp-2Ch]
  int v38; // [esp+54h] [ebp-28h]
  int v39; // [esp+58h] [ebp-24h]
  float v40; // [esp+5Ch] [ebp-20h] BYREF
  const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v41; // [esp+60h] [ebp-1Ch]
  float v42; // [esp+64h] [ebp-18h] BYREF
  int i; // [esp+68h] [ebp-14h]
  float v44; // [esp+6Ch] [ebp-10h]
  float v45; // [esp+70h] [ebp-Ch]
  float v46; // [esp+74h] [ebp-8h]

  v4 = initial_event_types;
  if ( !disabled_channel_ids_at_start_time )
  {
    v5 = *(_DWORD *)(initial_event_types + 16);
    if ( *(_DWORD *)(v5 + 68) == 1
      && ((v6 = *(_DWORD *)(v5 + 28)) != 0 && *(_BYTE *)(v6 + 117) || (*(_BYTE *)(initial_event_types + 12) & 8) != 0) )
    {
LABEL_6:
      v36 = -1;
      v38 = -1;
      *(_DWORD *)(initial_event_types + 16) = 0;
      BYTE2(v39) = 0;
LABEL_7:
      LOWORD(v39) = 0;
      v37 = -33698355;
      HIBYTE(v39) = -1;
      *(_DWORD *)v4 = v36;
      *(_DWORD *)(v4 + 4) = v37;
      *(_DWORD *)(v4 + 8) = v38;
      *(_DWORD *)(v4 + 12) = v39;
      return;
    }
  }
  v7 = *(_DWORD **)(initial_event_types + 16);
  if ( v7[2] || v7[3] )
  {
    if ( (disabled_channel_ids_at_start_time & 1) != 0 )
      return;
    goto LABEL_6;
  }
  v8 = v7[7];
  if ( v8 )
    v9 = *(float *)(v8 + 100);
  else
    v9 = *(float *)(initial_event_types + 4);
  v46 = v9;
  for ( i = 0; ; ++i )
  {
    v10 = *(_DWORD *)(v4 + 16);
    v11 = *(_DWORD *)(v10 + 16) + 20 * *(_DWORD *)v4;
    v12 = *(float *)(v4 + 4);
    v13 = *(float *)(v11 + 16);
    v41 = (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)v11;
    if ( v12 > v13 )
      *(float *)(v4 + 4) = v13;
    if ( i )
      v46 = *(float *)(v4 + 4);
    v14 = *(_DWORD *)(v10 + 20);
    if ( !v14 )
      v14 = v10;
    if ( *(_DWORD *)(v14 + 4)
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(v14 + 88) + 12))(*(_DWORD *)(v14 + 88)) )
    {
      vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
        0,
        (int)v34,
        *(_DWORD *)(v4 + 4),
        *(_DWORD *)(v4 + 8),
        *(float *)(v4 + 8),
        v32,
        v33);
      (*(void (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)(v14 + 88) + 8))(*(_DWORD *)(v14 + 88), v34);
      v15 = v35;
    }
    else
    {
      v15 = s_bm_current_air_resistance;
    }
    if ( !disabled_channel_ids_at_start_time && v15 == 0.0 )
    {
      vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator(
        0,
        (int)v34,
        *(_DWORD *)(v4 + 4),
        *(_DWORD *)(v4 + 8) + 1,
        COERCE_FLOAT(*(_DWORD *)(v4 + 8) + 1),
        v32,
        v33);
      v16 = *(_DWORD *)(v14 + 4) ? *(_DWORD *)(v14 + 88) : 0;
      if ( v16 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 12))(v16) )
      {
        (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v16 + 8))(v16, v34);
        v15 = v35;
      }
      else
      {
        v15 = s_bm_current_air_resistance;
      }
      if ( v15 == 0.0 )
      {
        *(_DWORD *)(v4 + 16) = 0;
        v36 = -1;
        v38 = -1;
        BYTE2(v39) = 0;
        goto LABEL_7;
      }
    }
    v17 = *(_DWORD *)(v4 + 16);
    if ( *(_DWORD *)(v17 + 20) )
      v17 = *(_DWORD *)(v17 + 20);
    v18 = *(float *)(*(_DWORD *)(v17 + 16) + 20 * *(_DWORD *)v4 + 16) / *(float *)(v11 + 16);
    v19 = v15 < 0.0;
    v20 = *(float *)(v4 + 4);
    *(_WORD *)(v4 + 12) = disabled_channel_ids_at_start_time;
    v36 = *(_DWORD *)v4;
    v37 = *(_DWORD *)(v4 + 4);
    v38 = *(_DWORD *)(v4 + 8);
    v45 = v18;
    v39 = *(_DWORD *)(v4 + 12);
    v44 = v20;
    if ( v19 )
    {
      if ( v20 > v46 )
        v46 = v20;
      v21 = (_BYTE *)(v4 + 14);
      vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
        v41,
        (const vostok::animation::mixing::animation_interval *)LODWORD(v44),
        0.0,
        &initial_event_types,
        (unsigned __int16 *)(v4 + 14),
        (unsigned __int8 *)(v4 + 15),
        a4);
      v40 = v20 * v45;
      time_in_ms = vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_time_in_ms(
                     (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)v4,
                     (unsigned __int16 *)&initial_event_types,
                     *(_DWORD *)(v4 + 8),
                     v45 * v46,
                     &v40);
      if ( disabled_channel_ids_at_start_time && time_in_ms != *(_DWORD *)(v4 + 8) )
        return;
      v27 = v40 / v45;
      *(_DWORD *)(v4 + 8) = time_in_ms;
      *(_WORD *)(v4 + 12) |= initial_event_types;
      v24 = *(_WORD *)(v4 + 12);
      *(float *)(v4 + 4) = v27;
      if ( (v24 & 4) != 0 )
      {
        if ( !*(_DWORD *)v4
          || (v28 = *(_DWORD *)v4 - 1, v29 = *(_DWORD **)(v4 + 16), *(_DWORD *)v4 = v28, v28 < v29[16]) )
        {
          v29 = *(_DWORD **)(v4 + 16);
          *(_DWORD *)v4 = v29[15] - 1;
        }
        *(float *)(v4 + 4) = *(float *)(v29[4] + 20 * *(_DWORD *)v4 + 16);
      }
    }
    else
    {
      if ( v46 > v20 )
        v46 = v20;
      v21 = (_BYTE *)(v4 + 14);
      vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
        v41,
        (const vostok::animation::mixing::animation_interval *)LODWORD(v44),
        *(float *)&v41[4].m_object,
        &initial_event_types,
        (unsigned __int16 *)(v4 + 14),
        (unsigned __int8 *)(v4 + 15),
        a4);
      v42 = v20 * v45;
      v22 = vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_time_in_ms(
              (vostok::animation::mixing::n_ary_tree_animation_event_iterator *)v4,
              (unsigned __int16 *)&initial_event_types,
              *(_DWORD *)(v4 + 8),
              v45 * v46,
              &v42);
      if ( disabled_channel_ids_at_start_time && v22 != *(_DWORD *)(v4 + 8) )
        return;
      v23 = v42 / v45;
      *(_DWORD *)(v4 + 8) = v22;
      *(_WORD *)(v4 + 12) |= initial_event_types;
      v24 = *(_WORD *)(v4 + 12);
      *(float *)(v4 + 4) = v23;
      if ( (v24 & 4) != 0 )
      {
        ++*(_DWORD *)v4;
        v25 = *(_DWORD *)(v4 + 16);
        if ( *(_DWORD *)v4 == *(_DWORD *)(v25 + 60) )
          *(_DWORD *)v4 = *(_DWORD *)(v25 + 64);
        *(_DWORD *)(v4 + 4) = 0;
      }
    }
    if ( v38 != *(_DWORD *)(v4 + 8) )
      break;
    v30 = ((unsigned __int8)~(_BYTE)a4 & *v21) == 0;
    *v21 &= ~(_BYTE)a4;
    if ( v30 && disabled_channel_ids_at_start_time )
      return;
    if ( disabled_channel_ids_at_start_time )
      break;
    if ( (v24 & 0x20) != 0 )
    {
      *(_WORD *)(v4 + 12) = 32;
      break;
    }
  }
  if ( *(_DWORD *)(*(_DWORD *)(v4 + 16) + 68) == 2 )
  {
    v31 = *(_WORD *)(v4 + 12);
    if ( (v31 & 8) != 0 )
      *(_WORD *)(v4 + 12) = v31 | 2;
  }
}
