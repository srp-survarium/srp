void __thiscall survarium::player_logic_sprint_state::finalize(survarium::player_logic_sprint_state *this)
{
  survarium::player_stamina_subscriber *p_m_stamina_subscriber; // ebx
  survarium::player_stamina *p_m_stamina; // esi
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v4; // ecx
  int v5; // ecx

  p_m_stamina_subscriber = &this->m_stamina_subscriber;
  p_m_stamina = &this->m_user->m_stamina;
  if ( vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::contains_object(
         (vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
         (int)p_m_stamina,
         &this->m_stamina_subscriber) )
  {
    vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
      v4,
      (int)p_m_stamina,
      p_m_stamina_subscriber);
  }
  v5 = -(this->m_finalize_callback.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v5) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v5, &this->m_finalize_callback.vtable);
  *(_BYTE *)(**(_DWORD **)((char *)&dword_10E74 + (unsigned int)this->m_user) + 500) = 0;
}
