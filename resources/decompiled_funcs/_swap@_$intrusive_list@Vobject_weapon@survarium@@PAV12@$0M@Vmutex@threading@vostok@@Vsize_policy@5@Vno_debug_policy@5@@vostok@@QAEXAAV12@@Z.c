void __usercall vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::swap(
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this@<edi>,
        vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *other@<eax>)
{
  survarium::object_weapon *m_first; // eax
  survarium::object_weapon *m_last; // eax
  unsigned int m_size; // eax

  vostok::threading::mutex::lock(&this->vostok::threading::mutex);
  vostok::threading::mutex::lock(&other->vostok::threading::mutex);
  m_first = this->m_first;
  this->m_first = other->m_first;
  other->m_first = m_first;
  m_last = this->m_last;
  this->m_last = other->m_last;
  other->m_last = m_last;
  m_size = this->m_size;
  this->m_size = other->m_size;
  other->m_size = m_size;
  LeaveCriticalSection((LPCRITICAL_SECTION)&other->vostok::threading::mutex);
  LeaveCriticalSection((LPCRITICAL_SECTION)&this->vostok::threading::mutex);
}
