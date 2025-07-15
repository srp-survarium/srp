vostok::render::streaming_ready_texture *__userpurge vostok::render::streaming_ready_texture::operator=@<eax>(
        vostok::render::streaming_ready_texture *this@<ecx>,
        int a2@<edi>,
        const vostok::render::streaming_ready_texture *__that)
{
  const vostok::render::streaming_ready_texture *v3; // ebx
  vostok::render::res_texture *m_object; // ecx
  vostok::render::res_texture *v5; // eax
  int v6; // esi
  const vostok::render::streaming_ready_texture *v8; // eax

  v3 = __that;
  vostok::fixed_string<260>::operator=((vostok::fixed_string<260> *)a2, &__that->name);
  m_object = v3->texture.m_object;
  v5 = 0;
  if ( m_object )
  {
    v5 = v3->texture.m_object;
    ++m_object->m_reference_count;
  }
  v6 = *(_DWORD *)(a2 + 272);
  *(_DWORD *)(a2 + 272) = v5;
  if ( v6 )
  {
    if ( (*(_DWORD *)(v6 + 4))-- == 1 )
      vostok::render::res_texture::destroy_impl(m_object);
  }
  __that = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&__that,
    &v3->data);
  v8 = __that;
  __that = *(const vostok::render::streaming_ready_texture **)(a2 + 276);
  *(_DWORD *)(a2 + 276) = v8;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&__that);
  *(_DWORD *)(a2 + 280) = v3->num_mips;
  *(float *)(a2 + 284) = v3->distance;
  return (vostok::render::streaming_ready_texture *)a2;
}
