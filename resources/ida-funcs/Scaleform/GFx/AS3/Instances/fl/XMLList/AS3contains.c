void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3contains(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        bool *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::Value::V1U v4; // ebx
  unsigned int Size; // ebp
  unsigned int i; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx

  *result = 0;
  if ( (value->Flags & 0x1F) - 12 <= 3 && Scaleform::GFx::AS3::IsXMLObject(value->value.VS._1.VObj) )
  {
    v4 = value->value.VS._1;
    Size = this->List.Data.Size;
    for ( i = 0; i < Size; ++i )
    {
      if ( *result )
        break;
      pObject = this->List.Data.Data[i].pObject;
      if ( ((int (__thiscall *)(Scaleform::GFx::AS3::Instances::fl::XML *, Scaleform::GFx::AS3::Value::V1U))pObject->EqualsInternal)(
             pObject,
             v4) == 1 )
        *result = 1;
    }
  }
}
