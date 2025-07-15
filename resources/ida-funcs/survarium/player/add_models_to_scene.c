void __thiscall survarium::player::add_models_to_scene(
        survarium::player *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::render::scene_renderer *v3; // ecx
  vostok::render::scene_renderer *v4; // ecx
  vostok::render::scene_renderer *v5; // ecx
  vostok::render::scene_renderer *v6; // ecx
  vostok::render::scene_renderer *v7; // ecx
  vostok::render::scene_renderer *v8; // ecx
  vostok::render::scene_renderer *v9; // ecx

  m_object = a2.m_object;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(int *)((char *)&dword_11410 + (unsigned int)a2.m_object) + 4));
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*(vostok::particle::particle_system_instance_impl_vtbl **)((char *)&m_object->__vftable + (_DWORD)&loc_1119E + 2))[8].link_child_resource,
    *(vostok::render::scene_renderer **)((char *)&dword_200060
                                       + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)m_object) + 160)
                                                   + 172)),
    &a2,
    (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)m_object],
    (const vostok::math::float4x4 *)&byte_10E2C[(_DWORD)m_object]);
  if ( m_object[89].m_lods[0].m_emitter_instance_list.m_first
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    vostok::render::scene_renderer::append_model_material(
      v3,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)m_object) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*(vostok::particle::particle_system_instance_impl_vtbl **)((char *)&m_object->__vftable + (_DWORD)&loc_1119E + 2))[8].link_child_resource,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&m_object[89].m_lods[0].m_emitter_instance_list.m_first,
      0);
    vostok::render::scene_renderer::append_model_material(
      v4,
      *(boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> const &,unsigned int>,boost::_bi::list4<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<unsigned int> > > **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + (_DWORD)m_object) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&(*(vostok::particle::particle_system_instance_impl_vtbl **)((char *)&m_object->__vftable + (_DWORD)&loc_1119E + 2))[8].link_child_resource,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&m_object[89].m_lods[0].m_emitter_instance_list.m_first,
      (boost::_bi::value<vostok::render::engine::world *> *)1);
    vostok::render::scene_renderer::register_material_parameter(
      v5,
      *(vostok::render::material_parameter_host **)((char *)&dword_200060
                                                  + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410
                                                                                   + (_DWORD)m_object)
                                                                          + 160)
                                                              + 172)),
      *(int *)((char *)&dword_11420 + (_DWORD)m_object));
    vostok::render::scene_renderer::register_material_parameter(
      v6,
      *(vostok::render::material_parameter_host **)((char *)&dword_200060
                                                  + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410
                                                                                   + (_DWORD)m_object)
                                                                          + 160)
                                                              + 172)),
      *(int *)((char *)&m_object->__vftable + (_DWORD)&loc_11427 + 1));
    vostok::render::scene_renderer::register_material_parameter(
      v7,
      *(vostok::render::material_parameter_host **)((char *)&dword_200060
                                                  + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410
                                                                                   + (_DWORD)m_object)
                                                                          + 160)
                                                              + 172)),
      *(_DWORD *)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
                + (_DWORD)m_object));
    vostok::render::scene_renderer::register_material_parameter(
      v8,
      *(vostok::render::material_parameter_host **)((char *)&dword_200060
                                                  + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410
                                                                                   + (_DWORD)m_object)
                                                                          + 160)
                                                              + 172)),
      *(_DWORD *)((char *)&loc_1142C + (_DWORD)m_object));
    vostok::render::scene_renderer::register_material_parameter(
      v9,
      *(vostok::render::material_parameter_host **)((char *)&dword_200060
                                                  + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410
                                                                                   + (_DWORD)m_object)
                                                                          + 160)
                                                              + 172)),
      *(int *)((char *)&m_object->__vftable + (_DWORD)&loc_1142E + 2));
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
}
