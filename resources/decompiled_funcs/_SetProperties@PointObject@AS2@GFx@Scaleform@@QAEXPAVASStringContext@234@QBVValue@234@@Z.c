void __thiscall Scaleform::GFx::AS2::PointObject::SetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        const Scaleform::GFx::AS2::Value *params)
{
  bool (__thiscall *SetMemberRaw)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // eax
  const Scaleform::GFx::AS2::Value *v4; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface *v6; // esi
  Scaleform::GFx::AS2::GlobalContext *v7; // ecx
  bool (__thiscall *v8)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, const Scaleform::GFx::AS2::Value *, const Scaleform::GFx::AS2::PropFlags *); // edx
  char v9; // [esp+Fh] [ebp-1h] BYREF

  SetMemberRaw = this->SetMemberRaw;
  v4 = params;
  pContext = psc->pContext;
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v9 = 0;
  SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34],
    params,
    (const Scaleform::GFx::AS2::PropFlags *)&v9);
  v7 = psc->pContext;
  v8 = v6->SetMemberRaw;
  LOBYTE(params) = 0;
  v8(
    v6,
    psc,
    (const Scaleform::GFx::ASString *)&v7->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    v4 + 1,
    (const Scaleform::GFx::AS2::PropFlags *)&params);
}
