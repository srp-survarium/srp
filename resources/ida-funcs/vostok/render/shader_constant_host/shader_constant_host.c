void __thiscall vostok::render::shader_constant_host::shader_constant_host(
        vostok::render::shader_constant_host *this,
        const vostok::shared_string *name,
        const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *type,
        vostok::strings::shared::profile *a4)
{
  vostok::render::shader_constant_slot *v4; // esi
  int i; // edi

  name->m_pointer.m_object = 0;
  name[1].m_pointer.m_object = 0;
  v4 = (vostok::render::shader_constant_slot *)&name[2];
  for ( i = 2; i >= 0; --i )
    vostok::render::shader_constant_slot::shader_constant_slot(v4++);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>(
    &name[8].m_pointer,
    type);
  name[12].m_pointer.m_object = a4;
  name[9].m_pointer.m_object = 0;
  name[10].m_pointer.m_object = 0;
  name[11].m_pointer.m_object = 0;
}
