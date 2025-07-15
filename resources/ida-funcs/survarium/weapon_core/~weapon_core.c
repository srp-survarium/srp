void __usercall survarium::weapon_core::~weapon_core(survarium::weapon_core *this@<ecx>, int a2@<edi>)
{
  int v2; // eax
  int v3; // eax
  survarium::breath_vibration_calculator *v4; // ecx
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // [esp-4h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+4h] [ebp-Ch]
  unsigned int v9; // [esp+8h] [ebp-8h]

  *(_DWORD *)a2 = &survarium::weapon_core::`vftable'{for `survarium::interactive_object'};
  *(_DWORD *)(a2 + 16) = &survarium::weapon_core::`vftable'{for `survarium::inventory_item'};
  v2 = *(_DWORD *)(a2 + 1096);
  if ( v2 )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)survarium::g_allocator,
      (char *)(v2 - 8),
      v7,
      v8,
      v9);
  if ( *(_DWORD *)(a2 + 1044) )
  {
    v3 = *(_DWORD *)(a2 + 1044);
    if ( v3 )
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)survarium::g_allocator,
        (char *)(v3 - 8),
        v7,
        v8,
        v9);
  }
  vostok::ai::fsm::clear_transitions((vostok::ai::fsm *)this, *(_DWORD *)(a2 + 408));
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::ai::fsm>(
    survarium::g_allocator,
    (vostok::ai::fsm **)(a2 + 408));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v6,
    (int *)(a2 + 1000));
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 988));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 976));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 972));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 968));
  `vector destructor iterator'(
    (char *)(a2 + 872),
    4u,
    24,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  for ( i = *(vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 412);
        i != *(vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 416);
        ++i )
  {
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  *(_DWORD *)(a2 + 416) = *(_DWORD *)(a2 + 412);
  survarium::breath_vibration_calculator::~breath_vibration_calculator(v4, a2 + 312);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 16));
}
