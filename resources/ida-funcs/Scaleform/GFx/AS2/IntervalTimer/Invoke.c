char __thiscall Scaleform::GFx::AS2::IntervalTimer::Invoke(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  Scaleform::GFx::AS2::IntervalTimer *v3; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  unsigned int TimeElapsed_high; // eax
  char v9; // bl
  Scaleform::GFx::CharacterHandle *v10; // ecx
  Scaleform::GFx::InteractiveObject *v11; // eax
  Scaleform::RefCountNTSImpl *v12; // esi
  char v13; // dl
  int v14; // eax
  Scaleform::GFx::AS2::Object *v15; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ObjectInterface *v18; // esi
  Scaleform::GFx::Sprite *v19; // esi
  int v20; // eax
  int v21; // eax
  Scaleform::GFx::Sprite *v22; // eax
  int v23; // eax
  int v24; // eax
  Scaleform::GFx::AS2::FunctionRef *v25; // eax
  unsigned int v26; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v28; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  int v30; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  int v32; // eax
  int Size; // ebp
  int v34; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v36; // ebp
  Scaleform::GFx::AS2::Value *Data; // edi
  const Scaleform::GFx::AS2::Value *v38; // edi
  int v39; // eax
  int v40; // ebp
  int v41; // esi
  __int64 v42; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v43; // ecx
  unsigned int v44; // eax
  Scaleform::GFx::AS2::FunctionObject *v45; // ecx
  unsigned int v46; // eax
  Scaleform::GFx::AS2::LocalFrame *v47; // ecx
  unsigned int v48; // eax
  Scaleform::AmpStats *v49; // edi
  void (__thiscall **v50)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v51; // rax
  Scaleform::GFx::AS2::Environment *penv; // [esp+Ch] [ebp-7Ch]
  Scaleform::GFx::AS2::ObjectInterface *v53; // [esp+10h] [ebp-78h]
  Scaleform::GFx::AS2::MovieRoot *pObject; // [esp+14h] [ebp-74h]
  Scaleform::GFx::AS2::MovieRoot *v55; // [esp+14h] [ebp-74h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+1Ch] [ebp-6Ch] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v58; // [esp+20h] [ebp-68h]
  unsigned __int64 v59; // [esp+24h] [ebp-64h]
  Scaleform::GFx::AS2::FunctionRefBase v60; // [esp+2Ch] [ebp-5Ch] BYREF
  Scaleform::GFx::AS2::FunctionRef v61; // [esp+38h] [ebp-50h] BYREF
  Scaleform::AmpFunctionTimer v62; // [esp+44h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v63; // [esp+54h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v64; // [esp+64h] [ebp-24h] BYREF

  v3 = this;
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v62,
    proot->AdvanceStats.pObject,
    "IntervalTimer::Invoke",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  if ( !v3->Active )
  {
    Stats = v62.Stats;
    if ( v62.Stats )
    {
      p_NativePopCallstack = &v62.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v62.StartTicks),
        (ProfileTicks - v62.StartTicks) >> 32);
    }
    return 0;
  }
  pObject = (Scaleform::GFx::AS2::MovieRoot *)proot->pASMovieRoot.pObject;
  TimeElapsed_high = HIDWORD(proot->TimeElapsed);
  v9 = 0;
  LODWORD(v59) = proot->TimeElapsed;
  HIDWORD(v59) = TimeElapsed_high;
  if ( __PAIR64__(TimeElapsed_high, v59) >= v3->InvokeTime )
  {
    memset(&v60, 0, 9);
    v53 = 0;
    v58 = 0;
    result.pObject = 0;
    penv = 0;
    if ( v3->Function.Function )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&v60, &v3->Function);
