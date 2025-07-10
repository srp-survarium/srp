void __userpurge vostok::render::material::material(
        vostok::render::material *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> in_config)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &vostok::render::material::`vftable';
  *(_DWORD *)(a2 + 272) = a2 + 404;
  *(_DWORD *)(a2 + 264) = a2 + 276;
  *(_DWORD *)(a2 + 268) = a2 + 276;
  *(_BYTE *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 404) = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 404),
    &in_config);
  if ( in_config.m_object )
  {
    if ( !_InterlockedExchangeAdd(&in_config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &in_config.m_object->vostok::resources::unmanaged_intrusive_base,
        in_config.m_object);
  }
}
