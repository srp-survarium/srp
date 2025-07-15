void __usercall vostok::render::shader_constant_bindings::~shader_constant_bindings(
        vostok::render::shader_constant_bindings *this@<ecx>,
        vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; i += 5 )
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(i + 2);
  a2[1] = *a2;
}
