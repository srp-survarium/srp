void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::OnMouseDown(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl penv,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *button,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::AS2::Environment *v4; // ebx
  void (__thiscall *Invoke)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, const Scaleform::GFx::AS2::FunctionRef *); // edi
  int v7; // eax
  unsigned int v8; // ebp
  unsigned int v9; // eax
  void (__thiscall *v10)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, const Scaleform::GFx::AS2::FunctionRef *); // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  bool v14; // [esp+Ch] [ebp-Ch]
  float v15; // [esp+14h] [ebp-4h]

  v4 = (Scaleform::GFx::AS2::Environment *)penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback;
  Invoke = penv.Invoke;
  v14 = 0;
  if ( *(_BYTE *)(*((_DWORD *)penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback + 29) + 52) == 1 )
  {
    penv.Invoke = (void (__thiscall *)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, const Scaleform::GFx::AS2::FunctionRef *))(Scaleform::Timer::GetTicks() / 0x3E8);
    if ( (unsigned int)Invoke < 6 )
      v7 = (int)&v4->Target->pASRoot->pMovieImpl->mMouseState[(_DWORD)Invoke];
    else
      v7 = 0;
    v15 = *(float *)(v7 + 36);
    *(float *)&penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback = *(float *)(v7 + 32) * 0.05000000074505806;
    v8 = (int)*(float *)&penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback;
    *(float *)&penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback = 0.05000000074505806 * v15;
    v9 = (int)*(float *)&penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback;
    v10 = penv.Invoke;
    if ( (char *)penv.Invoke <= (char *)&this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable[3].ToFunction
      && this->RootIndex == v8
      && this->RefCount == v9 )
    {
      v14 = 1;
    }
    this->RootIndex = v8;
    this->RefCount = v9;
    this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)v10;
  }
  if ( ptarget )
  {
    pObject = ptarget->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
    v12 = button;
    penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback = (void (__thiscall *)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *))pObject->NamePath.pNode;
    ++*((_DWORD *)penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback + 3);
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      v4,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)Invoke,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)0x67,
      &penv,
      v12,
      0,
      v14);
    v13 = (Scaleform::GFx::ASStringNode *)penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback;
    --*((_DWORD *)penv.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback + 3);
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      v4,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)Invoke,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)0x67,
      0,
      button,
      0,
      v14);
  }
}
