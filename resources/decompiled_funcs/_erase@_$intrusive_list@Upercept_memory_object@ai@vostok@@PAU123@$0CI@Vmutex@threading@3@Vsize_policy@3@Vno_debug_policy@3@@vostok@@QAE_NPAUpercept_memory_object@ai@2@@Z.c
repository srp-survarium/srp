char __thiscall vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::ai::percept_memory_object *object)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v3; // ecx
  vostok::ai::percept_memory_object *m_first; // [esp+4h] [ebp-2Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+20h] [ebp-10h] BYREF
  vostok::ai::percept_memory_object *i; // [esp+28h] [ebp-8h]
  vostok::ai::percept_memory_object *previous_i; // [esp+2Ch] [ebp-4h]

  if ( !this->m_first )
    return 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  previous_i = 0;
  for ( i = this->m_first; i && i != object; i = i->next )
    previous_i = i;
  if ( i == object )
  {
    vostok::size_policy::decrement_size((vostok::size_policy *)i, this);
    if ( previous_i )
      previous_i->next = i->next;
    else
      this->m_first = i->next;
    v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i;
    if ( !i->next )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v3 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v3,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)i,
      (int)&raii);
    return 0;
  }
}
