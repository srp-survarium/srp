void __usercall Scaleform::GFx::AS2::ObjectProto::AddProperty(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::Environment *v6; // edx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Value *v8; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::GFx::AS2::FunctionObject *v10; // ebx
  Scaleform::GFx::AS2::LocalFrame *v11; // ebp
  bool v12; // cc
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::FunctionRef *v15; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *v17; // ecx
  unsigned int v18; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v21; // ecx
  Scaleform::GFx::AS2::ASRefCountCollector *v22; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ValueProperty *v24; // eax
  void *v25; // eax
  Scaleform::GFx::AS2::Value *v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned __int8 Flags; // bl
  unsigned int v30; // eax
  Scaleform::GFx::AS2::LocalFrame *v31; // ecx
  unsigned int v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::AS2::Value *v34; // esi
  Scaleform::GFx::AS2::Value *v35; // esi
  Scaleform::GFx::AS2::Environment *v36; // [esp+4h] [ebp-4Ch]
  int v37; // [esp+8h] [ebp-48h]
  Scaleform::GFx::ASStringNode *v40; // [esp+18h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase v41; // [esp+1Ch] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+28h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRef getterMethod; // [esp+34h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v44; // [esp+40h] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+50h] [ebp+0h]

  if ( fn->NArgs < 2 )
  {
    v35 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v35);
    v35->T.Type = 2;
    v35->V.BooleanValue = 0;
  }
  else
  {
    Env = fn->Env;
    v5 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v40, Env, -1, 0);
    v6 = fn->Env;
    v7 = fn->FirstArgBottomIndex - 1;
    v8 = 0;
    if ( v7 <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
      v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
    Scaleform::GFx::AS2::Value::ToFunction(v8, &result, fn->Env);
    Function = result.Function;
    if ( result.Function )
    {
      v37 = a2;
      v10 = 0;
      v11 = 0;
      v12 = fn->NArgs < 3;
      memset(&v41, 0, 9);
      if ( !v12 )
      {
        Type = Scaleform::GFx::AS2::FnCall::Arg(fn, 2)->T.Type;
        if ( Type == 8 || Type == 11 )
        {
          v36 = fn->Env;
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
          v15 = Scaleform::GFx::AS2::Value::ToFunction(v14, &getterMethod, v36);
          Scaleform::GFx::AS2::FunctionRefBase::Assign(&v41, v15);
          if ( (getterMethod.Flags & 2) == 0 )
          {
            if ( getterMethod.Function )
            {
              RefCount = getterMethod.Function->RefCount;
              v17 = getterMethod.Function;
              if ( (RefCount & 0x3FFFFFF) != 0 )
              {
                getterMethod.Function->RefCount = RefCount - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
              }
            }
          }
          getterMethod.Function = 0;
          if ( (getterMethod.Flags & 1) == 0 )
          {
            if ( getterMethod.pLocalFrame )
            {
              v18 = getterMethod.pLocalFrame->RefCount;
              pLocalFrame = getterMethod.pLocalFrame;
              if ( (v18 & 0x3FFFFFF) != 0 )
              {
                getterMethod.pLocalFrame->RefCount = v18 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
              }
            }
          }
          v10 = v41.Function;
          v11 = v41.pLocalFrame;
        }
      }
      Target = fn->Env->Target;
      if ( Target )
      {
        v21 = &Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
            + Target->AvmObjOffset;
        v22 = *(Scaleform::GFx::AS2::ASRefCountCollector **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **, int))(*v21)->CreateRenderNode)(
                                                                                                   v21,
                                                                                                   v37)
                                                                                               + 16)
                                                                                   + 16)
                                                                       + 28)
                                                           + 16);
      }
      else
      {
        v22 = 0;
      }
      pHeap = fn->Env->StringContext.pContext->pHeap;
      v44.T.Type = 9;
      v24 = (Scaleform::GFx::AS2::ValueProperty *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int, int))pHeap->Alloc)(
                                                    pHeap,
                                                    40,
                                                    0,
                                                    v37,
                                                    a3,
                                                    a1);
      if ( v24 )
      {
        Scaleform::GFx::AS2::ValueProperty::ValueProperty(v24, v22, &getterMethod, &result);
        retaddr = v25;
      }
      else
      {
        retaddr = 0;
      }
      ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *))fn->ThisPtr->SetMemberRaw)(
        fn->ThisPtr,
        &fn->Env->StringContext);
      v26 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v26);
      v26->T.Type = 2;
      v26->V.BooleanValue = 1;
      if ( v44.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v44);
      if ( (v41.Flags & 2) == 0 )
      {
        if ( v10 )
        {
          v27 = v10->RefCount;
          if ( (v27 & 0x3FFFFFF) != 0 )
          {
            v10->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
          }
        }
      }
      if ( (v41.Flags & 1) == 0 )
      {
        if ( v11 )
        {
          v28 = v11->RefCount;
          if ( (v28 & 0x3FFFFFF) != 0 )
          {
            v11->RefCount = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          }
        }
      }
      Function = result.Function;
    }
    else
    {
      v34 = fn->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v34);
      v34->T.Type = 2;
      v34->V.BooleanValue = 0;
    }
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      if ( Function )
      {
        v30 = Function->RefCount;
        if ( (v30 & 0x3FFFFFF) != 0 )
        {
          Function->RefCount = v30 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    if ( (Flags & 1) == 0 )
    {
      v31 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v32 = result.pLocalFrame->RefCount;
        if ( (v32 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v32 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v31);
        }
      }
    }
    v33 = v40;
    --v40->RefCount;
    if ( !v33->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  }
}
