vostok::ai::percept_memory_object *__thiscall vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
        vostok::intrusive_list<vostok::ai::percept_memory_object,vostok::ai::percept_memory_object *,40,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this)
{
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v2; // ecx
  vostok::ai::percept_memory_object *result; // [esp+18h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+1Ch] [ebp-8h] BYREF

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
  if ( this->m_first )
  {
    vostok::size_policy::decrement_size(this, this);
    result = this->m_first;
    v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
    this->m_first = result->next;
    if ( !this->m_first )
    {
      v2 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this;
      this->m_last = 0;
    }
    result->next = 0;
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v2,
      (int)&raii);
    return result;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)this,
      (int)&raii);
    return 0;
  }
}
