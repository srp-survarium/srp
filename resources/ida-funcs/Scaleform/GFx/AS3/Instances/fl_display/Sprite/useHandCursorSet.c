void __thiscall Scaleform::GFx::AS3::Instances::fl_display::Sprite::useHandCursorSet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::DisplayObject *pObject; // eax

  pObject = this->pDispObj.pObject;
  if ( value )
    pObject[1].Id.Id |= 0x600u;
  else
    pObject[1].Id.Id = pObject[1].Id.Id & 0xFFFFF9FF | 0x400;
}
