vostok::math::sphere *__thiscall vostok::render::decal_texture_instance_proxy::bound_sphere(
        vostok::render::decal_texture_instance_proxy *this,
        vostok::math::sphere *result)
{
  vostok::math::aabb v3; // [esp+8h] [ebp-18h] BYREF

  qmemcpy(&v3, &this->m_decal->m_aabb, sizeof(v3));
  vostok::math::aabb::sphere(&v3, result);
  return result;
}
