void __usercall survarium::damage_model::~damage_model(survarium::damage_model *this@<ecx>, int a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx

  *(_DWORD *)a2 = &survarium::damage_model::`vftable';
  survarium::damage_model::unsubscribe_from_affect(
    (survarium::damage_model *)a2,
    affects_type_leg_damage,
    (survarium::affect_subscriber *const)(a2 + 1664));
  survarium::damage_model::unsubscribe_from_affect(
    (survarium::damage_model *)a2,
    affects_type_hand_damage,
    (survarium::affect_subscriber *const)(a2 + 1704));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)(a2 + 1704));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)(a2 + 1664));
  survarium::damage_protector::~damage_protector((survarium::damage_protector *)(a2 + 1528));
  `vector destructor iterator'(
    (char *)(a2 + 1144),
    0x30u,
    8,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  `vector destructor iterator'(
    (char *)(a2 + 712),
    0x30u,
    9,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  `vector destructor iterator'(
    (char *)(a2 + 280),
    0x30u,
    9,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
