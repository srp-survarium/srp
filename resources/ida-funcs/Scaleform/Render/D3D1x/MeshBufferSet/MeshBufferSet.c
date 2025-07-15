void __userpurge Scaleform::Render::D3D1x::MeshBufferSet::MeshBufferSet(
        Scaleform::Render::D3D1x::MeshBufferSet *this@<ecx>,
        int a2@<esi>,
        Scaleform::MemoryHeap *pheap,
        unsigned int granularity)
{
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::MeshBufferSet::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  Scaleform::AllocAddr::AllocAddr((Scaleform::AllocAddr *)(a2 + 16), pheap);
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 28) = granularity;
}
