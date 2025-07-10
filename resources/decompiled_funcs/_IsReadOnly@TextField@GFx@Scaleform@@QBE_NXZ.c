int __thiscall Scaleform::GFx::TextField::IsReadOnly(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // eax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return ((int (__thiscall *)(Scaleform::Render::Text::EditorKitBase *))pObject->IsReadOnly)(this->pDocument.pObject->pEditorKit.pObject);
  else
    return (this->pDef.pObject->Flags & 8) != 0;
}
