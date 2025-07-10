void __usercall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  void *v4; // eax

  v2 = (_DWORD *)a2[1];
  if ( v2 )
  {
    if ( (unsigned int)(v2[1] + 1) > 8 )
    {
      v4 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 168, 0);
      a2[1] = v4;
      *v2 = v4;
      *(_DWORD *)a2[1] = 0;
      *(_DWORD *)(a2[1] + 4) = 0;
    }
  }
  else
  {
    v3 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, a2, 168, 0);
    *a2 = v3;
    a2[1] = v3;
    *v3 = 0;
    *(_DWORD *)(a2[1] + 4) = 0;
  }
}
