char __userpurge vostok::render::remove_model_if_in_frustum_predicate::operator()@<al>(
        const vostok::render::lpv_render_surface *surface@<esi>,
        vostok::render::remove_model_if_in_frustum_predicate *this)
{
  vostok::math::aabb *v2; // ecx
  vostok::math::cuboid *v3; // eax
  vostok::math::aabb bbox; // [esp+4h] [ebp-18h] BYREF

  surface->surface->m_parent->get_aabb(surface->surface->m_parent, &bbox);
  vostok::math::aabb::operator*=(v2, bbox.min.x);
  v3 = (vostok::math::cuboid *)vostok::math::aabb::modify(
                                 (vostok::math::aabb *)surface->surface->m_transform,
                                 (const vostok::math::float4x4 *)LODWORD(bbox.min.x));
  if ( vostok::math::cuboid::test_inexact(v3, (const vostok::math::aabb *)v3) != intersection_inside )
    return 0;
  ++vostok::quasi_singleton<vostok::render::statistics>::pinst->lpv_stat_group.num_clipped_dips.value;
  return 1;
}
