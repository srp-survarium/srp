void __usercall vostok::render::one_way_render_channel::render_on_end_frame(
        vostok::render::one_way_render_channel *this@<ecx>,
        vostok::render::one_way_render_channel *a2@<edi>)
{
  vostok::render::base_scene_view *m_object; // eax
  vostok::resources::unmanaged_resource *v3; // esi
  volatile int m_flags; // ecx
  vostok::render::base_scene_view *v5; // eax
  vostok::resources::unmanaged_resource *v6; // edx
  vostok::resources::unmanaged_resource *v7; // eax
  vostok::render::base_scene_view *v8; // eax
  vostok::resources::unmanaged_resource *v9; // esi
  volatile int v10; // ecx
  vostok::render::base_scene_view *v11; // eax
  vostok::resources::unmanaged_resource *v12; // edx
  vostok::resources::unmanaged_resource *v13; // eax
  vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> i; // [esp+8h] [ebp-4h] BYREF

  m_object = (vostok::render::base_scene_view *)a2->m_scenes.m_object;
  v3 = 0;
  i.m_object = 0;
  if ( m_object )
  {
    v3 = m_object;
    i.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  while ( v3 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
      break;
    }
    vostok::render::one_way_render_channel::move_commands_from_list<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>(
      a2,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&i);
    m_flags = v3[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    v5 = 0;
    if ( m_flags )
    {
      v5 = (vostok::render::base_scene_view *)v3[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      _InterlockedExchangeAdd((volatile signed __int32 *)(m_flags + 208), 1u);
    }
    v6 = v3;
    v3 = v5;
    i.m_object = v5;
    if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  }
  v7 = a2->m_scenes.m_object;
  a2->m_scenes.m_object = 0;
  if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  v8 = a2->m_scene_views.m_object;
  v9 = 0;
  i.m_object = 0;
  if ( v8 )
  {
    v9 = v8;
    i.m_object = v8;
    _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
  }
  while ( v9 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
      break;
    }
    vostok::render::one_way_render_channel::move_commands_from_list<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>(
      a2,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)&i);
    v10 = v9[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    v11 = 0;
    if ( v10 )
    {
      v11 = (vostok::render::base_scene_view *)v9[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
      _InterlockedExchangeAdd((volatile signed __int32 *)(v10 + 208), 1u);
    }
    v12 = v9;
    v9 = v11;
    i.m_object = v11;
    if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
  }
  v13 = a2->m_scene_views.m_object;
  a2->m_scene_views.m_object = 0;
  if ( v13 && !_InterlockedExchangeAdd(&v13->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v13->vostok::resources::unmanaged_intrusive_base, v13);
  ++a2->m_current_frame_id;
}
