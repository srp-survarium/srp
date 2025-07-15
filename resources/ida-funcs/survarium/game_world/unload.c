void __thiscall survarium::game_world::unload(
        survarium::game_world *this,
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> it_npc)
{
  survarium::human_npc *m_object; // ebp
  float m_current_satisfaction; // edi
  int v4; // ecx
  vostok::resources::unmanaged_intrusive_base *v5; // ecx
  survarium::human_npc *v6; // esi
  vostok::resources::unmanaged_intrusive_base *v7; // ecx
  survarium::human_npc *v8; // eax
  survarium::human_npc *v9; // edi
  survarium::human_npc *v10; // eax
  survarium::human_npc *v11; // ecx
  survarium::human_npc *v12; // eax
  survarium::affect_subscriber *next; // eax
  char *v14; // eax
  char *v15; // eax
  survarium::simple_game_project *v16; // ecx
  int outfit_id; // esi
  vostok::resources::unmanaged_resource *v18; // eax
  survarium::animation_space_graph *i; // esi
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *v20; // eax
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *v21; // ecx
  vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *v22; // esi
  int v23; // eax
  float y; // [esp-8h] [ebp-18h]

  m_object = it_npc.m_object;
  m_current_satisfaction = it_npc.m_object->m_current_satisfaction;
  y = it_npc.m_object->m_transform.i.y;
  *((_DWORD *)&it_npc.m_object->m_affects_subscription.next + 1) = 1;
  survarium::camera_director::switch_to_camera(
    (survarium::camera_director *)this,
    (survarium::camera_director *)LODWORD(m_current_satisfaction),
    (survarium::game_camera *)LODWORD(y),
    (const char *)&stru_96A440.m_inverted_view.lines[1]);
  v4 = *(_DWORD *)(LODWORD(m_object->m_last_fail_of_increasing_quality) + 952);
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 32))(v4);
  it_npc.m_object = 0;
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &it_npc,
    (const vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_affects_subscription.subscription_callback.functor.data
  + 2);
  v6 = it_npc.m_object;
  while ( v6 )
  {
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v5 = &v6->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v5, &v6->survarium::game_object_);
      break;
    }
    survarium::delete_weapons(&it_npc);
    v6->clear_resources(v6);
    v7 = &v6->vostok::resources::unmanaged_intrusive_base;
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    v8 = v6->next_npc.m_object;
    v9 = 0;
    if ( v8 )
    {
      v9 = v6->next_npc.m_object;
      _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
    }
    if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v7, &v6->survarium::game_object_);
    v10 = 0;
    if ( v9 )
    {
      v10 = v9;
      _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
    }
    v11 = v10;
    v12 = v6;
    v6 = v11;
    it_npc.m_object = v11;
    v5 = &v12->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, &v12->survarium::game_object_);
    if ( v9 )
    {
      v5 = &v9->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v5, &v9->survarium::game_object_);
    }
  }
  next = m_object->m_affects_subscription.next;
  m_object->m_affects_subscription.next = 0;
  if ( next )
  {
    v5 = (vostok::resources::unmanaged_intrusive_base *)(&next[6].subscription_callback.functor.data + 8);
    if ( !_InterlockedExchangeAdd(
            (volatile signed __int32 *)&next[6].subscription_callback.functor.vostok_pointer_size_alignment[2],
            0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        v5,
        (vostok::resources::unmanaged_resource *)&next[1].subscription_callback.functor);
  }
  m_object->m_sound_produced = 0;
  v14 = (char *)m_object->m_affects_subscription.subscription_callback.functor.vostok_pointer_size_alignment[2];
  m_object->m_affects_subscription.subscription_callback.functor.vostok_pointer_size_alignment[2] = 0;
  if ( v14 )
  {
    v5 = (vostok::resources::unmanaged_intrusive_base *)(v14 + 256);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v14 + 64, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, (vostok::resources::unmanaged_resource *)(v14 + 48));
  }
  v15 = (char *)m_object->m_affects_subscription.subscription_callback.functor.vostok_pointer_size_alignment[3];
  m_object->m_affects_subscription.subscription_callback.functor.vostok_pointer_size_alignment[3] = 0;
  if ( v15 )
  {
    v5 = (vostok::resources::unmanaged_intrusive_base *)(v15 + 256);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)v15 + 64, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v5, (vostok::resources::unmanaged_resource *)(v15 + 48));
  }
  m_object->m_affects_subscription.subscription_callback.functor.obj_ptr = 0;
  survarium::camera_director::switch_to_camera(
    (survarium::camera_director *)v5,
    (survarium::camera_director *)LODWORD(m_object->m_current_satisfaction),
    0,
    (const char *)&stru_96A440.m_projection.lines[0].elements[1]);
  outfit_id = m_object->m_game_attributes.outfit_id;
  if ( outfit_id )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( *(_BYTE *)(outfit_id + 436) )
      {
        survarium::simple_game_project::remove(v16, outfit_id);
        v18 = (vostok::resources::unmanaged_resource *)m_object->m_game_attributes.outfit_id;
        m_object->m_game_attributes.outfit_id = 0;
        if ( v18 )
        {
          if ( !_InterlockedExchangeAdd(&v18->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(&v18->vostok::resources::unmanaged_intrusive_base, v18);
        }
      }
    }
  }
  for ( i = (survarium::animation_space_graph *)m_object->m_default_animation.m_object;
        i != m_object->m_animation_space_graph.m_object;
        i = (survarium::animation_space_graph *)((char *)i + 4) )
  {
    if ( LOBYTE(i->__vftable[13].~vostok::resources::resource_base) )
      (*((void (__thiscall **)(survarium::animation_space_graph_vtbl *))i->~vostok::resources::resource_base + 12))(i->__vftable);
  }
  v20 = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)m_object->m_animation_space_graph.m_object;
  v21 = (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)m_object->m_default_animation.m_object;
  if ( v21 != v20 )
  {
    v22 = stlp_std::priv::__copy<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *,int>(
            v20,
            v21,
            (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)m_object->m_animation_space_graph.m_object);
    stlp_std::__destroy_range_aux<vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base>>(
      v22,
      (vostok::resources::resource_ptr<survarium::victory_item,vostok::resources::unmanaged_intrusive_base> *)m_object->m_animation_space_graph.m_object);
    m_object->m_animation_space_graph.m_object = (survarium::animation_space_graph *)v22;
  }
  v23 = *(_DWORD *)&m_object->m_game_attributes.name.m_buffer[12];
  if ( v23 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*(_DWORD *)(v23 + 264) + 4) + 88))(
        *(_DWORD *)(*(_DWORD *)(v23 + 264) + 4),
        1);
    *(_WORD *)&m_object->m_game_attributes.description.m_buffer[12] = 0;
  }
  else
  {
    *(_WORD *)&m_object->m_game_attributes.description.m_buffer[12] = 0;
  }
}
