void __thiscall Scaleform::GFx::AS2::AvmSprite::CallFrameActions(
        Scaleform::GFx::AS2::AvmSprite *this,
        unsigned int frameNumber)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  unsigned int v6; // ebp
  unsigned int i; // ebx
  int v8; // edi
  int v9; // [esp+8h] [ebp-8h] BYREF
  unsigned int v10; // [esp+Ch] [ebp-4h]
  Scaleform::GFx::MovieImpl *v11; // [esp+14h] [ebp+4h]

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
    v11 = pMovieImpl;
    (*(void (__thiscall **)(unsigned int, int *, unsigned int))(*(_DWORD *)this->pDispObj[1].CreateFrame + 44))(
      this->pDispObj[1].CreateFrame,
      &v9,
      frameNumber);
    for ( i = 0; i < v10; ++i )
    {
      v8 = *(_DWORD *)(v9 + 4 * i);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v8 + 16))(v8) )
        (*(void (__thiscall **)(int, Scaleform::GFx::InteractiveObject *))(*(_DWORD *)v8 + 4))(v8, this->pDispObj);
    }
    this->pDispObj->pASRoot[7].pMovieImpl = v11;
    Scaleform::GFx::AS2::MovieRoot::DoActionsForSession((Scaleform::GFx::AS2::MovieRoot *)this->pDispObj->pASRoot, v6);
  }
}
