char __thiscall Scaleform::GFx::AS2::IntervalTimer::Invoke(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  Scaleform::GFx::AS2::IntervalTimer *v3; // edi
  Scaleform::GFx::MovieImpl *v5; // esi
  unsigned int TimeElapsed_high; // eax
  char v7; // bl
  const Scaleform::GFx::AS2::Environment *v8; // ebp
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ObjectInterface *v12; // esi
  Scaleform::GFx::InteractiveObject *v13; // esi
  int v14; // eax
  int v15; // eax
  Scaleform::GFx::Sprite *v16; // eax
  int v17; // eax
  int v18; // eax
  Scaleform::GFx::AS2::FunctionRef *v19; // eax
  unsigned int v20; // edx
  Scaleform::GFx::AS2::FunctionObject *v21; // ecx
  unsigned int v22; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // ecx
  Scaleform::GFx::InteractiveObject *v25; // eax
  Scaleform::RefCountNTSImpl *v26; // esi
  char v27; // cl
  unsigned __int8 *v28; // eax
  unsigned __int8 *v29; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v31; // eax
  int Size; // ebp
  int v33; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v35; // ebp
  Scaleform::GFx::AS2::Value *Data; // edi
  const Scaleform::GFx::AS2::Value *v37; // edi
  int v38; // eax
  int v39; // ebp
  int v40; // esi
  __int64 v41; // rax
  Scaleform::GFx::AS2::Object *v42; // ecx
  unsigned int v43; // eax
  Scaleform::GFx::AS2::FunctionObject *v44; // ecx
  unsigned int v45; // eax
  Scaleform::GFx::AS2::LocalFrame *v46; // ecx
  unsigned int v47; // eax
  Scaleform::GFx::AS2::Environment *penv; // [esp+Ch] [ebp-6Ch]
  Scaleform::GFx::AS2::ObjectInterface *thisPtr; // [esp+10h] [ebp-68h]
  Scaleform::GFx::AS2::MovieRoot *asroot; // [esp+14h] [ebp-64h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> targetHolder; // [esp+1Ch] [ebp-5Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> thisHolder; // [esp+20h] [ebp-58h]
  unsigned __int64 currentTime; // [esp+24h] [ebp-54h]
  Scaleform::GFx::AS2::FunctionRef function; // [esp+2Ch] [ebp-4Ch] BYREF
  Scaleform::GFx::AS2::FunctionRef v56; // [esp+38h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+44h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v58; // [esp+54h] [ebp-24h] BYREF
  int nArgs; // [esp+7Ch] [ebp+4h]

  v3 = this;
  if ( !this->Active )
    return 0;
  v5 = proot;
  asroot = (Scaleform::GFx::AS2::MovieRoot *)proot->pASMovieRoot.pObject;
  TimeElapsed_high = HIDWORD(proot->TimeElapsed);
  v7 = 0;
  LODWORD(currentTime) = proot->TimeElapsed;
  HIDWORD(currentTime) = TimeElapsed_high;
  if ( __PAIR64__(TimeElapsed_high, currentTime) >= this->InvokeTime )
  {
    v8 = 0;
    memset(&function, 0, 9);
    thisPtr = 0;
    thisHolder.pObject = 0;
    targetHolder.pObject = 0;
    penv = 0;
    if ( this->Function.Function )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&function, &this->Function);
LABEL_37:
      if ( function.Function )
      {
        result.T.Type = 0;
        if ( !v8 )
        {
          pObject = v3->LevelHandle.pObject;
          if ( !pObject )
            goto LABEL_46;
          v25 = Scaleform::GFx::CharacterHandle::ResolveCharacter(pObject, v5);
          v26 = v25;
          if ( !v25 )
            goto LABEL_46;
          ++v25->RefCount;
          v27 = LOBYTE(v25->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7;
          v28 = v27 != 0 ? (unsigned __int8 *)v25 : 0;
          if ( (v27 != 0 ? (unsigned int)v26 : 0) != 0 )
          {
            v29 = &v28[4 * v28[65]];
            v28 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v29 + 4))(v29);
          }
          penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v28 + 124))(v28);
          Scaleform::RefCountNTSImpl::Release(v26);
          if ( !penv )
          {
LABEL_46:
            LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(asroot, 0);
            if ( LevelMovie )
              v31 = (*(int (__thiscall **)(int))(*((_DWORD *)&LevelMovie->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + LevelMovie->AvmObjOffset)
                                               + 4))((int)LevelMovie + 4 * LevelMovie->AvmObjOffset);
            else
              v31 = 0;
            penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v31 + 124))(v31);
          }
        }
        Size = v3->Params.Data.Size;
        nArgs = Size;
        if ( Size > 0 )
        {
          v33 = Size - 1;
          if ( Size - 1 >= 0 )
          {
            p_Stack = &penv->Stack;
            v35 = v33;
            do
            {
              Data = v3->Params.Data.Data;
              ++p_Stack->pCurrent;
              v37 = &Data[v35];
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              if ( p_Stack->pCurrent )
                Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v37);
              v3 = this;
              --v33;
              --v35;
            }
            while ( v33 >= 0 );
            Size = nArgs;
          }
        }
        v38 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
        v58.Result = &result;
        v58.ThisPtr = thisPtr;
        v58.Env = penv;
        v58.FirstArgBottomIndex = v38;
        v58.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
        memset(&v58.ThisFunctionRef, 0, 9);
        v58.NArgs = Size;
        function.Function->Invoke(function.Function, &v58, function.pLocalFrame, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v58);
        if ( Size > 0 )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&penv->Stack, Size);
        if ( result.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&result);
      }
      goto LABEL_63;
    }
    v9 = this->pObject.pObject;
    if ( v9 )
      v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
    v10 = this->pObject.pObject;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    thisHolder.pObject = v10;
    if ( v10 )
    {
      RefCount = v10->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
      v12 = &v10->Scaleform::GFx::AS2::ObjectInterface;
      thisPtr = v12;
    }
    else
    {
      Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->Character,
        &targetHolder);
      v13 = targetHolder.pObject;
      if ( targetHolder.pObject )
      {
        ++targetHolder.pObject->RefCount;
        ++v13->RefCount;
      }
      targetHolder.pObject = v13;
      if ( !v13 )
        goto LABEL_43;
      Scaleform::RefCountNTSImpl::Release(v13);
      Scaleform::RefCountNTSImpl::Release(v13);
      v14 = (*(int (__thiscall **)(int))(*((_DWORD *)&v13->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v13->AvmObjOffset)
                                       + 4))((int)v13 + 4 * v13->AvmObjOffset);
      if ( v14 )
        thisPtr = (Scaleform::GFx::AS2::ObjectInterface *)(v14 + 4);
      else
        thisPtr = 0;
      v15 = (*(int (__thiscall **)(int))(*((_DWORD *)&v13->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v13->AvmObjOffset)
                                       + 4))((int)v13 + 4 * v13->AvmObjOffset);
      v12 = thisPtr;
      penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 124))(v15);
      v8 = penv;
    }
    if ( v12 )
    {
      result.T.Type = 0;
      v16 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(asroot, 0);
      if ( v16 )
        v17 = (*(int (__thiscall **)(int))(*((_DWORD *)&v16->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v16->AvmObjOffset)
                                         + 4))((int)v16 + 4 * v16->AvmObjOffset);
      else
        v17 = 0;
      v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v17 + 124))(v17);
      if ( v12->GetMemberRaw(v12, (Scaleform::GFx::AS2::ASStringContext *)(v18 + 116), &v3->MethodName, &result) )
      {
        v19 = Scaleform::GFx::AS2::Value::ToFunction(&result, &v56, v8);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&function, v19);
        if ( (v56.Flags & 2) == 0 )
        {
          if ( v56.Function )
          {
            v20 = v56.Function->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v20) != 0 )
            {
              v21 = v56.Function;
              v56.Function->RefCount = v20 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
            }
          }
        }
        v56.Function = 0;
        if ( (v56.Flags & 1) == 0 )
        {
          if ( v56.pLocalFrame )
          {
            v22 = v56.pLocalFrame->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
            {
              pLocalFrame = v56.pLocalFrame;
              v56.pLocalFrame->RefCount = v22 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
      }
      if ( result.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&result);
      v5 = proot;
      goto LABEL_37;
    }
LABEL_43:
    v3->Active = 0;
LABEL_63:
    if ( v3->Timeout )
    {
      v3->Active = 0;
    }
    else
    {
      v39 = HIDWORD(currentTime);
      v40 = currentTime;
      LODWORD(v41) = Scaleform::GFx::AS2::IntervalTimer::GetNextInterval(
                       v3,
                       currentTime,
                       (unsigned __int64)(frameTime * 1000000.0));
      if ( v41 )
      {
        v3->InvokeTime += v41;
      }
      else
      {
        LODWORD(v3->InvokeTime) = v40;
        HIDWORD(v3->InvokeTime) = v39;
      }
    }
    v7 = 1;
    if ( targetHolder.pObject )
      Scaleform::RefCountNTSImpl::Release(targetHolder.pObject);
    v42 = thisHolder.pObject;
    if ( thisHolder.pObject )
    {
      v43 = thisHolder.pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v43) != 0 )
      {
        thisHolder.pObject->RefCount = v43 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v42);
      }
    }
    if ( (function.Flags & 2) == 0 )
    {
      v44 = function.Function;
      if ( function.Function )
      {
        v45 = function.Function->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v45) != 0 )
        {
          function.Function->RefCount = v45 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v44);
        }
      }
    }
    if ( (function.Flags & 1) == 0 )
    {
      v46 = function.pLocalFrame;
      if ( function.pLocalFrame )
      {
        v47 = function.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v47) != 0 )
        {
          function.pLocalFrame->RefCount = v47 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
        }
      }
    }
  }
  return v7;
}
