const Scaleform::Render::VertexElement *__thiscall Scaleform::Render::VertexFormat::GetElement(
        Scaleform::Render::VertexFormat *this,
        unsigned int attrValue,
        unsigned int attrMask)
{
  const Scaleform::Render::VertexElement *result; // eax
  unsigned int Attribute; // ecx

  for ( result = this->pElements; ; ++result )
  {
    Attribute = result->Attribute;
    if ( !Attribute )
      break;
    if ( (attrMask & Attribute) == attrValue )
      return result;
  }
  return 0;
}
