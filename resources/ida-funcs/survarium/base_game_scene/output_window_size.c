vostok::resources::unmanaged_resource *__usercall survarium::base_game_scene::output_window_size@<eax>(
        survarium::base_game_scene *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::unmanaged_resource *v2; // ecx
  vostok::resources::unmanaged_resource *v3; // eax
  vostok::resources::unmanaged_resource *v4; // esi

  v2 = *(vostok::resources::unmanaged_resource **)(*(_DWORD *)(a2 + 168) + 88);
  v3 = 0;
  if ( v2 )
  {
    v3 = v2;
    _InterlockedExchangeAdd(&v2->m_reference_count, 1u);
  }
  v4 = v3 + 1;
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  return v4;
}
