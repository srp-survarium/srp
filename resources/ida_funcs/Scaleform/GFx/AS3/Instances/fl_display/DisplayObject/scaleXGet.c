void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scaleXGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetXScale(this->pDispObj.pObject) / 100.0;
}
