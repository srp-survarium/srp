void __usercall drawVertex(btIDebugDraw *idraw@<edi>, const btVector3 *x@<esi>, float s, const btVector3 *c)
{
  float v4; // xmm1_4
  int v5; // xmm2_4
  int v6; // xmm3_4
  btIDebugDraw_vtbl *v7; // eax
  float v8; // xmm1_4
  int v9; // xmm2_4
  int v10; // xmm3_4
  btIDebugDraw_vtbl *v11; // eax
  float v12; // xmm1_4
  int v13; // xmm2_4
  int v14; // xmm3_4
  btIDebugDraw_vtbl *v15; // eax
  float v16; // [esp+18h] [ebp-20h] BYREF
  float v17; // [esp+1Ch] [ebp-1Ch]
  float v18; // [esp+20h] [ebp-18h]
  int v19; // [esp+24h] [ebp-14h]
  float v20; // [esp+28h] [ebp-10h] BYREF
  float v21; // [esp+2Ch] [ebp-Ch]
  float v22; // [esp+30h] [ebp-8h]
  int v23; // [esp+34h] [ebp-4h]

  v4 = x->mVec128.m128_f32[0];
  v5 = x->mVec128.m128_i32[1];
  v6 = x->mVec128.m128_i32[2];
  v7 = idraw->__vftable;
  v16 = x->mVec128.m128_f32[0] + s;
  v17 = *(float *)&v5;
  v18 = *(float *)&v6;
  v19 = 0;
  v20 = v4 - s;
  v21 = *(float *)&v5;
  v22 = *(float *)&v6;
  v23 = 0;
  v7->drawLine(idraw, (const btVector3 *)&v20, (const btVector3 *)&v16, c);
  v8 = x->mVec128.m128_f32[1];
  v9 = x->mVec128.m128_i32[0];
  v10 = x->mVec128.m128_i32[2];
  v11 = idraw->__vftable;
  v21 = v8 + s;
  v20 = *(float *)&v9;
  v22 = *(float *)&v10;
  v23 = 0;
  v16 = *(float *)&v9;
  v17 = v8 - s;
  v18 = *(float *)&v10;
  v19 = 0;
  v11->drawLine(idraw, (const btVector3 *)&v16, (const btVector3 *)&v20, c);
  v12 = x->mVec128.m128_f32[2];
  v13 = x->mVec128.m128_i32[0];
  v14 = x->mVec128.m128_i32[1];
  v15 = idraw->__vftable;
  v22 = v12 + s;
  v20 = *(float *)&v13;
  v21 = *(float *)&v14;
  v23 = 0;
  v16 = *(float *)&v13;
  v17 = *(float *)&v14;
  v18 = v12 - s;
  v19 = 0;
  v15->drawLine(idraw, (const btVector3 *)&v16, (const btVector3 *)&v20, c);
}
