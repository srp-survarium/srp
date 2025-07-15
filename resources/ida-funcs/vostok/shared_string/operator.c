vostok::shared_string *__usercall vostok::shared_string::operator=@<eax>(
        vostok::shared_string *this@<esi>,
        const vostok::shared_string *__that@<eax>)
{
  vostok::strings::shared::profile *m_object; // eax
  vostok::strings::shared::profile *v3; // ecx
  vostok::strings::shared::profile *v4; // eax

  m_object = __that->m_pointer.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = this->m_pointer.m_object;
  this->m_pointer.m_object = v3;
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      v4,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v4);
  return this;
}
