btDbvtProxy *__thiscall btDbvtBroadphase::createProxy(
        btDbvtBroadphase *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int __formal,
        void *userPtr,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask,
        btDispatcher *a8,
        void *a9)
{
  btDbvtProxy *v10; // eax
  btDbvt *v11; // ecx
  btDbvtProxy *v12; // eax
  btDbvtProxy *v13; // ebx
  int m_stageCurrent; // edx
  unsigned __int64 v15; // xmm0_8
  btDbvtProxy **v16; // eax
  btDbvtNode *m_root; // edi
  btDbvtNode *v18; // esi
  btDbvtTreeCollider policy; // [esp+60h] [ebp-28h] BYREF
  btDbvtAabbMm volume; // [esp+68h] [ebp-20h] BYREF

  ++gNumAlignedAllocs;
  v10 = (btDbvtProxy *)sAlignedAllocFunc(0x40u, 16);
  if ( v10 )
  {
    btDbvtProxy::btDbvtProxy(v10, userPtr, collisionFilterGroup, collisionFilterMask);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  m_stageCurrent = this->m_stageCurrent;
  volume.mi = (btVector3)aabbMin->mVec128;
  volume.mx.mVec128.m128_u64[0] = aabbMax->mVec128.m128_u64[0];
  v15 = aabbMax->mVec128.m128_u64[1];
  v13->stage = m_stageCurrent;
  v13->m_uniqueId = ++this->m_gid;
  volume.mx.mVec128.m128_u64[1] = v15;
  v13->leaf = btDbvt::insert(v11, &volume, v13);
  v16 = &this->m_stageRoots[this->m_stageCurrent];
  v13->links[0] = 0;
  v13->links[1] = *v16;
  if ( *v16 )
    (*v16)->links[0] = v13;
  *v16 = v13;
  if ( !this->m_deferedcollide )
  {
    m_root = this->m_sets[0].m_root;
    policy.pbp = this;
    policy.proxy = v13;
    if ( m_root )
      btDbvt::collideTV<btDbvtTreeCollider>(&volume, m_root, &policy);
    v18 = this->m_sets[1].m_root;
    if ( v18 )
      btDbvt::collideTV<btDbvtTreeCollider>(&volume, v18, &policy);
  }
  return v13;
}
