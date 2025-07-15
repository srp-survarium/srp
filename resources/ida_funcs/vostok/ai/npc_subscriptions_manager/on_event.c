void __thiscall vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object>::on_event(
        vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object> *this,
        vostok::ai::npc *npc,
        const vostok::ai::sensed_sound_object *parameter)
{
  survarium::game_camera *v3; // ecx
  vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_M_left; // [esp+4h] [ebp-40h]
  vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::subscribers_callback_predicate<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object> > pred; // [esp+1Ch] [ebp-28h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v6; // [esp+20h] [ebp-24h]
  char v7; // [esp+37h] [ebp-Dh]
  char *__k; // [esp+38h] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > > it_subscriber; // [esp+3Ch] [ebp-8h] BYREF
  vostok::ai::npc_subscribers_callback_predicate<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object> callback_predicate; // [esp+40h] [ebp-4h] BYREF

  __k = (char *)npc;
  v6 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_find<char const *>(
                                                                     (stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> >,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)this,
                                                                     (const char *const *)&__k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v6,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it_subscriber);
  v7 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&callback_predicate);
  callback_predicate.m_parameter = parameter;
  p_M_left = (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&it_subscriber._M_node[1]._M_left;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  pred.m_predicate_ref = (vostok::ai::subscribers_callback_predicate<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object> *)&callback_predicate;
  vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::npc_subscribers_callback_predicate<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object>>>(
    p_M_left,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&callback_predicate);
}
