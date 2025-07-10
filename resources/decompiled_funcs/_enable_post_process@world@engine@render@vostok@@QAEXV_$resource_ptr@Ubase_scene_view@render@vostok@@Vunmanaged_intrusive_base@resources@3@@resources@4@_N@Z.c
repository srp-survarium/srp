void __thiscall vostok::render::engine::world::enable_post_process(
        vostok::render::engine::world *this,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> view_ptr,
        bool enable)
{
  LOBYTE(view_ptr.m_object[4].m_memory_usage_self.size) = enable;
  if ( !_InterlockedExchangeAdd(&view_ptr.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &view_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
      view_ptr.m_object);
}
