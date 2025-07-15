void __thiscall survarium::player_logic_sprint_state::initialize(survarium::player_logic_sprint_state *this)
{
  int v2; // ecx

  survarium::player_stamina::subscribe_on_depletion(
    &this->m_user->m_stamina,
    &this->m_stamina_subscriber,
    (vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this);
  v2 = -(this->m_initialize_callback.vtable != 0);
  if ( ((unsigned int)vostok::memory::process_allocator::finalize_impl & v2) != 0 )
    boost::function0<void>::operator()((boost::function0<bool> *)v2, &this->m_initialize_callback.vtable);
  *(_BYTE *)(**(_DWORD **)((char *)&dword_10E74 + (unsigned int)this->m_user) + 500) = 1;
}
