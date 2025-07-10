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
  Scaleform::GFx::AS2::Value params[2]; // [esp+20h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h] BYREF

  pContext = penv->StringContext.pContext;
  v4 = &this->Scaleform::GFx::AS2::ObjectInterface;
  params[0].T.Type = 0;
  params[1].T.Type = 0;
  this->GetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34],
    params);
  v4->GetMemberRaw(
    v4,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    &params[1]);
  v8 = Scaleform::GFx::AS2::Value::ToNumber(params, penv);
  v5 = Scaleform::GFx::AS2::Value::ToNumber(&params[1], penv);
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
