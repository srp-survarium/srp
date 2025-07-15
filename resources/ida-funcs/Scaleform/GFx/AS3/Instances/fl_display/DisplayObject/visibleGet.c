void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::visibleGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        bool *result)
{
  *result = this->pDispObj.pObject->GetVisible(this->pDispObj.pObject);
}
