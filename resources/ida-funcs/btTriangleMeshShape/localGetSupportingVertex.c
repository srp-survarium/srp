btVector3 *__thiscall btTriangleMeshShape::localGetSupportingVertex(
        btTriangleMeshShape *this,
        btVector3 *result,
        const btVector3 *vec)
{
  float v4; // xmm4_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  btTriangleMeshShape_vtbl *v7; // eax
  btVector3 *v8; // eax
  float v9; // [esp+10h] [ebp-E0h] BYREF
  float v10; // [esp+14h] [ebp-DCh]
  float v11; // [esp+18h] [ebp-D8h]
  int v12; // [esp+1Ch] [ebp-D4h]
  _DWORD v13[4]; // [esp+20h] [ebp-D0h] BYREF
  float v14; // [esp+30h] [ebp-C0h] BYREF
  float v15; // [esp+34h] [ebp-BCh]
  float v16; // [esp+38h] [ebp-B8h]
  int v17; // [esp+3Ch] [ebp-B4h]
  float v18; // [esp+40h] [ebp-B0h]
  float v19; // [esp+44h] [ebp-ACh]
  float v20; // [esp+48h] [ebp-A8h]
  int v21; // [esp+4Ch] [ebp-A4h]
  float v22; // [esp+50h] [ebp-A0h]
  float v23; // [esp+54h] [ebp-9Ch]
  float v24; // [esp+58h] [ebp-98h]
  int v25; // [esp+5Ch] [ebp-94h]
  int v26; // [esp+60h] [ebp-90h]
  int v27; // [esp+64h] [ebp-8Ch]
  int v28; // [esp+68h] [ebp-88h]
  int v29; // [esp+6Ch] [ebp-84h]
  _DWORD v30[8]; // [esp+70h] [ebp-80h] BYREF
  float v31; // [esp+90h] [ebp-60h]
  float v32; // [esp+94h] [ebp-5Ch]
  float v33; // [esp+98h] [ebp-58h]
  int v34; // [esp+9Ch] [ebp-54h]
  float v35; // [esp+A0h] [ebp-50h]
  float v36; // [esp+A4h] [ebp-4Ch]
  float v37; // [esp+A8h] [ebp-48h]
  int v38; // [esp+ACh] [ebp-44h]
  float v39; // [esp+B0h] [ebp-40h]
  float v40; // [esp+B4h] [ebp-3Ch]
  float v41; // [esp+B8h] [ebp-38h]
  int v42; // [esp+BCh] [ebp-34h]
  int v43; // [esp+C0h] [ebp-30h]
  int v44; // [esp+C4h] [ebp-2Ch]
  int v45; // [esp+C8h] [ebp-28h]
  int v46; // [esp+CCh] [ebp-24h]
  float v47; // [esp+D0h] [ebp-20h]
  float v48; // [esp+E0h] [ebp-10h]
  float v49; // [esp+E4h] [ebp-Ch]
  float v50; // [esp+E8h] [ebp-8h]
  int v51; // [esp+ECh] [ebp-4h]

  btMatrix3x3::setIdentity((btMatrix3x3 *)this, (int)&v14);
  v30[0] = &SupportVertexCallback::`vftable';
  memset(&v30[4], 0, 16);
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v31 = v14;
  v32 = v15;
  v33 = v16;
  v34 = v17;
  v35 = v18;
  v36 = v19;
  v37 = v20;
  v38 = v21;
  v4 = vec->mVec128.m128_f32[1];
  v5 = vec->mVec128.m128_f32[0];
  v6 = vec->mVec128.m128_f32[2];
  v39 = v22;
  v40 = v23;
  v41 = v24;
  v42 = v25;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v9 = (float)((float)(v5 * v14) + (float)(v4 * v18)) + (float)(v6 * v22);
  v46 = 0;
  v47 = FLOAT_N9_9999998e17;
  v12 = 0;
  v11 = (float)((float)(v5 * v16) + (float)(v4 * v20)) + (float)(v6 * v24);
  v10 = (float)((float)(v5 * v15) + (float)(v4 * v19)) + (float)(v6 * v23);
  v48 = v9;
  v49 = v10;
  v50 = v11;
  v51 = 0;
  *(float *)v13 = FLOAT_9_9999998e17;
  *(float *)&v13[1] = FLOAT_9_9999998e17;
  v7 = this->__vftable;
  *(float *)&v13[2] = FLOAT_9_9999998e17;
  v13[3] = 0;
  v9 = FLOAT_N9_9999998e17;
  v10 = FLOAT_N9_9999998e17;
  v11 = FLOAT_N9_9999998e17;
  v12 = 0;
  v7->processAllTriangles(this, (btTriangleCallback *)v30, (const btVector3 *)&v9, (const btVector3 *)v13);
  v8 = result;
  *result = *(btVector3 *)&v30[4];
  return v8;
}
