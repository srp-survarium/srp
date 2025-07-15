// bad sp value at call has been detected, the output may be wrong!
void __userpurge vostok::physics::bullet_physics_world::get_all_objects_in_radius(
        vostok::physics::bullet_physics_world *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const vostok::math::float3 *center,
        float radius,
        int filter_group,
        int filter_mask,
        stlp_std::priv::_STLP_alloc_proxy<void * *,void *,vostok::vectora_allocator<void *> > *results,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        btPairCachingGhostObject a24)
{
  btPairCachingGhostObject *v25; // ecx
  vostok::math::float4x4 *v26; // eax
  btCollisionObject *v27; // eax
  int v28; // eax
  int v29; // edi
  btPairCachingGhostObject ***v30; // eax
  btPairCachingGhostObject *v31; // ecx
  btPairCachingGhostObject *v32; // esi
  int v33; // eax
  int v34; // eax
  char v36; // [esp+24h] [ebp-200h] BYREF
  int v37; // [esp+28h] [ebp-1FCh]
  stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *> > v38; // [esp+2Ch] [ebp-1F8h] BYREF
  btPairCachingGhostObject v39; // [esp+64h] [ebp-1C0h] BYREF
  btMatrix3x3 v40; // [esp+1A4h] [ebp-80h] BYREF
  vostok::math::float4x4 v41; // [esp+1E4h] [ebp-40h] BYREF

  btSphereShape::btSphereShape((btSphereShape *)this, radius);
  btPairCachingGhostObject::btPairCachingGhostObject(v25, &v39);
  v39.m_collisionShape = (btCollisionShape *)&v36;
  v39.m_rootCollisionShape = (btCollisionShape *)&v36;
  v39.m_collisionFlags = 16;
  v26 = vostok::math::create_translation(center, &v41);
  v27 = (btCollisionObject *)vostok::physics::from_vostok(v26, &v40);
  btCollisionObject::setWorldTransform(v27, (btVector3 *)&v39);
  ((void (__thiscall *)(btSoftRigidDynamicsWorld *, btPairCachingGhostObject *, int, int, int, int, int))this->m_dynamicsWorld->addCollisionObject)(
    this->m_dynamicsWorld,
    &v39,
    filter_group,
    filter_mask,
    a3,
    a4,
    a2);
  btCollisionWorld::updateSingleAabb(this->m_dynamicsWorld, (btCollisionObject *)(&v39.__vftable + 3));
  ((void (__stdcall *)(_DWORD, btDispatcherInfo *, btDispatcher *))this->m_dynamicsWorld->m_dispatcher1->dispatchAllCollisionPairs)(
    *((_DWORD *)&v39.m_hashPairCache + 3),
    &this->m_dynamicsWorld->m_dispatchInfo,
    this->m_dynamicsWorld->m_dispatcher1);
  v28 = **((_DWORD **)&v39.m_hashPairCache + 3);
  v29 = 0;
  v37 = 0;
  if ( (*(int (__thiscall **)(_DWORD))(v28 + 32))(*((_DWORD *)&v39.m_hashPairCache + 3)) > 0 )
  {
    do
    {
      v30 = (btPairCachingGhostObject ***)(v29
                                         + *(_DWORD *)((*(int (__thiscall **)(_DWORD))(**((_DWORD **)&v39.m_hashPairCache
                                                                                        + 3)
                                                                                     + 24))(*((_DWORD *)&v39.m_hashPairCache
                                                                                            + 3))
                                                     + 12));
      v31 = **v30;
      v32 = *v30[1];
      if ( v31 != (btPairCachingGhostObject *)(&v39.__vftable + 3) )
        v32 = **v30;
      if ( vostok::physics::bullet_physics_world::contact_pair_test(
             (vostok::physics::bullet_physics_world *)v31,
             (btCollisionObject *)this,
             v31,
             *v30[1]) )
      {
        v38._M_start = (void **)v32->m_userObjectPointer;
        stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::push_back(&v38, results);
      }
      v33 = **((_DWORD **)&v39.m_hashPairCache + 3);
      ++v37;
      v29 += 16;
      v34 = (*(int (__thiscall **)(_DWORD))(v33 + 32))(*((_DWORD *)&v39.m_hashPairCache + 3));
    }
    while ( v37 < v34 );
  }
  this->m_dynamicsWorld->removeCollisionObject(this->m_dynamicsWorld, (btCollisionObject *)(&v39.__vftable + 3));
  btPairCachingGhostObject::~btPairCachingGhostObject(&a24);
}
