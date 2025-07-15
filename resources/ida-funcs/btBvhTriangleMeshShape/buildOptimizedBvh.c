void __usercall btBvhTriangleMeshShape::buildOptimizedBvh(btBvhTriangleMeshShape *this@<ecx>, int a2@<esi>)
{
  btQuantizedBvh *v2; // eax
  btOptimizedBvh *v3; // eax
  btStridingMeshInterface *v4; // [esp-Ch] [ebp-Ch]
  btQuantizedBvh *v5; // [esp-8h] [ebp-8h]

  if ( *(_BYTE *)(a2 + 73) )
  {
    (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 64))(*(_DWORD *)(a2 + 64), 0);
    btAlignedFreeInternal(*(void **)(a2 + 64));
  }
  v2 = (btQuantizedBvh *)btAlignedAllocInternal(0xC0u);
  if ( v2 )
  {
    v3 = (btOptimizedBvh *)btQuantizedBvh::btQuantizedBvh(v5, v2);
    v3->__vftable = (btOptimizedBvh_vtbl *)&btOptimizedBvh::`vftable';
  }
  else
  {
    v3 = 0;
  }
  v4 = *(btStridingMeshInterface **)(a2 + 48);
  *(_DWORD *)(a2 + 64) = v3;
  btOptimizedBvh::build(*(_BYTE *)(a2 + 72), (const btVector3 *)(a2 + 32), v3, v4, (const btVector3 *)(a2 + 16));
  *(_BYTE *)(a2 + 73) = 1;
}
