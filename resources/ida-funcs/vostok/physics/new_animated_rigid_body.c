vostok::physics::bt_animated_rigid_body *__usercall vostok::physics::new_animated_rigid_body@<eax>(
        vostok::memory::base_allocator *allocator@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        btCompoundShape *shape)
{
  btCompoundShape_vtbl *v6; // eax
  btRigidBody::btRigidBodyConstructionInfo *v7; // eax
  btRigidBody *v8; // esi
  char *v9; // eax
  vostok::physics::base_physics_object *v10; // ecx
  vostok::physics::bt_animated_rigid_body *v11; // edi
  vostok::physics::bt_animated_rigid_body *result; // eax
  struct btMotionState *v14; // [esp+14h] [ebp-B4h]
  struct btCollisionShape *v15; // [esp+18h] [ebp-B0h] BYREF
  const struct btVector3 *v16; // [esp+1Ch] [ebp-ACh]
  int v17; // [esp+20h] [ebp-A8h]
  btRigidBody::btRigidBodyConstructionInfo v18; // [esp+24h] [ebp-A4h] BYREF

  v6 = shape->__vftable;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18.m_mass = 0.0;
  ((void (__thiscall *)(btCompoundShape *, _DWORD, struct btCollisionShape **, int, int, int))v6->calculateLocalInertia)(
    shape,
    0.0,
    &v15,
    a3,
    a4,
    a2);
  btRigidBody::btRigidBodyConstructionInfo::btRigidBodyConstructionInfo(
    &v18,
    (int)shape,
    0,
    &v18.m_startWorldTransform,
    v14,
    v15,
    v16);
  v7 = (btRigidBody::btRigidBodyConstructionInfo *)btAlignedAllocInternal(0x290u);
  if ( v7 )
    v8 = btRigidBody::btRigidBody(
           (btRigidBody *)&v18.m_startWorldTransform,
           v7,
           (const btRigidBody::btRigidBodyConstructionInfo *)&v18.m_startWorldTransform);
  else
    v8 = 0;
  v8->m_collisionFlags = 1;
  v9 = type_info::raw_name(&vostok::physics::bt_animated_rigid_body `RTTI Type Descriptor');
  v11 = (vostok::physics::bt_animated_rigid_body *)allocator->call_malloc(
                                                     allocator,
                                                     64,
                                                     v9,
                                                     "vostok::physics::new_animated_rigid_body",
                                                     ".\\animated_rigid_body.cpp",
                                                     209);
  if ( v11 )
  {
    vostok::physics::base_physics_object::base_physics_object(v10, v11, vostok::physics::g_allocator);
    v11->__vftable = (vostok::physics::bt_animated_rigid_body_vtbl *)&vostok::physics::bt_animated_rigid_body::`vftable';
    v11->m_recompute_bones_callback.vtable = 0;
    v11->m_game_material_id = 10;
    v11->m_bt_body = v8;
    v11->m_shape = shape;
    v8->m_userObjectPointer = v11;
    result = v11;
  }
  else
  {
    result = 0;
  }
  shape->m_children.m_data[shape->m_children.m_size - 1].m_childShape->m_userPointer = (char *)&result->__vftable + 1;
  return result;
}
