void __userpurge btSparseSdf<3>::BuildCell(
        btSparseSdf<3> *this@<ecx>,
        btGjkEpaSolver2::sResults *a2@<edi>,
        btSparseSdf<3> *c,
        btSparseSdf<3>::Cell *ca)
{
  btSparseSdf<3>::Cell *v4; // ecx
  float voxelsz; // xmm0_4
  float v6; // xmm3_4
  const vostok::math::float4x4 *v7; // xmm2_4
  int v8; // eax
  float *v9; // edi
  float v10; // xmm0_4
  int v11; // eax
  int v12; // esi
  float v13; // eax
  bool v14; // cc
  float v15; // xmm0_4
  btGjkEpaSolver2::sResults *v16; // [esp+214h] [ebp-D0h]
  btSparseSdf<3>::Cell *v17; // [esp+224h] [ebp-C0h]
  int v18; // [esp+228h] [ebp-BCh]
  float *v19; // [esp+22Ch] [ebp-B8h]
  int v20; // [esp+230h] [ebp-B4h]
  float v21; // [esp+234h] [ebp-B0h]
  float v22; // [esp+238h] [ebp-ACh]
  float v23; // [esp+23Ch] [ebp-A8h]
  btVector3 position; // [esp+244h] [ebp-A0h] BYREF
  btTransform wtrs0; // [esp+254h] [ebp-90h] BYREF
  btConvexShape shape0; // [esp+294h] [ebp-50h] BYREF

  v4 = ca;
  voxelsz = c->voxelsz;
  v6 = voxelsz * (float)((float)ca->c[0] * 3.0);
  v16 = a2;
  v7 = clear_value;
  v8 = 0;
  v9 = (float *)ca;
  v21 = v6;
  v22 = voxelsz * (float)((float)ca->c[1] * 3.0);
  v23 = voxelsz * (float)((float)ca->c[2] * 3.0);
  v18 = 0;
  position.mVec128.m128_i32[3] = 0;
  v17 = ca;
  do
  {
    v10 = (float)((float)v8 * c->voxelsz) + v23;
    v11 = 0;
    v20 = 0;
    position.mVec128.m128_f32[2] = v10;
    v19 = v9;
    do
    {
      v12 = 0;
      position.mVec128.m128_f32[1] = (float)((float)v11 * c->voxelsz) + v22;
      do
      {
        v13 = *(float *)&v4->pclient;
        v14 = *(_DWORD *)(LODWORD(v13) + 4) < 20;
        v15 = (float)((float)v12 * c->voxelsz) + v6;
        position.mVec128.m128_f32[0] = v15;
        wtrs0.m_basis.m_el[0].mVec128.m128_u64[0] = (unsigned int)v7;
        memset(&wtrs0.m_basis.m_el[0].m_floats[2], 0, 12);
        *(unsigned __int64 *)((char *)wtrs0.m_basis.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)v7;
        memset(&wtrs0.m_basis.m_el[1].m_floats[3], 0, 12);
        wtrs0.m_basis.m_el[2].mVec128.m128_u64[1] = (unsigned int)v7;
        memset(&wtrs0.m_origin, 0, sizeof(wtrs0.m_origin));
        if ( v14 )
        {
          btGjkEpaSolver2::SignedDistance(&position, v13, &shape0, &wtrs0, v16);
          v6 = v21;
          v7 = clear_value;
          v4 = ca;
        }
        else
        {
          v15 = 0.0;
        }
        *v9 = v15;
        ++v12;
        v9 += 16;
      }
      while ( v12 <= 3 );
      v11 = v20 + 1;
      v9 = v19 + 4;
      v14 = ++v20 <= 3;
      v19 += 4;
    }
    while ( v14 );
    v8 = v18 + 1;
    v9 = &v17->d[0][0][1];
    v14 = ++v18 <= 3;
    v17 = (btSparseSdf<3>::Cell *)((char *)v17 + 4);
  }
  while ( v14 );
}
