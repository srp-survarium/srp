void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseDown(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        float penv,
        unsigned int mouseIndex,
        unsigned int button,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::AS2::Environment *v5; // ebx
  unsigned int v6; // edi
  int v8; // eax
  unsigned int v9; // ebp
  unsigned int v10; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v11; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  unsigned int v13; // ecx
  Scaleform::GFx::ASStringNode *v14; // eax
  bool doubleClicked; // [esp+Ch] [ebp-Ch]
  float pt_4; // [esp+14h] [ebp-4h]

  v5 = (Scaleform::GFx::AS2::Environment *)LODWORD(penv);
  v6 = mouseIndex;
  doubleClicked = 0;
  if ( *(_BYTE *)(*(_DWORD *)(LODWORD(penv) + 116) + 52) == 1 )
  {
    mouseIndex = Scaleform::Timer::GetTicks() / 0x3E8;
    if ( v6 < 6 )
      v8 = (int)&v5->Target->pASRoot->pMovieImpl->mMouseState[v6];
    else
      v8 = 0;
    pt_4 = *(float *)(v8 + 36);
    penv = *(float *)(v8 + 32) * 0.05000000074505806;
    v9 = (int)penv;
    penv = 0.05000000074505806 * pt_4;
    v10 = (int)penv;
    v11 = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)mouseIndex;
    if ( (Scaleform::GFx::AS2::FunctionRef *(__thiscall **)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FunctionRef *))mouseIndex <= &this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable[3].ToFunction
      && this->RootIndex == v9
      && this->RefCount == v10 )
    {
      doubleClicked = 1;
    }
    this->RootIndex = v9;
    this->RefCount = v10;
    this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = v11;
  }
  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    v13 = button;
    penv = *(float *)&pObject->NamePath.pNode;
    ++*(_DWORD *)(LODWORD(penv) + 12);
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      v5,
      v6,
      ASBuiltin_onMouseDown,
      (const Scaleform::GFx::ASString *)&penv,
      v13,
      0,
      doubleClicked);
    v14 = (Scaleform::GFx::ASStringNode *)LODWORD(penv);
    --*(_DWORD *)(LODWORD(penv) + 12);
    if ( !v14->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      v5,
      v6,
      ASBuiltin_onMouseDown,
      0,
      button,
      0,
      doubleClicked);
  }
}
