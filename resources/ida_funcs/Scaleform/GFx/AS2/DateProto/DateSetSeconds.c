void __cdecl Scaleform::GFx::AS2::DateProto::DateSetSeconds(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::DateObject *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v3; // eax
  long double v4; // st7
  int LTime; // edi
  __int64 v6; // rax
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-10h]

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
      v4 = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      LTime = p_pProto->LTime;
      v6 = 1000 * ((int)v4 - LTime % 60000 / 1000);
      p_pProto->LDate += v6;
      p_pProto->LTime = v6 + LTime;
      Scaleform::GFx::AS2::DateObject::UpdateGMT(p_pProto);
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
