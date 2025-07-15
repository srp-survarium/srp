void __cdecl Scaleform::GFx::AS2::GASMatrixCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // eax
  Scaleform::GFx::AS2::Object *v4; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::MatrixObject *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Environment *Env; // eax
  const Scaleform::GFx::AS2::Value *v9; // edx
  Scaleform::GFx::ASStringNode *p_StringContext; // ebx
  Scaleform::GFx::AS2::ObjectInterface *p_pLocalFrame; // edi
  const Scaleform::GFx::AS2::Value *v12; // eax
  const Scaleform::GFx::AS2::Value *v13; // eax
  const Scaleform::GFx::AS2::Value *v14; // eax
  const Scaleform::GFx::AS2::Value *v15; // eax
  const Scaleform::GFx::AS2::Value *v16; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FnCall *v18; // [esp+Ch] [ebp+4h]

  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Matrix
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( p_pProto )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
      v4 = p_pProto;
      v18 = (Scaleform::GFx::AS2::FnCall *)p_pProto;
    }
    else
    {
      v4 = 0;
      v18 = 0;
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::AS2::MatrixObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v6 )
      Scaleform::GFx::AS2::MatrixObject::MatrixObject(v6, fn->Env);
    else
      v7 = 0;
    v4 = v7;
    v18 = (Scaleform::GFx::AS2::FnCall *)v7;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v9 = 0;
    p_StringContext = (Scaleform::GFx::ASStringNode *)&Env->StringContext;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v9 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = (Scaleform::GFx::AS2::Object *)v18;
    p_pLocalFrame = (Scaleform::GFx::AS2::ObjectInterface *)&v18->ThisFunctionRef.pLocalFrame;
    Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v18->ThisFunctionRef.pLocalFrame,
      p_StringContext,
      (char *)&stru_809F70,
      v9);
    if ( fn->NArgs > 1 )
    {
      v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(p_pLocalFrame, p_StringContext, "b", v12);
      if ( fn->NArgs > 2 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(p_pLocalFrame, p_StringContext, "c", v13);
        if ( fn->NArgs > 3 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(p_pLocalFrame, p_StringContext, "d", v14);
          if ( fn->NArgs > 4 )
          {
            v15 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
            Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(p_pLocalFrame, p_StringContext, "tx", v15);
            if ( fn->NArgs > 5 )
            {
              v16 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
              Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(p_pLocalFrame, p_StringContext, "ty", v16);
            }
          }
        }
      }
    }
  }
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
}
