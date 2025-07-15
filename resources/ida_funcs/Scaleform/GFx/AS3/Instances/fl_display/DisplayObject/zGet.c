void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::zGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetZ(this->pDispObj.pObject) * 0.05;
}
