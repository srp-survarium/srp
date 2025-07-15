void __userpurge vostok::physics::bt_dynamic_rigid_body::set_transform(
        vostok::physics::bt_dynamic_rigid_body *this@<ecx>,
        const float *a2@<edi>,
        btMatrix3x3 *transform)
{
  btVector3 *m_bt_body; // eax
  btRigidBody *v5; // ecx
  int v6; // [esp+8h] [ebp-54h] BYREF
  int v7; // [esp+Ch] [ebp-50h]
  int v8; // [esp+10h] [ebp-4Ch]
  int v9; // [esp+14h] [ebp-48h]
  int v10; // [esp+18h] [ebp-44h]
  _BYTE v11[48]; // [esp+1Ch] [ebp-40h] BYREF
  int v12; // [esp+4Ch] [ebp-10h]
  int v13; // [esp+50h] [ebp-Ch]
  int v14; // [esp+54h] [ebp-8h]
  int v15; // [esp+58h] [ebp-4h]

  v6 = transform->m_el[2].mVec128.m128_i32[2] ^ _mask__NegFloat_;
  btMatrix3x3::setValue(
    transform,
    (int)v11,
    &transform->m_el[0].mVec128.m128_f32[1],
    &transform->m_el[0].mVec128.m128_f32[2],
    transform->m_el[1].mVec128.m128_f32,
    &transform->m_el[1].mVec128.m128_f32[1],
    &transform->m_el[1].mVec128.m128_f32[2],
    transform->m_el[2].mVec128.m128_f32,
    &transform->m_el[2].mVec128.m128_f32[1],
    (const float *)&v6,
    a2);
  m_bt_body = (btVector3 *)this->m_bt_body;
  v7 = transform[1].m_el[0].mVec128.m128_i32[0];
  v8 = transform[1].m_el[0].mVec128.m128_i32[1];
  v9 = transform[1].m_el[0].mVec128.m128_i32[2] ^ _mask__NegFloat_;
  v10 = 0;
  v12 = v7;
  v13 = v8;
  v14 = v9;
  v15 = 0;
  btCollisionObject::setWorldTransform((btCollisionObject *)v11, m_bt_body);
  btCollisionObject::setInterpolationWorldTransform((btCollisionObject *)v11, (btVector3 *)this->m_bt_body);
  btRigidBody::updateInertiaTensor(v5, (int)this->m_bt_body);
}
