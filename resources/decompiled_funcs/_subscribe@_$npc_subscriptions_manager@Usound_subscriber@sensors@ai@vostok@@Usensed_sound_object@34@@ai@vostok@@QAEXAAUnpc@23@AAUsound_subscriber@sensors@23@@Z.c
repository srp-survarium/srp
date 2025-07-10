void __thiscall vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object>::subscribe(
        vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::damage_subscriber,vostok::ai::sensed_hit_object> *this,
        vostok::ai::npc *npc,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  vostok::threading::mutex *v3; // ecx
  vostok::threading::mutex *v4; // ecx
  vostok::threading::mutex *v5; // ecx
  vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> other; // [esp+1Ch] [ebp-D0h] BYREF
  vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_other; // [esp+4Ch] [ebp-A0h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v9[2]; // [esp+50h] [ebp-9Ch] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10; // [esp+58h] [ebp-94h]
  vostok::ai::npc *v11; // [esp+5Ch] [ebp-90h]
  vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> v12; // [esp+64h] [ebp-88h] BYREF
  stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > __val; // [esp+9Ch] [ebp-50h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v14; // [esp+D4h] [ebp-18h] BYREF
  char *__k; // [esp+DCh] [ebp-10h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > >,bool> result; // [esp+E0h] [ebp-Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> > > > it_subscriber; // [esp+E8h] [ebp-4h] BYREF

  __k = (char *)npc;
  v10 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int>>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int>>>::_M_find<char const *>(
                                                                      (stlp_std::priv::_Rb_tree<char const *,stlp_std::less<char const *>,stlp_std::pair<char const * const,unsigned int>,stlp_std::priv::_Select1st<stlp_std::pair<char const * const,unsigned int> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<char const * const,unsigned int> >,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)this,
                                                                      (const char *const *)&__k);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v10,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&it_subscriber);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)this,
    &v14);
  v9[1] = (boost::_bi::list1<vostok::network_core::packet_reader &> *)v9;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v14,
    v9);
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)it_subscriber._M_node == v9[0] )
  {
    p_other = &other;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)((boost::_bi::list1<vostok::network_core::packet_reader &> *)it_subscriber._M_node == v9[0]),
      &other);
    vostok::threading::mutex::mutex(&p_other->vostok::threading::mutex);
    p_other->m_first = 0;
    p_other->m_last = 0;
    v11 = npc;
    vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
      &v12,
      &other);
    vostok::threading::mutex::~mutex(v3, (_RTL_CRITICAL_SECTION *)&other.vostok::threading::mutex);
    __val.first = v11;
    vostok::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::intrusive_list<vostok::ai::sensors::damage_subscriber,vostok::ai::sensors::damage_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>(
      &__val.second,
      &v12);
    stlp_std::priv::_Rb_tree<vostok::ai::npc *,stlp_std::less<vostok::ai::npc *>,stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::ai::npc * const,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::insert_unique(
      &this->m_subscribers._M_t,
      &result,
      &__val);
    vostok::threading::mutex::~mutex(v4, (_RTL_CRITICAL_SECTION *)&__val.second.vostok::threading::mutex);
    vostok::threading::mutex::~mutex(v5, (_RTL_CRITICAL_SECTION *)&v12.vostok::threading::mutex);
    it_subscriber._M_node = result.first._M_node;
  }
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&it_subscriber._M_node[1]._M_left,
    subscriber,
    0);
}
