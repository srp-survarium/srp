void __thiscall vostok::collision::aabb_object::render(
        vostok::collision::aabb_object *this,
        vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  vostok::math::float3 center; // [esp+0h] [ebp-1Ch] BYREF
  vostok::math::float3 size; // [esp+Ch] [ebp-10h] BYREF
  vostok::math::color color; // [esp+18h] [ebp-4h] BYREF

  v3 = this->m_aabb.max.x - this->m_aabb.min.x;
  v4 = this->m_aabb.max.y - this->m_aabb.min.y;
  v5 = this->m_aabb.max.z - this->m_aabb.min.z;
  color = (vostok::math::color)-1;
  size.x = v3 * 0.5;
  v6 = this->m_aabb.max.x + this->m_aabb.min.x;
  size.y = v4 * 0.5;
  v7 = this->m_aabb.max.y + this->m_aabb.min.y;
  size.z = v5 * 0.5;
  v8 = v6 * 0.5;
  v9 = (float)(this->m_aabb.max.z + this->m_aabb.min.z) * 0.5;
  center.y = v7 * 0.5;
  center.z = v9;
  vostok::render::debug::renderer::draw_aabb(&center, renderer, scene, &size, &color, SLOBYTE(v8));
}
