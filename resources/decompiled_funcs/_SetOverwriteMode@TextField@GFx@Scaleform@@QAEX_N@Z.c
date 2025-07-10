void __thiscall Scaleform::GFx::TextField::SetOverwriteMode(Scaleform::GFx::TextField *this, bool overwMode)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
  {
    if ( overwMode )
      LOWORD(pObject[16].__vftable) |= 0x80u;
    else
      LOWORD(pObject[16].__vftable) &= ~0x80u;
  }
}
