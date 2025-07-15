void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Stage::stageFocusRectSet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( value )
    pObject[1].Id.Id |= 0x180u;
  else
    pObject[1].Id.Id = pObject[1].Id.Id & 0xFFFFFE7F | 0x100;
}
