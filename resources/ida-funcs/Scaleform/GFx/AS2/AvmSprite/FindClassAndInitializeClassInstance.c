void __cdecl Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned int FirstArgBottomIndex; // edx
  int v3; // esi
  int v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // ecx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // esi
  Scaleform::GFx::AS2::AvmCharacter *p_pProto; // esi
  Scaleform::GFx::AS2::ObjectInterface *v8; // eax
  Scaleform::GFx::InteractiveObject *pDispObj; // edi
  Scaleform::GFx::InteractiveObject *v10; // eax
  Scaleform::GFx::InteractiveObject *v11; // edi
  Scaleform::GFx::InteractiveObject *v12; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v13; // ecx
  Scaleform::GFx::InteractiveObject *v14; // edi
  Scaleform::GFx::InteractiveObject *v15; // edx
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // esi
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  unsigned int v20; // eax
  Scaleform::GFx::AS2::FunctionRefBase orig; // [esp+10h] [ebp-9Ch] BYREF
  Scaleform::GFx::ASStringNode *v22; // [esp+1Ch] [ebp-90h] BYREF
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v23; // [esp+20h] [ebp-8Ch] BYREF
  Scaleform::GFx::AS2::GlobalContext *pContext; // [esp+64h] [ebp-48h]
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v25; // [esp+68h] [ebp-44h] BYREF

  Env = fn->Env;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  v3 = Env->Stack.pCurrent - Env->Stack.pPageStart;
  v4 = 32 * (Env->Stack.Pages.Data.Size - 1);
  pContext = Env->StringContext.pContext;
  v5 = 0;
  memset(&orig, 0, 9);
  if ( FirstArgBottomIndex <= v4 + v3 )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v22, Env, -1, 0);
  if ( v22->Size )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr->GetObjectType(ThisPtr) == Object_Sprite )
      p_pProto = (Scaleform::GFx::AS2::AvmCharacter *)&ThisPtr[-1].pProto;
    else
      p_pProto = 0;
    if ( Scaleform::GFx::AS2::GlobalContext::FindRegisteredClass(
           pContext,
           &fn->Env->StringContext,
           (const Scaleform::GFx::ASString *)&v22,
           (Scaleform::GFx::AS2::FunctionRef *)&orig) )
    {
      if ( orig.Function )
        v8 = &orig.Function->Scaleform::GFx::AS2::ObjectInterface;
      else
        v8 = 0;
      Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(p_pProto, v8);
      pDispObj = p_pProto->pDispObj;
      memset(&v23.pCharacter, 0, 21);
      v23.mEventId.RollOverCnt = 0;
      memset(&v23.mEventId.KeysState, 0, 11);
      v23.mEventId.ControllerIndex = -1;
      memset(&v23.FunctionParams, 0, sizeof(v23.FunctionParams));
      v23.pNextEntry = 0;
      v23.Type = Entry_Event;
      if ( pDispObj )
      {
        ++pDispObj->RefCount;
        if ( v23.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release(v23.pCharacter.pObject);
      }
      v23.pCharacter.pObject = pDispObj;
      if ( v23.pActionBuffer.pObject )
        Scaleform::RefCountNTSImpl::Release(v23.pActionBuffer.pObject);
      v10 = p_pProto->pDispObj;
      v23.pActionBuffer.pObject = 0;
      v23.mEventId.Id = 0x40000;
      memset(&v23.mEventId.WcharCode, 0, 9);
      v23.mEventId.RollOverCnt = 0;
      v23.mEventId.ControllerIndex = -1;
      v23.mEventId.KeysState.States = 0;
      v23.mEventId.MouseWheelDelta = 0;
      v23.SessionId = 0;
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(&v23, (Scaleform::GFx::AS2::MovieRoot *)v10->pASRoot);
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v23);
      v11 = p_pProto->pDispObj;
      memset(&v25.pCharacter, 0, 21);
      v25.mEventId.RollOverCnt = 0;
      memset(&v25.mEventId.KeysState, 0, 11);
      v25.mEventId.ControllerIndex = -1;
      memset(&v25.FunctionParams, 0, sizeof(v25.FunctionParams));
      v25.pNextEntry = 0;
      v25.Type = Entry_Function;
      if ( v11 )
      {
        ++v11->RefCount;
        if ( v25.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release(v25.pCharacter.pObject);
      }
      v25.pCharacter.pObject = v11;
      if ( v25.pActionBuffer.pObject )
        Scaleform::RefCountNTSImpl::Release(v25.pActionBuffer.pObject);
      v25.pActionBuffer.pObject = 0;
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&v25.Function, &orig);
      v12 = p_pProto->pDispObj;
      v25.SessionId = 0;
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(&v25, (Scaleform::GFx::AS2::MovieRoot *)v12->pASRoot);
      v13 = &v25;
    }
    else
    {
      v14 = p_pProto->pDispObj;
      memset(&v23.pCharacter, 0, 21);
      v23.mEventId.RollOverCnt = 0;
      memset(&v23.mEventId.KeysState, 0, 11);
      v23.mEventId.ControllerIndex = -1;
      memset(&v23.FunctionParams, 0, sizeof(v23.FunctionParams));
      v23.pNextEntry = 0;
      v23.Type = Entry_Event;
      if ( v14 )
      {
        ++v14->RefCount;
        if ( v23.pCharacter.pObject )
          Scaleform::RefCountNTSImpl::Release(v23.pCharacter.pObject);
      }
      v23.pCharacter.pObject = v14;
      if ( v23.pActionBuffer.pObject )
        Scaleform::RefCountNTSImpl::Release(v23.pActionBuffer.pObject);
      v15 = p_pProto->pDispObj;
      v23.pActionBuffer.pObject = 0;
      v23.mEventId.Id = 0x40000;
      memset(&v23.mEventId.WcharCode, 0, 9);
      v23.mEventId.RollOverCnt = 0;
      v23.mEventId.ControllerIndex = -1;
      v23.mEventId.KeysState.States = 0;
      v23.mEventId.MouseWheelDelta = 0;
      v23.SessionId = 0;
      Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(&v23, (Scaleform::GFx::AS2::MovieRoot *)v15->pASRoot);
      v13 = &v23;
    }
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(v13);
  }
  v16 = v22;
  --v22->RefCount;
  pLocalFrame = orig.pLocalFrame;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( (orig.Flags & 2) == 0 )
  {
    Function = orig.Function;
    if ( orig.Function )
    {
      RefCount = orig.Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        orig.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (orig.Flags & 1) == 0 && pLocalFrame )
  {
    v20 = pLocalFrame->RefCount;
    if ( (v20 & 0x3FFFFFF) != 0 )
    {
      pLocalFrame->RefCount = v20 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
  }
}
