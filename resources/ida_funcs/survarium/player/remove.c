void __usercall survarium::player::remove(survarium::player *this@<ecx>, int a2@<eax>)
{
  int v3; // edi
  vostok::resources::unmanaged_resource **v4; // edi
  void (__thiscall *v5)(int, int, vostok::resources::unmanaged_resource **); // edx
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  vostok::resources::unmanaged_resource *v7; // eax
  vostok::resources::unmanaged_resource *v8; // eax
  int v9; // eax
  survarium::base_network_client *v10; // ecx
  survarium::player *m_object; // eax
  vostok::resources::unmanaged_resource *resource; // [esp+10h] [ebp-4h] BYREF

  *(_BYTE *)(a2 + 283) = 0;
  if ( !byte_10F80[a2] )
  {
    v3 = *(_DWORD *)(*(int *)((char *)&dword_10F00 + a2) + 164);
    Scaleform::RefCountNTSImpl::Release(*(Scaleform::RefCountNTSImpl **)((char *)&dword_10EE4 + a2));
    *(int *)((char *)&dword_10EE4 + a2) = 0;
    *(int *)((char *)&dword_10EE8 + a2) = 0;
    *((_BYTE *)&dword_10EEC + a2) = 0;
    *(_BYTE *)(v3 + 4) = 1;
  }
  if ( byte_10F34[a2] )
  {
    byte_10F34[a2] = 0;
    survarium::player::remove_models_from_scene(this, a2);
  }
  v4 = (vostok::resources::unmanaged_resource **)(a2 + 64);
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 64) + 32))(*(_DWORD *)(a2 + 64));
  v5 = *(void (__thiscall **)(int, int, vostok::resources::unmanaged_resource **))(*(_DWORD *)a2 + 124);
  resource = 0;
  v5(a2, a2 + 64, &resource);
  if ( resource )
  {
    v6 = (vostok::resources::unmanaged_intrusive_base *)_InterlockedExchangeAdd(
                                                          &resource->m_reference_count,
                                                          0xFFFFFFFF);
    if ( !v6 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &resource->vostok::resources::unmanaged_intrusive_base,
        resource);
  }
  v7 = *v4;
  *v4 = 0;
  if ( v7 )
  {
    v6 = &v7->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v6, v7);
  }
  v8 = *(vostok::resources::unmanaged_resource **)(a2 + 68);
  *(_DWORD *)(a2 + 68) = 0;
  if ( v8 )
  {
    v6 = &v8->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v6, v8);
  }
  if ( *(_BYTE *)(a2 + 281) )
    survarium::player::remove_alive((survarium::player *)v6, a2);
  if ( !byte_10F80[a2] )
  {
    v9 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(*(int *)((char *)&dword_10F04 + a2) + 952) + 52))(*(_DWORD *)(*(int *)((char *)&dword_10F04 + a2) + 952));
    survarium::inventory::unload_to_profile(
      *(survarium::inventory **)(a2 + 8),
      (survarium::player_profile *)(v9 + 440 * *(unsigned __int8 *)(a2 + 52)),
      *(const survarium::items_dictionary **)(*(int *)((char *)&dword_10F04 + a2) + 948));
  }
  survarium::inventory::remove(*(survarium::inventory **)(a2 + 8));
  v10 = *(survarium::base_network_client **)(*(int *)((char *)&dword_10F04 + a2) + 952);
  m_object = v10->m_current_player.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && m_object->id == *(_BYTE *)(a2 + 52) )
  {
    survarium::base_network_client::detach_from_player(v10);
  }
}
