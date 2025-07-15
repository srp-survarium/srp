Scaleform::Render::VertexFormat *__userpurge Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add@<eax>(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this@<ecx>,
        _DWORD *a2@<eax>,
        Scaleform::Render::VertexElement **ppnewKeys,
        Scaleform::Render::VertexElement *keys,
        unsigned int count)
{
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  _DWORD *v7; // eax
  void *v8; // eax
  _DWORD *v9; // eax

  v5 = a2 + 2;
  *ppnewKeys = Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(
                 &this->KeyBuffer,
                 a2,
                 keys,
                 count);
  v6 = (_DWORD *)v5[1];
  if ( v6 )
  {
    if ( (unsigned int)(v6[1] + 1) <= 8 )
      goto LABEL_6;
    v8 = Scaleform::Memory::AllocAutoHeap(v5, 0xA8u);
    v5[1] = v8;
    *v6 = v8;
    v7 = (_DWORD *)v5[1];
  }
  else
  {
    v7 = Scaleform::Memory::AllocAutoHeap(v5, 0xA8u);
    *v5 = v7;
    v5[1] = v7;
  }
  *v7 = 0;
  *(_DWORD *)(v5[1] + 4) = 0;
LABEL_6:
  v9 = (_DWORD *)(20 * *(_DWORD *)(v5[1] + 4) + v5[1] + 8);
  if ( 20 * *(_DWORD *)(v5[1] + 4) + v5[1] != -8 )
    *(_DWORD *)(20 * *(_DWORD *)(v5[1] + 4) + v5[1] + 24) = 0;
  ++*(_DWORD *)(v5[1] + 4);
  if ( !*ppnewKeys || !v9 )
    return 0;
  *v9 = *ppnewKeys;
  v9[1] = count;
  return (Scaleform::Render::VertexFormat *)(v9 + 2);
}
