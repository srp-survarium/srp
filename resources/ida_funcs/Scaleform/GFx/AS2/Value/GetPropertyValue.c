char __thiscall Scaleform::GFx::AS2::Value::GetPropertyValue(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Value *value)
{
  Scaleform::GFx::ASStringNode *pStringNode; // eax
  Scaleform::GFx::AS2::Value result; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v7; // [esp+1Ch] [ebp-24h] BYREF

  if ( this->T.Type != 9 || !penv )
    return 0;
  pStringNode = this->V.pStringNode;
  if ( !pStringNode->HashFlags )
  {
    if ( penv->IsVerboseActionErrors(penv) )
      Scaleform::GFx::AS2::Environment::LogScriptError(penv, "Getter method is null.");
    return 0;
  }
  v7.Result = &result;
  result.T.Type = 0;
  memset(&v7.ThisFunctionRef, 0, 9);
  v7.NArgs = 0;
  v7.FirstArgBottomIndex = 0;
  v7.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  v7.ThisPtr = pthis;
  v7.Env = penv;
  (*(void (__thiscall **)(unsigned int, Scaleform::GFx::AS2::FnCall *, unsigned int, _DWORD))(*(_DWORD *)pStringNode->HashFlags
                                                                                            + 40))(
    pStringNode->HashFlags,
    &v7,
    pStringNode->Size,
    0);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v7);
  Scaleform::GFx::AS2::Value::operator=(value, &result);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  return 1;
}
