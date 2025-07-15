void __userpurge btRigidBody::addConstraintRef(btRigidBody *this@<ecx>, int a2@<esi>, btTypedConstraint *c)
{
  int v3; // eax
  int v4; // edx
  btTypedConstraint **v5; // ecx
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // eax
  _DWORD *v13; // [esp+4h] [ebp-4h]

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
      v8 = v7 ? 2 * v7 : 1;
      if ( v6 < v8 )
      {
        if ( v8 )
          v13 = btAlignedAllocInternal(4 * v8);
        else
          v13 = 0;
        v9 = *(_DWORD *)(a2 + 508);
        v10 = 0;
        if ( v9 > 0 )
        {
          v11 = v13;
          do
          {
            if ( v11 )
              *v11 = *(_DWORD *)(*(_DWORD *)(a2 + 516) + 4 * v10);
            ++v10;
            ++v11;
          }
          while ( v10 < v9 );
        }
        if ( *(_DWORD *)(a2 + 516) )
        {
          if ( *(_BYTE *)(a2 + 520) )
            btAlignedFreeInternal(*(void **)(a2 + 516));
          *(_DWORD *)(a2 + 516) = 0;
        }
        *(_BYTE *)(a2 + 520) = 1;
        *(_DWORD *)(a2 + 516) = v13;
        *(_DWORD *)(a2 + 512) = v8;
      }
    }
    v12 = (_DWORD *)(*(_DWORD *)(a2 + 516) + 4 * *(_DWORD *)(a2 + 508));
    if ( v12 )
      *v12 = c;
    ++*(_DWORD *)(a2 + 508);
  }
  *(_DWORD *)(a2 + 264) = 1;
}
