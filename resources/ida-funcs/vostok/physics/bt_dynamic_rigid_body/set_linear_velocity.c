void __userpurge vostok::physics::bt_dynamic_rigid_body::set_linear_velocity(
        const vostok::math::float3 *v@<eax>,
        vostok::physics::bt_dynamic_rigid_body *this)
{
  btVector3 *p_m_linearVelocity; // edi
  float y; // [esp+Ch] [ebp-Ch]
  int v4; // [esp+10h] [ebp-8h]

  y = v->y;
  v4 = LODWORD(v->z) ^ _mask__NegFloat_;
  p_m_linearVelocity = &this->m_bt_body->m_linearVelocity;
  p_m_linearVelocity->mVec128.m128_i32[0] = LODWORD(v->x);
  p_m_linearVelocity = (btVector3 *)((char *)p_m_linearVelocity + 4);
  p_m_linearVelocity->mVec128.m128_f32[0] = y;
  p_m_linearVelocity = (btVector3 *)((char *)p_m_linearVelocity + 4);
  p_m_linearVelocity->mVec128.m128_i32[0] = v4;
  p_m_linearVelocity->mVec128.m128_i32[1] = 0;
}
