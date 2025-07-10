bool __thiscall Scaleform::GFx::TextField::IsOverwriteMode(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  int v2; // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return (LOWORD(pObject[16].__vftable) >> 7) & 1;
  else
    LOBYTE(v2) = 0;
  return v2;
}
