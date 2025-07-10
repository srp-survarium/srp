void __cdecl Scaleform::GFx::AS2::BooleanCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  char v1; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Value retVal; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v9; // [esp+20h] [ebp-10h] BYREF

  v1 = 0;
  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Boolean
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( fn->NArgs <= 0 )
    {
      v1 = 1;
      v9.T.Type = 0;
      v4 = &v9;
    }
    else
    {
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    }
    Scaleform::GFx::AS2::Value::Value(&retVal, v4);
    if ( (v1 & 1) != 0 && v9.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v9);
    ((void (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->RefCount)(
      p_pProto,
      fn->Env,
      &retVal);
    Scaleform::GFx::AS2::Value::operator=(fn->Result, &retVal);
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
  }
  else
  {
    if ( fn->NArgs )
    {
      Env = fn->Env;
      v6 = 0;
      if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1)
                                    + Env->Stack.pCurrent
                                    - Env->Stack.pPageStart )
        v6 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                           & 0x1F];
      v1 = Scaleform::GFx::AS2::Value::ToBool(v6, fn->Env);
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v1;
    Result->T.Type = 2;
  }
}
