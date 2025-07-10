void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3hasSimpleContent(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        bool *result)
{
  unsigned int Size; // edi
  int v4; // esi
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // ecx

  Size = this->List.Data.Size;
  if ( Size )
  {
    if ( Size == 1 )
    {
      *result = this->List.Data.Data->pObject->HasSimpleContent(this->List.Data.Data->pObject);
    }
    else
    {
      v4 = 0;
      *result = 1;
      if ( Size )
      {
        while ( 1 )
        {
          pObject = this->List.Data.Data[v4].pObject;
          if ( pObject->GetKind(pObject) == kElement )
            break;
          if ( ++v4 >= Size )
            return;
        }
        *result = 0;
      }
    }
  }
  else
  {
    *result = 1;
  }
}
