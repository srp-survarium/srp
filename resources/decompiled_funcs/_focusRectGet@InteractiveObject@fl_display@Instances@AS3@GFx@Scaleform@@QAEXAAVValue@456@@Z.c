void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::focusRectGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        Scaleform::GFx::AS3::Value *result)
{
  unsigned int v2; // edx
  Scaleform::GFx::AS3::Value::V2U v3; // [esp+4h] [ebp-4h]

  if ( (this->pDispObj.pObject[1].Id.Id & 0x60) != 0 )
  {
    Scaleform::GFx::AS3::Value::SetBool(result, (this->pDispObj.pObject[1].Id.Id & 0x60) == 96);
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
    v2 = result->Flags & 0xFFFFFFE0 | 0xC;
    result->value.VS._1.VInt = 0;
    result->Flags = v2;
    result->value.VS._2 = v3;
  }
}
