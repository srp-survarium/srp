void __thiscall vostok::physics::bullet_physics_world::add(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_constraint *constraint)
{
  this->m_dynamicsWorld->addConstraint(this->m_dynamicsWorld, constraint->m_bt_typed_constraint, 0);
}


void __thiscall vostok::physics::bullet_physics_world::add(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bt_rigid_body_base *body,
        int filter_group,
        int filter_mask)
{
  vostok::math::aabb *v4; // edi
  btSoftRigidDynamicsWorld_vtbl *v5; // ebx
  int v6; // eax
  btRigidBody *v7; // eax
  unsigned __int64 v8; // xmm0_8
  btRigidBody *(__thiscall *get_rigid_body)(vostok::physics::bt_rigid_body_base *); // edx
  int v10; // eax
  vostok::math::aabb v11; // [esp+104h] [ebp-6Ch] BYREF
  __int64 v12; // [esp+120h] [ebp-50h] BYREF
  float v13; // [esp+128h] [ebp-48h]
  _QWORD v14[8]; // [esp+130h] [ebp-40h] BYREF

  v4 = (vostok::math::aabb *)this;
  v5 = this->m_dynamicsWorld->__vftable;
  v6 = ((int (__thiscall *)(vostok::physics::bt_rigid_body_base *, int, int))body->get_rigid_body)(
         body,
         filter_group,
         filter_mask);
  ((void (__thiscall *)(_DWORD, int))v5->addRigidBody)(LODWORD(v11.min.y), v6);
  v7 = body->get_rigid_body(body);
  v8 = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v7 = (btRigidBody *)((char *)v7 + 16);
  v14[0] = v8;
  v14[1] = *((_QWORD *)&v7->__vftable + 1);
  v14[2] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[0];
  v14[3] = v7->m_worldTransform.m_basis.m_el[0].mVec128.m128_u64[1];
  v14[4] = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[0];
  v14[5] = v7->m_worldTransform.m_basis.m_el[1].mVec128.m128_u64[1];
  v14[6] = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[0];
  get_rigid_body = body->get_rigid_body;
  v14[7] = v7->m_worldTransform.m_basis.m_el[2].mVec128.m128_u64[1];
  v10 = (int)get_rigid_body(body);
  (*(void (__thiscall **)(_DWORD, _QWORD *, vostok::math::float3 *, __int64 *))(**(_DWORD **)(v10 + 204) + 4))(
    *(_DWORD *)(v10 + 204),
    v14,
    &v11.max,
    &v12);
  *(_QWORD *)&v11.min.x = *(_QWORD *)&v11.max.x;
  v4 = (vostok::math::aabb *)((char *)v4 + 64);
  v11.min.z = -v11.max.z;
  vostok::math::aabb::modify(&v11, v4);
  *(_QWORD *)&v11.min.x = v12;
  v11.min.z = -v13;
  vostok::math::aabb::modify(&v11, v4);
}
