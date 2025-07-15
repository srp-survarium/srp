void __usercall btSparseSdf<3>::BuildCell(
        btSparseSdf<3> *this@<esi>,
        btSparseSdf<3>::Cell *c@<edi>,
        btMatrix3x3 *a3@<ecx>)
{
  float voxelsz; // xmm1_4
  const btConvexShape *pclient; // ebx
  bool v6; // cc
  float v7; // xmm0_4
  float *v8; // eax
  int v9; // [esp+4h] [ebp-C8h]
  int v10; // [esp+8h] [ebp-C4h]
  int v11; // [esp+Ch] [ebp-C0h]
  btSparseSdf<3>::Cell *v12; // [esp+10h] [ebp-BCh]
  float *v13; // [esp+14h] [ebp-B8h]
  btSparseSdf<3>::Cell *v14; // [esp+18h] [ebp-B4h]
  float v15; // [esp+1Ch] [ebp-B0h]
  float v16; // [esp+20h] [ebp-ACh]
  float v17; // [esp+24h] [ebp-A8h]
  btVector3 position; // [esp+2Ch] [ebp-A0h] BYREF
  btTransform shape0; // [esp+3Ch] [ebp-90h] BYREF
  btGjkEpaSolver2::sResults wtrs0; // [esp+7Ch] [ebp-50h] BYREF

  v11 = 0;
  voxelsz = this->voxelsz;
  v17 = voxelsz * (float)((float)c->c[2] * 3.0);
  v15 = voxelsz * (float)((float)c->c[0] * 3.0);
  v16 = voxelsz * (float)((float)c->c[1] * 3.0);
  position.mVec128.m128_i32[3] = 0;
  v14 = c;
  do
  {
    v9 = 0;
    position.mVec128.m128_f32[2] = (float)((float)v11 * this->voxelsz) + v17;
    v12 = v14;
    do
    {
      v10 = 0;
      position.mVec128.m128_f32[1] = (float)((float)v9 * this->voxelsz) + v16;
      v13 = (float *)v12;
      do
      {
        pclient = (const btConvexShape *)c->pclient;
        position.mVec128.m128_f32[0] = (float)((float)v10 * this->voxelsz) + v15;
        btMatrix3x3::setIdentity(a3, (int)&shape0);
        v6 = pclient->m_shapeType < 20;
        v7 = 0.0;
        memset(&shape0.m_origin, 0, sizeof(shape0.m_origin));
        if ( v6 )
          v7 = btGjkEpaSolver2::SignedDistance(&position, pclient, &shape0, &wtrs0);
        v8 = v13;
        ++v10;
        v13 += 16;
        *v8 = v7;
      }
      while ( v10 <= 3 );
      ++v9;
      v12 = (btSparseSdf<3>::Cell *)((char *)v12 + 16);
    }
    while ( v9 <= 3 );
    ++v11;
    v14 = (btSparseSdf<3>::Cell *)((char *)v14 + 4);
  }
  while ( v11 <= 3 );
}
