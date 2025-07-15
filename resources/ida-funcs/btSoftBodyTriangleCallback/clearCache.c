void __usercall btSoftBodyTriangleCallback::clearCache(btSoftBodyTriangleCallback *this@<ecx>, _DWORD *a2@<edi>)
{
  int i; // ebx
  int v3; // esi

  for ( i = 0; i < a2[27]; ++i )
  {
    v3 = a2[29] + 8 * i;
    btSparseSdf<3>::RemoveReferences(
      *(btSparseSdf<3> **)(v3 + 4),
      (btSparseSdf<3> *)(*(_DWORD *)(a2[1] + 692) + 64),
      *(btCollisionShape **)(v3 + 4));
    this = *(btSoftBodyTriangleCallback **)(v3 + 4);
    if ( this )
      ((void (__thiscall *)(btSoftBodyTriangleCallback *, int))this->~btSoftBodyTriangleCallback)(this, 1);
  }
  btHashMap<btHashKey<btTriIndex>,btTriIndex>::clear(
    (btHashMap<btHashKey<btTriIndex>,btTriIndex> *)this,
    (int)(a2 + 16));
}
