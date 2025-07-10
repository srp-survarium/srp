void __cdecl Scaleform::GFx::AS2::NumberCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  char v1; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v4; // eax
  double v5; // st7
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v7; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  long double v9; // st7
  Scaleform::GFx::AS2::Value retVal; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+1Ch] [ebp-10h] BYREF

  v1 = 0;
  *(_DWORD *)&retVal.T.Type = 0;
  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Number
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
      v11.T.Type = 0;
      v4 = &v11;
    }
    else
    {
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    }
    Scaleform::GFx::AS2::Value::Value(&retVal, v4);
    if ( (v1 & 1) != 0 && v11.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v11);
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
      v7 = 0;
      if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1)
                                    + Env->Stack.pCurrent
                                    - Env->Stack.pPageStart )
        v7 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                           & 0x1F];
      v5 = Scaleform::GFx::AS2::Value::ToNumber(v7, fn->Env);
    }
    else
    {
      v5 = 0.0;
    }
    Result = fn->Result;
    *(double *)&retVal.T.Type = v5;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    v9 = *(double *)&retVal.T.Type;
    Result->T.Type = 3;
    Result->NV.NumberValue = v9;
  }
}
