char __thiscall Scaleform::GFx::AS2::GASPrototypeBase::SetConstructor(
        Scaleform::GFx::AS2::GASPrototypeBase *this,
        Scaleform::GFx::AS2::Object *pthis,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *ctor)
{
  Scaleform::GFx::AS2::FunctionRef *v5; // eax
  int v6; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  int v8; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  Scaleform::GFx::AS2::GlobalContext *pContext; // esi
  Scaleform::GFx::AS2::Value result; // [esp+10h] [ebp-10h] BYREF

  v5 = Scaleform::GFx::AS2::Value::ToFunction(ctor, (Scaleform::GFx::AS2::FunctionRef *)&result, 0);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->Constructor, v5);
  if ( (BYTE4(result.NV.NumberValue) & 2) == 0 )
  {
    if ( *(_DWORD *)&result.T.Type )
    {
      v6 = *(_DWORD *)(*(_DWORD *)&result.T.Type + 12);
      v7 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&result.T.Type + 12) = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
  *(_DWORD *)&result.T.Type = 0;
  if ( (BYTE4(result.NV.NumberValue) & 1) == 0 )
  {
    if ( result.NV.Int32Value )
    {
      v8 = *(_DWORD *)(result.NV.Int32Value + 12);
      pStringNode = result.V.pStringNode;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(result.NV.Int32Value + 12) = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
      }
    }
  }
  SetMemberRaw = pthis->SetMemberRaw;
  pContext = psc->pContext;
  LOBYTE(ctor) = 3;
  result.T.Type = 10;
  SetMemberRaw(
    &pthis->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[24],
    &result,
    (const Scaleform::GFx::AS2::PropFlags *)&ctor);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  return 1;
}
