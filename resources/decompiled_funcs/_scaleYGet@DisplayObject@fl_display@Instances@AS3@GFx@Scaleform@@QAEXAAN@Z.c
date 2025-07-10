void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scaleYGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetYScale(this->pDispObj.pObject) / 100.0;
}
