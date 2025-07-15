void __thiscall vostok::render::renderer_context::clear_resources(vostok::render::renderer_context *this)
{
  vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->m_scene_view,
    0);
}
