float __thiscall vostok::animation::mixing::n_ary_tree_animation_event_iterator::get_nearest_animation_interval_event_time(
        vostok::animation::mixing::n_ary_tree_animation_event_iterator *this,
        const vostok::animation::mixing::animation_interval *interval,
        vostok::animation::mixing::animation_interval *start_time,
        float target_time,
        float event_type,
        unsigned __int16 *channel_ids,
        unsigned __int8 *domain_data,
        unsigned __int8 *start_time_may_be_used,
        bool start_time_may_be_useda)
{
  vostok::animation::mixing::animation_interval *v9; // eax
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v10; // ecx
  int v14; // ebp
  double started; // st7
  const unsigned __int8 *v19; // esi
  unsigned int v20; // eax
  const unsigned __int8 *v21; // ebx
  int v22; // eax
  _DWORD *v23; // esi
  float *v24; // edi
  int v25; // ebp
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  unsigned __int8 v34; // dl
  bool is_relatively_similar; // al
  const unsigned __int8 *v36; // eax
  volatile signed __int32 *v37; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v39; // [esp-14h] [ebp-40h] BYREF
  float v40; // [esp+4h] [ebp-28h]
  float animation_length; // [esp+8h] [ebp-24h]
  int time_direction; // [esp+Ch] [ebp-20h]
  const vostok::animation::subscribed_channel *subscribed_channel; // [esp+10h] [ebp-1Ch] BYREF
  float current_knot_time; // [esp+14h] [ebp-18h]
  float v45; // [esp+18h] [ebp-14h]
  unsigned int channel_id; // [esp+1Ch] [ebp-10h]
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+20h] [ebp-Ch] BYREF
  float knot_time; // [esp+30h] [ebp+4h]

  *domain_data = 0;
  *start_time_may_be_used = -1;
  time_direction = 1;
  if ( event_type < target_time )
    time_direction = -1;
  v9 = vostok::animation::mixing::animation_interval::animation(start_time);
  *(float *)&subscribed_channel = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&subscribed_channel,
    &v9->m_animation);
  v39.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v39,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&subscribed_channel);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v10,
    &pinned_animation.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v39.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&subscribed_channel);
  *channel_ids = 4;
  _EAX = &pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 5)];
  _EDX = *((_DWORD *)_EAX + 1) + 20 * *(_DWORD *)_EAX;
  __asm { fld     dword ptr [edx+eax-4] }
  _ECX = *((_DWORD *)_EAX + 1) + 16 * *(_DWORD *)_EAX;
  __asm { fsub    dword ptr [ecx+eax] }
  __asm
  {
    fmul    dword ptr ds:stru_984D24.m_working_macro_list.m_buffer.m_store+1554h
    fstp    [esp+3Ch+animation_length]
  }
  vostok::animation::mixing::animation_interval::start_time(start_time);
  __asm { fsubr   [esp+3Ch+animation_length] }
  v14 = time_direction;
  v40 = (float)time_direction;
  __asm { fstp    [esp+3Ch+current_knot_time] }
  *(float *)&subscribed_channel = (float)time_direction * animation_length;
  started = vostok::animation::mixing::animation_interval::start_time(start_time);
  __asm { fadd    [esp+3Ch+start_time] }
  __asm
  {
    fmul    [esp+3Ch+var_28]
    fld     [esp+3Ch+subscribed_channel]
  }
  if ( !start_time_may_be_useda )
  {
    __asm
    {
      fcomip  st, st(1)
      fstp    st
    }
    if ( _CF | _ZF )
      goto LABEL_12;
LABEL_7:
    started = vostok::animation::mixing::animation_interval::start_time(start_time);
    __asm
    {
      fadd    [esp+3Ch+target_time]
      fmul    [esp+3Ch+var_28]
      fld     [esp+3Ch+subscribed_channel]
      fxch    st(1)
      fcomip  st, st(1)
      fstp    st
    }
    if ( !_CF )
    {
      started = vostok::animation::mixing::animation_interval::start_time(start_time);
      __asm
      {
        fadd    [esp+3Ch+target_time]
        fld     [esp+3Ch+animation_length]
        fxch    st(1)
        fucomip st, st(1)
        fstp    st
      }
      if ( _PF | _ZF )
        *channel_ids |= 8 * (v14 != 1) + 8;
      else
        *channel_ids = 8 * (v14 != 1) + 8;
      event_type = current_knot_time;
    }
    goto LABEL_12;
  }
  __asm
  {
    fcomip  st, st(1)
    fstp    st
  }
  if ( !_CF )
    goto LABEL_7;
