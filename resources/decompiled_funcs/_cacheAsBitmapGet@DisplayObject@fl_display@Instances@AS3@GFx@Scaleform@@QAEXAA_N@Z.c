void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::cacheAsBitmapGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        bool *result)
{
  *result = this->pDispObj.pObject->GetFilters(this->pDispObj.pObject) != 0;
}
