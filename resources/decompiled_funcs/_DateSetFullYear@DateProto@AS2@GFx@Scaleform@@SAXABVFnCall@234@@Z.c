void __cdecl Scaleform::GFx::AS2::DateProto::DateSetFullYear(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::DateObject *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v3; // eax
  long double v4; // st7
  int LJDate; // edi
  void *v6; // ebx
  int v7; // edi
  __int64 v8; // kr00_8
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
      LJDate = p_pProto->LJDate;
      v6 = (void *)(int)v4;
      if ( LJDate >= 60 )
      {
        v7 = LJDate - Scaleform::GFx::AS2::IsLeapYear(p_pProto->LYear);
        p_pProto->LJDate = Scaleform::GFx::AS2::IsLeapYear((int)v6) + v7;
      }
      v8 = p_pProto->LTime + 86400000LL * (p_pProto->LJDate + Scaleform::GFx::AS2::StartOfYear(v6));
      p_pProto->LYear = (int)v6;
      p_pProto->LDate = v8;
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
