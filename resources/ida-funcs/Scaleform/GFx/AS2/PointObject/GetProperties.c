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


void __thiscall Scaleform::GFx::AS2::PointObject::GetProperties(
        Scaleform::GFx::AS2::PointObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::Render::Point<double> *pt)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface *v4; // edi
  long double v5; // st7
  Scaleform::GFx::AS2::Value *v6; // esi
  int v7; // edi
  long double v8; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS2::Value v9; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+30h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h] BYREF

  pContext = penv->StringContext.pContext;
  v4 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v9.T.Type = 0;
  v10.T.Type = 0;
  this->GetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34],
    &v9);
  v4->GetMemberRaw(
    v4,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    &v10);
  v8 = Scaleform::GFx::AS2::Value::ToNumber(&v9, penv);
  v5 = Scaleform::GFx::AS2::Value::ToNumber(&v10, penv);
  pt->x = v8;
  v6 = (Scaleform::GFx::AS2::Value *)&retaddr;
  v7 = 1;
  pt->y = v5;
  do
  {
    --v6;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    --v7;
  }
  while ( v7 >= 0 );
}
