void __usercall btSoftBody::cleanupClusters(btSoftBody *this@<ecx>, int a2@<esi>)
{
  int v2; // edi
  int *v3; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  _DWORD *v8; // ecx
  int v9; // ecx
  int *v10; // edx
  int v11; // ebx
  int v12; // edi
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(a2 + 860); ++i )
  {
    v2 = 4 * i;
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(4 * i + *(_DWORD *)(a2 + 868)) + 12))(*(float *)(a2 + 460));
    if ( *(_BYTE *)(*(_DWORD *)(4 * i + *(_DWORD *)(a2 + 868)) + 176) )
    {
      btAlignedFreeInternal(*(void **)(v2 + *(_DWORD *)(a2 + 868)));
      v3 = (int *)(v2 + *(_DWORD *)(a2 + 868));
      v4 = *(_DWORD *)(a2 + 860);
      v5 = 0;
      v6 = v4;
      if ( v4 > 0 )
      {
        v7 = *v3;
        v8 = *(_DWORD **)(a2 + 868);
        while ( *v8 != v7 )
        {
          ++v5;
          ++v8;
          if ( v5 >= v4 )
            goto LABEL_9;
        }
        v6 = v5;
      }
LABEL_9:
      if ( v6 < v4 )
      {
        v9 = *(_DWORD *)(a2 + 868);
        v10 = (int *)(v9 + 4 * v6);
        v11 = *v10;
        v12 = 4 * v4 - 4;
        *v10 = *(_DWORD *)(v12 + v9);
        *(_DWORD *)(v12 + *(_DWORD *)(a2 + 868)) = v11;
        --*(_DWORD *)(a2 + 860);
      }
      --i;
    }
  }
}
