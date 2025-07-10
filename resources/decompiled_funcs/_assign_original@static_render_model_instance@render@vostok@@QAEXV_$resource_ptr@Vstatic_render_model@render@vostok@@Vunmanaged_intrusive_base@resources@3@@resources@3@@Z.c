void __userpurge vostok::render::static_render_model_instance::assign_original(
        vostok::render::static_render_model_instance *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::render::static_render_model,vostok::resources::unmanaged_intrusive_base> v)
{
  vostok::render::static_render_model *m_object; // eax
  vostok::render::static_render_model *v4; // ecx
  vostok::resources::unmanaged_resource *v5; // eax
  unsigned __int8 v6; // al
  vostok::render::render_surface_instance *v7; // eax
  int v8; // edx
  _DWORD *v9; // eax

  m_object = 0;
  if ( v.m_object )
  {
    m_object = v.m_object;
    _InterlockedExchangeAdd(&v.m_object->m_reference_count, 1u);
  }
  v4 = m_object;
  v5 = *(vostok::resources::unmanaged_resource **)(a2 + 392);
  *(_DWORD *)(a2 + 392) = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  v6 = *(_BYTE *)(*(_DWORD *)(a2 + 392) + 304);
  *(_BYTE *)(a2 + 396) = v6;
  v7 = vostok::memory::new_array_helper<vostok::render::render_surface_instance>::call<vostok::memory::doug_lea_allocator>(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         v6);
  v8 = 0;
  for ( *(_DWORD *)(a2 + 400) = v7; (unsigned __int16)v8 < *(unsigned __int8 *)(a2 + 396); ++v8 )
  {
    v9 = (_DWORD *)(*(_DWORD *)(a2 + 400) + 28 * (unsigned __int16)v8);
    v9[2] = a2;
    *v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 392) + 300) + 4 * (unsigned __int16)v8);
    v9[1] = a2 + 324;
    v9[5] = 3;
  }
  if ( v.m_object )
  {
    if ( !_InterlockedExchangeAdd(&v.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v.m_object->vostok::resources::unmanaged_intrusive_base,
        v.m_object);
  }
}
