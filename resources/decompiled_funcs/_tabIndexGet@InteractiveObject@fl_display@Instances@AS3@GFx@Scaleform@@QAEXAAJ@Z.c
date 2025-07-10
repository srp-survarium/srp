void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::tabIndexGet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        int *result)
{
  *result = SLOWORD(this->pDispObj.pObject[1].Depth);
}
