void __thiscall Scaleform::GFx::TextField::ClearRestrict(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::Text::EditorKit *pObject; // ecx

  pObject = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    Scaleform::GFx::Text::EditorKit::ClearRestrict(pObject);
}
