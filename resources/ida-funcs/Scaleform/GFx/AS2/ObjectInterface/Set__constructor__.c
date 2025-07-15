void __thiscall Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::FunctionRef *ctorFunc)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  char v6; // [esp+Fh] [ebp-11h] BYREF
  Scaleform::GFx::AS2::Value v7; // [esp+10h] [ebp-10h] BYREF

  Function = ctorFunc->Function;
  v6 = 3;
  v7.T.Type = 8;
  v7.V.FunctionValue.Flags = 0;
  v7.NV.Int32Value = (int)Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  pLocalFrame = ctorFunc->pLocalFrame;
  v7.V.FunctionValue.pLocalFrame = 0;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v7.V.FunctionValue, pLocalFrame, ctorFunc->Flags & 1);
  this->SetMemberRaw(
    this,
    psc,
    (const Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[24].RefCount,
    &v7,
    (const Scaleform::GFx::AS2::PropFlags *)&v6);
  if ( v7.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v7);
}
