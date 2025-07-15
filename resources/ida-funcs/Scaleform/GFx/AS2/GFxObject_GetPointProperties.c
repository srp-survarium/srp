void __cdecl Scaleform::GFx::AS2::GFxObject_GetPointProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::Render::Point<double> *pt)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  long double v4; // st7
  Scaleform::GFx::AS2::Value *v5; // esi
  int v6; // edi
  long double v7; // [esp+18h] [ebp-28h]
  Scaleform::GFx::AS2::Value v8; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v9; // [esp+30h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+40h] [ebp+0h] BYREF

  pContext = penv->StringContext.pContext;
  v8.T.Type = 0;
  v9.T.Type = 0;
  pobj->GetMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[34],
    &v8);
  pobj->GetMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    &v9);
  v7 = Scaleform::GFx::AS2::Value::ToNumber(&v8, penv);
  v4 = Scaleform::GFx::AS2::Value::ToNumber(&v9, penv);
  pt->x = v7;
  v5 = (Scaleform::GFx::AS2::Value *)&retaddr;
  v6 = 1;
  pt->y = v4;
  do
  {
    --v5;
    if ( v5->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v5);
    --v6;
  }
  while ( v6 >= 0 );
}


void __cdecl Scaleform::GFx::AS2::GFxObject_GetPointProperties(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *pobj,
        Scaleform::GFx::AS2::Value *params)
{
  pobj->GetMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[34],
    params);
  pobj->GetMemberRaw(
    &pobj->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    (const Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[34].RefCount,
    &params[1]);
}
