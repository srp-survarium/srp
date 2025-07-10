void __thiscall Scaleform::GFx::AS3::Instances::fl::XMLList::AS3parent(
        Scaleform::GFx::AS3::Instances::fl::XMLList *this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int Size; // edx
  Scaleform::GFx::AS3::Value *v3; // esi
  Scaleform::GFx::AS3::Value *v4; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *Data; // ecx
  Scaleform::GFx::AS3::Object *pObject; // esi
  unsigned int v7; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *v8; // ecx
  unsigned int Flags; // eax
  bool v10; // cc

  Size = this->List.Data.Size;
  if ( Size )
  {
    Data = this->List.Data.Data;
    pObject = Data->pObject->Parent.pObject;
    v7 = 1;
    if ( Size <= 1 )
    {
LABEL_11:
      if ( pObject )
      {
        Scaleform::GFx::AS3::Value::Assign(result, pObject);
        return;
      }
      v3 = result;
      Flags = result->Flags;
      v10 = (result->Flags & 0x1F) <= 9;
    }
    else
    {
      v8 = Data + 1;
      while ( pObject == v8->pObject->Parent.pObject )
      {
        ++v7;
        ++v8;
        if ( v7 >= Size )
          goto LABEL_11;
      }
      v3 = result;
      Flags = result->Flags;
      v10 = (result->Flags & 0x1F) <= 9;
    }
    if ( !v10 )
    {
      v4 = v3;
      if ( (Flags & 0x200) != 0 )
        goto LABEL_4;
      Scaleform::GFx::AS3::Value::ReleaseInternal(v3);
    }
    v3->Flags &= 0xFFFFFFE0;
  }
  else
  {
    v3 = result;
    if ( (result->Flags & 0x1F) > 9 )
    {
      v4 = result;
      if ( (result->Flags & 0x200) != 0 )
      {
LABEL_4:
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
        v3->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    result->Flags &= 0xFFFFFFE0;
  }
}
