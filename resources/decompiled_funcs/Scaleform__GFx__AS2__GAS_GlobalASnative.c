void __cdecl Scaleform::GFx::AS2::GAS_GlobalASnative(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v3; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Environment *v5; // edx
  unsigned int v6; // edi
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // ecx
  unsigned int v9; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::CFunctionObject *v11; // eax
  Scaleform::GFx::AS2::FunctionObject *v12; // eax
  Scaleform::GFx::AS2::FunctionObject *v13; // edi
  Scaleform::GFx::AS2::Value *v14; // ecx
  unsigned int RefCount; // eax
  unsigned int v16; // eax
  Scaleform::GFx::AS2::FunctionRefBase func; // [esp+8h] [ebp-Ch] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs >= 2 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
    v5 = fn->Env;
    v6 = v4;
    v7 = fn->FirstArgBottomIndex - 1;
    v8 = 0;
    if ( v7 <= 32 * (v5->Stack.Pages.Data.Size - 1) + v5->Stack.pCurrent - v5->Stack.pPageStart )
      v8 = &v5->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    v9 = Scaleform::GFx::AS2::Value::ToUInt32(v8, fn->Env);
    if ( v6 == 800 && v9 == 2 )
    {
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v11 = (Scaleform::GFx::AS2::CFunctionObject *)pHeap->Alloc(pHeap, 56u, 0);
      if ( v11 )
      {
        Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
          v11,
          &fn->Env->StringContext,
          Scaleform::GFx::AS2::GAS_ASnativeMouseButtonStates);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      func.Flags = 0;
      func.Function = v13;
      if ( v13 )
        v13->RefCount = (v13->RefCount + 1) & 0x8FFFFFFF;
      v14 = fn->Result;
      func.pLocalFrame = 0;
      Scaleform::GFx::AS2::Value::SetAsFunction(v14, &func);
      if ( v13 )
      {
        RefCount = v13->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v13->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
        }
        v16 = v13->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v16) != 0 )
        {
          v13->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
        }
      }
    }
  }
}
