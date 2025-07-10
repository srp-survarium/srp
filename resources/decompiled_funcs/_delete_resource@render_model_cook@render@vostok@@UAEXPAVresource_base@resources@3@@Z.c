void __thiscall vostok::render::render_model_cook::delete_resource(
        vostok::render::render_model_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::render::grass_render_model *m_object; // ebx
  _BYTE *v3; // edi
  void *m_reconstruction_info_actuality_tick_high; // esi

  m_object = vostok::render::g_allocator.m_object;
  if ( resource )
  {
    v3 = __RTCastToVoid((void **)&resource->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
      resource,
      0);
    if ( v3 )
    {
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
    }
  }
}
