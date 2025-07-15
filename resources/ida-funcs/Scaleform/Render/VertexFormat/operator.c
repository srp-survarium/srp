bool __thiscall Scaleform::Render::VertexFormat::operator==(
        Scaleform::Render::VertexFormat *this,
        const Scaleform::Render::VertexFormat *o)
{
  Scaleform::Render::VertexElement *pElements; // ecx
  Scaleform::Render::VertexElement *i; // edx
  int v4; // eax
  int v5; // eax
  unsigned int Attribute; // esi
  unsigned int v7; // eax

  pElements = this->pElements;
  for ( i = o->pElements; ; ++i )
  {
    v4 = pElements->Attribute & 0xF0;
    if ( v4 == 112 || v4 == 128 )
      ++pElements;
    v5 = i->Attribute & 0xF0;
    if ( v5 == 112 || v5 == 128 )
      ++i;
    Attribute = pElements->Attribute;
    if ( !Attribute )
      break;
    v7 = i->Attribute;
    if ( !v7 )
      break;
    if ( pElements->Offset != i->Offset || Attribute != v7 )
      return 0;
    ++pElements;
  }
  return pElements->Offset == i->Offset && Attribute == i->Attribute;
}
