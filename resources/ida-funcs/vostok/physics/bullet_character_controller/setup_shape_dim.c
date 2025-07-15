void __userpurge vostok::physics::bullet_character_controller::setup_shape_dim(
        const vostok::math::float2 *shape_dim@<eax>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::physics::bullet_character_controller *this)
{
  float x; // xmm2_4
  btPairCachingGhostObject_vtbl *v6; // eax
  btDynamicsWorld *m_collision_world; // eax
  float v8; // [esp+8h] [ebp-Ch]

  x = shape_dim->x;
  v8 = (float)(shape_dim->y - shape_dim->x) * 0.5;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[0] = shape_dim->x * 0.5;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[1] = v8;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_f32[2] = x * 0.5;
  v6 = this->m_ghost_object.__vftable;
  this->m_shape.m_implicitShapeDimensions.mVec128.m128_i32[3] = 0;
  ((void (__stdcall *)(btCapsuleShape *, int, int, int))v6->setCollisionShape)(&this->m_shape, a3, a4, a2);
  m_collision_world = this->m_collision_world;
  if ( m_collision_world )
    this->m_ghost_object.m_hashPairCache->cleanProxyFromPairs(
      this->m_ghost_object.m_hashPairCache,
      this->m_ghost_object.m_broadphaseHandle,
      m_collision_world->m_dispatcher1);
}
