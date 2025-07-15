void __cdecl Scaleform::GFx::AS2::DateProto::DateSetMonth(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  int v5; // ebp
  int v6; // ebx
  int v7; // ecx
  int v8; // eax
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-18h]
  Scaleform::GFx::AS2::Object *pObject; // [esp+4h] [ebp-4h]
  Scaleform::GFx::AS2::FnCall *fna; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Date )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v5 = (int)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
      Scaleform::GFx::AS2::DateProto::DateGetDate(fn);
      fna = (Scaleform::GFx::AS2::FnCall *)(int)Scaleform::GFx::AS2::Value::ToNumber(fn->Result, fn->Env);
      v6 = 0;
      pObject = p_pProto[24].pObject;
      if ( v5 > 0 )
        v6 = dword_6F8914[12 * Scaleform::GFx::AS2::IsLeapYear((int)p_pProto[23].pObject) + v5];
      v7 = v5 + 12 * Scaleform::GFx::AS2::IsLeapYear((int)p_pProto[23].pObject);
      if ( (int)fna > months[0][v7] - v6 )
        fna = (Scaleform::GFx::AS2::FnCall *)(months[0][v7] - v6);
      v8 = (int)fna + v6 - 1;
      p_pProto[24].pObject = (Scaleform::GFx::AS2::Object *)v8;
      *(_QWORD *)&p_pProto[20].pObject += 86400000LL * (v8 - (int)pObject);
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
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
