void __thiscall btRigidBody::setDamping(btRigidBody *this, float lin_damping, float ang_damping)
{
  const vostok::math::float4x4 *v3; // xmm1_4
  float *p_lin_damping; // eax
  float v5; // xmm2_4
  bool v6; // cc
  float *p_ang_damping; // eax
  int v8; // [esp+0h] [ebp-8h] BYREF
  const vostok::math::float4x4 *v9; // [esp+4h] [ebp-4h] BYREF

  v3 = clear_value;
  v9 = clear_value;
  v8 = 0;
  if ( lin_damping >= 0.0 )
  {
    p_lin_damping = (float *)&v9;
    if ( lin_damping <= *(float *)&clear_value )
      p_lin_damping = &lin_damping;
  }
  else
  {
    p_lin_damping = (float *)&v8;
  }
  v5 = ang_damping;
  v6 = ang_damping >= 0.0;
  this->m_linearDamping = *p_lin_damping;
  v9 = v3;
  lin_damping = 0.0;
  if ( v6 )
  {
    p_ang_damping = (float *)&v9;
    if ( v5 <= *(float *)&v3 )
      p_ang_damping = &ang_damping;
    this->m_angularDamping = *p_ang_damping;
  }
  else
  {
    this->m_angularDamping = lin_damping;
  }
}
