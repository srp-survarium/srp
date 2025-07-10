void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::focusRectSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::DisplayObject *pObject; // esi

  if ( (value->Flags & 0x1F) != 0 )
  {
    pObject = this->pDispObj.pObject;
    if ( Scaleform::GFx::AS3::Value::Convert2Boolean(value) )
      pObject[1].Id.Id |= 0x180u;
    else
      pObject[1].Id.Id = pObject[1].Id.Id & 0xFFFFFE7F | 0x100;
  }
  else
  {
    this->pDispObj.pObject[1].Id.Id &= 0xFFFFFF9F;
  }
}