LABEL_8:
      if ( v60.Function )
      {
        v63.T.Type = 0;
        if ( !penv )
        {
          v10 = v3->LevelHandle.pObject;
          if ( !v10 )
            goto LABEL_47;
          v11 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v10, proot);
          v12 = v11;
          if ( !v11 )
            goto LABEL_47;
          ++v11->RefCount;
          v13 = LOBYTE(v11->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >> 7;
          v14 = v13 != 0 ? (unsigned int)v11 : 0;
          if ( (v13 != 0 ? (unsigned int)v12 : 0) != 0 )
          {
            v30 = *(v13 != 0 ? (unsigned __int8 *)&v12[8].__vftable + 1 : (unsigned __int8 *)65);
            v14 = (*(int (__thiscall **)(int))(*(_DWORD *)(v14 + 4 * v30) + 4))(v14 + 4 * v30);
          }
          penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 124))(v14);
          Scaleform::RefCountNTSImpl::Release(v12);
          if ( !penv )
          {
LABEL_47:
            LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
            if ( LevelMovie )
              v32 = (*(int (__thiscall **)(int))(*((_DWORD *)&LevelMovie->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + LevelMovie->AvmObjOffset)
                                               + 4))((int)LevelMovie + 4 * LevelMovie->AvmObjOffset);
            else
              v32 = 0;
            penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v32 + 124))(v32);
          }
        }
        Size = v3->Params.Data.Size;
        v55 = (Scaleform::GFx::AS2::MovieRoot *)Size;
        if ( Size > 0 )
        {
          v34 = Size - 1;
          if ( Size - 1 >= 0 )
          {
            p_Stack = &penv->Stack;
            v36 = v34;
            do
            {
              Data = v3->Params.Data.Data;
              ++p_Stack->pCurrent;
              v38 = &Data[v36];
              if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
              if ( p_Stack->pCurrent )
                Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, v38);
              v3 = this;
              --v34;
              --v36;
            }
            while ( v34 >= 0 );
            Size = (int)v55;
          }
        }
        v39 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
        v64.Result = &v63;
        v64.FirstArgBottomIndex = v39;
        v64.Env = penv;
        v64.ThisPtr = v53;
        v64.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
        memset(&v64.ThisFunctionRef, 0, 9);
        v64.NArgs = Size;
        v60.Function->Invoke(v60.Function, &v64, v60.pLocalFrame, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v64);
        if ( Size > 0 )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&penv->Stack, Size);
        if ( v63.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v63);
      }
      goto LABEL_64;
    }
    v15 = v3->pObject.pObject;
    if ( v15 )
      v15->RefCount = (v15->RefCount + 1) & 0x8FFFFFFF;
    v16 = v3->pObject.pObject;
    if ( v16 )
      v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
    v58 = v16;
    if ( v16 )
    {
      RefCount = v16->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v16->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
      }
      v18 = (Scaleform::GFx::AS2::ObjectInterface *)&v16[1];
      v53 = v18;
    }
    else
    {
      Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v3->Character,
        &result);
      v19 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        ++v19->RefCount;
      }
      result.pObject = v19;
      if ( !v19 )
        goto LABEL_44;
      Scaleform::RefCountNTSImpl::Release(v19);
      Scaleform::RefCountNTSImpl::Release(v19);
      v20 = (*(int (__thiscall **)(int))(*((_DWORD *)&v19->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v19->AvmObjOffset)
                                       + 4))((int)v19 + 4 * v19->AvmObjOffset);
      if ( v20 )
        v53 = (Scaleform::GFx::AS2::ObjectInterface *)(v20 + 4);
      else
        v53 = 0;
      v21 = (*(int (__thiscall **)(int))(*((_DWORD *)&v19->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + v19->AvmObjOffset)
                                       + 4))((int)v19 + 4 * v19->AvmObjOffset);
      v18 = v53;
      penv = (Scaleform::GFx::AS2::Environment *)(*(int (__thiscall **)(int))(*(_DWORD *)v21 + 124))(v21);
    }
    if ( v18 )
    {
      v63.T.Type = 0;
      v22 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
      if ( v22 )
        v23 = (*(int (__thiscall **)(int))(*((_DWORD *)&v22->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + v22->AvmObjOffset)
                                         + 4))((int)v22 + 4 * v22->AvmObjOffset);
      else
        v23 = 0;
      v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 124))(v23);
      if ( v18->GetMemberRaw(v18, (Scaleform::GFx::AS2::ASStringContext *)(v24 + 116), &v3->MethodName, &v63) )
      {
        v25 = Scaleform::GFx::AS2::Value::ToFunction(&v63, &v61, penv);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v60, v25);
        if ( (v61.Flags & 2) == 0 )
        {
          if ( v61.Function )
          {
            v26 = v61.Function->RefCount;
            Function = v61.Function;
            if ( (v26 & 0x3FFFFFF) != 0 )
            {
              v61.Function->RefCount = v26 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            }
          }
        }
        v61.Function = 0;
        if ( (v61.Flags & 1) == 0 )
        {
          if ( v61.pLocalFrame )
          {
            v28 = v61.pLocalFrame->RefCount;
            pLocalFrame = v61.pLocalFrame;
            if ( (v28 & 0x3FFFFFF) != 0 )
            {
              v61.pLocalFrame->RefCount = v28 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
      }
      if ( v63.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v63);
      goto LABEL_8;
    }
LABEL_44:
    v3->Active = 0;
LABEL_64:
    if ( v3->Timeout )
    {
      v3->Active = 0;
    }
    else
    {
      v40 = HIDWORD(v59);
      v41 = v59;
      LODWORD(v42) = Scaleform::GFx::AS2::IntervalTimer::GetNextInterval(
                       v3,
                       v59,
                       (unsigned __int64)(frameTime * 1000000.0));
      if ( v42 )
      {
        v3->InvokeTime += v42;
      }
      else
      {
        LODWORD(v3->InvokeTime) = v41;
        HIDWORD(v3->InvokeTime) = v40;
      }
    }
    v9 = 1;
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    v43 = v58;
    if ( v58 )
    {
      v44 = v58->RefCount;
      if ( (v44 & 0x3FFFFFF) != 0 )
      {
        v58->RefCount = v44 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v43);
      }
    }
    if ( (v60.Flags & 2) == 0 )
    {
      v45 = v60.Function;
      if ( v60.Function )
      {
        v46 = v60.Function->RefCount;
        if ( (v46 & 0x3FFFFFF) != 0 )
        {
          v60.Function->RefCount = v46 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v45);
        }
      }
    }
    if ( (v60.Flags & 1) == 0 )
    {
      v47 = v60.pLocalFrame;
      if ( v60.pLocalFrame )
      {
        v48 = v60.pLocalFrame->RefCount;
        if ( (v48 & 0x3FFFFFF) != 0 )
        {
          v60.pLocalFrame->RefCount = v48 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v47);
        }
      }
    }
  }
  v49 = v62.Stats;
  if ( v62.Stats )
  {
    v50 = &v62.Stats->NativePopCallstack;
    v51 = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v50)(
      v49,
      v51 - LODWORD(v62.StartTicks),
      (v51 - v62.StartTicks) >> 32);
  }
  return v9;
}