LABEL_12:
  if ( !*((_DWORD *)pinned_animation.m_data + 2) )
  {
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
    return started;
  }
  subscribed_channel = *(const vostok::animation::subscribed_channel **)LODWORD(interval[1].m_length);
  if ( *(float *)&subscribed_channel == 0.0 )
    goto LABEL_47;
  while ( 2 )
  {
    v19 = pinned_animation.m_data + 8;
    v20 = vostok::animation::animation_event_channels::get_channel_id(
            (vostok::animation::animation_event_channels *)pinned_animation.m_data + 1,
            subscribed_channel->channel_id);
    channel_id = v20;
    if ( v20 == -1 )
      goto LABEL_46;
    v21 = &v19[44 * v20 + *((_DWORD *)v19 + 1)];
    v22 = *((_DWORD *)v21 + 8);
    v23 = v21 + 32;
    if ( v14 == 1 )
    {
      v24 = (float *)&v21[v22 + 32 + *((_DWORD *)v21 + 9)];
      v25 = (int)&v23[v22] + v22 + *((_DWORD *)v21 + 9);
    }
    else
    {
      v24 = (float *)((char *)&v23[v22 - 1] + v22 + *((_DWORD *)v21 + 9));
      v25 = (int)v23 + v22 + *((_DWORD *)v21 + 9) - 4;
    }
    if ( v24 == (float *)v25 )
      goto LABEL_46;
    while ( 1 )
    {
      v26 = *v24 * 0.033333335;
      if ( animation_length <= v26 )
        v26 = v26 - animation_length;
      current_knot_time = v26;
      started = vostok::animation::mixing::animation_interval::start_time(start_time);
      __asm { fsubr   [esp+3Ch+current_knot_time] }
      v27 = v40;
      __asm
      {
        fst     [esp+3Ch+knot_time]
        fldz
      }
      v28 = knot_time;
      __asm
      {
        fcomip  st, st(1)
        fstp    st
      }
      if ( !(_CF | _ZF) )
      {
        v28 = knot_time + animation_length;
        v45 = knot_time + animation_length;
        if ( (float)((float)(knot_time + animation_length) * v40) > (float)(v40 * event_type) )
        {
          if ( !vostok::math::is_relatively_similar((float)(knot_time + animation_length) * v40, v40 * event_type) )
            goto LABEL_39;
          v28 = v45;
          v27 = v40;
        }
        knot_time = v28;
      }
      v29 = v27 * target_time;
      v30 = v27 * v28;
      if ( !start_time_may_be_useda )
        break;
      if ( v29 <= v30 )
        goto LABEL_31;
LABEL_38:
      if ( (float)((float)(v28 + animation_length) * v27) < (float)(v27 * event_type) )
        goto LABEL_31;
LABEL_39:
      v24 += time_direction;
      if ( v24 == (float *)v25 )
        goto LABEL_46;
    }
    if ( v29 >= v30 )
      goto LABEL_38;
    is_relatively_similar = vostok::math::is_relatively_similar(v30, v29);
    v27 = v40;
    v28 = knot_time;
    if ( is_relatively_similar )
      goto LABEL_38;
LABEL_31:
    v31 = v27;
    v32 = v27 * event_type;
    v33 = v31 * v28;
    if ( v33 <= v32 )
      goto LABEL_34;
    if ( vostok::math::is_relatively_similar(v33, v32) )
    {
      v28 = knot_time;
LABEL_34:
      v34 = 1 << channel_id;
      if ( v28 == event_type )
      {
        *channel_ids |= 0x20u;
        *domain_data |= v34;
      }
      else
      {
        *channel_ids = 32;
        *domain_data = v34;
      }
      if ( *((int *)v21 + 10) <= 1 )
        *start_time_may_be_used = *((_BYTE *)v23
                                  + *((_DWORD *)v21 + 9)
                                  + (unsigned int)(((char *)v24
                                                  - *((_DWORD *)v21 + 9)
                                                  - (char *)(v21 + 32)
                                                  - *((_DWORD *)v21 + 8)) >> 2)
                                  % *((_DWORD *)v21 + 8));
      else
        *start_time_may_be_used = -1;
      event_type = v28;
    }
LABEL_46:
    subscribed_channel = subscribed_channel->next;
    if ( *(float *)&subscribed_channel != 0.0 )
    {
      v14 = time_direction;
      continue;
    }
    break;
  }
LABEL_47:
  if ( pinned_animation.m_resource.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v36 = pinned_animation.m_data - 52;
      v37 = (volatile signed __int32 *)(pinned_animation.m_data - 8);
      _InterlockedExchangeAdd(v37, 0xFFFFFFFF);
      if ( *((_DWORD *)v36 + 4) )
      {
        if ( !*v37 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)v36 + 4) + 40), 1u);
          *((_DWORD *)v36 + 4) = 0;
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&pinned_animation.m_resource);
  return started;
}
