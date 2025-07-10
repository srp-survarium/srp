void __cdecl Scaleform::GFx::AS2::GAS_NumberValueOf(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-20h]
  double v6; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Value v7; // [esp+Ch] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Number )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = fn->Env;
    v3 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->__vftable)(
                                         p_pProto,
                                         &v7);
    v6 = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
    if ( v7.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v7);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Number");
  }
}
