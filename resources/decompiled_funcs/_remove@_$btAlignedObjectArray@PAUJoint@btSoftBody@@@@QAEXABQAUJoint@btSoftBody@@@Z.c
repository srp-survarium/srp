void __userpurge btAlignedObjectArray<btSoftBody::Joint *>::remove(
        btAlignedObjectArray<btSoftBody *> *this@<ecx>,
        int a2@<eax>,
        btSoftBody *const *key)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  btSoftBody *const *v6; // esi
  int v7; // ecx
  int v8; // esi

  v3 = *(_DWORD *)(a2 + 4);
  v4 = 0;
  v5 = v3;
  if ( v3 > 0 )
  {
    v6 = *(btSoftBody *const **)(a2 + 12);
    while ( *v6 != *key )
    {
      ++v4;
      ++v6;
      if ( v4 >= v3 )
        goto LABEL_7;
    }
    v5 = v4;
  }
LABEL_7:
  if ( v5 < v3 )
  {
    v7 = *(_DWORD *)(a2 + 12);
    v8 = *(_DWORD *)(v7 + 4 * v5);
    *(_DWORD *)(v7 + 4 * v5) = *(_DWORD *)(v7 + 4 * v3 - 4);
    *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v3 - 4) = v8;
    --*(_DWORD *)(a2 + 4);
  }
}
