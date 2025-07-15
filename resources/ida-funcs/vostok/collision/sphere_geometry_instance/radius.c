void __thiscall vostok::collision::sphere_geometry_instance::radius(vostok::collision::sphere_geometry_instance *this)
{
  vostok::math::float3 v1; // [esp+0h] [ebp-Ch] BYREF

  vostok::math::float4x4::get_scale(&this->m_matrix, &v1);
}
