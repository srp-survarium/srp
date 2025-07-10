void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::scrollVSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        int value)
{
  int v3; // eax
  Scaleform::GFx::TextField *pObject; // esi

  v3 = value;
  if ( value < 1 )
    v3 = 1;
  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  Scaleform::Render::Text::DocView::SetVScrollOffset(pObject->pDocument.pObject, v3 - 1);
  Scaleform::GFx::TextField::SetDirtyFlag(pObject);
}
