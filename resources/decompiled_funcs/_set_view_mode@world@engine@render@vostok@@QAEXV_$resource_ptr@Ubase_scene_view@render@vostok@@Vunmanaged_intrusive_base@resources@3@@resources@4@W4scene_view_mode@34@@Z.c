void __thiscall vostok::render::engine::world::set_view_mode(
        vostok::render::engine::world *this,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> view_ptr,
        vostok::render::scene_view_mode view_mode)
{
  *((_DWORD *)&view_ptr.m_object[4].m_parent_resources + 6) = view_mode;
  if ( !_InterlockedExchangeAdd(&view_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &view_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
      view_ptr.m_object);
}
