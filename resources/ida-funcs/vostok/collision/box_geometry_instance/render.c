void __thiscall vostok::collision::box_geometry_instance::render(
        vostok::collision::box_geometry_instance *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  ((void (__stdcall *)(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, vostok::render::debug::renderer *, vostok::math::float4x4 *))this->render)(
    scene,
    renderer,
    &this->m_matrix);
}


void __userpurge vostok::collision::box_geometry_instance::render(
        vostok::collision::box_geometry_instance *this@<ecx>,
        bool a2@<dil>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer,
        const vostok::math::float4x4 *transform)
{
  vostok::math::color color; // [esp+0h] [ebp-10h] BYREF
  vostok::math::float3 size; // [esp+4h] [ebp-Ch] BYREF

  color = (vostok::math::color)-1;
  LODWORD(size.x) = clear_value;
  LODWORD(size.y) = clear_value;
  LODWORD(size.z) = clear_value;
  vostok::render::debug::renderer::draw_cube(renderer, scene, transform, &size, &color, a2);
}
