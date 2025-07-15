void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::scrollHSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        int value)
{
  Scaleform::GFx::TextField *pObject; // esi

  if ( value < 0 )
    value = 0;
  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  Scaleform::Render::Text::DocView::SetHScrollOffset(pObject->pDocument.pObject, (__int64)((double)value * 20.0));
  Scaleform::GFx::TextField::SetDirtyFlag(pObject);
}
