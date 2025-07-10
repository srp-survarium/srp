void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::multilineSet(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        const Scaleform::GFx::AS3::Value *result,
        bool value)
{
  Scaleform::GFx::TextField *pObject; // edi
  Scaleform::Render::Text::DocView *v4; // eax

  pObject = (Scaleform::GFx::TextField *)this->pDispObj.pObject;
  v4 = pObject->pDocument.pObject;
  if ( ((v4->Flags & 4) != 0) != value )
  {
    if ( value )
    {
      v4->Flags |= 4u;
      Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(this);
      Scaleform::GFx::TextField::SetDirtyFlag(pObject);
      return;
    }
    v4->Flags &= ~4u;
    Scaleform::GFx::AS3::Instances::fl_text::TextField::UpdateAutosizeSettings(this);
  }
  Scaleform::GFx::TextField::SetDirtyFlag(pObject);
}
