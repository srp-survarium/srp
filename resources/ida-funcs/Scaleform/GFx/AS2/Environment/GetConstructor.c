Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::Environment::GetConstructor(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::ASBuiltinType className)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  bool v5; // zf
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::FunctionRef *v7; // esi
  bool v8; // cf
  Scaleform::GFx::AS2::Environment *ctor; // [esp+0h] [ebp-10h]
  Scaleform::GFx::AS2::Value v11; // [esp+10h] [ebp+0h] BYREF

  pContext = this->StringContext.pContext;
  v11.T.Type = 0;
  v5 = !pContext->pGlobal.pObject->GetMemberRaw(
          &pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
          &this->StringContext,
          (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount + className,
          &v11);
  Type = v11.T.Type;
  if ( !v5 && (v11.T.Type == 8 || v11.T.Type == 11) )
  {
    ctor = this;
    v7 = result;
    Scaleform::GFx::AS2::Value::ToFunction(&v11, result, ctor);
    v8 = v11.T.Type < 5u;
  }
  else
  {
    v7 = result;
    result->Flags = 0;
    result->Function = 0;
    result->pLocalFrame = 0;
    v8 = Type < 5u;
  }
  if ( !v8 )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  return v7;
}
