void __thiscall Scaleform::GFx::AS3::Instances::fl::QName::uriGet(
        Scaleform::GFx::AS3::Instances::fl::QName *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::Instances::fl::Namespace *pObject; // eax
  unsigned int v3; // edx
  Scaleform::GFx::AS3::Value::V2U v4; // [esp+4h] [ebp-4h]

  pObject = this->Ns.pObject;
  if ( pObject )
  {
    Scaleform::GFx::AS3::Value::Assign(result, &pObject->Uri);
  }
  else
  {
    if ( (result->Flags & 0x1F) > 9 )
    {
      if ( (result->Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(result);
    }
    v3 = result->Flags & 0xFFFFFFE0 | 0xC;
    result->value.VS._1.VInt = 0;
    result->Flags = v3;
    result->value.VS._2 = v4;
  }
}
