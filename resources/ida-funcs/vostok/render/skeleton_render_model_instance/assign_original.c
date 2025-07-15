void __userpurge vostok::render::skeleton_render_model_instance::assign_original(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        int a2@<edi>,
        vostok::resources::resource_ptr<vostok::render::skeleton_render_model,vostok::resources::unmanaged_intrusive_base> v)
{
  vostok::render::skeleton_render_model *m_object; // eax
  vostok::render::skeleton_render_model *v4; // ecx
  vostok::resources::unmanaged_resource *v5; // eax
  vostok::math::float4x4 *v6; // ebx
  vostok::math::float4x4 *i; // esi
  vostok::math::float4x4 *v8; // esi
  vostok::math::float4x4 *j; // ebx
  unsigned __int8 v10; // al
  vostok::render::render_surface_instance *v11; // eax
  int v12; // edx
  _DWORD *v13; // eax
  vostok::math::float4x4 __x; // [esp+8h] [ebp-40h] BYREF

  m_object = 0;
  if ( v.m_object )
  {
    m_object = v.m_object;
    _InterlockedExchangeAdd(&v.m_object->m_reference_count, 1u);
  }
  v4 = m_object;
  v5 = *(vostok::resources::unmanaged_resource **)(a2 + 416);
  *(_DWORD *)(a2 + 416) = v4;
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
    (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)(a2 + 404),
    (*(_DWORD *)(*(_DWORD *)(a2 + 416) + 324) - *(_DWORD *)(*(_DWORD *)(a2 + 416) + 320)) >> 6,
    &__x);
  stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4>>::resize(
    (stlp_std::priv::_Impl_vector<vostok::math::float4x4,vostok::render::std_allocator<vostok::math::float4x4> > *)(a2 + 392),
    (*(_DWORD *)(*(_DWORD *)(a2 + 416) + 324) - *(_DWORD *)(*(_DWORD *)(a2 + 416) + 320)) >> 6,
    &__x);
  v6 = *(vostok::math::float4x4 **)(a2 + 404);
  for ( i = *(vostok::math::float4x4 **)(a2 + 408); v6 != i; ++v6 )
    vostok::math::float4x4::identity(v6);
  v8 = *(vostok::math::float4x4 **)(a2 + 392);
  for ( j = *(vostok::math::float4x4 **)(a2 + 396); v8 != j; ++v8 )
    vostok::math::float4x4::identity(v8);
  v10 = *(_BYTE *)(*(_DWORD *)(a2 + 416) + 304);
  *(_BYTE *)(a2 + 420) = v10;
  v11 = vostok::memory::new_array_helper<vostok::render::render_surface_instance>::call<vostok::memory::doug_lea_allocator>(
          (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
          v10);
  v12 = 0;
  for ( *(_DWORD *)(a2 + 424) = v11; (unsigned __int16)v12 < *(unsigned __int8 *)(a2 + 420); ++v12 )
  {
    v13 = (_DWORD *)(*(_DWORD *)(a2 + 424) + 28 * (unsigned __int16)v12);
    v13[2] = a2;
    *v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 416) + 300) + 4 * (unsigned __int16)v12);
    v13[1] = a2 + 324;
    v13[5] = 3;
  }
  if ( v.m_object )
  {
    if ( !_InterlockedExchangeAdd(&v.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v.m_object->vostok::resources::unmanaged_intrusive_base,
        v.m_object);
  }
}
