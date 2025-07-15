void __usercall survarium::stamina_sound_effect::~stamina_sound_effect(
        survarium::stamina_sound_effect *this@<ecx>,
        int a2@<edi>)
{
  int v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  survarium::base_player *v4; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(void)> v6; // [esp+8h] [ebp-20h] BYREF

  v2 = *(_DWORD *)(a2 + 40);
  v6.vtable = 0;
  boost::function<void __cdecl (void)>::operator=(
    &v6,
    (boost::function1<void,vostok::physics::contact_point const &> *)(v2 + 69832));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v6);
  survarium::base_player::unsubscribe_from_player_death(
    v4,
    *(_DWORD *)(a2 + 40),
    (survarium::player_death_subscriber *)(a2 + 48));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v5,
    (int *)(a2 + 48));
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *)(a2 + 24));
  `vector destructor iterator'(
    (char *)a2,
    4u,
    6,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
}
