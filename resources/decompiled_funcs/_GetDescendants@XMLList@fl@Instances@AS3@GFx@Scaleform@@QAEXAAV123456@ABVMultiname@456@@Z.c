void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::GetDescendants(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Instances::fl::XMLList *list,
        const Scaleform::GFx::AS3::Multiname *prop_name)
{
  unsigned int Size; // ebx
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx

  Size = this->List.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->List.Data.Data[i].pObject;
    pObject->GetDescendants(pObject, list, prop_name);
  }
}
