void __cdecl Scaleform::GFx::AS2::ObjectProto::HasOwnProperty(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  bool v4; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  bool v6; // bl
  Scaleform::GFx::ASStringNode *v7; // eax

  v1 = fn;
  Env = fn->Env;
  v3 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&fn, Env, -1, 0);
  v4 = v1->ThisPtr->HasMember(v1->ThisPtr, &v1->Env->StringContext, (const Scaleform::GFx::ASString *)&fn, 0);
  Result = v1->Result;
  v6 = v4;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.BooleanValue = v6;
  Result->T.Type = 2;
  v7 = (Scaleform::GFx::ASStringNode *)fn;
  --fn->ThisFunctionRef.Function;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
}
