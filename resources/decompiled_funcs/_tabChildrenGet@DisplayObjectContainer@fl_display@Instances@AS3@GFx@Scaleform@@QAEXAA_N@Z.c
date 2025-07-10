void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer::tabChildrenGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObjectContainer *this,
        bool *result)
{
  *result = (this->pDispObj.pObject[1].Id.Id & 0x8000) == 0;
}
