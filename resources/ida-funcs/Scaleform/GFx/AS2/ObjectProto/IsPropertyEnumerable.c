void __cdecl Scaleform::GFx::AS2::ObjectProto::IsPropertyEnumerable(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  bool v4; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  Scaleform::GFx::AS2::Environment *v6; // eax
  Scaleform::GFx::AS2::Value *v7; // esi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Value v10; // [esp+18h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->NArgs < 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = 0;
  }
  else
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
    v4 = v1->ThisPtr->HasMember(v1->ThisPtr, &v1->Env->StringContext, (const Scaleform::GFx::ASString *)&fn, 0);
    if ( v4 )
    {
      ThisPtr = v1->ThisPtr;
      v6 = v1->Env;
      v10.T = 0;
      ThisPtr->FindMember(
        ThisPtr,
        &v6->StringContext,
        (const Scaleform::GFx::ASString *)&fn,
        (Scaleform::GFx::AS2::Member *)&v10);
      if ( (v10.T.PropFlags & 1) != 0 )
        v4 = 0;
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
    }
    v7 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->V.BooleanValue = v4;
    v7->T.Type = 2;
    v8 = (Scaleform::GFx::ASStringNode *)fn;
    --fn->ThisFunctionRef.Function;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
}
