int __usercall survarium::computed_shooting_animation_time_scale@<xmm0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *shooting_animation@<eax>,
        float rounds_per_second)
{
  int v2; // ebp
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v3; // ecx
  int i; // ebx
  const unsigned __int8 *v5; // esi
  int v6; // ecx
  unsigned int v7; // edx
  int v8; // eax
  int v9; // esi
  const unsigned __int8 *v10; // eax
  const unsigned __int8 *v11; // eax
  volatile signed __int32 *v12; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v14; // [esp-4h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+10h] [ebp-14h] BYREF
  float v16; // [esp+14h] [ebp-10h]
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+18h] [ebp-Ch] BYREF

  v2 = 0;
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    shooting_animation);
  v14.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v14,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v3,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v14.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  for ( i = 0; ; ++i )
  {
    v5 = &pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 3) + 8 + v2];
    if ( !strcmp((const char *)v5, "shoot") )
      break;
    v2 += 44;
  }
  v6 = *((_DWORD *)v5 + 8);
  v7 = 0;
  v8 = 0;
  if ( v6 )
  {
    v9 = (int)&v5[*((_DWORD *)v5 + 9) + 32];
    do
    {
      if ( *(_BYTE *)(v9 + v8) == 7 )
        ++v7;
      ++v8;
    }
    while ( v8 != v6 );
  }
  v10 = &pinned_animation.m_data[*((_DWORD *)pinned_animation.m_data + 5)];
  v16 = *(float *)&v7;
  v16 = rounds_per_second
      / ((double)v7
       / ((*(float *)&v10[20 * *(_DWORD *)v10 - 4 + *((_DWORD *)v10 + 1)]
         - *(float *)&v10[16 * *(_DWORD *)v10 + *((_DWORD *)v10 + 1)])
        * 0.033333335));
  if ( pinned_animation.m_resource.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v11 = pinned_animation.m_data - 52;
      v12 = (volatile signed __int32 *)(pinned_animation.m_data - 8);
      _InterlockedExchangeAdd(v12, 0xFFFFFFFF);
      if ( *((_DWORD *)v11 + 4) )
      {
        if ( !*v12 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)(*((_DWORD *)v11 + 4) + 40), 1u);
          *((_DWORD *)v11 + 4) = 0;
        }
      }
    }
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&pinned_animation.m_resource);
  return LODWORD(v16);
}
