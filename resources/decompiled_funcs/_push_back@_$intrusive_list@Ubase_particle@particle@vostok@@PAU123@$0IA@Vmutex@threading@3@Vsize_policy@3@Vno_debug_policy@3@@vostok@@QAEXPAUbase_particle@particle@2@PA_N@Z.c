void __thiscall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::particle::base_particle *object,
        bool *out_pushed_first)
{
  vostok::size_policy *v3; // ecx
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+10h] [ebp-8h] BYREF

  object->next = 0;
  if ( this )
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
      (int)&raii);
  else
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
      0,
      (int)&raii);
  vostok::size_policy::increment_size(v3, this);
  if ( out_pushed_first )
    *out_pushed_first = this->m_first == 0;
  if ( this->m_first )
    this->m_last->next = object;
  else
    this->m_first = object;
  this->m_last = object;
  vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
    (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)object,
    (int)&raii);
}
