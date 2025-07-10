char __thiscall vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::particle::base_particle *object)
{
  vostok::size_policy *v3; // ecx
  vostok::particle::base_particle *next_of_object; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v5; // ecx
  vostok::particle::base_particle *m_first; // [esp+4h] [ebp-24h]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+18h] [ebp-10h] BYREF
  vostok::particle::base_particle *i; // [esp+20h] [ebp-8h]
  vostok::particle::base_particle *previous_i; // [esp+24h] [ebp-4h]

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
  v3 = this;
  for ( i = this->m_first;
        i;
        i = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i) )
  {
    v3 = (vostok::size_policy *)i;
    if ( i == object )
      break;
    previous_i = i;
  }
  if ( i == object )
  {
    vostok::size_policy::decrement_size(v3, this);
    if ( previous_i )
    {
      next_of_object = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i);
      previous_i->next = next_of_object;
    }
    else
    {
      this->m_first = vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i);
    }
    if ( !vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,128,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(i) )
    {
      if ( previous_i )
        m_first = previous_i;
      else
        m_first = this->m_first;
      v5 = (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)m_first;
      this->m_last = m_first;
    }
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v5,
      (int)&raii);
    return 1;
  }
  else
  {
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)v3,
      (int)&raii);
    return 0;
  }
}
