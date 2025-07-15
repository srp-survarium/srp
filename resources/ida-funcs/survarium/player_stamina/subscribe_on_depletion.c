void __usercall survarium::player_stamina::subscribe_on_depletion(
        survarium::player_stamina *this@<esi>,
        survarium::player_stamina_subscriber *const subscriber@<edi>,
        vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *a3@<ecx>)
{
  vostok::threading::mutex *v3; // ecx
  vostok::threading::mutex *v4; // ebx

  if ( !vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::contains_object(
          a3,
          (int)this,
          subscriber) )
  {
    v4 = 0;
    subscriber->next = 0;
    if ( this )
      v4 = &this->m_subscribers.vostok::threading::mutex;
    vostok::threading::mutex::lock(v3, (_RTL_CRITICAL_SECTION *)v4);
    ++this->m_subscribers.m_size;
    if ( this->m_subscribers.m_first )
      this->m_subscribers.m_last->next = subscriber;
    else
      this->m_subscribers.m_first = subscriber;
    this->m_subscribers.m_last = subscriber;
    LeaveCriticalSection((LPCRITICAL_SECTION)v4);
  }
}
