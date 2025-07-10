void __userpurge Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<ecx>,
        _DWORD *a2@<esi>,
        unsigned int count)
{
  _DWORD *v3; // edi
  _DWORD *v4; // eax
  void *v5; // eax

  v3 = (_DWORD *)a2[1];
  if ( v3 )
  {
    if ( count + v3[1] > 0x20 )
    {
      v5 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 264, 0);
      a2[1] = v5;
      *v3 = v5;
      *(_DWORD *)a2[1] = 0;
      *(_DWORD *)(a2[1] + 4) = 0;
    }
  }
  else
  {
    v4 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 264, 0);
    *a2 = v4;
    a2[1] = v4;
    *v4 = 0;
    *(_DWORD *)(a2[1] + 4) = 0;
  }
}
