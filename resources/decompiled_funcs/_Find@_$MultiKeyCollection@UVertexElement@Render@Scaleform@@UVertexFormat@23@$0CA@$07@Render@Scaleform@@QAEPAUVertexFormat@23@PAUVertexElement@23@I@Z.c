Scaleform::Render::VertexFormat *__userpurge Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find@<eax>(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this@<eax>,
        unsigned int count@<edi>,
        Scaleform::Render::VertexElement *keys)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pPages; // eax
  Scaleform::Render::VertexElement *v4; // ebp
  unsigned int v5; // ecx
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem *Items; // ebx
  unsigned int v7; // ecx
  $B996288B4BA8DC1872D28A6FA0F1BFD9 *v8; // edx
  Scaleform::Render::VertexElement *v9; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pvp; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  unsigned int v13; // [esp+14h] [ebp-4h]

  pPages = this->ValueBuffer.pPages;
  v4 = keys;
  pvp = pPages;
  if ( !pPages )
    return 0;
  while ( 1 )
  {
    v5 = pPages->Count;
    i = 0;
    v13 = v5;
    if ( v5 )
      break;
LABEL_14:
    pPages = pPages->pNext;
    pvp = pPages;
    if ( !pPages )
      return 0;
  }
  Items = pPages->Items;
  while ( Items->KeyCount != count )
  {
LABEL_13:
    ++Items;
    if ( ++i >= v5 )
      goto LABEL_14;
  }
  v7 = 0;
  if ( count )
  {
    v8 = &Items->pKey->4;
    v9 = v4;
    do
    {
      if ( *(unsigned int *)((char *)&v9->Offset + (char *)Items->pKey - (char *)v4) != v9->Offset )
        break;
      if ( v8->Attribute != v9->Attribute )
        break;
      ++v7;
      ++v9;
      v8 += 2;
    }
    while ( v7 < count );
    pPages = pvp;
  }
  if ( v7 != count )
  {
    v5 = v13;
    v4 = keys;
    goto LABEL_13;
  }
  return &Items->Value;
}
