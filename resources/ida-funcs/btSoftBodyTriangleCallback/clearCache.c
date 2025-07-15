void __usercall btSoftBodyTriangleCallback::clearCache(btSoftBodyTriangleCallback *this@<ecx>, _DWORD *a2@<eax>)
{
  int i; // ebx
  int v4; // edi

  for ( i = 0; i < a2[27]; ++i )
  {
    v4 = a2[29] + 8 * i;
    btSparseSdf<3>::RemoveReferences(
      (btSparseSdf<3> *)this,
      (btCollisionShape *)(*(_DWORD *)(a2[1] + 692) + 64),
      *(_DWORD *)(v4 + 4));
    this = *(btSoftBodyTriangleCallback **)(v4 + 4);
    if ( this )
      ((void (__thiscall *)(btSoftBodyTriangleCallback *, int))this->~btSoftBodyTriangleCallback)(this, 1);
  }
  btHashMap<btHashKey<btTriIndex>,btTriIndex>::clear(
    (btHashMap<btHashKey<btTriIndex>,btTriIndex> *)this,
    (int)(a2 + 16));
}
