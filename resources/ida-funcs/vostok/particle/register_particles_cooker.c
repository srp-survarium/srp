void __usercall vostok::particle::register_particles_cooker(
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> a1@<esi>,
        vostok::memory::base_allocator *allocator)
{
  if ( !particles_cooker_registered )
  {
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x3E,
      (vostok::resources::cook_base *)&vostok::particle::s_particle_cook_object,
      reuse_false,
      0xFFFFFFFD,
      0,
      a1);
    *(_DWORD *)&vostok::particle::s_particle_cook_object.m_static_memory[32] = allocator;
    *(_DWORD *)vostok::particle::s_particle_cook_object.m_static_memory = &vostok::particle::particle_system_instance_cook::`vftable';
    _InterlockedExchange(&vostok::particle::s_particle_cook_object.m_initialized, 1);
    vostok::resources::resources_manager::register_cook(
      vostok::particle::s_particle_cook_object.m_variable,
      (vostok::buffer_vector<vostok::resources::cook_base *> *)&vostok::particle::s_particle_cook_object.m_initialized);
    particles_cooker_registered = 1;
  }
}
