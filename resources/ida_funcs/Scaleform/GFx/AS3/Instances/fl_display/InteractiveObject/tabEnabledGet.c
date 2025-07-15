void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::tabEnabledGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        bool *result)
{
  *result = (this->pDispObj.pObject[1].Id.Id & 0x60) == 96;
}
