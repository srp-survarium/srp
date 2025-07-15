char __userpurge vostok::render::remove_model_if_fully_in_frustum_predicate::operator()@<al>(
        vostok::render::render_surface_instance *in_model@<eax>,
        vostok::render::remove_model_if_fully_in_frustum_predicate *this)
{
  vostok::math::aabb_plane *v3; // eax
  vostok::math::frustum *m_frustum; // ebx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  vostok::math::cuboid *v8; // ecx
  vostok::math::aabb v10; // [esp+10h] [ebp-34h] BYREF
  _BYTE v11[24]; // [esp+28h] [ebp-1Ch] BYREF

  in_model->m_parent->get_aabb(in_model->m_parent, &v10);
  v3 = (vostok::math::aabb_plane *)vostok::math::aabb::modify((vostok::math::aabb *)in_model->m_transform, &v10);
  m_frustum = this->m_frustum;
  v5 = this->m_sun_direction.x * s_spot_max_distance;
  v6 = this->m_sun_direction.y * s_spot_max_distance;
  v7 = this->m_sun_direction.z * s_spot_max_distance;
  qmemcpy(v11, v3, sizeof(v11));
  *(float *)v11 = v10.min.x + v5;
  *(float *)&v11[4] = *(float *)&v11[4] + v6;
  *(float *)&v11[8] = *(float *)&v11[8] + v7;
  *(float *)&v11[12] = *(float *)&v11[12] + v5;
  *(float *)&v11[16] = *(float *)&v11[16] + v6;
  *(float *)&v11[20] = *(float *)&v11[20] + v7;
  if ( vostok::math::cuboid::test_inexact(0, (int)m_frustum, v3) != 1
    || vostok::math::cuboid::test_inexact(v8, (int)m_frustum, (vostok::math::aabb_plane *)v11) != 1 )
  {
    return 0;
  }
  ++vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_prev_cascade_clipped_dips.value;
  return 1;
}
