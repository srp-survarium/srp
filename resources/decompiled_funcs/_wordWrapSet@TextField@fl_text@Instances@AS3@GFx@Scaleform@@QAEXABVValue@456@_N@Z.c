void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::wordWrapSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::Render::Text::DocView *v5; // ecx

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  v5 = pObject->pDocument.pObject;
  if ( ((v5->Flags & 8) != 0) != value )
  {
    if ( value )
    {
      Scaleform::Render::Text::DocView::SetWordWrap(v5);
      Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(this);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
      return;
    }
    Scaleform::Render::Text::DocView::ClearWordWrap(v5);
    Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(this);
  }
  Scaleform::GFx::TextField::SetDirtyFlag(pObject);
}
