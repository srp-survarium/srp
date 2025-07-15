void __cdecl Scaleform::GFx::AS2::FunctionProto::Apply(Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> fn)
{
  Scaleform::GFx::AS2::Value *pRCC; // esi
  Scaleform::GFx::AS2::Environment *pObject; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // esi
  Scaleform::RefCountNTSImpl *v8; // esi
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Environment *v10; // edx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // ecx
  Scaleform::GFx::AS2::Object *v13; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // ebp
  int RefCount; // eax
  int i; // ebx
  Scaleform::GFx::AS2::Environment *v17; // esi
  Scaleform::GFx::AS2::Value *v18; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::AS2::Environment *v21; // eax
  signed int v22; // ebp
  int v23; // ecx
  Scaleform::GFx::AS2::LocalFrame *v24; // edx
  Scaleform::GFx::AS2::FunctionObject *v25; // ecx
  Scaleform::GFx::AS2::ObjectInterface *RootIndex; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *p_pProto; // esi
  Scaleform::GFx::AS2::Environment *v28; // eax
  int v29; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v30; // eax
  void (__thiscall *Finalize_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *); // edx
  unsigned int v32; // eax
  unsigned int v33; // eax
  unsigned int v34; // eax
  Scaleform::GFx::AS2::Environment *v35; // [esp-4h] [ebp-5Ch]
  Scaleform::GFx::AS2::ObjectInterface *thisObj; // [esp+10h] [ebp-48h]
  int nArgs; // [esp+14h] [ebp-44h]
  Scaleform::RefCountNTSImpl *charHolder; // [esp+18h] [ebp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *objectHolder; // [esp+1Ch] [ebp-3Ch]
  Scaleform::GFx::AS2::Value *v; // [esp+20h] [ebp-38h]
  Scaleform::GFx::AS2::Value result; // [esp+24h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v42; // [esp+34h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *arguments; // [esp+5Ch] [ebp+4h]

  pRCC = (Scaleform::GFx::AS2::Value *)fn.pObject->pRCC;
  objectHolder = 0;
  charHolder = 0;
  thisObj = 0;
  nArgs = 0;
  Scaleform::GFx::AS2::Value::DropRefs(pRCC);
  pRCC->T.Type = 0;
  arguments = 0;
  if ( (int)fn.pObject->Members.mHash.pTable < 1 )
    goto LABEL_20;
  pObject = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
  v4 = 0;
  if ( fn.pObject->ResolveHandler.Function <= (Scaleform::GFx::AS2::FunctionObject *)(32
                                                                                    * (pObject->Stack.Pages.Data.Size - 1)
                                                                                    + pObject->Stack.pCurrent
                                                                                    - pObject->Stack.pPageStart) )
    v4 = &pObject->Stack.Pages.Data.Data[(unsigned int)fn.pObject->ResolveHandler.Function >> 5]->Values[(int)fn.pObject->ResolveHandler.Function & 0x1F];
  v35 = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
  if ( v4->T.Type == 7 )
  {
    v5 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v4, v35);
    if ( v5 )
    {
      v6 = &v5->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_7;
    }
LABEL_15:
    thisObj = 0;
    goto LABEL_20;
  }
  v9 = Scaleform::GFx::AS2::Value::ToObject(v4, v35);
  if ( !v9 )
    goto LABEL_15;
  v6 = &v9->Scaleform::GFx::AS2::ObjectInterface;
