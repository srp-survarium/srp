void __usercall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::Initialize(
        Scaleform::GFx::AS2::LocalFrame **a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // edi
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  int v11; // [esp-8h] [ebp-Ch]

  if ( fn->NArgs < 1 )
    return;
  Env = fn->Env;
  v11 = a2;
  v5 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  if ( v5->T.Type != 7 )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(v5, Env);
    if ( v8 )
    {
      v7 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_10;
    }
LABEL_9:
    v7 = 0;
    goto LABEL_10;
  }
  v6 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v5, Env);
  if ( !v6 )
    goto LABEL_9;
  v7 = &v6->Scaleform::GFx::AS2::ObjectInterface;
LABEL_10:
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  p_StringContext = &fn->Env->StringContext;
  if ( v7 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (unsigned __int8 *)fn,
      a1,
      v7,
      p_StringContext,
      GAS_AsBcFunctionTable,
      1u,
      v11);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance((int)v7, (int)p_StringContext, p_StringContext, v7, v11, a3);
}
