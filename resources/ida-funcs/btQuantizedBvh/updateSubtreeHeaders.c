void __thiscall btQuantizedBvh::updateSubtreeHeaders(
        btQuantizedBvh *this,
        int leftChildNodexIndex,
        int rightChildNodexIndex,
        int a4)
{
  int v4; // edx
  int v5; // ecx
  const btQuantizedBvhNode *v6; // eax
  int m_escapeIndexOrTriangleIndex; // edx
  int v8; // edx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  char *v12; // edx
  void *v13; // edi
  btBvhSubtreeInfo *v14; // esi
  int v15; // esi
  int v16; // ecx
  char *v17; // edx
  _DWORD *v18; // edx
  int v19; // edi
  int v20; // esi
  bool v21; // zf
  void *v22; // edi
  int v23; // esi
  int v24; // [esp+Ch] [ebp-44h]
  int v25; // [esp+Ch] [ebp-44h]
  int v26; // [esp+10h] [ebp-40h]
  int v27; // [esp+10h] [ebp-40h]
  char *v28; // [esp+14h] [ebp-3Ch]
  char *v29; // [esp+14h] [ebp-3Ch]
  int v30; // [esp+18h] [ebp-38h]
  int v31; // [esp+18h] [ebp-38h]
  const btQuantizedBvhNode *v32; // [esp+1Ch] [ebp-34h]
  int v33; // [esp+20h] [ebp-30h]
  int v34; // [esp+24h] [ebp-2Ch]
  const btQuantizedBvhNode *v35; // [esp+28h] [ebp-28h]
  int v36; // [esp+2Ch] [ebp-24h]
  int v37; // [esp+2Ch] [ebp-24h]
  _BYTE v38[32]; // [esp+30h] [ebp-20h] BYREF

  v4 = *(_DWORD *)(leftChildNodexIndex + 148);
  v5 = *(_DWORD *)(v4 + 16 * rightChildNodexIndex + 12);
  v35 = (const btQuantizedBvhNode *)(v4 + 16 * rightChildNodexIndex);
  if ( v5 < 0 )
    v30 = -v5;
  else
    v30 = 1;
  v6 = (const btQuantizedBvhNode *)(v4 + 16 * a4);
  m_escapeIndexOrTriangleIndex = v6->m_escapeIndexOrTriangleIndex;
  v32 = v6;
  if ( m_escapeIndexOrTriangleIndex < 0 )
    v33 = -m_escapeIndexOrTriangleIndex;
  else
    v33 = 1;
  v8 = 16 * v33;
  if ( 16 * v30 <= 2048 )
  {
    v9 = *(_DWORD *)(leftChildNodexIndex + 164);
    v10 = *(_DWORD *)(leftChildNodexIndex + 168);
    v34 = v9;
    if ( v9 == v10 )
    {
      v24 = v9 ? 2 * v9 : 1;
      if ( v10 < v24 )
      {
        if ( v24 )
          v28 = (char *)btAlignedAllocInternal(32 * v24);
        else
          v28 = 0;
        v11 = *(_DWORD *)(leftChildNodexIndex + 164);
        if ( v11 > 0 )
        {
          v26 = 0;
          v12 = v28;
          do
          {
            if ( v12 )
            {
              qmemcpy(v12, (const void *)(v26 + *(_DWORD *)(leftChildNodexIndex + 172)), 0x20u);
              v9 = v34;
            }
            v26 += 32;
            v12 += 32;
            --v11;
          }
          while ( v11 );
        }
        if ( *(_DWORD *)(leftChildNodexIndex + 172) )
        {
          if ( *(_BYTE *)(leftChildNodexIndex + 176) )
            btAlignedFreeInternal(*(void **)(leftChildNodexIndex + 172));
          *(_DWORD *)(leftChildNodexIndex + 172) = 0;
        }
        *(_DWORD *)(leftChildNodexIndex + 172) = v28;
        *(_BYTE *)(leftChildNodexIndex + 176) = 1;
        *(_DWORD *)(leftChildNodexIndex + 168) = v24;
      }
    }
    ++*(_DWORD *)(leftChildNodexIndex + 164);
    v13 = (void *)(32 * v9 + *(_DWORD *)(leftChildNodexIndex + 172));
    if ( v13 )
      qmemcpy(v13, v38, 0x20u);
    v14 = (btBvhSubtreeInfo *)(32 * v9 + *(_DWORD *)(leftChildNodexIndex + 172));
    btBvhSubtreeInfo::setAabbFromQuantizeNode(v14, v35);
    v8 = 16 * v33;
    v14->m_rootNodeIndex = rightChildNodexIndex;
    v14->m_subtreeSize = v30;
    v6 = v32;
  }
  if ( v8 <= 2048 )
  {
    v15 = *(_DWORD *)(leftChildNodexIndex + 164);
    v16 = *(_DWORD *)(leftChildNodexIndex + 168);
    v36 = v15;
    if ( v15 == v16 )
    {
      v25 = v15 ? 2 * v15 : 1;
      if ( v16 < v25 )
      {
        if ( v25 )
        {
          v29 = (char *)btAlignedAllocInternal(32 * v25);
          v6 = v32;
        }
        else
        {
          v29 = 0;
        }
        if ( *(int *)(leftChildNodexIndex + 164) > 0 )
        {
          v31 = 0;
          v17 = v29;
          v27 = *(_DWORD *)(leftChildNodexIndex + 164);
          do
          {
            if ( v17 )
            {
              qmemcpy(v17, (const void *)(v31 + *(_DWORD *)(leftChildNodexIndex + 172)), 0x20u);
              v15 = v36;
            }
            v31 += 32;
            v17 += 32;
            --v27;
          }
          while ( v27 );
        }
        if ( *(_DWORD *)(leftChildNodexIndex + 172) )
        {
          if ( *(_BYTE *)(leftChildNodexIndex + 176) )
          {
            btAlignedFreeInternal(*(void **)(leftChildNodexIndex + 172));
            v6 = v32;
          }
          *(_DWORD *)(leftChildNodexIndex + 172) = 0;
        }
        *(_DWORD *)(leftChildNodexIndex + 172) = v29;
        *(_BYTE *)(leftChildNodexIndex + 176) = 1;
        *(_DWORD *)(leftChildNodexIndex + 168) = v25;
      }
    }
    ++*(_DWORD *)(leftChildNodexIndex + 164);
    v18 = (_DWORD *)(leftChildNodexIndex + 172);
    v19 = *(_DWORD *)(leftChildNodexIndex + 172);
    v20 = 32 * v15;
    v21 = v20 + v19 == 0;
    v22 = (void *)(v20 + v19);
    v37 = v20;
    if ( !v21 )
      qmemcpy(v22, v38, 0x20u);
    v23 = v20 + *v18;
    btBvhSubtreeInfo::setAabbFromQuantizeNode((btBvhSubtreeInfo *)(v37 + *v18), v6);
    *(_DWORD *)(v23 + 12) = a4;
    *(_DWORD *)(v23 + 16) = v33;
  }
  *(_DWORD *)(leftChildNodexIndex + 180) = *(_DWORD *)(leftChildNodexIndex + 164);
}
