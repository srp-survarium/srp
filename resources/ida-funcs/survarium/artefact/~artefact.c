void __thiscall survarium::artefact<survarium::artefact_lifebone_core>::~artefact<survarium::artefact_lifebone_core>(
        survarium::artefact<survarium::artefact_lifebone_core> *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_world; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax

  m_game_world = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_world;
  this->survarium::artefact_lifebone_core::survarium::artefact_base::survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact<survarium::artefact_lifebone_core>_vtbl *)&survarium::artefact<survarium::artefact_lifebone_core>::`vftable'{for `survarium::artefact_lifebone_core'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::artefact<survarium::artefact_lifebone_core>::`vftable'{for `survarium::drawable_object'};
  if ( m_game_world
    && m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    p_m_render_model = &this->m_model.m_object->m_render_model;
    if ( p_m_render_model->m_object->m_in_scene )
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_world[40].m_object->m_fat_it.m_type),
        m_game_world + 1);
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_on_spawn);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  survarium::artefact_lifebone_core::~artefact_lifebone_core(this);
}


void __thiscall survarium::artefact<survarium::artefact_onyx_core>::~artefact<survarium::artefact_onyx_core>(
        survarium::artefact<survarium::artefact_onyx_core> *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_world; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax
  survarium::artefact_onyx_core *v4; // ecx

  m_game_world = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_world;
  this->survarium::artefact_onyx_core::survarium::artefact_base::survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact<survarium::artefact_onyx_core>_vtbl *)&survarium::artefact<survarium::artefact_onyx_core>::`vftable'{for `survarium::artefact_onyx_core'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::artefact<survarium::artefact_onyx_core>::`vftable'{for `survarium::drawable_object'};
  if ( m_game_world
    && m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    p_m_render_model = &this->m_model.m_object->m_render_model;
    if ( p_m_render_model->m_object->m_in_scene )
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_world[40].m_object->m_fat_it.m_type),
        m_game_world + 1);
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_on_spawn);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  survarium::artefact_onyx_core::~artefact_onyx_core(v4, (int)this);
}


void __thiscall survarium::artefact<survarium::artefact_rattle_core>::~artefact<survarium::artefact_rattle_core>(
        survarium::artefact<survarium::artefact_rattle_core> *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_world; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax
  survarium::artefact_base *v4; // ecx

  m_game_world = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_world;
  this->survarium::artefact_rattle_core::survarium::artefact_base::survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact<survarium::artefact_rattle_core>_vtbl *)&survarium::artefact<survarium::artefact_rattle_core>::`vftable'{for `survarium::artefact_rattle_core'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::artefact<survarium::artefact_rattle_core>::`vftable'{for `survarium::drawable_object'};
  if ( m_game_world
    && m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    p_m_render_model = &this->m_model.m_object->m_render_model;
    if ( p_m_render_model->m_object->m_in_scene )
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_world[40].m_object->m_fat_it.m_type),
        m_game_world + 1);
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_on_spawn);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  survarium::artefact_base::~artefact_base(v4, (int)this);
}


void __thiscall survarium::artefact<survarium::artefact_spring_core>::~artefact<survarium::artefact_spring_core>(
        survarium::artefact<survarium::artefact_spring_core> *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_game_world; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // eax
  survarium::artefact_base *v4; // ecx

  m_game_world = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this->m_game_world;
  this->survarium::artefact_spring_core::survarium::artefact_base::survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact<survarium::artefact_spring_core>_vtbl *)&survarium::artefact<survarium::artefact_spring_core>::`vftable'{for `survarium::artefact_spring_core'};
  this->survarium::drawable_object::__vftable = (survarium::drawable_object_vtbl *)&survarium::artefact<survarium::artefact_spring_core>::`vftable'{for `survarium::drawable_object'};
  if ( m_game_world
    && m_game_world[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    p_m_render_model = &this->m_model.m_object->m_render_model;
    if ( p_m_render_model->m_object->m_in_scene )
      vostok::render::scene_renderer::remove_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + m_game_world[40].m_object->m_fat_it.m_type),
        m_game_world + 1);
    vostok::render::scene_renderer::remove_particle_system_instance(
      (vostok::render::scene_renderer *)&this->m_game_world->m_render_scene,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
      (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&this->m_particle_on_spawn);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_particle_on_spawn);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model);
  survarium::artefact_base::~artefact_base(v4, (int)this);
}
