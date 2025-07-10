void __thiscall survarium::game_world::on_portal_system_loaded(
        survarium::game_world *this,
        vostok::configs::binary_config *data)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v3; // ebx
  vostok::resources::unmanaged_resource *v4; // ebp
  vostok::configs::binary_config *m_object; // esi
  vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *p_m_portal_sector_structure; // ecx
  vostok::configs::binary_config *v7; // eax
  vostok::resources::unmanaged_resource *v8; // edx
  vostok::configs::binary_config *v9; // eax
  vostok::resources::unmanaged_intrusive_base *v10; // ecx
  vostok::configs::binary_config *v11; // eax
  vostok::resources::unmanaged_intrusive_base *v12; // ecx
  vostok::sound::world_user *v13; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *v14; // [esp-Ch] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v15; // [esp-4h] [ebp-24h]
  vostok::render::base_scene *v16; // [esp-4h] [ebp-24h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v17; // [esp+10h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v18; // [esp+14h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+18h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *graph; // [esp+1Ch] [ebp-4h]

  if ( data->m_parent_resources.m_lock == 1 )
  {
    v3 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&data[1].m_reconstruction_size + 1);
    v15 = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)(&data[1].m_reconstruction_size + 1);
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v15);
    v4 = data;
    v19.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v19,
      data);
    m_object = v19.m_object;
    p_m_portal_sector_structure = &this->m_portal_sector_structure;
    v7 = 0;
    graph = &this->m_portal_sector_structure;
    if ( v19.m_object )
    {
      v7 = v19.m_object;
      _InterlockedExchangeAdd(&v19.m_object->m_reference_count, 1u);
      p_m_portal_sector_structure = graph;
    }
    v8 = p_m_portal_sector_structure->m_object;
    p_m_portal_sector_structure->m_object = (vostok::render::culling::portal_sector_structure *)v7;
    if ( v8 )
    {
      if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
      v4 = data;
    }
    if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &m_object->vostok::resources::unmanaged_intrusive_base,
        m_object);
    if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
    v16 = this->m_render_scene.m_object;
    v18.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v18,
      (vostok::configs::binary_config *)v16);
    v17.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v17,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3);
    vostok::render::scene_renderer::set_portal_system(
      (vostok::render::scene_renderer *)this->m_game,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game->m_renderer->m_scene,
      (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v18);
    v9 = v17.m_object;
    if ( v17.m_object )
    {
      v10 = &v17.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v17.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v10, v9);
    }
    v11 = v18.m_object;
    if ( v18.m_object )
    {
      v12 = &v18.m_object->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v18.m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v12, v11);
    }
    if ( this->m_sound_scene.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v14 = (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)graph;
        v13 = this->m_game->m_sound_world->get_logic_world_user(this->m_game->m_sound_world);
        vostok::sound::world_user::set_active_sound_scene(v13, &this->m_sound_scene, v14, 0, 0);
      }
    }
  }
}
