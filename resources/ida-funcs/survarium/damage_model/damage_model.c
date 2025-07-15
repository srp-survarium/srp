void __thiscall survarium::damage_model::damage_model(survarium::damage_model *this, survarium::damage_model *model)
{
  boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *p_m_affect_subscriptions; // edi
  boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *p_m_all_affects_subscriptions; // edi
  vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_damage_subscriptions; // edi
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v6; // [esp-14h] [ebp-38h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3> > > v7; // [esp-14h] [ebp-38h]
  unsigned int v8; // [esp+1Ch] [ebp-8h]
  int modela; // [esp+2Ch] [ebp+8h]
  int modelb; // [esp+2Ch] [ebp+8h]
  int modelc; // [esp+2Ch] [ebp+8h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, model, fs_iterator_class);
  model->__vftable = (survarium::damage_model_vtbl *)&survarium::damage_model::`vftable';
  model->m_body_parts.m_size = 0;
  model->m_body_parts.m_first = 0;
  model->m_body_parts.m_last = 0;
  p_m_affect_subscriptions = &model->m_affect_subscriptions;
  for ( modela = 8; modela >= 0; --modela )
  {
    vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(p_m_affect_subscriptions->elems);
    p_m_affect_subscriptions = (boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *)((char *)p_m_affect_subscriptions + 48);
  }
  p_m_all_affects_subscriptions = &model->m_all_affects_subscriptions;
  for ( modelb = 8; modelb >= 0; --modelb )
  {
    vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(p_m_all_affects_subscriptions->elems);
    p_m_all_affects_subscriptions = (boost::array<vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,9> *)((char *)p_m_all_affects_subscriptions + 48);
  }
  p_m_damage_subscriptions = (vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&model->m_damage_subscriptions;
  for ( modelc = 7; modelc >= 0; --modelc )
    vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(p_m_damage_subscriptions++);
  survarium::anomaly_damage_protector::anomaly_damage_protector(model, &model->m_damage_protector);
  model->m_last_tick_time_in_ms = -1;
  model->m_invulnerability_time_in_ms = -1;
  model->m_invulnerability_attenuation = 0;
  model->m_leg_damaged_subscriber.subscription_callback.vtable = 0;
  model->m_leg_damaged_subscriber.next = 0;
  model->m_hand_damaged_subscriber.subscription_callback.vtable = 0;
  model->m_hand_damaged_subscriber.next = 0;
  model->m_owner = 0;
  model->m_broken_legs_count = 0;
  model->m_broken_hands_count = 0;
  model->m_medkit_actions_subscribers.m_first = 0;
  model->m_medkit_actions_subscribers.m_last = 0;
  HIDWORD(v6.f_.f_) = survarium::damage_model::on_broken_limb_affect;
  *(_QWORD *)&v6.l_.a1_.t_ = __PAIR64__((unsigned int)model, 0);
  LODWORD(v6.f_.f_) = &model->m_leg_damaged_subscriber;
  boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
    (boost::function<void __cdecl(char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)> *)survarium::damage_model::on_broken_limb_affect,
    v6,
    v8);
  HIDWORD(v7.f_.f_) = survarium::damage_model::on_broken_limb_affect;
  *(_QWORD *)&v7.l_.a1_.t_ = __PAIR64__((unsigned int)model, 0);
  LODWORD(v7.f_.f_) = &model->m_hand_damaged_subscriber;
  boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf3<void,survarium::damage_model,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum>,boost::_bi::list4<boost::_bi::value<survarium::damage_model *>,boost::arg<1>,boost::arg<2>,boost::arg<3>>>>(
    0,
    v7,
    v8);
  survarium::damage_model::subscribe_on_affect(model, affects_type_leg_damage, &model->m_leg_damaged_subscriber);
  survarium::damage_model::subscribe_on_affect(model, affects_type_hand_damage, &model->m_hand_damaged_subscriber);
}
