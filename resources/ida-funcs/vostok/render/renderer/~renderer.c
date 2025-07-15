void __thiscall vostok::render::renderer::~renderer(vostok::render::renderer *this, vostok::ai::fsm_state *pointer)
{
  vostok::ai::fsm_state *v2; // ebx
  unsigned int m_size; // eax
  vostok::ai::fsm_state **v4; // esi
  bool i; // zf
  vostok::render::statistics *v6; // ecx
  char *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // esi
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // esi
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // esi
  vostok::memory::doug_lea_allocator *v14; // ecx
  vostok::render::cloud_simulation *v15; // ecx
  vostok::memory::doug_lea_allocator *v16; // [esp-4h] [ebp-18h]
  vostok::render::statistics *v17; // [esp-4h] [ebp-18h]
  const char *v18; // [esp+0h] [ebp-14h]
  const char *v19; // [esp+0h] [ebp-14h]
  const char *v20; // [esp+0h] [ebp-14h]
  const char *v21; // [esp+0h] [ebp-14h]
  const char *v22; // [esp+0h] [ebp-14h]
  const char *v23; // [esp+0h] [ebp-14h]
  const char *v24; // [esp+4h] [ebp-10h]
  const char *v25; // [esp+4h] [ebp-10h]
  const char *v26; // [esp+4h] [ebp-10h]
  const char *v27; // [esp+4h] [ebp-10h]
  const char *v28; // [esp+4h] [ebp-10h]
  const char *v29; // [esp+4h] [ebp-10h]
  unsigned int v30; // [esp+8h] [ebp-Ch]
  unsigned int v31; // [esp+8h] [ebp-Ch]
  unsigned int v32; // [esp+8h] [ebp-Ch]
  unsigned int v33; // [esp+8h] [ebp-Ch]
  unsigned int v34; // [esp+8h] [ebp-Ch]
  unsigned int v35; // [esp+8h] [ebp-Ch]
  vostok::ai::fsm_state **v36; // [esp+10h] [ebp-4h]

  v2 = pointer;
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::shader_buffer>(
    vostok::render::g_allocator,
    (vostok::render::shader_buffer **)&pointer[7].transitions.gap4,
    v18,
    v24,
    v30);
  m_size = v2[7].transitions.m_size;
  if ( m_size )
    vostok::memory::doug_lea_allocator::free_impl(
      v16,
      (int)vostok::render::g_allocator,
      (char *)(m_size - 8),
      v19,
      v25,
      v31);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::event_query>(
    vostok::render::g_allocator,
    (vostok::render::event_query **)&v2[9],
    v19,
    v25,
    v31);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::event_query>(
    vostok::render::g_allocator,
    (vostok::render::event_query **)&v2[9].next,
    v20,
    v26,
    v32);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::event_query>(
    vostok::render::g_allocator,
    (vostok::render::event_query **)&v2[9].transitions,
    v21,
    v27,
    v33);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::event_query>(
    vostok::render::g_allocator,
    (vostok::render::event_query **)&v2[9].transitions.gap4,
    v22,
    v28,
    v34);
  v4 = (vostok::ai::fsm_state **)v2[14].transitions.m_size;
  v36 = *(vostok::ai::fsm_state ***)&v2[14].transitions.gap4;
  for ( i = v4 == v36; ; i = v4 == v36 )
  {
    v6 = v17;
    if ( i )
      break;
    pointer = *v4;
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      vostok::render::g_allocator,
      &pointer,
      v23,
      v29,
      v35);
    ++v4;
  }
  pointer = (vostok::ai::fsm_state *)vostok::render::g_allocator;
  if ( v2[20].transitions.m_last )
  {
    v7 = __RTCastToVoid((void **)&v2[20].transitions.m_last->predicate.vtable);
    ((void (__thiscall *)(vostok::ai::fsm_state_transition *, _DWORD))v2[20].transitions.m_last->predicate.vtable->manager)(
      v2[20].transitions.m_last,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v8, (int)pointer, v7, v23, v29, v35);
    v2[20].transitions.m_last = 0;
  }
  pointer = (vostok::ai::fsm_state *)vostok::render::g_allocator;
  if ( *(_DWORD *)&v2[20].transitions.gap4 )
  {
    v9 = __RTCastToVoid(*(void ***)&v2[20].transitions.gap4);
    (***(void (__thiscall ****)(_DWORD, _DWORD))&v2[20].transitions.gap4)(*(_DWORD *)&v2[20].transitions.gap4, 0);
    vostok::memory::doug_lea_allocator::free_impl(v10, (int)pointer, v9, v23, v29, v35);
    *(_DWORD *)&v2[20].transitions.gap4 = 0;
  }
  pointer = (vostok::ai::fsm_state *)vostok::render::g_allocator;
  if ( v2[20].transitions.m_size )
  {
    v11 = __RTCastToVoid((void **)v2[20].transitions.m_size);
    (**(void (__thiscall ***)(unsigned int, _DWORD))v2[20].transitions.m_size)(v2[20].transitions.m_size, 0);
    vostok::memory::doug_lea_allocator::free_impl(v12, (int)pointer, v11, v23, v29, v35);
    v2[20].transitions.m_size = 0;
  }
  pointer = (vostok::ai::fsm_state *)vostok::render::g_allocator;
  if ( v2[20].transitions.m_first )
  {
    v13 = __RTCastToVoid((void **)&v2[20].transitions.m_first->predicate.vtable);
    ((void (__thiscall *)(vostok::ai::fsm_state_transition *, _DWORD))v2[20].transitions.m_first->predicate.vtable->manager)(
      v2[20].transitions.m_first,
      0);
    vostok::memory::doug_lea_allocator::free_impl(v14, (int)pointer, v13, v23, v29, v35);
    v2[20].transitions.m_first = 0;
  }
  vostok::render::statistics::~statistics(v6);
  DeleteCriticalSection((LPCRITICAL_SECTION)&v2[31].transitions);
  vostok::render::cloud_simulation::~cloud_simulation(v15);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[26].transitions);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[26].next);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[26]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25].transitions.m_last);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25].transitions.m_first);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25].transitions.gap4);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25].transitions);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25].next);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[25]);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[24].transitions.m_last);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2[24].transitions.m_first);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[19].transitions.m_first);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v2[19].transitions.gap4);
  *(_DWORD *)&v2[14].transitions.gap4 = v2[14].transitions.m_size;
  `vector destructor iterator'(
    (char *)&v2[11],
    4u,
    4,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  `vector destructor iterator'(
    (char *)&v2[10].transitions,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  `vector destructor iterator'(
    (char *)&v2[9].transitions.m_first,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
}
