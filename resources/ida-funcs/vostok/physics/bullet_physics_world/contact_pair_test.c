char __thiscall vostok::physics::bullet_physics_world::contact_pair_test(
        vostok::physics::bullet_physics_world *this,
        btCollisionObject *first_object,
        btCollisionObject *second_object,
        btCollisionObject *colObjB)
{
  int v4; // edi
  btCollisionWorld::ContactResultCallback resultCallback; // [esp+8h] [ebp-Ch] BYREF
  char v7; // [esp+10h] [ebp-4h]

  resultCallback.m_collisionFilterGroup = 1;
  resultCallback.m_collisionFilterMask = -1;
  v4 = first_object->m_worldTransform.m_basis.m_el[2].mVec128.m128_i32[2];
  resultCallback.__vftable = (btCollisionWorld::ContactResultCallback_vtbl *)&vostok::physics::contact_result_callback::`vftable';
  v7 = 0;
  btCollisionWorld::contactPairTest(
    (btCollisionWorld *)this,
    v4,
    (btManifoldResult *)second_object,
    colObjB,
    &resultCallback);
  return v7;
}
