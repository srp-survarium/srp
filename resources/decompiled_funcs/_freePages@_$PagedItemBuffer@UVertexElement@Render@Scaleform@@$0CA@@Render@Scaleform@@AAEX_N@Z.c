void __usercall Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::freePages(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<ecx>,
        int a2@<edi>)
{
  _DWORD *v2; // esi
  void *v3; // eax

  v2 = *(_DWORD **)a2;
  v3 = 0;
  if ( *(_DWORD *)a2 )
  {
    do
    {
      if ( v3 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
      v3 = v2;
      v2 = (_DWORD *)*v2;
    }
    while ( v2 );
    if ( v3 )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
      v3 = 0;
    }
  }
  *(_DWORD *)a2 = v3;
  *(_DWORD *)(a2 + 4) = v3;
}
