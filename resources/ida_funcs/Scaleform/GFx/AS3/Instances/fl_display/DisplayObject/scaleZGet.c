void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::scaleZGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetZScale(this->pDispObj.pObject) / 100.0;
}
