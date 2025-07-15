Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::ObjectInterface::Get_constructor(
        Scaleform::GFx::AS2::ObjectInterface *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v4; // esi
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  pContext = psc->pContext;
  v4 = this->__vftable;
  val.T.Type = 0;
  if ( v4->GetMemberRaw(
         this,
         psc,
         (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &val) )
  {
    Scaleform::GFx::AS2::Value::ToFunction(&val, result, 0);
  }
  else
  {
    result->Flags = 0;
    result->Function = 0;
    result->pLocalFrame = 0;
  }
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  return result;
}
