vostok::render::shader_constant_host *__userpurge vostok::render::backend::register_constant_host@<eax>(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        const vostok::shared_string *name,
        vostok::render::enum_constant_type type)
{
  const vostok::shared_string *v4; // ebx
  vostok::render::shader_constant_host **v5; // esi
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v6; // ebp
  vostok::render::shader_constant_host **v7; // eax
  void **v8; // edi
  vostok::render::shader_constant_host *result; // eax
  void *v10; // eax
  vostok::render::shader_constant_host *v11; // ecx
  const vostok::shared_string *v12; // eax

  v4 = name;
  v5 = *(vostok::render::shader_constant_host ***)(a2 + 2124);
  v6 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)(a2 + 2120);
  v7 = stlp_std::priv::__lower_bound<vostok::render::shader_constant_host * *,vostok::shared_string,bool (__cdecl *)(vostok::render::shader_constant_host const *,vostok::shared_string const &),bool (__cdecl *)(vostok::render::shader_constant_host const *,vostok::shared_string const &),int>(
         *(vostok::render::shader_constant_host ***)(a2 + 2120),
         v5,
         name);
  v8 = (void **)v7;
  if ( v7 == v5 || (result = *v7, (vostok::strings::shared::profile *)*((_DWORD *)*v8 + 8) != v4->m_pointer.m_object) )
  {
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
            0x38u);
    if ( v10 )
    {
      vostok::render::shader_constant_host::shader_constant_host(v11, (int)v10, v4, type);
      name = v12;
    }
    else
    {
      name = 0;
    }
    return (vostok::render::shader_constant_host *)*stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::insert(
                                                      v8,
                                                      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&name,
                                                      v6);
  }
  return result;
}
