int __thiscall btSparseSdf<3>::RemoveReferences(btSparseSdf<3> *this, btCollisionShape *pcs, int a3)
{
  void (__thiscall **v4)(btCollisionShape *); // esi
  void (__thiscall *v5)(btCollisionShape *); // eax
  void (__thiscall *v6)(btCollisionShape *); // edi
  int v8; // [esp+4h] [ebp-8h]
  void (__thiscall *v9)(btCollisionShape *); // [esp+8h] [ebp-4h]
  int i; // [esp+14h] [ebp+8h]

  v8 = 0;
  for ( i = 0; i < pcs->m_shapeType; ++i )
  {
    v9 = 0;
    v4 = &pcs[1].~btCollisionShape + i;
    v5 = *v4;
    if ( *v4 )
    {
      do
      {
        v6 = (void (__thiscall *)(btCollisionShape *))*((_DWORD *)v5 + 70);
        if ( *((_DWORD *)v5 + 69) == a3 )
        {
          if ( v9 )
            *((_DWORD *)v9 + 70) = v6;
          else
            *v4 = v6;
          operator delete(v5);
          v5 = v9;
          ++v8;
        }
        v9 = v5;
        v5 = v6;
      }
      while ( v6 );
    }
  }
  return v8;
}
