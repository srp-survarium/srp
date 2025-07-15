void __cdecl Scaleform::GFx::AS2::StringProto::StringCharCodeAt(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::ASConstString *p_pProto; // eax
  Scaleform::GFx::ASConstString *v3; // ebx
  Scaleform::GFx::AS2::Value *v4; // eax
  char *v5; // edi
  double CharAt; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-18h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::ASConstString *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v3 = p_pProto + 13;
    if ( fn->NArgs < 1
      || (Env = fn->Env,
          v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0),
          v5 = (char *)(int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env),
          (int)v5 < 0)
      || (int)v5 >= (int)Scaleform::GFx::ASConstString::GetLength(v3) )
    {
      CharAt = Scaleform::GFx::NumberUtil::NaN();
    }
    else
    {
      CharAt = (double)Scaleform::GFx::ASConstString::GetCharAt(v3, v5);
    }
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->NV.NumberValue = CharAt;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "String");
  }
}
