void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::widthGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        long double *result)
{
  *result = this->pDispObj.pObject->GetWidth(this->pDispObj.pObject);
}
