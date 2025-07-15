vostok::resources::unmanaged_resource *__usercall vostok::render::decal_instance::get_effects@<eax>(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::unmanaged_resource *v2; // eax
  vostok::resources::unmanaged_resource *v3; // esi

  v2 = *(vostok::resources::unmanaged_resource **)(a2 + 68);
  if ( !v2 )
    return (vostok::resources::unmanaged_resource *)dword_4BB07F4;
  _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  v3 = v2 + 1;
  if ( !_InterlockedExchangeAdd(&v2->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v2->vostok::resources::unmanaged_intrusive_base, v2);
  return v3;
}
