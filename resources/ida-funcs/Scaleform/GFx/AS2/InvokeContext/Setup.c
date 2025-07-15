void __thiscall Scaleform::GFx::AS2::InvokeContext::Setup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::Environment *pOurEnv; // ebx
  Scaleform::GFx::AS2::AsFunctionObject *pThis; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *v4; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *p_CallStack; // ebx
  _DWORD *p_pObject; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v8; // ecx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebp
  int Size; // eax
  Scaleform::GFx::AS2::AsFunctionObject *v11; // edx
  unsigned __int8 ExecType; // al
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2,Scaleform::ArrayDefaultPolicy> *p_LocalFrames; // edi
  unsigned int v14; // ecx
  Scaleform::GFx::AS2::LocalFrame *NewLocalFrame; // eax
  Scaleform::GFx::AS2::LocalFrame *v16; // edi
  Scaleform::GFx::AS2::LocalFrame *pObject; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> **v20; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // ecx
  unsigned int v22; // eax
  Scaleform::GFx::AS2::ObjectInterface *v23; // ebx
  Scaleform::GFx::InteractiveObject *v24; // edi
  Scaleform::GFx::InteractiveObject *v25; // ecx
  Scaleform::GFx::AS2::Object *p_pProto; // edi
  Scaleform::GFx::AS2::Object *v27; // ecx
  unsigned int v28; // eax
  Scaleform::GFx::AS2::Environment *v29; // ecx
  int SWFVersion; // edi
  Scaleform::GFx::AS2::LocalFrame *v31; // eax
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::InteractiveObject *v33; // edi
  Scaleform::GFx::InteractiveObject *v34; // ecx
  Scaleform::GFx::AS2::Environment *v35; // ecx
  unsigned int v36; // eax
  Scaleform::GFx::AS2::Environment *v37; // ecx
  int v38; // eax
  Scaleform::GFx::AS2::Object **v39; // edx
  Scaleform::GFx::ASStringNode *v40; // eax
  int v41; // ebp
  const Scaleform::GFx::AS2::FnCall *v42; // ecx
  int v43; // eax
  _DWORD *v44; // ecx
  int v45; // edx
  int v46; // edi
  _DWORD *v47; // ecx
  unsigned int v48; // eax
  const Scaleform::GFx::AS2::Value *v49; // ebx
  Scaleform::GFx::AS2::Environment *v50; // eax
  unsigned int v51; // edx
  int v52; // edx
  int v53; // edi
  int v54; // eax
  Scaleform::GFx::AS2::AsFunctionObject *v55; // eax
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v56; // ecx
  Scaleform::GFx::AS2::Environment *v57; // eax
  int v58; // edx
  int v59; // edi
  int v60; // eax
  Scaleform::GFx::ASStringNode *NArgs; // eax
  int v62; // edi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // eax
  const Scaleform::GFx::AS2::Value *Register; // edx
  const Scaleform::GFx::AS2::FnCall *mFnCall; // ecx
  int FirstArgBottomIndex; // eax
  _DWORD *v67; // ecx
  int v68; // ebx
  int v69; // ebp
  _DWORD *v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // ebx
  Scaleform::GFx::AS2::Object *v73; // ebx
  Scaleform::GFx::AS2::Environment *v74; // ebp
  unsigned int v75; // eax
  Scaleform::GFx::AS2::Value *GlobalRegister; // eax
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v77; // ecx
  Scaleform::GFx::AS2::Environment *v78; // eax
  int v79; // edx
  int v80; // ebp
  int v81; // eax
  unsigned __int16 Function2Flags; // ax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // ebp
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *Owner; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v85; // edi
  Scaleform::GFx::ASStringNode *v86; // eax
  unsigned int SizeMask; // eax
  unsigned int v88; // eax
  Scaleform::GFx::AS2::SuperObject *v89; // eax
  Scaleform::GFx::AS2::ObjectInterface *v90; // ebx
  Scaleform::GFx::AS2::Object *v91; // eax
  unsigned int v92; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v94; // edx
  Scaleform::GFx::AS2::LocalFrame *v95; // ecx
  unsigned int v96; // eax
  bool v97; // zf
  Scaleform::GFx::AS2::Environment *v98; // edi
  unsigned int v99; // eax
  Scaleform::GFx::AS2::Environment *v100; // ebp
  unsigned int v101; // eax
  Scaleform::GFx::AS2::Value *v102; // edi
  Scaleform::GFx::AS2::Environment *v103; // eax
  const Scaleform::GFx::ASString *v104; // ebp
  int v105; // edx
  int v106; // edi
  int v107; // eax
  unsigned __int16 v108; // ax
  Scaleform::GFx::AS2::Object *v109; // eax
  Scaleform::GFx::AS2::Object *v110; // edi
  Scaleform::GFx::AS2::Environment *v111; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int j; // ebp
  const Scaleform::GFx::AS2::FnCall *v114; // ecx
  int v115; // eax
  _DWORD *v116; // ecx
  int v117; // edx
  int v118; // ebx
  _DWORD *v119; // ecx
  unsigned int v120; // eax
  const Scaleform::GFx::AS2::Value *pHash; // ebx
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // edx
  Scaleform::GFx::AS2::RefCountCollector<323>_vtbl *v123; // eax
  Scaleform::GFx::ASStringNode *v124; // ebp
  Scaleform::GFx::AS2::Environment *v125; // edi
  unsigned int v126; // eax
  Scaleform::GFx::AS2::Value *v127; // eax
  Scaleform::GFx::ASMovieRootBase *v128; // ebx
  Scaleform::GFx::AS2::Environment *v129; // ecx
  unsigned int v130; // edx
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v131; // eax
  int v132; // edi
  int v133; // edi
  int v134; // eax
  Scaleform::GFx::AS2::Environment *v135; // ecx
  unsigned int v136; // eax
  char *p_pUserDataHolder; // edi
  Scaleform::GFx::AS2::Environment *v138; // ecx
  int v139; // eax
  Scaleform::GFx::AS2::Object **v140; // edx
  Scaleform::GFx::AS2::Environment *v141; // edi
  unsigned int v142; // eax
  Scaleform::GFx::AS2::Value *v143; // eax
  Scaleform::GFx::AS2::Environment *v144; // eax
  int v145; // edx
  const Scaleform::GFx::ASString *p_pASSupport; // edi
  int v147; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v148; // ebx
  Scaleform::GFx::ASString *v149; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Environment *v151; // edi
  unsigned int v152; // eax
  Scaleform::GFx::InteractiveObject *Target; // ebx
  Scaleform::GFx::AS2::Value *v154; // edi
  Scaleform::GFx::DisplayObject *v155; // eax
  Scaleform::GFx::CharacterHandle *CharacterHandle; // ebx
  Scaleform::GFx::AS2::Environment *v157; // ecx
  Scaleform::GFx::AS2::Environment *v158; // edi
  unsigned int v159; // eax
  Scaleform::GFx::AS2::Value *v160; // eax
  Scaleform::GFx::AS2::Environment *v161; // esi
  unsigned int v162; // eax
  Scaleform::GFx::AS2::Object *v163; // edi
  Scaleform::GFx::AS2::Value *v164; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v165; // ecx
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v166; // eax
  Scaleform::GFx::AS2::Object *v167; // ecx
  unsigned int v168; // eax
  __int64 v169; // [esp+Ch] [ebp-60h]
  int v170; // [esp+20h] [ebp-4Ch]
  unsigned int HashFlags; // [esp+20h] [ebp-4Ch]
  int v172; // [esp+34h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ObjectInterface *_this; // [esp+38h] [ebp-34h]
  Scaleform::GFx::AS2::Object *obj; // [esp+3Ch] [ebp-30h]
  Scaleform::GFx::ASStringNode *i; // [esp+40h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString *key; // [esp+44h] [ebp-28h]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator value; // [esp+48h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::FunctionRef ctor; // [esp+50h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+5Ch] [ebp-10h] BYREF

  pOurEnv = this->pOurEnv;
  pThis = this->pThis;
  if ( this->pThis )
    pThis->RefCount = (pThis->RefCount + 1) & 0x8FFFFFFF;
  v4 = ++pOurEnv->CallStack.pCurrent;
  p_CallStack = &pOurEnv->CallStack;
  if ( v4 >= p_CallStack->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PushPage(p_CallStack);
  p_pObject = &p_CallStack->pCurrent->pObject;
  if ( p_pObject )
  {
    if ( pThis )
      pThis->RefCount = (pThis->RefCount + 1) & 0x8FFFFFFF;
    *p_pObject = pThis;
  }
  if ( pThis )
  {
    RefCount = pThis->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pThis->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pThis);
    }
  }
  v8 = this->pOurEnv;
  ThisPtr = this->mFnCall->ThisPtr;
  Size = v8->LocalFrames.Data.Size;
  key = (Scaleform::GFx::ASString *)v8->StringContext.pContext->pHeap;
  v11 = this->pThis;
  this->LocalStackTop = Size;
  ExecType = v11->ExecType;
  _this = ThisPtr;
  if ( ExecType == 2 || ExecType == 1 )
  {
    NewLocalFrame = Scaleform::GFx::AS2::Environment::CreateNewLocalFrame(v8);
    v16 = NewLocalFrame;
    if ( NewLocalFrame )
      NewLocalFrame->RefCount = (NewLocalFrame->RefCount + 1) & 0x8FFFFFFF;
    pObject = this->CurLocalFrame.pObject;
    if ( pObject )
    {
      v18 = pObject->RefCount;
      if ( (v18 & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    this->CurLocalFrame.pObject = v16;
    pLocalFrame = this->pLocalFrame;
    v20 = &v16->PrevFrame.pObject;
    if ( pLocalFrame )
      pLocalFrame->RefCount = (pLocalFrame->RefCount + 1) & 0x8FFFFFFF;
    v21 = *v20;
    if ( *v20 )
    {
      v22 = v21->RefCount;
      if ( (v22 & 0x3FFFFFF) != 0 )
      {
        v21->RefCount = v22 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
      }
    }
    *v20 = pLocalFrame;
  }
  else
  {
    p_LocalFrames = &v8->LocalFrames;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v8->LocalFrames,
      &v8->LocalFrames,
      v8->LocalFrames.Data.Size + 1);
    v14 = p_LocalFrames->Data.Size;
    if ( &p_LocalFrames->Data.Data[v14] != (Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *)4 )
      p_LocalFrames->Data.Data[v14 - 1].pObject = 0;
  }
  v23 = ThisPtr;
  value.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)ThisPtr;
  if ( ThisPtr )
  {
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 2) > 3 )
      v24 = 0;
    else
      v24 = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].__vftable;
    if ( v24 )
      ++v24->RefCount;
    v25 = this->PassedThisCh.pObject;
    if ( v25 )
      Scaleform::RefCountNTSImpl::Release(v25);
    this->PassedThisCh.pObject = v24;
    if ( (unsigned int)(ThisPtr->GetObjectType(ThisPtr) - 6) > 0x26 )
      p_pProto = 0;
    else
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
    if ( p_pProto )
      p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    v27 = this->PassedThisObj.pObject;
    if ( v27 )
    {
      v28 = v27->RefCount;
      if ( (v28 & 0x3FFFFFF) != 0 )
      {
        v27->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
      }
    }
    this->PassedThisObj.pObject = p_pProto;
    if ( ThisPtr->IsSuper(ThisPtr) )
    {
      ThisPtr = (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr[3].pProto.pObject;
      _this = ThisPtr;
    }
  }
  v29 = this->pOurEnv;
  if ( this->pThis->ExecType == 2 )
  {
    Scaleform::GFx::AS2::Environment::AddLocalRegisters(v29, this->pThis->LocalRegisterCount);
    NArgs = (Scaleform::GFx::ASStringNode *)this->pThis->Args.Data.Size;
    if ( this->mFnCall->NArgs >= (int)NArgs )
    {
      i = (Scaleform::GFx::ASStringNode *)this->pThis->Args.Data.Size;
    }
    else
    {
      NArgs = (Scaleform::GFx::ASStringNode *)this->mFnCall->NArgs;
      i = NArgs;
    }
    v62 = 0;
    if ( (int)NArgs > 0 )
    {
      do
      {
        Data = this->pThis->Args.Data.Data;
        Register = (const Scaleform::GFx::AS2::Value *)Data[v62].Register;
        mFnCall = this->mFnCall;
        obj = (Scaleform::GFx::AS2::Object *)&Data[v62];
        FirstArgBottomIndex = mFnCall->FirstArgBottomIndex;
        v67 = &mFnCall->Env->__vftable;
        v68 = v67[1] - v67[2];
        v69 = v67[6];
        v70 = v67 + 1;
        v71 = FirstArgBottomIndex - v62;
        v72 = 32 * (v69 - 1) + (v68 >> 4);
        if ( Register )
        {
          obj = 0;
          if ( v71 > v72 )
            v73 = obj;
          else
            v73 = (Scaleform::GFx::AS2::Object *)(*(_DWORD *)(v70[4] + 4 * (v71 >> 5)) + 16 * (v71 & 0x1F));
          v74 = this->pOurEnv;
          v75 = v74->LocalRegister.Data.Size;
          if ( (unsigned int)Register < v75 )
          {
            GlobalRegister = &v74->LocalRegister.Data.Data[v75 - (unsigned int)Register - 1];
          }
          else
          {
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
              v74,
              "Invalid local register %d, stack only has %d entries",
              Register,
              v74->LocalRegister.Data.Size);
            GlobalRegister = v74->GlobalRegister;
          }
          Scaleform::GFx::AS2::Value::operator=(GlobalRegister, (const Scaleform::GFx::AS2::Value *)v73);
        }
        else
        {
          if ( v71 <= v72 )
            Register = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v70[4] + 4 * (v71 >> 5)) + 16 * (v71 & 0x1F));
          Scaleform::GFx::AS2::Environment::AddLocal(this->pOurEnv, (const Scaleform::GFx::ASString *)&obj->4, Register);
        }
        ++v62;
      }
      while ( v62 < (int)i );
    }
    for ( i = (Scaleform::GFx::ASStringNode *)this->pThis->Args.Data.Size; v62 < (int)i; ++v62 )
    {
      v77 = this->pThis->Args.Data.Data;
      if ( !v77[v62].Register )
      {
        v78 = this->pOurEnv;
        val.T.Type = 0;
        v79 = (int)&v78->LocalFrames.Data.Data[v78->LocalFrames.Data.Size - 1];
        if ( *(_DWORD *)v79 )
          *(_DWORD *)(*(_DWORD *)v79 + 12) = (*(_DWORD *)(*(_DWORD *)v79 + 12) + 1) & 0x8FFFFFFF;
        v80 = *(_DWORD *)v79;
        if ( *(_DWORD *)v79 )
        {
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v80 + 16),
            &v77[v62].Name,
            &val,
            v78->StringContext.SWFVersion > 6u);
          v81 = *(_DWORD *)(v80 + 12);
          if ( (v81 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v80 + 12) = v81 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v80);
          }
        }
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
    }
    Function2Flags = this->pThis->Function2Flags;
    obj = 0;
    if ( ((Function2Flags & 0x10) != 0 || (Function2Flags & 0x20) == 0) && (pTable = value.pHash[2].pTable) != 0 )
    {
      pTable[1].SizeMask = (pTable[1].SizeMask + 1) & 0x8FFFFFFF;
      if ( this->pMethodName )
      {
        i = Scaleform::GFx::ASStringManager::CreateStringNode(
              (Scaleform::GFx::ASStringManager *)this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
              (__m128i *)this->pMethodName);
        ++i->RefCount;
        Owner = Scaleform::GFx::AS2::ObjectInterface::FindOwner(
                  (Scaleform::GFx::AS2::ObjectInterface *)&pTable[2],
                  &this->pOurEnv->StringContext,
                  (const Scaleform::GFx::ASString *)&i);
        v85 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)Owner;
        if ( Owner )
          Owner[3].pObject = (Scaleform::GFx::AS2::Object *)(((int)&Owner[3].pObject->__vftable + 1) & 0x8FFFFFFF);
        v86 = i;
        --i->RefCount;
        if ( !v86->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v86);
        if ( v85 )
        {
          v85->RefCount = (v85->RefCount + 1) & 0x8FFFFFFF;
          SizeMask = pTable[1].SizeMask;
          if ( (SizeMask & 0x3FFFFFF) != 0 )
          {
            pTable[1].SizeMask = SizeMask - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pTable);
          }
          v88 = v85->RefCount;
          pTable = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)v85;
          if ( (v88 & 0x3FFFFFF) != 0 )
          {
            v85->RefCount = v88 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v85);
          }
        }
      }
      (*(void (__thiscall **)(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *, Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::ASStringContext *))(pTable[2].EntryCount + 56))(
        pTable + 2,
        &ctor,
        &this->pOurEnv->StringContext);
      v89 = (Scaleform::GFx::AS2::SuperObject *)((int (__thiscall *)(Scaleform::GFx::ASString *, int, _DWORD))key->pNode[1].HashFlags)(
                                                  key,
                                                  76,
                                                  0);
      v90 = _this;
      if ( v89 )
        Scaleform::GFx::AS2::SuperObject::SuperObject(
          v89,
          (Scaleform::GFx::AS2::Object *)pTable[3].EntryCount,
          _this,
          &ctor);
      else
        v91 = 0;
      obj = v91;
      if ( (ctor.Flags & 2) == 0 )
      {
        if ( ctor.Function )
        {
          v92 = ctor.Function->RefCount;
          Function = ctor.Function;
          if ( (v92 & 0x3FFFFFF) != 0 )
          {
            ctor.Function->RefCount = v92 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      ctor.Function = 0;
      if ( (ctor.Flags & 1) == 0 )
      {
        if ( ctor.pLocalFrame )
        {
          v94 = ctor.pLocalFrame->RefCount;
          v95 = ctor.pLocalFrame;
          if ( (v94 & 0x3FFFFFF) != 0 )
          {
            ctor.pLocalFrame->RefCount = v94 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v95);
          }
        }
      }
      ctor.pLocalFrame = 0;
      v96 = pTable[1].SizeMask;
      if ( (v96 & 0x3FFFFFF) != 0 )
      {
        pTable[1].SizeMask = v96 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pTable);
      }
    }
    else
    {
      v90 = _this;
    }
    v97 = (this->pThis->Function2Flags & 1) == 0;
    i = (Scaleform::GFx::ASStringNode *)1;
    if ( !v97 )
    {
      if ( v90 )
      {
        v98 = this->pOurEnv;
        v99 = v98->LocalRegister.Data.Size;
        if ( v99 > 1 )
        {
          Scaleform::GFx::AS2::Value::SetAsObjectInterface(&v98->LocalRegister.Data.Data[v99 - 2], v90);
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            v98,
            "Invalid local register %d, stack only has %d entries",
            1,
            v98->LocalRegister.Data.Size);
          Scaleform::GFx::AS2::Value::SetAsObjectInterface(v98->GlobalRegister, v90);
        }
      }
      else
      {
        v100 = this->pOurEnv;
        v101 = v100->LocalRegister.Data.Size;
        if ( v101 > 1 )
        {
          v102 = &v100->LocalRegister.Data.Data[v101 - 2];
        }
        else
        {
          Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
            v100,
            "Invalid local register %d, stack only has %d entries",
            1,
            v100->LocalRegister.Data.Size);
          v102 = v100->GlobalRegister;
        }
        Scaleform::GFx::AS2::Value::DropRefs(v102);
        v102->T.Type = 0;
      }
      i = (Scaleform::GFx::ASStringNode *)2;
    }
    if ( (this->pThis->Function2Flags & 2) == 0 )
    {
      val.T.Type = 0;
      if ( v90 )
        Scaleform::GFx::AS2::Value::SetAsObjectInterface(&val, v90);
      v103 = this->pOurEnv;
      v104 = (const Scaleform::GFx::ASString *)v103->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      v105 = (int)&v103->LocalFrames.Data.Data[v103->LocalFrames.Data.Size - 1];
      if ( *(_DWORD *)v105 )
        *(_DWORD *)(*(_DWORD *)v105 + 12) = (*(_DWORD *)(*(_DWORD *)v105 + 12) + 1) & 0x8FFFFFFF;
      v106 = *(_DWORD *)v105;
      if ( *(_DWORD *)v105 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v106 + 16),
          v104 + 102,
          &val,
          v103->StringContext.SWFVersion > 6u);
        v107 = *(_DWORD *)(v106 + 12);
        if ( (v107 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v106 + 12) = v107 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v106);
        }
      }
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
    v108 = this->pThis->Function2Flags;
    _this = 0;
    if ( (v108 & 4) != 0 || (v108 & 8) == 0 )
    {
      v109 = (Scaleform::GFx::AS2::Object *)((int (__thiscall *)(Scaleform::GFx::ASString *, int, _DWORD))key->pNode[1].HashFlags)(
                                              key,
                                              80,
                                              0);
      v110 = v109;
      if ( v109 )
      {
        v111 = this->pOurEnv;
        Scaleform::GFx::AS2::Object::Object(v109, v111);
        v110->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
        v110->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ArrayObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
        v110[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)v111->Target->GetLog(v111->Target);
        v110[1].pRCC = 0;
        v110[1].RootIndex = 0;
        v110[1].RefCount = 0;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)&v110[1].Scaleform::GFx::AS2::ObjectInterface);
        v110[1].pUserDataHolder = 0;
        LOBYTE(v110[1].pProto.pObject) = 0;
        Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v111->StringContext.pContext, ASBuiltin_Array);
        Scaleform::GFx::AS2::Object::Set__proto__(
          (Scaleform::GFx::AS2::Object *)&v110->Scaleform::GFx::AS2::ObjectInterface,
          &v111->StringContext,
          Prototype);
      }
      else
      {
        v110 = 0;
      }
      v170 = this->mFnCall->NArgs;
      _this = (Scaleform::GFx::AS2::ObjectInterface *)v110;
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v110, v170);
      for ( j = 0; j < this->mFnCall->NArgs; ++j )
      {
        v114 = this->mFnCall;
        v115 = v114->FirstArgBottomIndex;
        v116 = &v114->Env->__vftable;
        v117 = v116[1] - v116[2];
        v118 = v116[6];
        v119 = v116 + 1;
        v120 = v115 - j;
        value.pHash = 0;
        if ( v120 > 32 * (v118 - 1) + (v117 >> 4) )
          pHash = (const Scaleform::GFx::AS2::Value *)value.pHash;
        else
          pHash = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v119[4] + 4 * (v120 >> 5)) + 16 * (v120 & 0x1F));
        if ( j >= 0 && j < (signed int)v110[1].RootIndex )
        {
          pRCC = v110[1].pRCC;
          LOBYTE(v110[1].pProto.pObject) = 0;
          if ( !(&pRCC->__vftable)[j] )
          {
            value.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)323;
            v123 = (Scaleform::GFx::AS2::RefCountCollector<323>_vtbl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                         Scaleform::Memory::pGlobalHeap,
                                                                         v110,
                                                                         16,
                                                                         &value);
            if ( v123 )
              LOBYTE(v123->~Scaleform::GFx::AS2::RefCountCollector<323>) = 0;
            else
              v123 = 0;
            (&v110[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[j] = v123;
          }
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)(&v110[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$C9E2C53B7BF33D1B05D56CCE19B38030::__vftable)[j],
            pHash);
        }
      }
    }
    v124 = i;
    if ( (this->pThis->Function2Flags & 4) != 0 )
    {
      v125 = this->pOurEnv;
      v126 = v125->LocalRegister.Data.Size;
      if ( (unsigned int)i < v126 )
      {
        v127 = &v125->LocalRegister.Data.Data[v126 - (unsigned int)i - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v125,
          "Invalid local register %d, stack only has %d entries",
          i,
          v125->LocalRegister.Data.Size);
        v127 = v125->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v127, (Scaleform::GFx::AS2::Object *)_this);
      v124 = (Scaleform::GFx::ASStringNode *)((char *)v124 + 1);
    }
    if ( (this->pThis->Function2Flags & 8) == 0 )
    {
      v128 = this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      Scaleform::GFx::AS2::Value::Value(&val, (Scaleform::GFx::AS2::Object *)_this);
      v129 = this->pOurEnv;
      v130 = v129->LocalFrames.Data.Size;
      value.pHash = v131;
      v132 = (int)&v129->LocalFrames.Data.Data[v130 - 1];
      if ( *(_DWORD *)v132 )
        *(_DWORD *)(*(_DWORD *)v132 + 12) = (*(_DWORD *)(*(_DWORD *)v132 + 12) + 1) & 0x8FFFFFFF;
      v133 = *(_DWORD *)v132;
      if ( v133 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v133 + 16),
          (const Scaleform::GFx::ASString *)&v128[21].AVMVersion,
          (const Scaleform::GFx::AS2::Value *)value.pHash,
          v129->StringContext.SWFVersion > 6u);
        v134 = *(_DWORD *)(v133 + 12);
        if ( (v134 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v133 + 12) = v134 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v133);
        }
      }
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      v135 = this->pOurEnv;
      HIBYTE(v172) = 7;
      v136 = 32 * (v135->CallStack.Pages.Data.Size - 1) + v135->CallStack.pCurrent - v135->CallStack.pPageStart;
      p_pUserDataHolder = (char *)&_this[1].pUserDataHolder;
      Scaleform::GFx::AS2::Value::Value(&val, v135->CallStack.Pages.Data.Data[v136 >> 5]->Values[v136 & 0x1F].pObject);
      (*(void (__thiscall **)(char *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::AS2::Value *, char *))(*(_DWORD *)p_pUserDataHolder + 40))(
        p_pUserDataHolder,
        &this->pOurEnv->StringContext,
        this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject + 22,
        &val,
        (char *)&v172 + 3);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
      v138 = this->pOurEnv;
      HIBYTE(v172) = 7;
      if ( 32 * (v138->CallStack.Pages.Data.Size - 1) + v138->CallStack.pCurrent - v138->CallStack.pPageStart )
      {
        v139 = 32 * (v138->CallStack.Pages.Data.Size - 1) + v138->CallStack.pCurrent - v138->CallStack.pPageStart;
        v140 = 0;
        if ( v139 )
          v140 = &v138->CallStack.Pages.Data.Data[(unsigned int)(v139 - 1) >> 5]->Values[(v139 - 1) & 0x1F].pObject;
        Scaleform::GFx::AS2::Value::Value(&val, *v140);
      }
      else
      {
        val.T.Type = 1;
      }
      (*(void (__thiscall **)(char *, Scaleform::GFx::AS2::ASStringContext *, volatile int *, Scaleform::GFx::AS2::Value *, char *))(*(_DWORD *)p_pUserDataHolder + 40))(
        p_pUserDataHolder,
        &this->pOurEnv->StringContext,
        &this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[22].RefCount,
        &val,
        (char *)&v172 + 3);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
    if ( (this->pThis->Function2Flags & 0x10) != 0 )
    {
      v141 = this->pOurEnv;
      v142 = v141->LocalRegister.Data.Size;
      if ( (unsigned int)v124 < v142 )
      {
        v143 = &v141->LocalRegister.Data.Data[v142 - (unsigned int)v124 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v141,
          "Invalid local register %d, stack only has %d entries",
          v124,
          v141->LocalRegister.Data.Size);
        v143 = v141->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v143, obj);
      v124 = (Scaleform::GFx::ASStringNode *)((char *)v124 + 1);
    }
    if ( (this->pThis->Function2Flags & 0x20) == 0 )
    {
      val.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObject(&val, obj);
      v144 = this->pOurEnv;
      v145 = (int)&v144->LocalFrames.Data.Data[v144->LocalFrames.Data.Size - 1];
      p_pASSupport = (const Scaleform::GFx::ASString *)&v144->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport;
      if ( *(_DWORD *)v145 )
        *(_DWORD *)(*(_DWORD *)v145 + 12) = (*(_DWORD *)(*(_DWORD *)v145 + 12) + 1) & 0x8FFFFFFF;
      v147 = *(_DWORD *)v145;
      key = (Scaleform::GFx::ASString *)v147;
      if ( v147 )
      {
        v148 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(v147 + 16);
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v147 + 16),
          &value,
          p_pASSupport,
          v144->StringContext.SWFVersion > 6u);
        if ( value.pHash && value.pHash->pTable && value.Index <= (signed int)value.pHash->pTable->SizeMask )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)&value.pHash->pTable[3 * value.Index + 2],
            &val);
        }
        else
        {
          HashFlags = p_pASSupport->pNode->HashFlags;
          value.Index = (int)&val;
          value.pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)p_pASSupport;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            v148,
            v148,
            (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&value,
            HashFlags);
        }
        v149 = key;
        pNode = key[3].pNode;
        if ( ((unsigned int)pNode & 0x3FFFFFF) != 0 )
        {
          key[3].pNode = (Scaleform::GFx::ASStringNode *)((char *)pNode - 1);
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v149);
        }
      }
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
    if ( (this->pThis->Function2Flags & 0x40) != 0 )
    {
      v151 = this->pOurEnv;
      v152 = v151->LocalRegister.Data.Size;
      Target = v151->Target;
      if ( (unsigned int)v124 < v152 )
      {
        v154 = &v151->LocalRegister.Data.Data[v152 - (unsigned int)v124 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v151,
          "Invalid local register %d, stack only has %d entries",
          v124,
          v151->LocalRegister.Data.Size);
        v154 = v151->GlobalRegister;
      }
      v155 = Target->GetTopParent(Target, 0);
      if ( v155 )
      {
        CharacterHandle = v155->pNameHandle.pObject;
        if ( !CharacterHandle )
          CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v155);
      }
      else
      {
        CharacterHandle = 0;
      }
      if ( v154->T.Type != 7 || v154->V.pCharHandle != CharacterHandle )
      {
        Scaleform::GFx::AS2::Value::DropRefs(v154);
        v154->T.Type = 7;
        v154->NV.Int32Value = (int)CharacterHandle;
        if ( CharacterHandle )
          ++CharacterHandle->RefCount;
      }
      v124 = (Scaleform::GFx::ASStringNode *)((char *)v124 + 1);
    }
    if ( SLOBYTE(this->pThis->Function2Flags) < 0 )
    {
      v157 = this->pOurEnv;
      val.T.Type = 0;
      HIDWORD(v169) = &val;
      LODWORD(v169) = (char *)v157->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject + 424;
      Scaleform::GFx::AS2::Environment::GetVariable(v157, v169, 0, 0, 0);
      v158 = this->pOurEnv;
      v159 = v158->LocalRegister.Data.Size;
      if ( (unsigned int)v124 < v159 )
      {
        v160 = &v158->LocalRegister.Data.Data[v159 - (unsigned int)v124 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v158,
          "Invalid local register %d, stack only has %d entries",
          v124,
          v158->LocalRegister.Data.Size);
        v160 = v158->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::operator=(v160, &val);
      v124 = (Scaleform::GFx::ASStringNode *)((char *)v124 + 1);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
    if ( (this->pThis->Function2Flags & 0x100) != 0 )
    {
      v161 = this->pOurEnv;
      v162 = v161->LocalRegister.Data.Size;
      v163 = v161->StringContext.pContext->pGlobal.pObject;
      if ( (unsigned int)v124 < v162 )
      {
        v164 = &v161->LocalRegister.Data.Data[v162 - (unsigned int)v124 - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v161,
          "Invalid local register %d, stack only has %d entries",
          v124,
          v161->LocalRegister.Data.Size);
        v164 = v161->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v164, v163);
    }
    v165 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)_this;
    if ( _this )
    {
      v166 = _this[1].__vftable;
      if ( ((unsigned int)v166 & 0x3FFFFFF) != 0 )
      {
        _this[1].__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)((char *)v166 - 1);
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v165);
      }
    }
    v167 = obj;
    if ( obj )
    {
      v168 = obj->RefCount;
      if ( (v168 & 0x3FFFFFF) != 0 )
      {
        obj->RefCount = v168 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v167);
      }
    }
  }
  else
  {
    SWFVersion = v29->StringContext.SWFVersion;
    if ( ThisPtr )
    {
      val.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(&val, ThisPtr);
      Scaleform::GFx::AS2::Environment::AddLocal(
        this->pOurEnv,
        (const Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl,
        &val);
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
    if ( SWFVersion >= 6 )
    {
      v31 = this->CurLocalFrame.pObject;
      if ( v31 )
        v31->SuperThis = v23;
    }
    if ( this->CurLocalFrame.pObject )
    {
      Env = this->mFnCall->Env;
      if ( Env )
      {
        if ( SWFVersion >= 5 )
        {
          if ( this->pOurEnv != Env )
          {
            v33 = Env->Target;
            if ( v33 )
              ++v33->RefCount;
            v34 = this->FnEnvCh.pObject;
            if ( v34 )
              Scaleform::RefCountNTSImpl::Release(v34);
            this->FnEnvCh.pObject = v33;
          }
          this->CurLocalFrame.pObject->Env = this->mFnCall->Env;
          this->CurLocalFrame.pObject->NArgs = this->mFnCall->NArgs;
          this->CurLocalFrame.pObject->FirstArgBottomIndex = this->mFnCall->FirstArgBottomIndex;
          v35 = this->pOurEnv;
          v36 = 32 * (v35->CallStack.Pages.Data.Size - 1) + v35->CallStack.pCurrent - v35->CallStack.pPageStart;
          Scaleform::GFx::AS2::Value::Value(&val, v35->CallStack.Pages.Data.Data[v36 >> 5]->Values[v36 & 0x1F].pObject);
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Callee, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
          v37 = this->pOurEnv;
          if ( 32 * (v37->CallStack.Pages.Data.Size - 1) + v37->CallStack.pCurrent - v37->CallStack.pPageStart )
          {
            v38 = 32 * (v37->CallStack.Pages.Data.Size - 1) + v37->CallStack.pCurrent - v37->CallStack.pPageStart;
            v39 = 0;
            if ( v38 )
              v39 = &v37->CallStack.Pages.Data.Data[(unsigned int)(v38 - 1) >> 5]->Values[(v38 - 1) & 0x1F].pObject;
            Scaleform::GFx::AS2::Value::Value(&val, *v39);
          }
          else
          {
            val.T.Type = 1;
          }
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Caller, &val);
          if ( val.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&val);
        }
      }
    }
    v40 = (Scaleform::GFx::ASStringNode *)this->pThis->Args.Data.Size;
    if ( this->mFnCall->NArgs >= (int)v40 )
    {
      i = (Scaleform::GFx::ASStringNode *)this->pThis->Args.Data.Size;
    }
    else
    {
      v40 = (Scaleform::GFx::ASStringNode *)this->mFnCall->NArgs;
      i = v40;
    }
    v41 = 0;
    if ( (int)v40 > 0 )
    {
      do
      {
        v42 = this->mFnCall;
        v43 = v42->FirstArgBottomIndex;
        v44 = &v42->Env->__vftable;
        v45 = v44[1] - v44[2];
        v46 = v44[6];
        v47 = v44 + 1;
        v48 = v43 - v41;
        v49 = 0;
        if ( v48 <= 32 * (v46 - 1) + (v45 >> 4) )
          v49 = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v47[4] + 4 * (v48 >> 5)) + 16 * (v48 & 0x1F));
        v50 = this->pOurEnv;
        v51 = v50->LocalFrames.Data.Size;
        key = &this->pThis->Args.Data.Data[v41].Name;
        v52 = (int)&v50->LocalFrames.Data.Data[v51 - 1];
        if ( *(_DWORD *)v52 )
          *(_DWORD *)(*(_DWORD *)v52 + 12) = (*(_DWORD *)(*(_DWORD *)v52 + 12) + 1) & 0x8FFFFFFF;
        v53 = *(_DWORD *)v52;
        if ( *(_DWORD *)v52 )
        {
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v53 + 16),
            key,
            v49,
            v50->StringContext.SWFVersion > 6u);
          v54 = *(_DWORD *)(v53 + 12);
          if ( (v54 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v53 + 12) = v54 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v53);
          }
        }
        ++v41;
      }
      while ( v41 < (int)i );
    }
    for ( key = (Scaleform::GFx::ASString *)this->pThis->Args.Data.Size; v41 < (int)key; ++v41 )
    {
      v55 = this->pThis;
      val.T.Type = 0;
      v56 = v55->Args.Data.Data;
      v57 = this->pOurEnv;
      v58 = (int)&v57->LocalFrames.Data.Data[v57->LocalFrames.Data.Size - 1];
      if ( *(_DWORD *)v58 )
        *(_DWORD *)(*(_DWORD *)v58 + 12) = (*(_DWORD *)(*(_DWORD *)v58 + 12) + 1) & 0x8FFFFFFF;
      v59 = *(_DWORD *)v58;
      if ( *(_DWORD *)v58 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v59 + 16),
          &v56[v41].Name,
          &val,
          v57->StringContext.SWFVersion > 6u);
        v60 = *(_DWORD *)(v59 + 12);
        if ( (v60 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(v59 + 12) = v60 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v59);
        }
      }
      if ( val.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&val);
    }
  }
}
