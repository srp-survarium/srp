char __userpurge Scaleform::Render::D3D1x::MeshCache::allocCacheBuffers@<al>(
        Scaleform::Render::D3D1x::MeshCache *this@<ecx>,
        int a2@<edi>,
        unsigned int size,
        Scaleform::Render::MeshBuffer::AllocType type,
        unsigned int arena)
{
  int v5; // ebp

  v5 = (*(int (__thiscall **)(int, unsigned int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a2 + 288) + 4))(
         a2 + 288,
         16 * (5 * (size >> 4) / 9),
         1,
         0,
         *(_DWORD *)(a2 + 8),
         *(_DWORD *)(a2 + 88));
  if ( !v5 )
    return 0;
  if ( !(*(int (__thiscall **)(int, unsigned int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a2 + 324) + 4))(
          a2 + 324,
          (size & 0xFFFFFFF0) - 16 * (5 * (size >> 4) / 9),
          1,
          0,
          *(_DWORD *)(a2 + 8),
          *(_DWORD *)(a2 + 88)) )
  {
    Scaleform::AllocAddr::RemoveSegment(
      (Scaleform::AllocAddr *)(a2 + 304),
      *(_DWORD *)(v5 + 28) << 24,
      (unsigned int)(*(_DWORD *)(v5 + 20) + 15) >> 4);
    *(_DWORD *)(a2 + 320) -= *(_DWORD *)(v5 + 20);
    *(_DWORD *)(*(_DWORD *)(a2 + 292) + 4 * *(_DWORD *)(v5 + 28)) = 0;
    (**(void (__thiscall ***)(int, int))v5)(v5, 1);
    return 0;
  }
  return 1;
}
