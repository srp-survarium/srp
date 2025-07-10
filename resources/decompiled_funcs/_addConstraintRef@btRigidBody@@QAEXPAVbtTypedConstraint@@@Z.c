void __userpurge btRigidBody::addConstraintRef(btRigidBody *this@<ecx>, int a2@<esi>, btTypedConstraint *c)
{
  int v3; // ecx
  int v4; // eax
  btTypedConstraint **v5; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // ebp
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  void *v13; // eax
  _DWORD *v14; // eax

  v3 = *(_DWORD *)(a2 + 508);
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = *(btTypedConstraint ***)(a2 + 516);
    while ( *v5 != c )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        goto LABEL_7;
    }
    v3 = v4;
  }
LABEL_7:
  if ( v3 == *(_DWORD *)(a2 + 508) )
  {
    v6 = *(_DWORD *)(a2 + 512);
    v7 = *(_DWORD *)(a2 + 508);
    if ( v7 == v6 )
    {
      v8 = 2 * v7;
      if ( !v7 )
        v8 = 1;
      if ( v6 < v8 )
      {
        if ( v8 )
        {
          ++gNumAlignedAllocs;
          v9 = sAlignedAllocFunc(4 * v8, 16);
        }
        else
        {
          v9 = 0;
        }
        v10 = *(_DWORD *)(a2 + 508);
        v11 = 0;
        if ( v10 > 0 )
        {
          v12 = v9;
          do
          {
            if ( v12 )
              *v12 = *(_DWORD *)(*(_DWORD *)(a2 + 516) + 4 * v11);
            ++v11;
            ++v12;
          }
          while ( v11 < v10 );
        }
        v13 = *(void **)(a2 + 516);
        if ( v13 )
        {
          if ( *(_BYTE *)(a2 + 520) )
          {
            ++gNumAlignedFree;
            sAlignedFreeFunc(v13);
          }
          *(_DWORD *)(a2 + 516) = 0;
        }
        *(_DWORD *)(a2 + 516) = v9;
        *(_BYTE *)(a2 + 520) = 1;
        *(_DWORD *)(a2 + 512) = v8;
      }
    }
    v14 = (_DWORD *)(*(_DWORD *)(a2 + 516) + 4 * *(_DWORD *)(a2 + 508));
    if ( v14 )
      *v14 = c;
    ++*(_DWORD *)(a2 + 508);
  }
  *(_DWORD *)(a2 + 264) = 1;
}
