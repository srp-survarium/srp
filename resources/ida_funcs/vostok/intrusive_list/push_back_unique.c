char __thiscall vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back_unique(
        vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::perceptors::sensors_subscriber *object,
        bool *out_pushed_first)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::ai::perceptors::sensors_subscriber *m_next; // [esp+4h] [ebp-30h]
  vostok::ai::perceptors::sensors_subscriber *m_first; // [esp+8h] [ebp-2Ch]
  unsigned __int8 v8; // [esp+23h] [ebp-11h]
  vostok::ai::perceptors::sensors_subscriber *i; // [esp+24h] [ebp-10h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+2Ch] [ebp-8h] BYREF

  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  if ( this->m_first )
    m_first = this->m_first;
  else
    m_first = 0;
  for ( i = m_first; i; i = m_next )
  {
    if ( i == object )
    {
      v8 = 1;
      goto LABEL_17;
    }
    if ( i->m_next )
      m_next = i->m_next;
    else
      m_next = 0;
  }
  v8 = 0;
LABEL_17:
  if ( v8 )
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v8,
      (int)&raii);
    return 0;
  }
  else
  {
    vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      this,
      object,
      out_pushed_first);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return 1;
  }
}
