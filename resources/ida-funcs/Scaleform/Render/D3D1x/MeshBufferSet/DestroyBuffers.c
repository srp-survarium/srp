void __userpurge Scaleform::Render::D3D1x::MeshBufferSet::DestroyBuffers(
        Scaleform::Render::D3D1x::MeshBufferSet *this@<ecx>,
        int a2@<edi>,
        Scaleform::Render::MeshBuffer::AllocType type)
{
  unsigned int i; // ebx
  int v4; // eax
  bool v5; // zf
  int *v6; // eax
  int v7; // esi

  for ( i = 0; i < *(_DWORD *)(a2 + 8); ++i )
  {
    v4 = *(_DWORD *)(a2 + 4);
    v5 = *(_DWORD *)(v4 + 4 * i) == 0;
    v6 = (int *)(v4 + 4 * i);
    if ( !v5 && (type == AT_None || *(_DWORD *)(*v6 + 16) == type) )
    {
      v7 = *v6;
      Scaleform::AllocAddr::RemoveSegment(
        (Scaleform::AllocAddr *)(a2 + 16),
        *(_DWORD *)(*v6 + 28) << 24,
        (unsigned int)(*(_DWORD *)(*v6 + 20) + 15) >> 4);
      *(_DWORD *)(a2 + 32) -= *(_DWORD *)(v7 + 20);
      *(_DWORD *)(*(_DWORD *)(a2 + 4) + 4 * *(_DWORD *)(v7 + 28)) = 0;
      (**(void (__thiscall ***)(int, int))v7)(v7, 1);
    }
  }
}
