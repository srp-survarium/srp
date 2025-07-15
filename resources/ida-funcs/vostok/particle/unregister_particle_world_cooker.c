void __cdecl vostok::particle::unregister_particle_world_cooker()
{
  if ( !cooker_unregistered )
  {
    vostok::resources::unregister_cook(particle_world_class);
    vostok::uninitialized_reference<vostok::particle::particle_world_cooker>::destroy(&vostok::particle::s_particle_world_cooker_object);
    cooker_unregistered = 1;
  }
}
