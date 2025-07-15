void __cdecl Scaleform::GFx::AS2::GAS_BooleanToString(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ecx
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *v7; // ecx
  bool v8; // zf
  Scaleform::GFx::AS2::Value v9; // [esp+4h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Boolean )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    Env = v1->Env;
    v5 = (Scaleform::GFx::AS2::Value *)((int (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->__vftable)(
                                         p_pProto,
                                         &v9);
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    v7 = (Scaleform::GFx::ASStringNode *)fn;
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)v7;
    v8 = ++v7->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    if ( v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Boolean");
  }
}
