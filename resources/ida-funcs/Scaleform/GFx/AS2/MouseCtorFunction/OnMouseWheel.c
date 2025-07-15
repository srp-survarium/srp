void __userpurge Scaleform::GFx::AS2::MouseCtorFunction::OnMouseWheel(
        Scaleform::GFx::AS2::MouseCtorFunction *this@<ecx>,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *mouseIndex,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *sdelta,
        Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl ptarget)
{
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::GFx::ASStringNode *v7; // eax

  if ( ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback )
  {
    CharacterHandle = (Scaleform::GFx::CharacterHandle *)*((_DWORD *)ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback
                                                         + 17);
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback);
    ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback = (void (__thiscall *)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *))CharacterHandle->NamePath.pNode;
    ++*((_DWORD *)ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback + 3);
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      penv,
      mouseIndex,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)0x6A,
      &ptarget,
      0,
      sdelta,
      0);
    v7 = (Scaleform::GFx::ASStringNode *)ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback;
    --*((_DWORD *)ptarget.~Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback + 3);
    if ( !v7->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else
  {
    Scaleform::GFx::AS2::MouseCtorFunction::NotifyListeners(
      (Scaleform::GFx::AS2::MouseCtorFunction *)((char *)this - 56),
      penv,
      mouseIndex,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback_vtbl *)0x6A,
      0,
      0,
      sdelta,
      0);
  }
}
