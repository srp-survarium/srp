void __thiscall survarium::profile_player_character::on_player_ready(
        survarium::profile_player_character *this,
        vostok::resources::queries_result *data,
        survarium::player_profile *profile_to_cook)
{
  char *v3; // eax
  malloc_state *v5; // esi
  survarium::player *m_object; // eax
  vostok::resources::unmanaged_resource *v7; // ebp
  volatile signed __int32 *p_id; // eax
  survarium::player *v9; // esi
  survarium::player *v10; // eax
  survarium::player *v11; // ecx
  survarium::player *v12; // eax
  survarium::player *v13; // eax
  vostok::math::float3 position; // [esp+18h] [ebp-Ch] BYREF

  v3 = (char *)profile_to_cook;
  if ( profile_to_cook )
  {
    v5 = *(malloc_state **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v5, v3);
  }
  if ( this->m_player.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::player::remove(
      (survarium::player *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      (int)this->m_player.m_object);
  }
  m_object = this->m_player.m_object;
  this->m_player.m_object = 0;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      &m_object->vostok::resources::unmanaged_resource);
  profile_to_cook = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&profile_to_cook,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  v7 = (vostok::resources::unmanaged_resource *)profile_to_cook;
  if ( profile_to_cook )
    p_id = (volatile signed __int32 *)&profile_to_cook[-1].slots[1].item.id;
  else
    p_id = 0;
  v9 = 0;
  if ( p_id )
  {
    v9 = (survarium::player *)p_id;
    _InterlockedExchangeAdd(p_id + 124, 1u);
  }
  v10 = 0;
  if ( v9 )
  {
    v10 = v9;
    _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
  }
  v11 = v10;
  v12 = this->m_player.m_object;
  this->m_player.m_object = v11;
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v12->vostok::resources::unmanaged_intrusive_base,
      &v12->vostok::resources::unmanaged_resource);
  if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &v9->vostok::resources::unmanaged_intrusive_base,
      &v9->vostok::resources::unmanaged_resource);
  if ( v7 && !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
  v13 = this->m_player.m_object;
  *(_QWORD *)&position.x = 0xBE4CCCCD00000000uLL;
  position.z = 0.0;
  survarium::player::set_character_transform(&position, v13, COERCE_VOSTOK_MATH_FLOAT4X4_(3.1415927), 0.0);
  survarium::player::insert(this->m_player.m_object, this->m_player.m_object, 1);
}
