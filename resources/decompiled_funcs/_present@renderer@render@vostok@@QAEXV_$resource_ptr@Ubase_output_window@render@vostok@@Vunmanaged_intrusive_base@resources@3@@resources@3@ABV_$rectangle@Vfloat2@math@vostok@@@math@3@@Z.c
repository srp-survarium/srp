void __userpurge vostok::render::renderer::present(
        vostok::render::renderer *this@<ecx>,
        int a2@<edx>,
        vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> in_output_window,
        const vostok::math::rectangle<vostok::math::float2> *viewport)
{
  int v4; // eax
  vostok::render::res_texture *v5; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v6; // [esp-4h] [ebp-4h] BYREF

  v4 = **(_DWORD **)(a2 + 352);
  v6.m_object = 0;
  v5 = *(vostok::render::res_texture **)(v4 + 7356);
  if ( v5 )
  {
    v6.m_object = v5;
    ++v5->m_reference_count;
  }
  vostok::render::stage_screen_image::execute((vostok::render::stage_screen_image *)&v6, v6);
  if ( in_output_window.m_object )
  {
    if ( !_InterlockedExchangeAdd(&in_output_window.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &in_output_window.m_object->vostok::resources::unmanaged_intrusive_base,
        in_output_window.m_object);
  }
}
