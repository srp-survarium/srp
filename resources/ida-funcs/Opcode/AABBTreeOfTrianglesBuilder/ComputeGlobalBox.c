char __thiscall Opcode::AABBTreeOfTrianglesBuilder::ComputeGlobalBox(
        Opcode::AABBTreeOfTrianglesBuilder *this,
        const unsigned int *primitives,
        unsigned int nb_prims,
        IceMaths::AABB *global_box)
{
  const unsigned int *v4; // edi
  unsigned int v5; // ebx
  float v6; // xmm0_4
  const Opcode::MeshInterface *mIMesh; // eax
  const IceMaths::Point *mVerts; // edx
  const IceMaths::IndexedTriangle *mTris; // ebp
  float v10; // xmm3_4
  float y; // xmm2_4
  const IceMaths::IndexedTriangle *v12; // eax
  float x; // xmm1_4
  const IceMaths::Point *v14; // esi
  float *p_x; // ecx
  float *v16; // eax
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm7_4
  float z; // [esp+8h] [ebp-1Ch]
  IceMaths::Point Max; // [esp+Ch] [ebp-18h] BYREF
  IceMaths::Point Min; // [esp+18h] [ebp-Ch] BYREF
  float nb_primsa; // [esp+2Ch] [ebp+8h]

  v4 = primitives;
  if ( !primitives )
    return 0;
  v5 = nb_prims;
  if ( !nb_prims )
    return 0;
  v6 = 3.4028235e38;
  mIMesh = this->mIMesh;
  mVerts = mIMesh->mVerts;
  mTris = mIMesh->mTris;
  v10 = 3.4028235e38;
  y = 3.4028235e38;
  Min.x = 3.4028235e38;
  Min.y = 3.4028235e38;
  Min.z = 3.4028235e38;
  Max.x = -3.4028235e38;
  Max.y = -3.4028235e38;
  Max.z = -3.4028235e38;
  while ( 1 )
  {
    v12 = &mTris[*v4];
    x = mVerts[v12->mVRef[0]].x;
    v14 = &mVerts[v12->mVRef[0]];
    --v5;
    ++v4;
    p_x = &mVerts[v12->mVRef[1]].x;
    v16 = &mVerts[v12->mVRef[2]].x;
    if ( x <= v10 )
    {
      v10 = x;
      Min.x = x;
    }
    nb_primsa = v14->y;
    if ( nb_primsa <= y )
    {
      y = v14->y;
      Min.y = y;
    }
    z = v14->z;
    if ( z <= v6 )
    {
      v6 = v14->z;
      Min.z = v6;
    }
    v17 = *p_x;
    if ( *p_x <= v10 )
    {
      v10 = *p_x;
      Min.x = *p_x;
    }
    v18 = p_x[1];
    if ( v18 <= y )
    {
      y = p_x[1];
      Min.y = y;
    }
    v19 = p_x[2];
    if ( v19 <= v6 )
    {
      v6 = p_x[2];
      Min.z = v6;
    }
    v20 = *v16;
    if ( *v16 <= v10 )
      Min.x = *v16;
    v21 = v16[1];
    if ( v21 <= y )
      Min.y = v16[1];
    v22 = v16[2];
    if ( v22 <= v6 )
      Min.z = v16[2];
    if ( Max.x <= x )
      Max.x = x;
    if ( Max.y <= nb_primsa )
      Max.y = nb_primsa;
    v23 = Max.z;
    if ( Max.z <= z )
    {
      v23 = z;
      Max.z = z;
    }
    if ( Max.x <= v17 )
      Max.x = v17;
    v24 = Max.y;
    if ( Max.y <= v18 )
    {
      v24 = v18;
      Max.y = v18;
    }
    if ( v23 <= v19 )
    {
      v23 = v19;
      Max.z = v19;
    }
    if ( Max.x <= v20 )
      Max.x = v20;
    if ( v24 <= v21 )
      Max.y = v21;
    if ( v23 <= v22 )
      Max.z = v22;
    if ( !v5 )
      break;
    v10 = Min.x;
    y = Min.y;
    v6 = Min.z;
  }
  IceMaths::AABB::SetMinMax(&Min, &Max, global_box);
  return 1;
}
