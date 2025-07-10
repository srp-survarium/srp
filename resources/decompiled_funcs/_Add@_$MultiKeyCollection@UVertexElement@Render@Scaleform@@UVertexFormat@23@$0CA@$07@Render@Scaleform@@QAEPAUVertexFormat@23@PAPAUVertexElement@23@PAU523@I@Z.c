Scaleform::Render::VertexFormat *__userpurge Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add@<eax>(
        Scaleform::Render::VertexElement *keys@<eax>,
        unsigned int count@<ecx>,
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this,
        Scaleform::Render::VertexElement **ppnewKeys)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v5; // ecx
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem *v6; // eax
  Scaleform::Render::VertexElement *v7; // ebx
  unsigned int v9; // [esp+0h] [ebp-Ch]

  *ppnewKeys = Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(
                 &this->KeyBuffer,
                 keys,
                 count);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::ensureCountAvailable(
    v5,
    v9);
  v6 = &this->ValueBuffer.pLast->Items[this->ValueBuffer.pLast->Count];
  if ( (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)((char *)this->ValueBuffer.pLast + 20 * this->ValueBuffer.pLast->Count) != (Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *)-8 )
    this->ValueBuffer.pLast->Items[this->ValueBuffer.pLast->Count].Value.pSysFormat.pObject = 0;
  ++this->ValueBuffer.pLast->Count;
  v7 = *ppnewKeys;
  if ( !*ppnewKeys || !v6 )
    return 0;
  v6->KeyCount = count;
  v6->pKey = v7;
  return &v6->Value;
}
