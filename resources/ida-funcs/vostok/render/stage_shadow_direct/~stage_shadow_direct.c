void __usercall vostok::render::stage_shadow_direct::~stage_shadow_direct(
        vostok::render::stage_shadow_direct *this@<ecx>,
        int a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx

  *(_DWORD *)a2 = &vostok::render::stage_shadow_direct::`vftable';
  `vector destructor iterator'(
    (char *)&loc_40C0C + a2,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  `vector destructor iterator'(
    (char *)&loc_40BF9 + a2 + 3,
    4u,
    4,
    (void (__thiscall *)(void *))vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_40174 + a2));
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_4016F + a2 + 1));
  `vector destructor iterator'(
    (char *)(a2 + 196900),
    0x400Cu,
    4,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::caster_model,2048>::~fixed_vector<vostok::render::caster_model,2048>);
  `vector destructor iterator'(
    (char *)(a2 + 131316),
    0x400Cu,
    4,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::caster_model,2048>::~fixed_vector<vostok::render::caster_model,2048>);
  `vector destructor iterator'(
    (char *)(a2 + 65732),
    0x400Cu,
    4,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::caster_model,2048>::~fixed_vector<vostok::render::caster_model,2048>);
  `vector destructor iterator'(
    (char *)(a2 + 148),
    0x400Cu,
    4,
    (void (__thiscall *)(void *))vostok::fixed_vector<vostok::render::caster_model,2048>::~fixed_vector<vostok::render::caster_model,2048>);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)(a2 + 88));
  *(_DWORD *)a2 = &vostok::render::stage::`vftable';
}
