void __thiscall vostok::render::decal_properties::decal_properties(
        vostok::render::decal_properties *this,
        vostok::render::decal_properties *__that,
        const vostok::render::decal_properties *__thata)
{
  qmemcpy(__that, __thata, 0x40u);
  __that->material.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that->material,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__thata->material);
  __that->width_height_far_distance = __thata->width_height_far_distance;
  __that->alpha_angle = __thata->alpha_angle;
  __that->clip_angle = __thata->clip_angle;
  __that->draw_priority = __thata->draw_priority;
  __that->projection_on_terrain_geometry = __thata->projection_on_terrain_geometry;
  __that->projection_on_static_geometry = __thata->projection_on_static_geometry;
  __that->projection_on_speedtree_geometry = __thata->projection_on_speedtree_geometry;
  __that->projection_on_skeleton_geometry = __thata->projection_on_skeleton_geometry;
  __that->projection_on_particle_geometry = __thata->projection_on_particle_geometry;
}
