void __thiscall vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object>::unsubscribe(
        vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object> *this,
        vostok::ai::npc *npc,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  survarium::game_camera *v3; // ecx
  stlp_std::priv::_Rb_tree_node_base *v4; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > > v5; // [esp-4h] [ebp-58h] BYREF
  vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object> *thisa; // [esp+0h] [ebp-54h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v7[15]; // [esp+4h] [ebp-50h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v8; // [esp+40h] [ebp-14h]
  char v9; // [esp+4Bh] [ebp-9h]
  char *__k; // [esp+4Ch] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > > it_subscriber; // [esp+50h] [ebp-4h] BYREF

  thisa = this;
  __k = (char *)npc;
  v8 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_find<char const *>(
                                                                     (stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> >,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)this,
                                                                     (const char *const *)&__k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v8,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it_subscriber);
  v9 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&it_subscriber._M_node[1]._M_left,
    subscriber);
  v7[6] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&it_subscriber._M_node[1];
  if ( !it_subscriber._M_node[3]._M_right )
  {
    v7[5] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v7;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      (boost::_bi::list1<vostok::network_core::packet_reader &> *)it_subscriber._M_node,
      v7);
    v5._M_node = v4;
    v7[3] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)&v5;
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v7[0],
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v5);
    stlp_std::priv::_Rb_tree<vostok::ai::npc *,stlp_std::less<vostok::ai::npc *>,stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::erase(
      &thisa->m_subscribers._M_t,
      v5);
  }
}
