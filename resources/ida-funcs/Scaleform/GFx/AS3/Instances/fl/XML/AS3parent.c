void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3parent(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::XML *pObject; // eax

  pObject = this->Parent.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Value::Assign(result, pObject);
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
      {
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
        result->Flags &= 0xFFFFFFE0;
        return;
      }
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    result->Flags &= 0xFFFFFFE0;
  }
}
