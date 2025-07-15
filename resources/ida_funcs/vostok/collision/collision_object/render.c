void __thiscall vostok::collision::collision_object::render(
        vostok::collision::collision_object *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  unsigned int v4; // xmm1_4
  unsigned int v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  const vostok::math::float4x4 *v9; // eax
  bool v10; // [esp+0h] [ebp-68h]
  vostok::math::color color; // [esp+Ch] [ebp-5Ch] BYREF
  vostok::math::float3 position; // [esp+10h] [ebp-58h] BYREF
  vostok::math::float3 size; // [esp+1Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 result; // [esp+28h] [ebp-40h] BYREF

  this->m_geometry_instance->render(this->m_geometry_instance, scene, renderer);
  *(float *)&v4 = (float)(this->m_aabb.max.y - this->m_aabb.min.y) * 0.5;
  *(float *)&v5 = (float)(this->m_aabb.max.z - this->m_aabb.min.z) * 0.5;
  size.x = (float)(this->m_aabb.max.x - this->m_aabb.min.x) * 0.5;
  v6 = this->m_aabb.max.x + this->m_aabb.min.x;
  *(_QWORD *)&size.elements[1] = __PAIR64__(v5, v4);
  v7 = this->m_aabb.max.y + this->m_aabb.min.y;
  v8 = this->m_aabb.max.z + this->m_aabb.min.z;
  color = (vostok::math::color)-1;
  position.x = v6 * 0.5;
  position.y = v7 * 0.5;
  position.z = v8 * 0.5;
  v9 = vostok::math::create_translation(&result, &position);
  vostok::render::debug::renderer::draw_cube(renderer, scene, v9, &size, &color, v10);
}
