void __cdecl Scaleform::GFx::AS2::DateProto::DateSetTime(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::DateObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  __int64 v4; // rax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-Ch]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::DateObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = (unsigned __int64)Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      Scaleform::GFx::AS2::DateObject::SetDate(p_pProto, v4);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Date");
  }
}
