void __usercall Scaleform::GFx::AS2::GAS_BooleanValueOf(int a1@<edi>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *v4; // eax
  bool v5; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v7; // bl
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v9; // [esp+4h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Boolean )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = fn->Env;
    v4 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->__vftable)(
                                         p_pProto,
                                         &v9);
    v5 = Scaleform::GFx::AS2::Value::ToBool(v4, a1, Env);
    Result = fn->Result;
    v7 = v5;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v7;
    Result->T.Type = 2;
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Boolean");
  }
}
