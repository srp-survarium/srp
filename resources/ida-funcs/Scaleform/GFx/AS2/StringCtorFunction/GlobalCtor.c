void __cdecl Scaleform::GFx::AS2::StringCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  char v2; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v5; // eax
  int RefCount; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::Value *v8; // esi
  Scaleform::GFx::ASMovieRootBase *pObject; // edi
  int v10; // eax
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v12; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::ASStringNode *v14; // ecx
  bool v15; // zf
  Scaleform::GFx::AS2::Value v16; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value retVal; // [esp+20h] [ebp-10h] BYREF

  v1 = fn;
  v2 = 0;
  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_String
    && !v1->ThisPtr->IsBuiltinPrototype(v1->ThisPtr) )
  {
    ThisPtr = v1->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( v1->NArgs <= 0 )
    {
      RefCount = v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
      v2 = 1;
      ++*(_DWORD *)(RefCount + 12);
      v16.NV.Int32Value = RefCount;
      v16.T.Type = 5;
      v5 = &v16;
    }
    else
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    }
    Scaleform::GFx::AS2::Value::Value(&retVal, v5);
    if ( (v2 & 1) != 0 && v16.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v16);
    ((void (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Value *))p_pProto->pObject->RefCount)(
      p_pProto,
      v1->Env,
      &retVal);
    Scaleform::GFx::AS2::Value::operator=(v1->Result, &retVal);
    if ( retVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&retVal);
  }
  else if ( v1->NArgs )
  {
    Env = v1->Env;
    v12 = 0;
    if ( v1->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v12 = &Env->Stack.Pages.Data.Data[(unsigned int)v1->FirstArgBottomIndex >> 5]->Values[v1->FirstArgBottomIndex
                                                                                          & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v12, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    Result = v1->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    v14 = (Scaleform::GFx::ASStringNode *)fn;
    Result->T.Type = 5;
    Result->NV.Int32Value = (int)v14;
    v15 = ++v14->RefCount == 1;
    --v14->RefCount;
    if ( v15 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
  else
  {
    pContext = v1->Env->StringContext.pContext;
    v8 = v1->Result;
    pObject = pContext->pMovieRoot->pASMovieRoot.pObject;
    if ( v8->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v8);
    v8->T.Type = 5;
    v10 = pObject[8].RefCount;
    v8->NV.Int32Value = v10;
    ++*(_DWORD *)(v10 + 12);
  }
}
