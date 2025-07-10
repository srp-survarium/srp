int __thiscall Scaleform::GFx::TextField::GetCursorType(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  char v3; // al

  if ( (this->Flags & 0x20) != 0 )
    return 1;
  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    v3 = LOBYTE(pObject[16].__vftable) >> 1;
  else
    v3 = LOBYTE(this->pDef.pObject->Flags) >> 5;
  if ( (v3 & 1) != 0 )
    return 2;
  else
    return Scaleform::GFx::InteractiveObject::GetCursorType(this);
}
