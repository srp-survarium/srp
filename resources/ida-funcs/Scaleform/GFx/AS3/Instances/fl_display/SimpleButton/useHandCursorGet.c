void __thiscall Scaleform::GFx::AS3::Instances::fl_display::SimpleButton::useHandCursorGet(
        Scaleform::GFx::AS3::Instances::fl_display::Sprite *this,
        bool *result)
{
  *result = (this->pDispObj.pObject[1].Id.Id & 0x600) == 1536;
}
