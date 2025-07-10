int __thiscall btSparseSdf<3>::RemoveReferences(btSparseSdf<3> *this, btSparseSdf<3> *pcs, btCollisionShape *pcsa)
{
  btCollisionShape *v3; // ecx
  int result; // eax
  int v5; // ebp
  void (__thiscall **v6)(btCollisionShape *); // ebx
  void (__thiscall *v7)(btCollisionShape *); // eax
  void (__thiscall *v8)(btCollisionShape *); // esi
  void (__thiscall *v9)(btCollisionShape *); // edi
  int refcount; // [esp+4h] [ebp-4h]

  v3 = (btCollisionShape *)pcs;
  result = 0;
  v5 = 0;
  refcount = 0;
  if ( pcs->cells.m_size > 0 )
  {
    do
    {
      v6 = &v3[1].~btCollisionShape + v5;
      v7 = *v6;
      v8 = 0;
      if ( *v6 )
      {
        do
        {
          v9 = (void (__thiscall *)(btCollisionShape *))*((_DWORD *)v7 + 70);
          if ( *((btCollisionShape **)v7 + 69) == pcsa )
          {
            if ( v8 )
              *((_DWORD *)v8 + 70) = v9;
            else
              *v6 = v9;
            operator delete(v7);
            ++refcount;
            v7 = v8;
          }
          v8 = v7;
          v7 = v9;
        }
        while ( v9 );
        v3 = (btCollisionShape *)pcs;
      }
      ++v5;
    }
    while ( v5 < v3->m_shapeType );
    return refcount;
  }
  return result;
}
