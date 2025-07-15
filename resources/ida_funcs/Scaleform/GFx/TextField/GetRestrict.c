const Scaleform::String *__thiscall Scaleform::GFx::TextField::GetRestrict(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::Text::EditorKit *pObject; // ecx

  pObject = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return Scaleform::GFx::Text::EditorKit::GetRestrict(pObject);
  else
    return 0;
}
