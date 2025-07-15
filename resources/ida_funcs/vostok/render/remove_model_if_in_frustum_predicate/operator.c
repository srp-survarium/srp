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


char __userpurge vostok::render::remove_model_if_in_frustum_predicate::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<esi>,
        vostok::render::remove_model_if_in_frustum_predicate *this)
{
  vostok::math::cuboid *v2; // eax
  const vostok::math::float3 *v4; // [esp+0h] [ebp-28h]
  const vostok::math::float4x4 *v5; // [esp+0h] [ebp-28h]
  vostok::math::aabb v6; // [esp+4h] [ebp-24h] BYREF

  in_model->m_parent->get_aabb(in_model->m_parent, (vostok::math::aabb *)&v6.max);
  *(_QWORD *)&v6.min.x = LODWORD(retry_to_increase_quality_period_sec) | 0x4040000000000000LL;
  v6.min.z = retry_to_increase_quality_period_sec;
  vostok::math::aabb::operator*=(&v6, v4);
  v2 = (vostok::math::cuboid *)vostok::math::aabb::modify((vostok::math::aabb *)in_model->m_transform, v5);
  if ( vostok::math::cuboid::test_inexact(v2, (const vostok::math::aabb *)v2) != intersection_inside )
    return 0;
  ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_clipped_dips.value;
  return 1;
}
