void __cdecl Scaleform::GFx::AS2::FunctionProto::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // esi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *Result; // ebx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // esi
  unsigned int RefCount; // eax

  if ( fn->NArgs == 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v3 = 0;
    if ( FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    Type = v3->T.Type;
    if ( Type == 8 || Type == 11 || Scaleform::GFx::AS2::FnCall::Arg(fn, 0)->T.Type == 11 )
    {
      v6 = 0;
      if ( FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
        v6 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v7);
    }
    else
    {
      Result = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(Result);
      Result->T.Type = 1;
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v9 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 56u, 0);
    v10 = v9;
    if ( v9 )
    {
      Scaleform::GFx::AS2::Object::Object(v9, fn->Env);
      v10->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
      v10->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
      v10[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = 0;
    }
    else
    {
      v10 = 0;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v10);
    if ( v10 )
    {
      RefCount = v10->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
  }
}
