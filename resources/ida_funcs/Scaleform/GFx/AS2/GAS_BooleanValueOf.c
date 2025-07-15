void __cdecl Scaleform::GFx::AS2::GAS_BooleanValueOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *v3; // eax
  char v4; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  char v6; // bl
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v8; // [esp+4h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Boolean )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = fn->Env;
    v3 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->__vftable)(
                                         p_pProto,
                                         &v8);
    v4 = Scaleform::GFx::AS2::Value::ToBool(v3, Env);
    Result = fn->Result;
    v6 = v4;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v6;
    Result->T.Type = 2;
    if ( v8.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v8);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Boolean");
  }
}
