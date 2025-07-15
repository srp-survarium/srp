void __userpurge vostok::shared_string::shared_string(
        vostok::shared_string *this@<ecx>,
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        char *value)
{
  vostok::strings::shared::profile *v3; // eax
  vostok::strings::shared::profile *v4; // edi

  v3 = vostok::strings::shared::manager::string((vostok::strings::shared::manager *)this, value);
  a2->m_object = 0;
  v4 = v3;
  if ( v3 )
  {
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(a2);
    a2->m_object = v4;
    _InterlockedExchangeAdd(&v4->m_reference_count, 1u);
  }
}
