void __thiscall vostok::collision::triangle_mesh_geometry_instance::enumerate_primitives(
        vostok::collision::triangle_mesh_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  const vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 result; // [esp+8h] [ebp-40h] BYREF

  v4 = this->get_matrix(this);
  vostok::math::mul4x3(&result, v4, transform);
  this->m_triangle_mesh->enumerate_primitives(
    (vostok::collision::triangle_mesh_geometry *)this->m_triangle_mesh,
    &result,
    cb);
}
