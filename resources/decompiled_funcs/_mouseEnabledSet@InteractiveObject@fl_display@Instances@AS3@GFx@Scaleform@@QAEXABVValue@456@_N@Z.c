void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::mouseEnabledSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *v3; // eax

  v3 = LOBYTE(this->pDispObj.pObject->Flags) >> 7 != 0 ? this->pDispObj.pObject : 0;
  if ( value )
    v3[1].Id.Id &= ~0x1000u;
  else
    v3[1].Id.Id |= 0x1000u;
}
