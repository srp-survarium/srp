char __thiscall Scaleform::GFx::AS3::Instances::fl::XMLElement::HasSimpleContent(
        Scaleform::GFx::AS3::Instances::fl::XMLElement *this)
{
  unsigned int Size; // ebx
  int v3; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx

  Size = this->Children.Data.Size;
  v3 = 0;
  if ( !Size )
    return 1;
  while ( 1 )
  {
    pObject = this->Children.Data.Data[v3].pObject;
    if ( pObject->GetKind(pObject) == kElement )
      break;
    if ( ++v3 >= Size )
      return 1;
  }
  return 0;
}
