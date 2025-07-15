btDbvtProxy *__thiscall btDbvtBroadphase::createProxy(
        btDbvtBroadphase *this,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        int __formal,
        int userPtr,
        __int16 collisionFilterGroup,
        __int16 collisionFilterMask,
        btDispatcher *a8,
        void *a9)
{
  btVector3 *v9; // eax
  btDbvtProxy *v10; // ebx
  btDbvt *v11; // ecx
  btDbvtBroadphase *pbp; // esi
  int m_stageCurrent; // eax
  int v14; // eax
  btAlignedObjectArray<GrahamVector2> *m_root; // edi
  btAlignedObjectArray<GrahamVector2> *v16; // esi
  btDbvt *v18; // [esp-4h] [ebp-44h]
  btDbvtTreeCollider policy; // [esp+18h] [ebp-28h] BYREF
  btDbvtAabbMm vol; // [esp+20h] [ebp-20h] BYREF

  policy.pbp = this;
  v9 = (btVector3 *)btAlignedAllocInternal(0x40u);
  v10 = 0;
  v11 = v18;
  if ( v9 )
  {
    HIWORD(v11) = HIWORD(userPtr);
    v9->mVec128.m128_i32[0] = userPtr;
    v9->mVec128.m128_i16[2] = collisionFilterGroup;
    LOWORD(v11) = collisionFilterMask;
    v9->mVec128.m128_i16[3] = collisionFilterMask;
    v9[1] = (btVector3)aabbMin->mVec128;
    v9[2] = (btVector3)aabbMax->mVec128;
    v9->mVec128.m128_i32[2] = 0;
    v9[3].mVec128.m128_i32[2] = 0;
    v9[3].mVec128.m128_i32[1] = 0;
    v10 = (btDbvtProxy *)v9;
  }
  vol.mi = (btVector3)aabbMin->mVec128;
  vol.mx = (btVector3)aabbMax->mVec128;
  pbp = policy.pbp;
  v10->stage = policy.pbp->m_stageCurrent;
  v10->m_uniqueId = ++pbp->m_gid;
  v10->leaf = btDbvt::insert(v11, pbp->m_sets, &vol, (int)v10);
  m_stageCurrent = pbp->m_stageCurrent;
  v10->links[0] = 0;
  v14 = (int)&pbp->m_stageRoots[m_stageCurrent];
  v10->links[1] = *(btDbvtProxy **)v14;
  if ( *(_DWORD *)v14 )
    *(_DWORD *)(*(_DWORD *)v14 + 52) = v10;
  *(_DWORD *)v14 = v10;
  if ( !pbp->m_deferedcollide )
  {
    m_root = (btAlignedObjectArray<GrahamVector2> *)pbp->m_sets[0].m_root;
    policy.pbp = pbp;
    policy.proxy = v10;
    if ( m_root )
      btDbvt::collideTV<btDbvtTreeCollider>(&vol, m_root, &policy);
    v16 = (btAlignedObjectArray<GrahamVector2> *)pbp->m_sets[1].m_root;
    if ( v16 )
      btDbvt::collideTV<btDbvtTreeCollider>(&vol, v16, &policy);
  }
  return v10;
}
