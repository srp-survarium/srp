void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::ToString(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this,
        Scaleform::StringBuffer *buf,
        int ident)
{
  unsigned int Size; // ebp
  unsigned int i; // edi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // esi

  if ( Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(this) )
  {
    Size = this->Children.Data.Size;
    for ( i = 0; i < Size; ++i )
    {
      pObject = this->Children.Data.Data[i].pObject;
      if ( pObject->GetKind(pObject) == kText )
        pObject->ToString(pObject, buf, ident);
    }
  }
  else
  {
    this->ToXMLString(this, buf, ident, 0, 0);
  }
}
