void __cdecl Scaleform::GFx::AS2::ObjectProto::Watch_(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // edx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *v4; // ecx
  bool v5; // cc
  const Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // eax
  bool v8; // al
  Scaleform::GFx::AS2::Value *v9; // esi
  bool v10; // bl
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::AS2::Value *v12; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v15; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::Value *v17; // esi
  Scaleform::GFx::AS2::Environment *v18; // [esp-14h] [ebp-34h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+4h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+10h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->NArgs < 2 )
  {
    v17 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v17);
    v17->T.Type = 2;
    v17->V.BooleanValue = 0;
  }
  else
  {
    Env = fn->Env;
    v3 = fn->FirstArgBottomIndex - 1;
    v4 = 0;
    if ( v3 <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v4, &result, Env);
    if ( result.Function )
    {
      v5 = v1->NArgs < 3;
      v20.T.Type = 0;
      if ( !v5 )
      {
        v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        Scaleform::GFx::AS2::Value::operator=(&v20, v6);
      }
      v18 = v1->Env;
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v7, (Scaleform::GFx::ASString *)&fn, v18, -1, 0);
      v8 = v1->ThisPtr->Watch(
             v1->ThisPtr,
             &v1->Env->StringContext,
             (const Scaleform::GFx::ASString *)&fn,
             &result,
             &v20);
      v9 = v1->Result;
      v10 = v8;
      Scaleform::GFx::AS2::Value::DropRefs(v9);
      v9->T.Type = 2;
      v9->V.BooleanValue = v10;
      v11 = (Scaleform::GFx::ASStringNode *)fn;
      --fn->ThisFunctionRef.Function;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    else
    {
      v12 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v12);
      v12->T.Type = 2;
      v12->V.BooleanValue = 0;
    }
    if ( (result.Flags & 2) == 0 )
    {
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        Function = result.Function;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    result.Function = 0;
    if ( (result.Flags & 1) == 0 && result.pLocalFrame )
    {
      v15 = result.pLocalFrame->RefCount;
      pLocalFrame = result.pLocalFrame;
      if ( (v15 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
}
