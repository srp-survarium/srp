void __usercall vostok::physics::new_animated_rigid_body(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        btCompoundShape *shape,
        vostok::memory::base_allocator *game_material_id)
{
  btCompoundShape *v5; // edi
  void (__thiscall *calculateLocalInertia)(struct btCompoundShape *, float, btVector3 *); // edx
  btCollisionObject *v7; // eax
  btCollisionObject *v8; // ecx
  btRigidBody *v9; // esi
  _DWORD *v10; // eax
  vostok::physics::bt_animated_rigid_body *v11; // ecx
  unsigned __int16 v13; // [esp+150h] [ebp-B4h]
  struct btMotionState *v14[3]; // [esp+154h] [ebp-B0h] BYREF
  btRigidBody::btRigidBodyConstructionInfo v15; // [esp+160h] [ebp-A4h] BYREF

  v5 = shape;
  calculateLocalInertia = shape->calculateLocalInertia;
  memset(v14, 0, sizeof(v14));
  v15.m_mass = 0.0;
  ((void (__thiscall *)(btCompoundShape *, _DWORD, struct btMotionState **, int, int, int))calculateLocalInertia)(
    shape,
    0.0,
    v14,
    a2,
    a3,
    a1);
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(
    &v15,
    (int)&v15.m_startWorldTransform,
    (int)shape,
    0);
  v7 = (btCollisionObject *)game_material_id->call_malloc(game_material_id, 704u);
  v9 = (btRigidBody *)v7;
  if ( v7 )
  {
    btCollisionObject::btCollisionObject(v8, v7);
    v9->__vftable = (btRigidBody_vtbl *)&btRigidBody::`vftable';
    v9->m_constraintRefs.m_ownsMemory = 1;
    v9->m_constraintRefs.m_data = 0;
    v9->m_constraintRefs.m_size = 0;
    v9->m_constraintRefs.m_capacity = 0;
    btRigidBody::setupRigidBody(v9, (const btRigidBody::btRigidBodyConstructionInfo *)&v15.m_startWorldTransform);
    v5 = shape;
  }
  else
  {
    v9 = 0;
  }
  v9->m_collisionFlags = 16;
  v10 = game_material_id->call_malloc(game_material_id, 24u);
  if ( v10 )
    vostok::physics::bt_animated_rigid_body::bt_animated_rigid_body(v11, v10, v5, v9, v13);
}
