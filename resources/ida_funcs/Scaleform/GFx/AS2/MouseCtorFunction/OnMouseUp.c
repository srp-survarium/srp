void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseUp(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv,
        unsigned int mouseIndex,
        unsigned int button,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::ASStringNode *v7; // eax

  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    ptarget = (Scaleform::GFx::InteractiveObject *)pObject->NamePath.pNode;
    ++ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      penv,
      mouseIndex,
      ASBuiltin_onMouseUp,
      (const Scaleform::GFx::ASString *)&ptarget,
      button,
      0,
      0);
    v7 = (Scaleform::GFx::ASStringNode *)ptarget;
    --ptarget->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      penv,
      mouseIndex,
      ASBuiltin_onMouseUp,
      0,
      button,
      0,
      0);
  }
}
