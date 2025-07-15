bool __thiscall Scaleform::GFx::TextField::IsSelectable(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    LOBYTE(pObject) = ((int)pObject[16].__vftable & 2) != 0;
  else
    return (this->pDef.pObject->Flags & 0x20) != 0;
  return (char)pObject;
}
