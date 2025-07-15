void __cdecl Scaleform::GFx::AS2::ColorCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::InteractiveObject *TargetByValue; // ebx
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::ASStringNode *v3; // edx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::ColorObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Object *v6; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ColorObject *v8; // eax
  Scaleform::GFx::AS2::Object *v9; // eax
  unsigned int RefCount; // eax

  TargetByValue = 0;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = (Scaleform::GFx::ASStringNode *)&Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(Env, v3);
  }
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Color )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::ColorObject *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
      v6 = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      Scaleform::GFx::AS2::ColorObject::SetTarget(p_pProto, TargetByValue);
    }
    else
    {
      v6 = 0;
      Scaleform::GFx::AS2::ColorObject::SetTarget(0, TargetByValue);
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v8 = (Scaleform::GFx::AS2::ColorObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v8 )
      Scaleform::GFx::AS2::ColorObject::ColorObject(v8, fn->Env, TargetByValue);
    else
      v9 = 0;
    v6 = v9;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
}
