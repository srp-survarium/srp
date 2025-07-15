void __thiscall btQuantizedBvh::walkStacklessTree(
        btQuantizedBvh *this,
        btNodeOverlapCallback *nodeCallback,
        const btVector3 *aabbMin,
        const btVector3 *aabbMax,
        float *a5)
{
  int v6; // edx
  btNodeOverlapCallback_vtbl *v7; // esi
  unsigned __int8 v8; // cl
  int v9; // edi
  void (__thiscall *v10)(btNodeOverlapCallback *); // eax
  int v11; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h]
  bool v13; // [esp+1Bh] [ebp+Bh]

  v6 = 0;
  v7 = nodeCallback[27].__vftable;
  v12 = 0;
  while ( v12 < (int)nodeCallback[17].__vftable )
  {
    v11 = ++v6;
    v8 = 1;
    if ( aabbMax->mVec128.m128_f32[0] > *(float *)&v7[2].~btNodeOverlapCallback
      || *(float *)&v7->~btNodeOverlapCallback > *a5 )
    {
      v8 = 0;
    }
    if ( aabbMax->mVec128.m128_f32[2] > *(float *)&v7[3].~btNodeOverlapCallback
      || *(float *)&v7[1].~btNodeOverlapCallback > a5[2] )
    {
      v8 = 0;
    }
    if ( aabbMax->mVec128.m128_f32[1] > *(float *)&v7[2].processNode || *(float *)&v7->processNode > a5[1] )
      v8 = 0;
    v9 = v8;
    v13 = v7[4].~btNodeOverlapCallback == (void (__thiscall *)(btNodeOverlapCallback *))-1;
    if ( v7[4].~btNodeOverlapCallback == (void (__thiscall *)(btNodeOverlapCallback *))-1 )
    {
      if ( !v8 )
        goto LABEL_15;
      (*(void (__thiscall **)(const btVector3 *, _DWORD, void (__thiscall *)(btNodeOverlapCallback *)))(aabbMin->mVec128.m128_i32[0] + 4))(
        aabbMin,
        v7[4].processNode,
        v7[5].~btNodeOverlapCallback);
      v6 = v11;
    }
    if ( v9 )
      goto LABEL_17;
LABEL_15:
    if ( v13 )
    {
LABEL_17:
      v7 += 8;
      ++v12;
      continue;
    }
    v10 = v7[4].~btNodeOverlapCallback;
    v7 += 8 * (_DWORD)v10;
    v12 += (int)v10;
  }
  if ( maxIterations < v6 )
    maxIterations = v6;
}
