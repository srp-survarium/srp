void __usercall vostok::physics::bullet_character_controller::setup_shape_dim(
        vostok::physics::bullet_character_controller *this@<ecx>,
        const vostok::math::float2 *shape_dim@<eax>)
{
  float x; // xmm1_4
  float y; // xmm3_4
  btVector3 v4; // [esp+0h] [ebp-10h]

  x = shape_dim->x;
  y = shape_dim->y;
  v4.mVec128.m128_f32[0] = shape_dim->x * 0.5;
  v4.mVec128.m128_u64[1] = v4.mVec128.m128_u32[0];
  v4.mVec128.m128_f32[1] = (float)(y - x) * 0.5;
  this->m_shape.m_implicitShapeDimensions = (btVector3)v4.mVec128;
}
