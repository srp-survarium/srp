void __thiscall survarium::damage_model::~damage_model(survarium::damage_model *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::booster_damage_protector *p; // [esp+2Ch] [ebp-4h] BYREF

  this->__vftable = (survarium::damage_model_vtbl *)&survarium::damage_model::`vftable';
  while ( 1 )
  {
    p = vostok::intrusive_list<survarium::booster_damage_protector,survarium::booster_damage_protector *,104,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&this->m_damage_protectors);
    if ( !p )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::inventory,vostok::memory::detail::call_destructor_predicate>(
      v2,
      (vostok::sound::sound_scene **)&p);
  }
  survarium::damage_model::unsubscribe_from_affect(
    this,
    affects_type_leg_damage,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_leg_damaged_subscriber);
  survarium::damage_model::unsubscribe_from_affect(
    this,
    affects_type_hand_damage,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_hand_damaged_subscriber);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v3,
    (int *)&this->m_hand_damaged_subscriber);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (int *)&this->m_leg_damaged_subscriber);
  survarium::weapon_user_dead_state::finalize(v5);
  `vector destructor iterator'(
    (char *)&this->m_affect_subscriptions,
    0x30u,
    9,
    (void (__thiscall *)(void *))vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::~intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>);
  survarium::weapon_user_dead_state::finalize(v6);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_body_parts);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
