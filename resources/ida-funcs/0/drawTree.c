void __cdecl drawTree(
        btIDebugDraw *idraw,
        const btDbvtNode *node,
        int depth,
        const btVector3 *ncolor,
        const btVector3 *lcolor,
        int mindepth,
        int maxdepth)
{
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm7_4
  float v10; // xmm3_4
  const btVector3 *v11; // edi
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  unsigned int v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm2_4
  float v19; // xmm3_4
  float v20; // [esp+14h] [ebp-2Ch]
  float v21; // [esp+18h] [ebp-28h]
  btVector3 v22; // [esp+20h] [ebp-20h] BYREF
  btVector3 v23; // [esp+30h] [ebp-10h] BYREF

  if ( node )
  {
    if ( node->childs[1] && (depth < maxdepth || maxdepth < 0) )
    {
      drawTree(idraw, node->childs[0], depth + 1, ncolor, lcolor, mindepth, maxdepth);
      drawTree(idraw, node->childs[1], depth + 1, ncolor, lcolor, mindepth, maxdepth);
    }
    if ( depth >= mindepth )
    {
      v7 = node->volume.mi.mVec128.m128_f32[0];
      v8 = node->volume.mi.mVec128.m128_f32[1];
      v9 = node->volume.mi.mVec128.m128_f32[2];
      v10 = node->volume.mx.mVec128.m128_f32[2];
      v11 = lcolor;
      if ( node->childs[1] )
        v11 = ncolor;
      v12 = (float)(node->volume.mx.mVec128.m128_f32[0] - v7) * 0.5;
      v13 = node->volume.mx.mVec128.m128_f32[0];
      v22.mVec128.m128_f32[1] = (float)(node->volume.mx.mVec128.m128_f32[1] - v8) * 0.5;
      v14 = node->volume.mx.mVec128.m128_f32[1];
      v22.mVec128.m128_f32[2] = (float)(v10 - v9) * 0.5;
      *(float *)&v15 = (float)((float)(node->volume.mx.mVec128.m128_f32[2] + v9) * 0.5) - v22.mVec128.m128_f32[2];
      v23.mVec128.m128_f32[0] = (float)((float)(v13 + v7) * 0.5) - v12;
      v16 = node->volume.mx.mVec128.m128_f32[0];
      v23.mVec128.m128_f32[1] = (float)((float)(v14 + v8) * 0.5) - v22.mVec128.m128_f32[1];
      v17 = node->volume.mx.mVec128.m128_f32[1];
      v23.mVec128.m128_u64[1] = v15;
      v20 = (float)(v17 - v8) * 0.5;
      v18 = node->volume.mx.mVec128.m128_f32[1];
      v21 = (float)(node->volume.mx.mVec128.m128_f32[2] - v9) * 0.5;
      v19 = node->volume.mx.mVec128.m128_f32[2];
      v22.mVec128.m128_f32[0] = (float)((float)(node->volume.mx.mVec128.m128_f32[0] + v7) * 0.5)
                              + (float)((float)(v16 - v7) * 0.5);
      v22.mVec128.m128_f32[1] = (float)((float)(v18 + v8) * 0.5) + v20;
      v22.mVec128.m128_f32[2] = (float)((float)(v19 + v9) * 0.5) + v21;
      v22.mVec128.m128_i32[3] = 0;
      drawBox(idraw, &v23, &v22, v11);
    }
  }
}
