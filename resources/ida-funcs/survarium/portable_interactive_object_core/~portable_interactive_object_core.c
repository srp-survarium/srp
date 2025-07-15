void __thiscall survarium::portable_interactive_object_core::~portable_interactive_object_core(
        survarium::portable_interactive_object_core *this,
        int a2)
{
  survarium::weapon_user_animations_selector *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // [esp-4h] [ebp-10h]

  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::legs_ik_drawer>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 344),
    &vostok::memory::g_resources_unmanaged_allocator);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)(a2 + 288));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 280));
  survarium::weapon_user_animations_selector::~weapon_user_animations_selector(v2, a2 + 8);
}
