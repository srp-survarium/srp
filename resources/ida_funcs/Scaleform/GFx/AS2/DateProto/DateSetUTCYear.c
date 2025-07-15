void __cdecl Scaleform::GFx::AS2::DateProto::DateSetUTCYear(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::DateObject *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v3; // eax
  unsigned int v4; // eax
  void *v5; // ebx
  int JDate; // edi
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
      v4 = (int)Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
      v5 = (void *)v4;
      if ( v4 <= 0x63 )
        v5 = (void *)(v4 + 1900);
      JDate = p_pProto->JDate;
      if ( JDate >= 60 )
      {
        v7 = JDate - Scaleform::GFx::AS2::IsLeapYear(p_pProto->Year);
        p_pProto->JDate = Scaleform::GFx::AS2::IsLeapYear((int)v5) + v7;
      }
      v8 = p_pProto->Time + 86400000LL * (p_pProto->JDate + Scaleform::GFx::AS2::StartOfYear(v5));
      p_pProto->Year = (int)v5;
      p_pProto->Date = v8;
      Scaleform::GFx::AS2::DateObject::UpdateLocal(p_pProto);
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
