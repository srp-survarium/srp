void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::cacheAsBitmapSet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        const Scaleform::GFx::AS3::Value *result,
        BOOL value)
{
  this->pDispObj.pObject->SetCacheAsBitmap(this->pDispObj.pObject, value);
}
