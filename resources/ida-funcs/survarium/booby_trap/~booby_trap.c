void __thiscall survarium::booby_trap::~booby_trap(survarium::booby_trap *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_world; // ecx
  vostok::render::static_model_instance *m_object; // eax

  m_game_world = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_world;
  this->survarium::booby_trap_core::survarium::hittable_object::survarium::hit_receiver::vostok::collision::game_object::__vftable = (survarium::booby_trap_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::hittable_object'};
  this->survarium::booby_trap_core::survarium::collision_sensor::survarium::collision_geometry_subscriber::__vftable = (survarium::collision_sensor_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::collision_sensor'};
  this->survarium::booby_trap_core::survarium::collision_sensor::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::collision_sensor'};
  this->survarium::booby_trap_core::survarium::usable_object::survarium::collision_geometry_subscriber::__vftable = (survarium::usable_object_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::collision_geometry_subscriber's `survarium::usable_object'};
  this->survarium::booby_trap_core::survarium::usable_object::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::link_resolver's `survarium::usable_object'};
  this->survarium::booby_trap_core::survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::tickable_object'};
  this->survarium::booby_trap_core::survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::booby_trap::`vftable'{for `survarium::serializable_object'};
  this->survarium::booby_trap_core::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::booby_trap::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::booby_trap::`vftable';
  if ( m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object = this->m_models[this->m_current_drawable_state].m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_world[40].m_object->m_fat_it.m_type),
        m_game_world + 1);
    }
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_fired);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_fired);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_fired);
  `vector destructor iterator'(
    (char *)this->m_models,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  survarium::booby_trap_core::~booby_trap_core(this);
}
