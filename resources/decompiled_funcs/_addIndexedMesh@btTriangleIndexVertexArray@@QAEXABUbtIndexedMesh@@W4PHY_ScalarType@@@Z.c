void __userpurge btTriangleIndexVertexArray::addIndexedMesh(
        btTriangleIndexVertexArray *this@<ecx>,
        int a2@<esi>,
        const btIndexedMesh *mesh,
        PHY_ScalarType indexType)
{
  int v4; // ecx
  int v5; // eax
  int v6; // ebx
  _QWORD *v7; // ebp
  int v8; // edx
  _QWORD *v9; // ecx
  int v10; // edi
  int v11; // eax
  __int64 v12; // xmm0_8
  _QWORD *v13; // eax
  void *v14; // eax
  btIndexedMesh *v15; // eax

  v4 = *(_DWORD *)(a2 + 40);
  v5 = *(_DWORD *)(a2 + 36);
  if ( v5 == v4 )
  {
    v6 = 2 * v5;
    if ( !v5 )
      v6 = 1;
    if ( v4 < v6 )
    {
      if ( v6 )
      {
        ++gNumAlignedAllocs;
        v7 = sAlignedAllocFunc(32 * v6, 16);
      }
      else
      {
        v7 = 0;
      }
      if ( *(int *)(a2 + 36) > 0 )
      {
        v8 = 0;
        v9 = v7;
        v10 = *(_DWORD *)(a2 + 36);
        do
        {
          if ( v9 )
          {
            v11 = *(_DWORD *)(a2 + 44);
            v12 = *(_QWORD *)(v11 + v8);
            v13 = (_QWORD *)(v8 + v11);
            *v9 = v12;
            v9[1] = v13[1];
            v9[2] = v13[2];
            v9[3] = v13[3];
          }
          v8 += 32;
          v9 += 4;
          --v10;
        }
        while ( v10 );
      }
      v14 = *(void **)(a2 + 44);
      if ( v14 )
      {
        if ( *(_BYTE *)(a2 + 48) )
        {
          ++gNumAlignedFree;
          sAlignedFreeFunc(v14);
        }
        *(_DWORD *)(a2 + 44) = 0;
      }
      *(_DWORD *)(a2 + 44) = v7;
      *(_BYTE *)(a2 + 48) = 1;
      *(_DWORD *)(a2 + 40) = v6;
    }
  }
  v15 = (btIndexedMesh *)(*(_DWORD *)(a2 + 44) + 32 * *(_DWORD *)(a2 + 36));
  if ( v15 )
    *v15 = *mesh;
  ++*(_DWORD *)(a2 + 36);
  *(_DWORD *)(32 * *(_DWORD *)(a2 + 36) + *(_DWORD *)(a2 + 44) - 8) = 2;
}
