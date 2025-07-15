char __thiscall Opcode::AABBTreeOfTrianglesBuilder::ComputeGlobalBox(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        IceMaths::AABB *global_box)
{
  const unsigned int *v4; // edi
  const Opcode::MeshInterface *mIMesh; // eax
  const IceMaths::IndexedTriangle *mTris; // ebx
  const IceMaths::Point *mVerts; // esi
  const IceMaths::IndexedTriangle *v8; // eax
  float *p_x; // ecx
  float v10; // xmm7_4
  float *v11; // edx
  float *v12; // eax
  float v13; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float z; // xmm0_4
  float y; // xmm6_4
  IceMaths::Point v22; // [esp+4h] [ebp-1Ch] BYREF
  IceMaths::Point v23; // [esp+10h] [ebp-10h] BYREF
  float v24; // [esp+1Ch] [ebp-4h]
  float v25; // [esp+28h] [ebp+8h]

  v4 = primitives;
  if ( !primitives || !nb_prims )
    return 0;
  mIMesh = this->mIMesh;
  mTris = mIMesh->mTris;
  v23.x = FLOAT_3_4028235e38;
  v23.y = FLOAT_3_4028235e38;
  v23.z = FLOAT_3_4028235e38;
  mVerts = mIMesh->mVerts;
  v22.x = FLOAT_N3_4028235e38;
  v22.y = FLOAT_N3_4028235e38;
  v22.z = FLOAT_N3_4028235e38;
  do
  {
    --nb_prims;
    v8 = &mTris[*v4];
    p_x = &mVerts[v8->mVRef[0]].x;
    v10 = *p_x;
    v11 = &mVerts[v8->mVRef[1]].x;
    v12 = &mVerts[v8->mVRef[2]].x;
    ++v4;
    if ( *p_x <= v23.x )
      v23.x = *p_x;
    v24 = p_x[1];
    if ( v24 <= v23.y )
      v23.y = v24;
    v25 = p_x[2];
    if ( v25 <= v23.z )
      v23.z = p_x[2];
    v13 = *v11;
    if ( *v11 <= v23.x )
      v23.x = *v11;
    v14 = v11[1];
    if ( v14 <= v23.y )
      v23.y = v11[1];
    v15 = v11[2];
    if ( v15 <= v23.z )
      v23.z = v11[2];
    v16 = *v12;
    if ( *v12 <= v23.x )
      v23.x = *v12;
    v17 = v12[1];
    if ( v17 <= v23.y )
      v23.y = v12[1];
    v18 = v12[2];
    if ( v18 <= v23.z )
      v23.z = v12[2];
    if ( v22.x <= v10 )
      v22.x = v10;
    if ( v22.y <= v24 )
      v22.y = v24;
    z = v22.z;
    if ( v22.z <= v25 )
    {
      z = v25;
      v22.z = v25;
    }
    if ( v22.x <= v13 )
      v22.x = v13;
    y = v22.y;
    if ( v22.y <= v14 )
    {
      y = v14;
      v22.y = v14;
    }
    if ( z <= v15 )
    {
      z = v15;
      v22.z = v15;
    }
    if ( v22.x <= v16 )
      v22.x = v16;
    if ( y <= v17 )
      v22.y = v17;
    if ( z <= v18 )
      v22.z = v18;
  }
  while ( nb_prims );
  IceMaths::AABB::SetMinMax(&v23, &v22, global_box);
  return 1;
}
