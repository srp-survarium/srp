vostok::math::float3 *__userpurge vostok::physics::bt_animated_rigid_body::get_random_surface_point_by_id@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        const unsigned int surface_id@<eax>,
        unsigned int seed,
        unsigned int a4)
{
  btCollisionShape_vtbl *v4; // eax
  long double v5; // rdi
  vostok::buffer_vector<float> *getBoundingSphere; // ecx
  float *m_end; // eax
  float *v8; // eax

  v4 = this->m_shape->m_children.m_data[surface_id].m_childShape[2].__vftable;
  HIDWORD(v5) = seed;
  seed = a4;
  getBoundingSphere = (vostok::buffer_vector<float> *)v4[1].getBoundingSphere;
  m_end = getBoundingSphere->m_end;
  if ( m_end )
  {
    v8 = m_end - 2;
    if ( v8 )
    {
      if ( v8 == (float *)2 )
      {
        LODWORD(v5) = 3;
        vostok::physics::get_capsule_random_surface_point(
          (vostok::math::random32 *)&seed,
          v5,
          *((float *)&getBoundingSphere[2].m_max_end + ((int)getBoundingSphere[5].m_end + 2) % 3),
          (vostok::physics *)HIDWORD(v5),
          COERCE_STRUCT_VOSTOK_MATH_FLOAT3_(*((float *)&getBoundingSphere[2].m_max_end + (int)getBoundingSphere[5].m_end)));
      }
      else
      {
        vostok::physics::get_cylinder_random_surface_point(
          getBoundingSphere,
          (float *)HIDWORD(v5),
          SHIDWORD(v5),
          (vostok::math::random32 *)&seed);
      }
    }
    else
    {
      vostok::physics::get_sphere_random_surface_point((float *)HIDWORD(v5), (vostok::math::random32 *)&seed);
    }
  }
  else
  {
    vostok::physics::get_box_random_surface_point(*((float *)&v5 + 1), (vostok::math::random32 *)&seed);
  }
  return (vostok::math::float3 *)HIDWORD(v5);
}