LABEL_7:
  thisObj = v6;
  if ( v6 )
  {
    v7 = v6;
    if ( (unsigned int)(v6->GetObjectType(v6) - 2) > 3 )
    {
      if ( v7 != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        v7[-1].pProto.pObject = (Scaleform::GFx::AS2::Object *)(((int)&v7[-1].pProto.pObject->__vftable + 1) & 0x8FFFFFFF);
      objectHolder = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7[-2].pProto;
    }
    else if ( (unsigned int)(v7->GetObjectType(v7) - 2) > 3 )
    {
      charHolder = 0;
    }
    else
    {
      v8 = (Scaleform::RefCountNTSImpl *)v7[1].__vftable;
      if ( v8 )
        ++v8->RefCount;
      charHolder = v8;
    }
  }
LABEL_20:
  if ( (int)fn.pObject->Members.mHash.pTable >= 2 )
  {
    v10 = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
    v11 = (unsigned int)(&fn.pObject->ResolveHandler.Function[-1].IsListenerSet + 2);
    v12 = 0;
    if ( v11 <= 32 * (v10->Stack.Pages.Data.Size - 1) + v10->Stack.pCurrent - v10->Stack.pPageStart )
      v12 = &v10->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
    v13 = Scaleform::GFx::AS2::Value::ToObject(v12, (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject);
    v14 = v13;
    if ( v13 )
    {
      if ( v13->GetObjectType(&v13->Scaleform::GFx::AS2::ObjectInterface) == Object_Array )
      {
        RefCount = v14[3].RefCount;
        v14->RefCount = (v14->RefCount + 1) & 0x8FFFFFFF;
        arguments = v14;
        nArgs = RefCount;
        if ( RefCount > 0 )
        {
          for ( i = RefCount - 1; i >= 0; --i )
          {
            v17 = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
            v18 = *(Scaleform::GFx::AS2::Value **)(v14[3].RootIndex + 4 * i);
            ++v17->Stack.pCurrent;
            p_Stack = &v17->Stack;
            v = v18;
            if ( p_Stack->pCurrent >= p_Stack->pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
            pCurrent = p_Stack->pCurrent;
            if ( pCurrent )
              Scaleform::GFx::AS2::Value::Value(pCurrent, v);
          }
        }
      }
    }
  }
  result.T.Type = 0;
  if ( fn.pObject->RefCount )
  {
    v21 = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
    v22 = nArgs;
    v23 = v21->Stack.pCurrent - v21->Stack.pPageStart + 32 * v21->Stack.Pages.Data.Size - 32;
    v42.Result = &result;
    v42.ThisPtr = thisObj;
    v24 = (Scaleform::GFx::AS2::LocalFrame *)fn.pObject->__vftable;
    v42.FirstArgBottomIndex = v23;
    v25 = (Scaleform::GFx::AS2::FunctionObject *)fn.pObject->RefCount;
    v42.Env = v21;
    v42.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v42.ThisFunctionRef, 0, 9);
    v42.NArgs = nArgs;
    v25->Invoke(v25, &v42, v24, 0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v42);
  }
  else
  {
    RootIndex = (Scaleform::GFx::AS2::ObjectInterface *)fn.pObject->RootIndex;
    if ( RootIndex )
    {
      p_pProto = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&RootIndex[-2].pProto;
      if ( p_pProto )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
    v28 = (Scaleform::GFx::AS2::Environment *)fn.pObject->pProto.pObject;
    v22 = nArgs;
    v29 = v28->Stack.pCurrent - v28->Stack.pPageStart + 32 * v28->Stack.Pages.Data.Size - 32;
    v42.Result = &result;
    v42.FirstArgBottomIndex = v29;
    v42.Env = v28;
    v30 = p_pProto->__vftable;
    v42.ThisPtr = thisObj;
    Finalize_GC = v30[3].Finalize_GC;
    v42.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v42.ThisFunctionRef, 0, 9);
    v42.NArgs = nArgs;
    ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::FnCall *, _DWORD, _DWORD))Finalize_GC)(
      p_pProto,
      &v42,
      0,
      0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v42);
    v32 = p_pProto->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v32) != 0 )
    {
      p_pProto->RefCount = v32 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
  if ( v22 > 0 )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
      (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&fn.pObject->pProto.pObject->4,
      v22);
  Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)fn.pObject->pRCC, &result);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( arguments )
  {
    v33 = arguments->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v33) != 0 )
    {
      arguments->RefCount = v33 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(arguments);
    }
  }
  if ( charHolder )
    Scaleform::RefCountNTSImpl::Release(charHolder);
  if ( objectHolder )
  {
    v34 = objectHolder->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v34) != 0 )
    {
      objectHolder->RefCount = v34 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(objectHolder);
    }
  }
}
