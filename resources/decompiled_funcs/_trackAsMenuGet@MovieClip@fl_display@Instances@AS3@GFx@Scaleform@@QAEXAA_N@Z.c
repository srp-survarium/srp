void __thiscall Scaleform::GFx::AS3::Instances::fl_display::MovieClip::trackAsMenuGet(
        Scaleform::GFx::AS3::Instances::fl_display::SimpleButton *this,
        bool *result)
{
  *result = (this->pDispObj.pObject[1].Id.Id & 0x4000) != 0;
}
