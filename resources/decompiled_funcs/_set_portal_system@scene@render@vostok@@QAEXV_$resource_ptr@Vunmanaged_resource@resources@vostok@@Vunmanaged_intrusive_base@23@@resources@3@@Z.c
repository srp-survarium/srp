void __thiscall vostok::render::scene::set_portal_system(
        vostok::render::scene *this,
        vostok::render::scene *pss,
        vostok::configs::binary_config *pssa)
{
  void *v3; // esi
  vostok::render::culling::portal_sector_system *v4; // ecx
  vostok::resources::resource_base *v5; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-8h] BYREF

  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x140u);
  if ( v3 )
  {
    v6.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v6,
      pssa);
    vostok::render::culling::portal_sector_system::portal_sector_system(
      v4,
      (int)v3,
      (vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base>)v6.m_object);
  }
  else
  {
    v5 = 0;
  }
  pss->m_portal_system = (vostok::render::culling::portal_sector_system *)v5;
  if ( pssa )
  {
    if ( !_InterlockedExchangeAdd(&pssa->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&pssa->vostok::resources::unmanaged_intrusive_base, pssa);
  }
}
