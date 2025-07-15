double __thiscall vostok::collision::box_geometry_instance::get_surface_area(
        vostok::collision::box_geometry_instance *this)
{
  vostok::math::float3 v2; // [esp+0h] [ebp-Ch] BYREF

  vostok::math::float4x4::get_scale(&this->m_matrix, &v2);
  return ((v2.x + v2.y) * v2.z + v2.x * v2.y) * gran1;
}
