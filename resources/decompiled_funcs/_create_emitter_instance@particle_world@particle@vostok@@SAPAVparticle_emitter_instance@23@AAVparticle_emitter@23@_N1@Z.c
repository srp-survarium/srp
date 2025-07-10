vostok::particle::particle_emitter_instance *__cdecl vostok::particle::particle_world::create_emitter_instance(
        vostok::particle::particle_emitter *emitter,
        bool is_child_emitter_instance,
        bool need_query_material)
{
  vostok::particle::particle_action_data_type *pointer; // ecx
  vostok::memory::pthreads3_allocator *v4; // eax
  int v5; // eax
  vostok::memory::pthreads3_allocator *v7; // eax
  int v8; // eax
  _DWORD *v11; // [esp+8h] [ebp-20h]
  _DWORD *_Where; // [esp+10h] [ebp-18h]
  vostok::particle::particle_emitter_instance *v13; // [esp+1Ch] [ebp-Ch]
  vostok::particle::particle_beam_emitter_instance *v14; // [esp+20h] [ebp-8h]

  pointer = emitter->m_data_type_action.pointer;
  if ( pointer
    && emitter->m_data_type_action.pointer->get_data_type(emitter->m_data_type_action.pointer) == particle_data_type_beam )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
    _Where = vostok::memory::pthreads3_allocator::malloc_impl(v4, (char *)0x180);
    v14 = (vostok::particle::particle_beam_emitter_instance *)operator new(0x180u, _Where);
    if ( !v14 )
      return 0;
    vostok::particle::particle_beam_emitter_instance::particle_beam_emitter_instance(
      v14,
      emitter,
      is_child_emitter_instance,
      need_query_material);
    return (vostok::particle::particle_emitter_instance *)v5;
  }
  else
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)pointer);
    v11 = vostok::memory::pthreads3_allocator::malloc_impl(v7, (char *)0x128);
    v13 = (vostok::particle::particle_emitter_instance *)operator new(0x128u, v11);
    if ( !v13 )
      return 0;
    vostok::particle::particle_emitter_instance::particle_emitter_instance(
      v13,
      emitter,
      is_child_emitter_instance,
      need_query_material);
    return (vostok::particle::particle_emitter_instance *)v8;
  }
}
