void __cdecl Scaleform::GFx::AS2::ObjectCtorFunction::RegisterClassA(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *v2; // edi
  _DWORD *v3; // eax
  Scaleform::GFx::AS2::GlobalContext *v4; // ebx
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::Environment *Env; // edi
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // ecx
  unsigned __int8 Type; // cl
  Scaleform::GFx::AS2::Value *v10; // eax
  Scaleform::GFx::AS2::Value *v11; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v14; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  char v16; // al
  Scaleform::GFx::AS2::Value *v17; // esi
  char v18; // bl
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // edi
  Scaleform::GFx::ASStringNode *v22; // eax
  const Scaleform::GFx::AS2::Environment *v23; // [esp-Ch] [ebp-24h]
  Scaleform::GFx::ASStringNode *v24; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+Ch] [ebp-Ch] BYREF

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( v1->NArgs >= 2 )
  {
    v3 = &v1->Env->__vftable;
    v4 = (Scaleform::GFx::AS2::GlobalContext *)v3[29];
    v5 = 0;
    if ( v1->FirstArgBottomIndex <= (unsigned int)(32 * (v3[6] - 1) + ((v3[1] - v3[2]) >> 4)) )
      v5 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v3[5] + 4 * ((unsigned int)v1->FirstArgBottomIndex >> 5))
                                        + 16 * (v1->FirstArgBottomIndex & 0x1F));
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&fn, v1->Env, -1, 0);
    Env = v1->Env;
    v7 = v1->FirstArgBottomIndex - 1;
    v8 = 0;
    if ( v7 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v8 = &Env->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    Type = v8->T.Type;
    if ( Type == 8 || Type == 11 )
    {
      v23 = v1->Env;
      v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToFunction(v10, &result, v23);
      Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::FunctionRef,Scaleform::HashUncachedLH<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
        &v4->RegisteredClasses,
        (const Scaleform::GFx::ASString *)&fn,
        &result,
        v1->Env->StringContext.SWFVersion > 6u);
      v11 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v11);
      v11->T.Type = 2;
      v11->V.BooleanValue = 1;
      if ( (result.Flags & 2) == 0 )
      {
        if ( result.Function )
        {
          RefCount = result.Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            Function = result.Function;
            result.Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      result.Function = 0;
      if ( (result.Flags & 1) == 0 )
      {
        if ( result.pLocalFrame )
        {
          v14 = result.pLocalFrame->RefCount;
          if ( (v14 & 0x3FFFFFF) != 0 )
          {
            pLocalFrame = result.pLocalFrame;
            result.pLocalFrame->RefCount = v14 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
    }
    else if ( Scaleform::GFx::AS2::FnCall::Arg(v1, 1)->T.Type == 1 )
    {
      v16 = Scaleform::GFx::AS2::GlobalContext::UnregisterClassA(
              v4,
              &Env->StringContext,
              (const Scaleform::GFx::ASString *)&fn);
      v17 = v1->Result;
      v18 = v16;
      Scaleform::GFx::AS2::Value::DropRefs(v17);
      v17->T.Type = 2;
      v17->V.BooleanValue = v18;
    }
    else
    {
      v19 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToStringImpl(v19, (Scaleform::GFx::ASString *)&v24, Env, -1, 0);
      v20 = v24;
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v1->Env,
        "Second parameter of Object.registerClass(%s, %s) should be function or null",
        (const char *)fn->__vftable,
        v24->pData);
      if ( v20->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v20);
    }
    v22 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v22->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Too few parameters for Object.registerClass (%d)",
      v1->NArgs);
  }
}
