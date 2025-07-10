void __cdecl Scaleform::GFx::AS2::DateProto::DateGetDate(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  int pObject; // esi
  bool IsLeapYear; // al
  int v5; // ecx
  BOOL v6; // ebx
  Scaleform::GFx::AS2::Value *Result; // esi
  long double v8; // st7
  int i; // edi
  bool v10; // al
  Scaleform::GFx::AS2::Value *v11; // esi

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    pObject = (int)p_pProto[23].pObject;
    IsLeapYear = Scaleform::GFx::AS2::IsLeapYear(pObject);
    v5 = (int)p_pProto[24].pObject;
    v6 = IsLeapYear;
    if ( v5 >= months[IsLeapYear][0] )
    {
      for ( i = 1; i < 12; ++i )
      {
        v10 = !(pObject % 4) && (pObject % 100 || !(pObject % 400));
        if ( v5 < months[v10][i] )
        {
          Result = fn->Result;
          v8 = (double)(v5 - dword_865024[12 * v6 + i] + 1);
          goto LABEL_9;
        }
      }
      v11 = fn->Result;
      if ( v11->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
      v11->NV.NumberValue = -1.0;
      v11->T.Type = 3;
    }
    else
    {
      Result = fn->Result;
      v8 = (double)(v5 + 1);
LABEL_9:
      if ( Result->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->NV.NumberValue = v8;
      Result->T.Type = 3;
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
