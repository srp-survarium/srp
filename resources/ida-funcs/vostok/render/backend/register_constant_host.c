vostok::render::shader_constant_host *__userpurge vostok::render::backend::register_constant_host@<eax>(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        const vostok::shared_string *name,
        vostok::strings::shared::profile *type)
{
  const vostok::shared_string *v4; // ebx
  int v6; // edi
  vostok::render::shader_constant_host **v7; // eax
  vostok::render::shader_constant_host *result; // eax
  vostok::memory::doug_lea_allocator *v9; // esi
  char *v10; // eax
  vostok::memory::doug_lea_allocator *v11; // ecx
  char *v12; // eax
  vostok::render::shader_constant_host *v13; // ecx
  const vostok::shared_string *v14; // eax
  const char *v15; // [esp+0h] [ebp-10h]
  vostok::render::shader_constant_host *const *v16; // [esp+0h] [ebp-10h]
  const char *v17; // [esp+4h] [ebp-Ch]
  unsigned int v18; // [esp+8h] [ebp-8h]
  vostok::render::shader_constant_host **where; // [esp+Ch] [ebp-4h] BYREF

  v4 = name;
  v6 = a2 + 5296;
  v7 = stlp_std::lower_bound<vostok::render::shader_constant_host * *,vostok::shared_string,bool (__cdecl *)(vostok::render::shader_constant_host const *,vostok::shared_string const &)>(
         *(vostok::render::shader_constant_host ***)(a2 + 5300),
         *(vostok::render::shader_constant_host ***)(a2 + 5296),
         name);
  where = v7;
  if ( v7 == *(vostok::render::shader_constant_host ***)(a2 + 5300)
    || (result = *v7, result->m_name.m_pointer.m_object != v4->m_pointer.m_object) )
  {
    v9 = vostok::render::g_allocator;
    v10 = type_info::raw_name(&vostok::render::shader_constant_host `RTTI Type Descriptor');
    v12 = vostok::memory::doug_lea_allocator::malloc_impl(v11, (int)v9, 0x38u, v10, v15, v17, v18);
    if ( v12 )
    {
      vostok::render::shader_constant_host::shader_constant_host(
        v13,
        (const vostok::shared_string *)v12,
        &v4->m_pointer,
        type);
      name = v14;
    }
    else
    {
      name = 0;
    }
    vostok::buffer_vector<vostok::render::shader_constant_host *>::insert(
      (vostok::buffer_vector<vostok::render::shader_constant_host *> *)v13,
      v6,
      &where,
      &name,
      v16);
    return *where;
  }
  return result;
}
