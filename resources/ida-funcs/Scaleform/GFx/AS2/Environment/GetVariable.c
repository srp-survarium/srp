char __thiscall Scaleform::GFx::AS2::Environment::GetVariable(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::ASString *varname,
        Scaleform::GFx::AS2::Value *presult,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        Scaleform::GFx::InteractiveObject **ppnewTarget,
        Scaleform::GFx::AS2::Value *powner,
        unsigned int excludeFlags)
{
  char VariableRaw; // bl
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  int p_pMovieImpl; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::ObjectInterface *v13; // eax
  Scaleform::GFx::AS2::AvmCharacter *v14; // eax
  Scaleform::GFx::InteractiveObject *Target; // eax
  Scaleform::GFx::AS2::GlobalContext *v17; // ecx
  Scaleform::GFx::AS2::Object *v18; // eax
  Scaleform::GFx::AS2::ObjectInterface *v19; // ebx
  Scaleform::GFx::AS2::AvmCharacter *v20; // eax
  Scaleform::GFx::InteractiveObject *v21; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v22; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  int v26; // eax
  unsigned int v27; // ecx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebp
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  unsigned int RefCount; // eax
  unsigned int v31; // eax
  int v32; // [esp+0h] [ebp-5Ch]
  int v33; // [esp+4h] [ebp-58h]
  Scaleform::GFx::AS2::FunctionRef resolveHandler; // [esp+10h] [ebp-4Ch] BYREF
  Scaleform::GFx::AS2::Value thisVal; // [esp+20h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value *v36; // [esp+30h] [ebp-2Ch]
  unsigned int v37; // [esp+34h] [ebp-28h]
  Scaleform::GFx::AS2::FnCall v38; // [esp+38h] [ebp-24h] BYREF
  char retVal; // [esp+64h] [ebp+8h]

  *(_QWORD *)&thisVal.T.Type = __PAIR64__((unsigned int)presult, (unsigned int)varname);
  *(_QWORD *)((char *)&thisVal.NV.NumberValue + 4) = __PAIR64__((unsigned int)ppnewTarget, (unsigned int)pwithStack);
  v36 = powner;
  v37 = excludeFlags;
  VariableRaw = Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(
                  this,
                  (int)presult,
                  (Scaleform::GFx::AS2::Object *)&thisVal);
  retVal = VariableRaw;
  if ( VariableRaw && presult->T.Type == 9 )
  {
    pContext = this->StringContext.pContext;
    LOBYTE(resolveHandler.Function) = 0;
    p_pMovieImpl = (int)&pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl;
    *(_QWORD *)((char *)&thisVal.NV.NumberValue + 4) = (unsigned int)pwithStack;
    *(_QWORD *)&thisVal.T.Type = __PAIR64__(&resolveHandler, p_pMovieImpl);
    v36 = 0;
    v37 = 0;
    if ( Scaleform::GFx::AS2::Environment::GetVariableRaw(
           this,
           (int)presult,
           (int)this,
           (Scaleform::GFx::AS2::Object *)&thisVal,
           v32,
           v33) )
    {
      v12 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)&resolveHandler, this);
      if ( v12 )
      {
        v13 = &v12->Scaleform::GFx::AS2::ObjectInterface;
        if ( v13 )
          goto LABEL_12;
      }
      v14 = Scaleform::GFx::AS2::Value::ToAvmCharacter((Scaleform::GFx::AS2::Value *)&resolveHandler, this);
    }
    else
    {
      Target = this->Target;
      if ( !Target )
        goto LABEL_11;
      v14 = (Scaleform::GFx::AS2::AvmCharacter *)(*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                              + Target->AvmObjOffset)
                                                                            + 4))((int)Target + 4 * Target->AvmObjOffset);
    }
    if ( v14 )
    {
      v13 = &v14->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_12;
    }
LABEL_11:
    v13 = 0;
LABEL_12:
    Scaleform::GFx::AS2::Value::GetPropertyValue(presult, this, v13, presult);
    if ( LOBYTE(resolveHandler.Function) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&resolveHandler);
    return VariableRaw;
  }
  if ( presult->T.Type != 12 )
    return VariableRaw;
  v17 = this->StringContext.pContext;
  thisVal.T.Type = 0;
  if ( Scaleform::GFx::AS2::Environment::GetVariable(
         this,
         (const Scaleform::GFx::ASString *)&v17->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl,
         &thisVal,
         pwithStack,
         0,
         0,
         0) )
  {
    v18 = Scaleform::GFx::AS2::Value::ToObject(&thisVal, this);
    if ( v18 )
    {
      v19 = &v18->Scaleform::GFx::AS2::ObjectInterface;
      if ( v18 != (Scaleform::GFx::AS2::Object *)-16 )
        goto LABEL_25;
    }
    v20 = Scaleform::GFx::AS2::Value::ToAvmCharacter(&thisVal, this);
  }
  else
  {
    v21 = this->Target;
    if ( !v21 )
    {
LABEL_24:
      v19 = 0;
      goto LABEL_25;
    }
    v22 = &v21->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + v21->AvmObjOffset;
    v20 = (Scaleform::GFx::AS2::AvmCharacter *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject_vtbl **))(*v22)->CreateRenderNode)(v22);
  }
  if ( !v20 )
    goto LABEL_24;
  v19 = &v20->Scaleform::GFx::AS2::ObjectInterface;
LABEL_25:
  Scaleform::GFx::AS2::Value::ToResolveHandler(presult, &resolveHandler);
  ++this->Stack.pCurrent;
  p_Stack = &this->Stack;
  if ( this->Stack.pCurrent >= this->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&this->Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    pCurrent->T.Type = 5;
    pNode = varname->pNode;
    pCurrent->NV.Int32Value = (int)varname->pNode;
    ++pNode->RefCount;
  }
  Scaleform::GFx::AS2::Value::DropRefs(presult);
  presult->T.Type = 0;
  v26 = this->Stack.pCurrent - this->Stack.pPageStart;
  v27 = 32 * this->Stack.Pages.Data.Size;
  v38.ThisPtr = v19;
  v38.Result = presult;
  pLocalFrame = resolveHandler.pLocalFrame;
  v38.Env = this;
  Function = resolveHandler.Function;
  v38.FirstArgBottomIndex = v26 + v27 - 32;
  v38.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  memset(&v38.ThisFunctionRef, 0, 9);
  v38.NArgs = 1;
  resolveHandler.Function->Invoke(resolveHandler.Function, &v38, resolveHandler.pLocalFrame, 0);
  Scaleform::GFx::AS2::FnCall::~FnCall(&v38);
  if ( p_Stack->pCurrent->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
  if ( --p_Stack->pCurrent < p_Stack->pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
  if ( (resolveHandler.Flags & 2) == 0 )
  {
    RefCount = Function->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      Function->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
  }
  if ( (resolveHandler.Flags & 1) == 0 )
  {
    if ( pLocalFrame )
    {
      v31 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v31) != 0 )
      {
        pLocalFrame->RefCount = v31 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  if ( thisVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&thisVal);
  return retVal;
}
