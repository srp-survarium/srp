Scaleform::Render::VertexElement *__userpurge Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems@<eax>(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<ecx>,
        _DWORD *a2@<eax>,
        Scaleform::Render::VertexElement *source,
        unsigned int count)
{
  unsigned int v4; // ebx
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  void *v8; // eax
  Scaleform::Render::VertexElement *result; // eax
  _DWORD *v10; // ecx
  int v11; // edx

  v4 = count;
  v6 = (_DWORD *)a2[1];
  if ( v6 )
  {
    if ( count + v6[1] <= 0x20 )
      goto LABEL_6;
    v8 = Scaleform::Memory::AllocAutoHeap(a2, 0x108u);
    a2[1] = v8;
    *v6 = v8;
    v7 = (_DWORD *)a2[1];
  }
  else
  {
    v7 = Scaleform::Memory::AllocAutoHeap(a2, 0x108u);
    *a2 = v7;
    a2[1] = v7;
  }
  *v7 = 0;
  *(_DWORD *)(a2[1] + 4) = 0;
LABEL_6:
  result = (Scaleform::Render::VertexElement *)(a2[1] + 8 * *(_DWORD *)(a2[1] + 4) + 8);
  if ( count )
  {
    v10 = (_DWORD *)(a2[1] + 8 * *(_DWORD *)(a2[1] + 4) + 8);
    v11 = (char *)source - (char *)result;
    do
    {
      if ( v10 )
      {
        *v10 = *(_DWORD *)((char *)v10 + v11);
        v10[1] = *(_DWORD *)((char *)v10 + v11 + 4);
      }
      v10 += 2;
      --count;
    }
    while ( count );
  }
  *(_DWORD *)(a2[1] + 4) += v4;
  return result;
}
