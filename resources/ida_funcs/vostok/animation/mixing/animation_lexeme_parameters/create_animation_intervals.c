void __thiscall vostok::animation::mixing::animation_lexeme_parameters::create_animation_intervals(
        vostok::animation::mixing::animation_lexeme_parameters *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation_interval_end)
{
  vostok::resources::managed_resource *m_object; // eax
  vostok::animation::mixing::animation_interval *v5; // ebp
  int v6; // ecx
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v7; // ecx
  const unsigned __int8 *v8; // eax
  float v9; // xmm0_4
  int v10; // esi
  float v11; // xmm0_4
  const unsigned __int8 *v12; // esi
  int channel_id; // eax
  const unsigned __int8 *v14; // ecx
  unsigned int v15; // eax
  _DWORD *v16; // esi
  float v17; // xmm0_4
  unsigned int v18; // edi
  float v19; // xmm1_4
  vostok::resources::managed_resource *v20; // edi
  vostok::animation::mixing::animation_interval *v21; // ebp
  const unsigned __int8 *v22; // eax
  volatile signed __int32 *v23; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> length; // [esp+4h] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+18h] [ebp-1Ch] BYREF
  float knot; // [esp+1Ch] [ebp-18h]
  unsigned int v27; // [esp+20h] [ebp-14h]
  vostok::animation::mixing::animation_interval *animation_intervals; // [esp+24h] [ebp-10h]
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+28h] [ebp-Ch] BYREF
  float animation_length; // [esp+38h] [ebp+4h]
  volatile float animation_interval_enda; // [esp+3Ch] [ebp+8h]
  volatile float animation_interval_endb; // [esp+3Ch] [ebp+8h]

  m_object = animation->m_object;
  v5 = (vostok::animation::mixing::animation_interval *)animation->m_object->__vftable;
  v6 = 12 * (int)animation[10].m_object;
  m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::managed_resource_vtbl *)((char *)m_object->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable + v6);
  m_object->type -= v6;
  animation_intervals = v5;
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    animation_interval_end);
  *(float *)&length.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &length,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v7,
    &pinned_animation.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)length.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v8 = &pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 5)];
  v9 = *(float *)&v8[20 * *(_DWORD *)v8 - 4 + *((_DWORD *)v8 + 1)];
  v10 = *((_DWORD *)v8 + 1) + 16 * *(_DWORD *)v8;
  *(float *)&length.m_object = COERCE_FLOAT("anim_intervals");
  v11 = (float)(v9 - *(float *)&v8[v10]) * 0.033333335;
  v12 = pinned_animation.m_data + 8;
  animation_length = v11;
  channel_id = vostok::animation::animation_event_channels::get_channel_id(
                 (vostok::animation::animation_event_channels *)pinned_animation.m_data + 1,
                 "anim_intervals");
  if ( channel_id != -1
    && (v14 = &v12[44 * channel_id + *((_DWORD *)v12 + 1)]) != 0
    && (v15 = *((_DWORD *)v14 + 8), v16 = v14 + 32, (v27 = v15) != 0) )
  {
    v17 = *(float *)((char *)v16 + v15 + *((_DWORD *)v14 + 9));
    v18 = 1;
    if ( v15 > 1 )
    {
      do
      {
        v19 = *(float *)((char *)&v16[v18] + *v16 + v16[1]);
        knot = v19;
        if ( v5 )
        {
          vostok::animation::mixing::animation_interval::animation_interval(
            v5,
            animation_interval_end,
            v17 * 0.033333335,
            (float)(v19 - v17) * 0.033333335);
          v19 = knot;
          v15 = v27;
        }
        ++v18;
        ++v5;
        v17 = v19;
      }
      while ( v18 < v15 );
      v5 = animation_intervals;
    }
    v20 = (vostok::resources::managed_resource *)(*v16 - 1);
    v21 = &v5[(_DWORD)v20];
    *(float *)&animation_intervals = (float)(*(float *)((char *)v16 + *v16 + v16[1]) - v17) * 0.033333335;
    if ( v21 )
    {
      *(float *)&length.m_object = *(float *)&animation_intervals + animation_length;
      vostok::animation::mixing::animation_interval::animation_interval(
        v21,
        animation_interval_end,
        v17 * 0.033333335,
        *(float *)&length.m_object);
    }
    animation_interval_enda = vostok::animation::mixing::animation_interval::start_time(v21);
    animation_interval_endb = vostok::animation::mixing::animation_interval::length(v21) + animation_interval_enda;
    if ( animation_interval_endb > (double)animation_length )
    {
      animation[12].m_object = v20;
      *(float *)&animation[13].m_object = animation_length
                                        - vostok::animation::mixing::animation_interval::start_time(v21);
    }
    if ( pinned_animation.m_resource.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v22 = pinned_animation.m_data - 52;
        v23 = (volatile signed __int32 *)(pinned_animation.m_data - 8);
        _InterlockedExchangeAdd(v23, 0xFFFFFFFF);
        if ( *((_DWORD *)v22 + 4) )
        {
          if ( !*v23 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)v22 + 4) + 40), 1u);
            *((_DWORD *)v22 + 4) = 0;
          }
        }
      }
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&pinned_animation.m_resource);
  }
  else
  {
    if ( v5 )
      vostok::animation::mixing::animation_interval::animation_interval(v5, animation_interval_end, 0.0, v11);
    animation[12].m_object = 0;
    animation[13].m_object = 0;
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
  }
}
