Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::TextField::GetCaretIndex(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx
  bool v3; // al
  Scaleform::Render::Text::EditorKitBase *v4; // eax
  char v5; // al
  Scaleform::Render::Text::EditorKitBase *v6; // ecx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    v3 = pObject->IsReadOnly(pObject);
  else
    v3 = (this->pDef.pObject->Flags & 8) != 0;
  if ( (!v3
     || ((v4 = this->pDocument.pObject->pEditorKit.pObject) == 0
       ? (v5 = LOBYTE(this->pDef.pObject->Flags) >> 5)
       : (v5 = LOBYTE(v4[16].__vftable) >> 1),
         (v5 & 1) != 0))
    && (v6 = this->pDocument.pObject->pEditorKit.pObject) != 0 )
  {
    return Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)v6);
  }
  else
  {
    return (Scaleform::GFx::AS3::VMAppDomain *)-1;
  }
}
