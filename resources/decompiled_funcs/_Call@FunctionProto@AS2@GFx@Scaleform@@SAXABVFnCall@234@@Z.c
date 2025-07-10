void __cdecl Scaleform::GFx::AS2::FunctionProto::Call(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // esi
  const Scaleform::GFx::AS2::Value *v2; // ebp
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::AvmCharacter *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // esi
  Scaleform::RefCountNTSImpl *v8; // esi
  Scaleform::GFx::AS2::Object *v9; // eax
  int v10; // eax
  int v11; // ebx
  Scaleform::GFx::AS2::Environment *v12; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Environment *v15; // eax
  signed int v16; // ebx
  int v17; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *p_pProto; // esi
  Scaleform::GFx::AS2::Environment *v22; // eax
  int v23; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323>_vtbl *v24; // eax
  void (__thiscall *Finalize_GC)(Scaleform::GFx::AS2::RefCountBaseGC<323> *); // edx
  unsigned int RefCount; // eax
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Environment *v28; // [esp-4h] [ebp-58h]
  Scaleform::GFx::AS2::ObjectInterface *thisObj; // [esp+10h] [ebp-44h]
  int nArgs; // [esp+14h] [ebp-40h]
  Scaleform::RefCountNTSImpl *charHolder; // [esp+18h] [ebp-3Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *objectHolder; // [esp+1Ch] [ebp-38h]
  Scaleform::GFx::AS2::Value result; // [esp+20h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v34; // [esp+30h] [ebp-24h] BYREF

  v1 = fn->Result;
  v2 = 0;
  objectHolder = 0;
  charHolder = 0;
  thisObj = 0;
  nArgs = 0;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  if ( fn->NArgs < 1 )
    goto LABEL_20;
  Env = fn->Env;
  v4 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v28 = fn->Env;
  if ( v4->T.Type == 7 )
  {
    v5 = Scaleform::GFx::AS2::Value::ToAvmCharacter(v4, v28);
    if ( v5 )
    {
      v6 = &v5->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_7;
    }
LABEL_15:
    thisObj = 0;
    goto LABEL_20;
  }
  v9 = Scaleform::GFx::AS2::Value::ToObject(v4, v28);
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
  v10 = fn->NArgs;
  if ( v10 >= 2 )
  {
    v11 = v10 - 1;
    for ( nArgs = v10 - 1; v11 >= 1; v2 = 0 )
    {
      v12 = fn->Env;
      p_Stack = &v12->Stack;
      v14 = fn->FirstArgBottomIndex - v11;
      if ( v14 <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
        v2 = &v12->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
      ++p_Stack->pCurrent;
      if ( v12->Stack.pCurrent >= v12->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
      if ( p_Stack->pCurrent )
        Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v2);
      --v11;
    }
  }
  result.T.Type = 0;
  if ( fn->ThisFunctionRef.Function )
  {
    v15 = fn->Env;
    v16 = nArgs;
    v17 = v15->Stack.pCurrent - v15->Stack.pPageStart + 32 * v15->Stack.Pages.Data.Size - 32;
    v34.Result = &result;
    v34.ThisPtr = thisObj;
    pLocalFrame = fn->ThisFunctionRef.pLocalFrame;
    v34.FirstArgBottomIndex = v17;
    Function = fn->ThisFunctionRef.Function;
    v34.Env = v15;
    v34.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v34.ThisFunctionRef, 0, 9);
    v34.NArgs = nArgs;
    Function->Invoke(Function, &v34, pLocalFrame, 0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v34);
  }
  else
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&ThisPtr[-2].pProto;
      if ( p_pProto )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
    v22 = fn->Env;
    v16 = nArgs;
    v23 = v22->Stack.pCurrent - v22->Stack.pPageStart + 32 * v22->Stack.Pages.Data.Size - 32;
    v34.Result = &result;
    v34.FirstArgBottomIndex = v23;
    v34.Env = v22;
    v24 = p_pProto->__vftable;
    v34.ThisPtr = thisObj;
    Finalize_GC = v24[3].Finalize_GC;
    v34.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v34.ThisFunctionRef, 0, 9);
    v34.NArgs = nArgs;
    ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::FnCall *, _DWORD, _DWORD))Finalize_GC)(
      p_pProto,
      &v34,
      0,
      0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v34);
    RefCount = p_pProto->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      p_pProto->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
  if ( v16 > 0 )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&fn->Env->Stack, v16);
  Scaleform::GFx::AS2::Value::operator=(fn->Result, &result);
  if ( result.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&result);
  if ( charHolder )
    Scaleform::RefCountNTSImpl::Release(charHolder);
  if ( objectHolder )
  {
    v27 = objectHolder->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v27) != 0 )
    {
      objectHolder->RefCount = v27 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(objectHolder);
    }
  }
}
