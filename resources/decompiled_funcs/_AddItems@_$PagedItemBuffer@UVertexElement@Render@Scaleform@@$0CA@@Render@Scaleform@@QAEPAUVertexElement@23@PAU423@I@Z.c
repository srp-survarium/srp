Scaleform::Render::VertexElement *__userpurge Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems@<eax>(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this@<eax>,
        unsigned int count@<edi>,
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *a3@<ecx>,
        Scaleform::Render::VertexElement *source)
{
  Scaleform::Render::VertexElement *result; // eax
  Scaleform::Render::VertexElement *v6; // ecx
  int v7; // edx
  unsigned int v8; // ebx

  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::ensureCountAvailable(a3, count);
  result = &this->pLast->Items[this->pLast->Count];
  if ( count )
  {
    v6 = &this->pLast->Items[this->pLast->Count];
    v7 = (char *)source - (char *)result;
    v8 = count;
    do
    {
      if ( v6 )
      {
        v6->Offset = *(unsigned int *)((char *)&v6->Offset + v7);
        v6->Attribute = *(unsigned int *)((char *)&v6->Attribute + v7);
      }
      ++v6;
      --v8;
    }
    while ( v8 );
  }
  this->pLast->Count += count;
  return result;
}
