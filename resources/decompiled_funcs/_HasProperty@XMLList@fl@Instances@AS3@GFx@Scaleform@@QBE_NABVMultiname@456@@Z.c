bool __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::HasProperty(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned int Size; // ebx
  int v5; // edi
  Scaleform::GFx::AS3::Instances::fl::XMLElement *pObject; // esi
  Scaleform::GFx::AS3::CheckResult result; // [esp+Bh] [ebp-5h] BYREF
  unsigned int ind; // [esp+Ch] [ebp-4h] BYREF

  if ( Scaleform::GFx::AS3::GetVectorInd(&result, prop_name, &ind)->Result )
    return ind < this->List.Data.Size;
  Size = this->List.Data.Size;
  v5 = 0;
  if ( !Size )
    return 0;
  while ( 1 )
  {
    pObject = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)this->List.Data.Data[v5].pObject;
    if ( pObject->GetKind(pObject) == kElement
      && Scaleform::GFx::AS3::Instances::fl::XMLElement::HasProperty(
           pObject,
           (Scaleform::GFx::AS3::SoundObject *)prop_name) )
    {
      break;
    }
    if ( ++v5 >= Size )
      return 0;
  }
  return 1;
}
