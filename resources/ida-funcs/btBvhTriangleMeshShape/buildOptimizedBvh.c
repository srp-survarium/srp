void __usercall btBvhTriangleMeshShape::buildOptimizedBvh(btBvhTriangleMeshShape *this@<ecx>, int a2@<esi>)
{
  void *v2; // eax
  btQuantizedBvh *v3; // ecx
  btOptimizedBvh *v4; // eax
  btStridingMeshInterface *v5; // [esp-Ch] [ebp-Ch]

  if ( *(_BYTE *)(a2 + 73) )
  {
    (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 64))(*(_DWORD *)(a2 + 64), 0);
    v2 = *(void **)(a2 + 64);
    if ( v2 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v2);
    }
  }
  ++gNumAlignedAllocs;
  if ( sAlignedAllocFunc(0xC0u, 16) )
  {
    v4 = (btOptimizedBvh *)btQuantizedBvh::btQuantizedBvh(v3);
    v4->__vftable = (btOptimizedBvh_vtbl *)&btOptimizedBvh::`vftable';
  }
  else
  {
    v4 = 0;
  }
  v5 = *(btStridingMeshInterface **)(a2 + 48);
  *(_DWORD *)(a2 + 64) = v4;
  btOptimizedBvh::build(v4, v5, *(_BYTE *)(a2 + 72), (const btVector3 *)(a2 + 16), (const btVector3 *)(a2 + 32));
  *(_BYTE *)(a2 + 73) = 1;
}
