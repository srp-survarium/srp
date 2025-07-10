void __thiscall vostok::collision::capsule_geometry_instance::render(
        vostok::collision::capsule_geometry_instance *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  ((void (__stdcall *)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::render::debug::renderer *, vostok::math::float4x4 *))this->render)(
    scene,
    renderer,
    &this->m_matrix);
}
