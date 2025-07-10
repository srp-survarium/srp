const struct SpeedTree::CCore *__cdecl ProcessCellInstances(
        struct SpeedTree::Vec4 *a1,
        int a2,
        int a3,
        SpeedTree::SForestCullResults *a4,
        SpeedTree::Vec3 *vIn,
        char a6)
{
  const struct SpeedTree::CCore *result; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // [esp+8h] [ebp-160h]
  const struct SpeedTree::CCore **v10; // [esp+70h] [ebp-F8h]
  float v11; // [esp+C4h] [ebp-A4h]
  int j; // [esp+C8h] [ebp-A0h]
  float v13; // [esp+CCh] [ebp-9Ch]
  struct SpeedTree::SInstanceLod v14; // [esp+D0h] [ebp-98h] BYREF
  SpeedTree::Vec3 *p_m_vPos; // [esp+F0h] [ebp-78h]
  float v16; // [esp+F4h] [ebp-74h]
  int k; // [esp+F8h] [ebp-70h]
  struct SpeedTree::SInstanceLod v18; // [esp+FCh] [ebp-6Ch] BYREF
  SpeedTree::Vec3 *v19; // [esp+11Ch] [ebp-4Ch]
  int i; // [esp+120h] [ebp-48h]
  int v21; // [esp+124h] [ebp-44h] BYREF
  const struct SpeedTree::CInstance *Instances; // [esp+128h] [ebp-40h]
  int v23; // [esp+12Ch] [ebp-3Ch]
  int nBaseTreeIndex; // [esp+130h] [ebp-38h]
  struct SpeedTree::SGeometry *p_m_sGeometry; // [esp+134h] [ebp-34h]
  struct SpeedTree::SLodProfile *p_m_sLodProfile; // [esp+138h] [ebp-30h]
  SpeedTree::CCore *v27; // [esp+13Ch] [ebp-2Ch]
  bool v28; // [esp+143h] [ebp-25h]
  float v29; // [esp+144h] [ebp-24h]
  SpeedTree::CCellInstances *v30; // [esp+148h] [ebp-20h]
  SpeedTree::CCellBaseTreeItr v31; // [esp+14Ch] [ebp-1Ch] BYREF
  float v32; // [esp+158h] [ebp-10h]
  int v33; // [esp+164h] [ebp-4h]

  v32 = SpeedTree::Vec3::Distance((SpeedTree::Vec3 *)(a2 + 40), vIn);
  v29 = v32 - *(float *)(a2 + 52);
  v30 = (SpeedTree::CCellInstances *)(a2 + 56);
  SpeedTree::CCellInstances::FirstBaseTree((SpeedTree::CCellInstances *)(a2 + 56), &v31);
  v33 = 0;
  while ( 1 )
  {
    result = SpeedTree::CCellBaseTreeItr::TreePtr(&v31);
    if ( !result )
      return result;
    v27 = (SpeedTree::CCore *)SpeedTree::CCellBaseTreeItr::TreePtr(&v31);
    p_m_sLodProfile = &v27->m_sLodProfile;
    p_m_sGeometry = &v27->m_sGeometry;
    v9 = !v27->m_sLodProfile.m_bLodIsPresent || p_m_sLodProfile->m_fBillboardFinalDistance > (double)v29;
    v28 = v9;
    if ( !v9 )
      goto LABEL_34;
    v21 = 0;
    Instances = SpeedTree::CCellInstances::GetInstances(v30, &v31, &v21);
    if ( Instances && v21 )
    {
      nBaseTreeIndex = -1;
      for ( i = 0; i < (signed int)a4->m_pBaseTrees->m_uiSize; ++i )
      {
        v10 = (const struct SpeedTree::CCore **)&a4->m_pBaseTrees->m_pData[i];
        if ( *v10 == SpeedTree::CCellBaseTreeItr::TreePtr(&v31) )
        {
          nBaseTreeIndex = i;
          break;
        }
      }
      v23 = SpeedTree::SForestCullResults::VisibleInstances(a4, (const SpeedTree::CCore *)nBaseTreeIndex);
      if ( a3 || p_m_sLodProfile->m_fBillboardFinalDistance <= (double)v29 && p_m_sLodProfile->m_bLodIsPresent )
      {
        v13 = p_m_sLodProfile->m_fBillboardFinalDistance * p_m_sLodProfile->m_fBillboardFinalDistance;
        v14.m_sLodSnapshot.m_nBranchLodIndex = -1;
        v14.m_sLodSnapshot.m_nFrondLodIndex = -1;
        v14.m_sLodSnapshot.m_nLeafCardLodIndex = -1;
        v14.m_sLodSnapshot.m_nLeafMeshLodIndex = -1;
        p_m_vPos = &Instances->m_vPos;
        for ( j = 0; j < v21; ++j )
        {
          v11 = SpeedTree::Vec3::DistanceSquared(p_m_vPos, vIn);
          if ( (!p_m_sLodProfile->m_bLodIsPresent || v13 > (double)v11)
            && !FrustumCullsSphere(a1, (SpeedTree::Vec3 *)((char *)p_m_vPos + 16), p_m_vPos[2].y) )
          {
            ComputeInstanceLodValues(
              &v14,
              p_m_sLodProfile,
              (const struct SpeedTree::CInstance *)p_m_vPos,
              v27,
              p_m_sGeometry,
              v11);
            if ( a6 )
            {
              v8 = SpeedTree::CArray<SpeedTree::SInstanceLod,1>::higher(&v14);
              SpeedTree::CArray<SpeedTree::SInstanceLod,1>::insert(v8, &v14);
            }
            else
            {
              SpeedTree::CArray<SpeedTree::SInstanceLod,1>::push_back(&v14);
            }
          }
          p_m_vPos += 3;
        }
      }
      else
      {
        v18.m_sLodSnapshot.m_nBranchLodIndex = -1;
        v18.m_sLodSnapshot.m_nFrondLodIndex = -1;
        v18.m_sLodSnapshot.m_nLeafCardLodIndex = -1;
        v18.m_sLodSnapshot.m_nLeafMeshLodIndex = -1;
        v19 = &Instances->m_vPos;
        for ( k = 0; k < v21; ++k )
        {
          v16 = SpeedTree::Vec3::DistanceSquared(v19, vIn);
          ComputeInstanceLodValues(
            &v18,
            p_m_sLodProfile,
            (const struct SpeedTree::CInstance *)v19,
            v27,
            p_m_sGeometry,
            v16);
          if ( a6 )
          {
            v7 = SpeedTree::CArray<SpeedTree::SInstanceLod,1>::higher(&v18);
            SpeedTree::CArray<SpeedTree::SInstanceLod,1>::insert(v7, &v18);
          }
          else
          {
            SpeedTree::CArray<SpeedTree::SInstanceLod,1>::push_back(&v18);
          }
          v19 += 3;
        }
      }
LABEL_34:
      SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::iterator_base::operator++(&v31);
    }
  }
}
