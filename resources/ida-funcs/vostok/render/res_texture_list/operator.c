vostok::render::res_texture_list *__thiscall vostok::render::res_texture_list::operator=(
        vostok::render::res_texture_list *this,
        const vostok::render::res_texture_list *__that,
        unsigned int *a3)
{
  unsigned int *v4; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_begin; // esi
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v7; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // esi
  unsigned int v10; // [esp+Ch] [ebp-4h]
  unsigned int v11; // [esp+18h] [ebp+8h]

  v4 = a3;
  __that->m_reference_count = *a3;
  m_begin = __that->m_container.m_begin;
  v10 = a3[2];
  v11 = a3[1];
  while ( m_begin != __that->m_container.m_end )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(m_begin++);
  v6 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v11;
  v7 = __that->m_container.m_begin;
  __that->m_container.m_end = &v7[(int)(v10 - v11) >> 2];
  v8 = v7;
  while ( v6 != (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v10 )
  {
    if ( v8 )
    {
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        v8,
        v6);
      v4 = a3;
    }
    v6 = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(v11 + 4);
    v11 += 4;
    ++v8;
  }
  __that->m_is_registered = *((_BYTE *)v4 + 272);
  return (vostok::render::res_texture_list *)__that;
}
