void __cdecl Scaleform::GFx::AS2::TransformCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // ecx
  Scaleform::GFx::ASStringNode *v2; // edx
  Scaleform::GFx::InteractiveObject *TargetByValue; // ebx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::TransformObject *p_pProto; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::TransformObject *v8; // eax
  Scaleform::GFx::AS2::TransformObject *v9; // eax
  unsigned int RefCount; // eax

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = (Scaleform::GFx::ASStringNode *)&Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
    TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(Env, v2);
    if ( TargetByValue )
    {
      if ( fn->ThisPtr
        && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Transform
        && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
      {
        ThisPtr = fn->ThisPtr;
        if ( ThisPtr )
        {
          p_pProto = (Scaleform::GFx::AS2::TransformObject *)&ThisPtr[-2].pProto;
          if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
            p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
        }
        else
        {
          p_pProto = 0;
        }
      }
      else
      {
        pHeap = fn->Env->StringContext.pContext->pHeap;
        v8 = (Scaleform::GFx::AS2::TransformObject *)pHeap->Alloc(pHeap, 72u, 0);
        if ( v8 )
          Scaleform::GFx::AS2::TransformObject::TransformObject(v8, fn->Env, 0);
        else
          v9 = 0;
        p_pProto = v9;
      }
      Scaleform::GFx::AS2::TransformObject::SetTarget(p_pProto, TargetByValue);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
      if ( p_pProto )
      {
        RefCount = p_pProto->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          p_pProto->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
        }
      }
    }
    else
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 0;
    }
  }
}
