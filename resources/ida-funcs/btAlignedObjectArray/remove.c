void __usercall btAlignedObjectArray<btTypedConstraint *>::remove(
        btAlignedObjectArray<btTypedConstraint *> *this@<ecx>,
        int a2@<eax>)
{
  int v2; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // edi
  _DWORD *v6; // ecx
  int v7; // ecx
  int *v8; // edx
  int v9; // edi
  int v10; // esi

  v2 = *(_DWORD *)(a2 + 4);
  v3 = 0;
  v4 = v2;
  if ( v2 > 0 )
  {
    v5 = *(_DWORD *)&this->m_allocator;
    v6 = *(_DWORD **)(a2 + 12);
    while ( *v6 != v5 )
    {
      ++v3;
      ++v6;
      if ( v3 >= v2 )
        goto LABEL_7;
    }
    v4 = v3;
  }
LABEL_7:
  if ( v4 < v2 )
  {
    v7 = *(_DWORD *)(a2 + 12);
    v8 = (int *)(v7 + 4 * v4);
    v9 = *v8;
    v10 = 4 * v2 - 4;
    *v8 = *(_DWORD *)(v10 + v7);
    *(_DWORD *)(v10 + *(_DWORD *)(a2 + 12)) = v9;
    --*(_DWORD *)(a2 + 4);
  }
}
