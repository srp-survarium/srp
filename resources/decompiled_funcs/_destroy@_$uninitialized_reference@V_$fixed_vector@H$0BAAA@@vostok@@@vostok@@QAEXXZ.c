void __thiscall vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::destroy(
        vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *this)
{
  this->m_variable->m_end = this->m_variable->m_begin;
  this->m_initialized = 0;
}
