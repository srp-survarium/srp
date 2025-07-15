void __thiscall Scaleform::GFx::AS2::AvmSprite::CallFrameActions(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frameNumber)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int v6; // ebp
  unsigned int i; // ebx
  Scaleform::GFx::ExecuteTag *v8; // edi
  Scaleform::GFx::TimelineDef::Frame playlist; // [esp+8h] [ebp-8h] BYREF
  Scaleform::GFx::MovieImpl *aqOldSession; // [esp+14h] [ebp+4h]

  if ( frameNumber == -1 || frameNumber >= this->pDispObj->GetLoadingFrame(this->pDispObj) )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      &this->pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "CallFrame('%d') - unknown frame",
      frameNumber);
  }
  else
  {
    pASRoot = this->pDispObj->pASRoot;
    ++*(_DWORD *)&pASRoot[7].AVMVersion;
    pMovieImpl = pASRoot[7].pMovieImpl;
    pASRoot = (Scaleform::GFx::ASMovieRootBase *)((char *)pASRoot + 68);
    v6 = (unsigned int)pASRoot[4].pMovieImpl;
    pASRoot[4].__vftable = (Scaleform::GFx::ASMovieRootBase_vtbl *)v6;
    aqOldSession = pMovieImpl;
    (*(void (__thiscall **)(unsigned int, Scaleform::GFx::TimelineDef::Frame *, unsigned int))(*(_DWORD *)this->pDispObj[1].CreateFrame
                                                                                             + 44))(
      this->pDispObj[1].CreateFrame,
      &playlist,
      frameNumber);
    for ( i = 0; i < playlist.TagCount; ++i )
    {
      v8 = playlist.pTagPtrList[i];
      if ( v8->IsActionTag(v8) )
        v8->Execute(v8, (Scaleform::GFx::DisplayObjContainer *)this->pDispObj);
    }
    this->pDispObj->pASRoot[7].pMovieImpl = aqOldSession;
    Scaleform::GFx::AS2::MovieRoot::DoActionsForSession((Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot, v6);
  }
}
