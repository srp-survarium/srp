void __usercall vostok::render::game::renderer::draw_scene_params::~draw_scene_params(
        vostok::render::game::renderer::draw_scene_params *this@<ecx>,
        vostok::resources::unmanaged_resource **a2@<eax>)
{
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::resources::unmanaged_resource *v4; // eax

  v3 = a2[2];
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&a2[2]->vostok::resources::unmanaged_intrusive_base, a2[2]);
  v4 = a2[1];
  if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&a2[1]->vostok::resources::unmanaged_intrusive_base, a2[1]);
  if ( *a2 )
  {
    if ( !_InterlockedExchangeAdd(&(*a2)->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&(*a2)->vostok::resources::unmanaged_intrusive_base, *a2);
  }
}
