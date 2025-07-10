void __usercall drawBox(
        btIDebugDraw *idraw@<esi>,
        const btVector3 *mins@<ecx>,
        const btVector3 *maxs@<eax>,
        const btVector3 *color@<edi>)
{
  int v4; // xmm1_4
  int v5; // xmm2_4
  int v6; // xmm4_4
  int v7; // xmm5_4
  int v8; // xmm3_4
  void (__thiscall *drawLine)(btIDebugDraw *, const btVector3 *, const btVector3 *, const btVector3 *); // eax
  _DWORD v10[2]; // [esp+80h] [ebp-80h] BYREF
  int v11; // [esp+88h] [ebp-78h]
  int v12; // [esp+8Ch] [ebp-74h]
  _DWORD v13[4]; // [esp+90h] [ebp-70h] BYREF
  _DWORD v14[4]; // [esp+A0h] [ebp-60h] BYREF
  _DWORD v15[4]; // [esp+B0h] [ebp-50h] BYREF
  _DWORD v16[4]; // [esp+C0h] [ebp-40h] BYREF
  _DWORD v17[4]; // [esp+D0h] [ebp-30h] BYREF
  _DWORD v18[4]; // [esp+E0h] [ebp-20h] BYREF
  _DWORD v19[4]; // [esp+F0h] [ebp-10h] BYREF

  v4 = mins->mVec128.m128_i32[0];
  v5 = mins->mVec128.m128_i32[1];
  v6 = maxs->mVec128.m128_i32[0];
  v7 = maxs->mVec128.m128_i32[1];
  v11 = mins->mVec128.m128_i32[2];
  v13[2] = v11;
  v14[2] = v11;
  v15[2] = v11;
  v8 = maxs->mVec128.m128_i32[2];
  drawLine = idraw->drawLine;
  v10[0] = v4;
  v10[1] = v5;
  v12 = 0;
  v13[0] = v6;
  v13[1] = v5;
  v13[3] = 0;
  v14[0] = v6;
  v14[1] = v7;
  v14[3] = 0;
  v15[0] = v4;
  v15[1] = v7;
  v15[3] = 0;
  v16[0] = v4;
  v16[1] = v5;
  v16[2] = v8;
  v16[3] = 0;
  v17[0] = v6;
  v17[1] = v5;
  v17[2] = v8;
  v17[3] = 0;
  v18[0] = v6;
  v18[1] = v7;
  v18[2] = v8;
  v18[3] = 0;
  v19[0] = v4;
  v19[1] = v7;
  v19[2] = v8;
  v19[3] = 0;
  drawLine(idraw, (const btVector3 *)v10, (const btVector3 *)v13, color);
  idraw->drawLine(idraw, (const btVector3 *)v13, (const btVector3 *)v14, color);
  idraw->drawLine(idraw, (const btVector3 *)v14, (const btVector3 *)v15, color);
  idraw->drawLine(idraw, (const btVector3 *)v15, (const btVector3 *)v10, color);
  idraw->drawLine(idraw, (const btVector3 *)v16, (const btVector3 *)v17, color);
  idraw->drawLine(idraw, (const btVector3 *)v17, (const btVector3 *)v18, color);
  idraw->drawLine(idraw, (const btVector3 *)v18, (const btVector3 *)v19, color);
  idraw->drawLine(idraw, (const btVector3 *)v19, (const btVector3 *)v16, color);
  idraw->drawLine(idraw, (const btVector3 *)v10, (const btVector3 *)v16, color);
  idraw->drawLine(idraw, (const btVector3 *)v13, (const btVector3 *)v17, color);
  idraw->drawLine(idraw, (const btVector3 *)v14, (const btVector3 *)v18, color);
  idraw->drawLine(idraw, (const btVector3 *)v15, (const btVector3 *)v19, color);
}
