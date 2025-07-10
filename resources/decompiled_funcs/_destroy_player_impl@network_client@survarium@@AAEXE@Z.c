void __userpurge survarium::network_client::destroy_player_impl(
        survarium::network_client *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> id)
{
  unsigned __int8 m_object; // bl
  vostok::resources::unmanaged_resource *v5; // edx
  int v6; // eax
  int v7; // eax
  vostok::resources::unmanaged_intrusive_base *v8; // ecx

  m_object = (unsigned __int8)id.m_object;
  (*(void (__thiscall **)(_DWORD *, vostok::resources::resource_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base> *, survarium::player *))(*a2 + 72))(
    a2,
    &id,
    id.m_object);
  v5 = (vostok::resources::unmanaged_resource *)a2[2 * m_object + 3846];
  a2[2 * m_object + 3846] = 0;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  if ( id.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && id.m_object->m_has_been_inserted )
  {
    survarium::player::remove((survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr);
  }
  v6 = a2[3886];
  if ( v6 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( *(_BYTE *)(v6 + 52) == m_object )
      {
        a2[3886] = 0;
        if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 496), 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            (vostok::resources::unmanaged_intrusive_base *)(v6 + 496),
            (vostok::resources::unmanaged_resource *)(v6 + 288));
      }
    }
  }
  v7 = a2[2];
  if ( v7
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && *(_BYTE *)(v7 + 52) == m_object )
  {
    a2[2] = 0;
    v8 = (vostok::resources::unmanaged_intrusive_base *)(v7 + 496);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 496), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v8, (vostok::resources::unmanaged_resource *)(v7 + 288));
    survarium::game_world_ui::show_quick_slots((survarium::game_world_ui *)v8, 0);
  }
  if ( id.m_object && !_InterlockedExchangeAdd(&id.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    if ( id.m_object )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &id.m_object->vostok::resources::unmanaged_intrusive_base,
        &id.m_object->vostok::resources::unmanaged_resource);
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}
