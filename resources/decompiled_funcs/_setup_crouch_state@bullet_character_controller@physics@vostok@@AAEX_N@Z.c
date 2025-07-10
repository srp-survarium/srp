void __usercall vostok::physics::bullet_character_controller::setup_crouch_state(
        vostok::physics::bullet_character_controller *this@<ecx>,
        bool crouch@<al>,
        int a3@<esi>)
{
  unsigned __int64 v4; // xmm0_8
  float y; // ecx
  float x; // xmm0_4
  float v7; // xmm1_4
  float v8; // eax
  float v9; // xmm0_4
  btPairCachingGhostObject *m_ghost_object; // eax
  btDynamicsWorld *m_collision_world; // eax
  unsigned __int64 v13; // [esp+3Ch] [ebp-20h]
  unsigned __int64 v14; // [esp+3Ch] [ebp-20h]
  unsigned __int64 v15; // [esp+3Ch] [ebp-20h]
  unsigned __int64 v16; // [esp+44h] [ebp-18h]
  unsigned __int64 v17; // [esp+4Ch] [ebp-10h]
  float v18; // [esp+54h] [ebp-8h]

  v17 = this->m_shape_offset.mVec128.m128_u64[0];
  v4 = this->m_shape_offset.mVec128.m128_u64[1];
  this->m_in_crouch = crouch;
  v18 = *(float *)&v4;
  if ( crouch )
  {
    y = this->m_crouch_shape_dim.y;
    this->m_current_shape_dim.x = this->m_crouch_shape_dim.x;
    this->m_current_shape_dim.y = y;
    x = this->m_current_shape_dim.x;
    *(float *)&v13 = x * 0.5;
    *((float *)&v13 + 1) = (float)(this->m_current_shape_dim.y - x) * 0.5;
    this->m_shape.m_implicitShapeDimensions.mVec128.m128_u64[0] = v13;
    this->m_shape.m_implicitShapeDimensions.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(x * 0.5);
    v7 = this->m_crouch_shape_dim.y;
  }
  else
  {
    v8 = this->m_stand_shape_dim.y;
    this->m_current_shape_dim.x = this->m_stand_shape_dim.x;
    this->m_current_shape_dim.y = v8;
    v9 = this->m_current_shape_dim.x;
    *(float *)&v14 = v9 * 0.5;
    *((float *)&v14 + 1) = (float)(this->m_current_shape_dim.y - v9) * 0.5;
    this->m_shape.m_implicitShapeDimensions.mVec128.m128_u64[0] = v14;
    this->m_shape.m_implicitShapeDimensions.mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v9 * 0.5);
    v7 = this->m_stand_shape_dim.y;
  }
  this->m_shape_offset.mVec128.m128_i32[3] = 0;
  this->m_shape_offset.mVec128.m128_i32[2] = 0;
  this->m_shape_offset.mVec128.m128_f32[1] = v7 * 0.5;
  this->m_shape_offset.mVec128.m128_i32[0] = 0;
  m_ghost_object = this->m_ghost_object;
  v15 = m_ghost_object->m_worldTransform.m_origin.mVec128.m128_u64[0];
  v16 = m_ghost_object->m_worldTransform.m_origin.mVec128.m128_u64[1];
  *((float *)&v15 + 1) = *((float *)&v15 + 1) - (float)(*((float *)&v17 + 1) - this->m_shape_offset.mVec128.m128_f32[1]);
  *(float *)&v16 = *(float *)&v16 - (float)(v18 - this->m_shape_offset.mVec128.m128_f32[2]);
  *(float *)&v15 = *(float *)&v15 - (float)(*(float *)&v17 - this->m_shape_offset.mVec128.m128_f32[0]);
  m_ghost_object->m_worldTransform.m_origin.mVec128.m128_u64[0] = v15;
  m_ghost_object->m_worldTransform.m_origin.mVec128.m128_u64[1] = v16;
  btCollisionObject::setInterpolationWorldTransform(this->m_ghost_object, &this->m_ghost_object->m_worldTransform);
  ((void (__thiscall *)(btPairCachingGhostObject *, btCapsuleShape *, int))this->m_ghost_object->setCollisionShape)(
    this->m_ghost_object,
    &this->m_shape,
    a3);
  m_collision_world = this->m_collision_world;
  if ( m_collision_world )
    this->m_ghost_object->m_hashPairCache->cleanProxyFromPairs(
      this->m_ghost_object->m_hashPairCache,
      this->m_ghost_object->m_broadphaseHandle,
      m_collision_world->m_dispatcher1);
}
