void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::heightGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetHeight(this->pDispObj.pObject);
}
