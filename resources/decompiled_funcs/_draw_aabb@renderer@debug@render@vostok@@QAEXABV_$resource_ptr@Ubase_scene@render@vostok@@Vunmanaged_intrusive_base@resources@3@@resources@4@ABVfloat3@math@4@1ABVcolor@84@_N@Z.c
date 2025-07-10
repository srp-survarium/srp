void __userpurge vostok::render::debug::renderer::draw_aabb(
        const vostok::math::float3 *center@<ecx>,
        const vostok::math::color *color@<eax>,
        vostok::render::debug::renderer *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        const vostok::math::float3 *size,
        bool use_depth)
{
  vostok::math::aabb *v6; // eax
  bool v8; // [esp+0h] [ebp-48h]
  vostok::math::float4x4 result; // [esp+8h] [ebp-40h] BYREF

  v6 = (vostok::math::aabb *)vostok::math::create_translation(&result, center);
  vostok::render::debug::renderer::draw_cube(v6, size, this, scene, color, v8);
}
