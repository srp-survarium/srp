void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::mouseChildrenGet(
        Scaleform::GFx::AS3::Instances::fl_display::Stage *this,
        bool *result)
{
  *result = (this->pDispObj.pObject[1].Id.Id & 0x2000) == 0;
}
