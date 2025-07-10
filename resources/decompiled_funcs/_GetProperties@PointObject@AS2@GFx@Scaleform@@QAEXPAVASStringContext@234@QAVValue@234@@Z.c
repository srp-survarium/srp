void __thiscall Scaleform::GFx::AS2::PointObject::GetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Value *params)
{
  Scaleform::GFx::AS2::ObjectInterface *v3; // esi

  v3 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->GetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[34],
    params);
  v3->GetMemberRaw(
    v3,
    psc,
    (const Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    params + 1);
}
