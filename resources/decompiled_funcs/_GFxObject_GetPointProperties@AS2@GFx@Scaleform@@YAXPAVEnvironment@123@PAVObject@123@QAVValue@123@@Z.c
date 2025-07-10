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
