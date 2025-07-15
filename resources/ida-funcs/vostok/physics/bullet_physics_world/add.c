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
  vostok::physics::bullet_physics_world *v4; // edi
  void (__thiscall **p_addRigidBody)(struct btSoftRigidDynamicsWorld *, btRigidBody *, __int16, __int16); // esi
  int v6; // eax
  btTransform *p_m_worldTransform; // eax
  __m128 *p_mVec128; // esi
  vostok::physics::bt_rigid_body_base_vtbl *v9; // eax
  int v10; // eax
  void (__thiscall **p_update_single_aabb)(vostok::physics::bullet_physics_world *, btRigidBody *); // esi
  btRigidBody *v12; // eax
  vostok::math::aabb v14; // [esp+1Ch] [ebp-6Ch] BYREF
  __int64 v15; // [esp+38h] [ebp-50h] BYREF
  int v16; // [esp+40h] [ebp-48h]
  _DWORD v17[16]; // [esp+48h] [ebp-40h] BYREF

  v4 = this;
  p_addRigidBody = &this->m_dynamicsWorld->addRigidBody;
  v6 = ((int (__thiscall *)(vostok::physics::bt_rigid_body_base *, int, int))body->get_rigid_body)(
         body,
         filter_group,
         filter_mask);
  ((void (__thiscall *)(btSoftRigidDynamicsWorld *, int))*p_addRigidBody)(v4->m_dynamicsWorld, v6);
  if ( (filter_group & 0xA) != 0 )
  {
    p_m_worldTransform = &body->get_rigid_body(body)->m_worldTransform;
    v17[0] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[0];
    v17[1] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[1];
    v17[2] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[2];
    v17[3] = p_m_worldTransform->m_basis.m_el[0].mVec128.m128_i32[3];
    v17[4] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[0];
    v17[5] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[1];
    v17[6] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[2];
    v17[7] = p_m_worldTransform->m_basis.m_el[1].mVec128.m128_i32[3];
    v17[8] = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[0];
    v17[9] = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[1];
    v17[10] = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[2];
    v17[11] = p_m_worldTransform->m_basis.m_el[2].mVec128.m128_i32[3];
    p_mVec128 = &p_m_worldTransform->m_origin.mVec128;
    v9 = body->__vftable;
    v17[12] = p_mVec128->m128_i32[0];
    p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
    v17[13] = p_mVec128->m128_i32[0];
    p_mVec128 = (__m128 *)((char *)p_mVec128 + 4);
    v17[14] = p_mVec128->m128_i32[0];
    v17[15] = p_mVec128->m128_i32[1];
    v10 = (int)v9->get_rigid_body(body);
    (*(void (__thiscall **)(_DWORD, _DWORD *, vostok::math::float3 *, __int64 *))(**(_DWORD **)(v10 + 204) + 4))(
      *(_DWORD *)(v10 + 204),
      v17,
      &v14.max,
      &v15);
    *(_QWORD *)&v14.min.x = *(_QWORD *)&v14.max.x;
    LODWORD(v14.min.z) = LODWORD(v14.max.z) ^ _mask__NegFloat_;
    vostok::math::aabb::modify(&v14, &this->m_world_aabb);
    *(_QWORD *)&v14.min.x = v15;
    LODWORD(v14.min.z) = v16 ^ _mask__NegFloat_;
    vostok::math::aabb::modify(&v14, &this->m_world_aabb);
    v4 = this;
  }
  p_update_single_aabb = (void (__thiscall **)(vostok::physics::bullet_physics_world *, btRigidBody *))&v4->update_single_aabb;
  v12 = body->get_rigid_body(body);
  (*p_update_single_aabb)(v4, v12);
}
