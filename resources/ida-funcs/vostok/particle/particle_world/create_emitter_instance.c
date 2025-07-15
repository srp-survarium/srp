void __usercall vostok::particle::particle_world::create_emitter_instance(
        vostok::memory::base_allocator *allocator@<esi>,
        vostok::particle::particle_emitter *emitter@<edi>,
        bool is_child_emitter_instance)
{
  vostok::particle::particle_action_data_type *pointer; // ecx
  char *v4; // eax
  vostok::memory::base_allocator *v5; // eax
  vostok::particle::particle_beam_emitter_instance *v6; // ecx
  char *v7; // eax
  vostok::memory::base_allocator *v8; // eax
  vostok::particle::particle_emitter_instance *v9; // ecx

  pointer = emitter->m_data_type_action.pointer;
  if ( pointer && pointer->get_data_type(pointer) == particle_data_type_beam )
  {
    v4 = type_info::raw_name(&vostok::particle::particle_beam_emitter_instance `RTTI Type Descriptor');
    v5 = (vostok::memory::base_allocator *)allocator->call_malloc(
                                             allocator,
                                             656,
                                             v4,
                                             "vostok::particle::particle_world::create_emitter_instance",
                                             ".\\particle_world.cpp",
                                             473);
    if ( v5 )
      vostok::particle::particle_beam_emitter_instance::particle_beam_emitter_instance(
        v6,
        v5,
        (vostok::particle::particle_emitter *)allocator,
        (int)emitter,
        is_child_emitter_instance);
  }
  else
  {
    v7 = type_info::raw_name(&vostok::particle::particle_emitter_instance `RTTI Type Descriptor');
    v8 = (vostok::memory::base_allocator *)allocator->call_malloc(
                                             allocator,
                                             568,
                                             v7,
                                             "vostok::particle::particle_world::create_emitter_instance",
                                             ".\\particle_world.cpp",
                                             475);
    if ( v8 )
      vostok::particle::particle_emitter_instance::particle_emitter_instance(
        v9,
        v8,
        (vostok::particle::particle_emitter *)allocator,
        (int)emitter,
        is_child_emitter_instance);
  }
}
