void __thiscall vostok::physics::contact_result_callback::addSingleResult(
        vostok::physics::contact_result_callback *this,
        btManifoldPoint *__formal,
        const btCollisionObject *colObj0,
        int a4,
        int a5,
        const btCollisionObject *colObj1,
        int a7,
        int a8)
{
  void *m_userPointer; // esi
  vostok::physics::contact_test_predicate_vtbl *v9; // edi
  vostok::physics::primitive_type v10; // eax
  vostok::physics::contact_test_predicate *v11; // edx
  vostok::physics::primitive_type v12; // [esp-Ch] [ebp-BCh]
  int type; // [esp+Ch] [ebp-A4h]
  int m_shapeType; // [esp+14h] [ebp-9Ch]
  vostok::math::float3 shape_1_dim; // [esp+18h] [ebp-98h] BYREF
  vostok::math::float3 shape_0_dim; // [esp+24h] [ebp-8Ch] BYREF
  vostok::math::float4x4 shape_1_transform; // [esp+30h] [ebp-80h] BYREF
  vostok::math::float4x4 shape_0_transform; // [esp+70h] [ebp-40h] BYREF

  m_shapeType = colObj0->m_collisionShape->m_shapeType;
  vostok::physics::from_bullet(&colObj0->m_worldTransform);
  vostok::physics::dimensions_from_bullet_shape(colObj0->m_collisionShape);
  type = colObj1->m_collisionShape->m_shapeType;
  vostok::physics::from_bullet(&colObj1->m_worldTransform);
  vostok::physics::dimensions_from_bullet_shape(colObj1->m_collisionShape);
  m_userPointer = colObj0->m_collisionShape->m_userPointer;
  v9 = this->m_predicate->__vftable;
  v12 = vostok::physics::from_bullet_shape_type(type);
  v10 = vostok::physics::from_bullet_shape_type(m_shapeType);
  v9->add_single_result(
    v11,
    m_userPointer,
    v10,
    &shape_0_transform,
    &shape_0_dim,
    v12,
    &shape_1_transform,
    &shape_1_dim);
}
