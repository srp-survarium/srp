void __thiscall vostok::render::render_target::set_name(
        vostok::render::render_target *this,
        vostok::shared_string *name,
        vostok::shared_string __that)
{
  vostok::strings::shared::profile *m_object; // eax

  vostok::shared_string::shared_string(
    (vostok::shared_string *)this,
    &__that.m_pointer,
    (char *)__that.m_pointer.m_object);
  vostok::shared_string::operator=(name + 1, &__that);
  if ( __that.m_pointer.m_object )
  {
    m_object = __that.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__that.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)m_object);
  }
}
