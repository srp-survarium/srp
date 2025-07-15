void __thiscall vostok::particle::particle_system_instance_impl::prepare_render_resources(
        vostok::particle::particle_system_instance_impl *this)
{
  const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *v1; // eax
  int v2; // eax
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v4; // [esp+28h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> v5; // [esp+2Ch] [ebp-10h] BYREF
  vostok::particle::lod_entry *e; // [esp+30h] [ebp-Ch]
  vostok::particle::particle_emitter_instance *instance; // [esp+34h] [ebp-8h]
  unsigned int i; // [esp+38h] [ebp-4h]

  v1 = (const vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)this->m_particle_world->m_engine->get_scene(this->m_particle_world->m_engine, &v5, this->m_particle_world);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base> *)&this->m_scene,
    v1);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v5);
  for ( i = 0; i < 0xA; ++i )
  {
    e = &this->m_lods[i];
    if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)e) )
      break;
    for ( instance = e->m_emitter_instance_list.m_first; instance; instance = instance->m_next )
    {
      instance->m_particle_world = this->m_particle_world;
      if ( !instance->m_render_instance )
      {
        v2 = ((int (__thiscall *)(vostok::particle::engine *, vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *, vostok::particle::particle_world *, vostok::particle::engine *))this->m_particle_world->m_engine->get_scene)(
               this->m_particle_world->m_engine,
               &v4,
               this->m_particle_world,
               this->m_particle_world->m_engine);
        ((void (__thiscall *)(vostok::particle::particle_emitter_instance *, int))instance->create_render_particle_emitter_instance)(
          instance,
          v2);
        vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(&v4);
      }
    }
  }
}
