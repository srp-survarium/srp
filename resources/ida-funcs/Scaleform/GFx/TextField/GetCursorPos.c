Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::TextField::GetCursorPos(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // ecx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return Scaleform::GFx::Text::EditorKit::GetCursorPos((Scaleform::GFx::AS3::Instances::fl_system::ApplicationDomain *)pObject);
  else
    return (Scaleform::GFx::AS3::VMAppDomain *)-1;
}
