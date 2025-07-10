void __usercall drawVertex(btIDebugDraw *idraw@<edi>, const btVector3 *x@<esi>, float s, const btVector3 *c)
{
  float v4; // xmm0_4
  int v5; // xmm2_4
  void (__thiscall *drawLine)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // eax
  float v7; // xmm0_4
  int v8; // xmm1_4
  void (__thiscall *v9)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // edx
  int v10; // xmm2_4
  float v11; // xmm0_4
  int v12; // xmm1_4
  int v13; // xmm2_4
  void (__thiscall *v14)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // eax
  float v15; // [esp+18h] [ebp-20h] BYREF
  float v16; // [esp+1Ch] [ebp-1Ch]
  float v17; // [esp+20h] [ebp-18h]
  int v18; // [esp+24h] [ebp-14h]
  float v19; // [esp+28h] [ebp-10h] BYREF
  float v20; // [esp+2Ch] [ebp-Ch]
  float v21; // [esp+30h] [ebp-8h]
  int v22; // [esp+34h] [ebp-4h]

  v4 = x->mVec128.m128_f32[0];
  v5 = x->mVec128.m128_i32[2];
  drawLine = idraw->drawLine;
  v15 = x->mVec128.m128_f32[0] + s;
  v16 = x->mVec128.m128_f32[1];
  v17 = *(float *)&v5;
  v18 = 0;
  v19 = v4 - s;
  v20 = v16;
  v21 = *(float *)&v5;
  v22 = 0;
  drawLine(idraw, (const btVector3 *)&v19, (const btVector3 *)&v15, c);
  v7 = x->mVec128.m128_f32[1];
  v8 = x->mVec128.m128_i32[0];
  v9 = idraw->drawLine;
  v20 = v7 + s;
  v10 = x->mVec128.m128_i32[2];
  v19 = *(float *)&v8;
  v21 = *(float *)&v10;
  v22 = 0;
  v15 = *(float *)&v8;
  v16 = v7 - s;
  v17 = *(float *)&v10;
  v18 = 0;
  v9(idraw, (const btVector3 *)&v15, (const btVector3 *)&v19, c);
  v11 = x->mVec128.m128_f32[2];
  v12 = x->mVec128.m128_i32[0];
  v13 = x->mVec128.m128_i32[1];
  v14 = idraw->drawLine;
  v21 = v11 + s;
  v19 = *(float *)&v12;
  v20 = *(float *)&v13;
  v22 = 0;
  v15 = *(float *)&v12;
  v16 = *(float *)&v13;
  v17 = v11 - s;
  v18 = 0;
  v14(idraw, (const btVector3 *)&v15, (const btVector3 *)&v19, c);
}
