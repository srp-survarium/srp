void __cdecl Scaleform::GFx::AS2::DateProto::DateSetDate(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::AS2::DateObject *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v3; // eax
  long double v4; // st7
  int LYear; // ecx
  int v6; // edi
  int LJDate; // ebp
  bool v8; // al
  int v9; // eax
  int v10; // eax
  __int64 v11; // rax
  bool v12; // cf
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-14h]

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
      LYear = p_pProto->LYear;
      v6 = 0;
      LJDate = p_pProto->LJDate;
      while ( 1 )
      {
        v8 = !(p_pProto->LYear % 4) && (LYear % 100 || !(LYear % 400));
        if ( LJDate < months[v8][v6] )
          break;
        if ( ++v6 >= 12 )
          return;
      }
      if ( v6 )
        v9 = dword_865024[12 * Scaleform::GFx::AS2::IsLeapYear(LYear) + v6];
      else
        v9 = 0;
      v10 = v9 - LJDate + (int)v4 - 1;
      p_pProto->LJDate = v10 + LJDate;
      v11 = 86400000LL * v10;
      v12 = __CFADD__((_DWORD)v11, p_pProto->LDate);
      LODWORD(p_pProto->LDate) += v11;
      HIDWORD(p_pProto->LDate) += HIDWORD(v11) + v12;
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
