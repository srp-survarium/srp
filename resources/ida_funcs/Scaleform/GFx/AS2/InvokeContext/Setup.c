void __thiscall Scaleform::GFx::AS2::InvokeContext::Setup(Scaleform::GFx::AS2::InvokeContext *this)
{
  Scaleform::GFx::AS2::Environment *pOurEnv; // ebx
  Scaleform::GFx::AS2::AsFunctionObject *pThis; // edi
  Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject> *v4; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *p_CallStack; // ebx
  _DWORD *p_pObject; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v8; // ecx
  Scaleform::GFx::AS2::ArrayObject *ThisPtr; // ebp
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
  Scaleform::GFx::AS2::Object *v26; // edi
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
  int v40; // eax
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
  int NArgs; // eax
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
  Scaleform::GFx::AS2::SuperObject *v73; // ebx
  Scaleform::GFx::AS2::Environment *v74; // ebp
  unsigned int v75; // eax
  Scaleform::GFx::AS2::Value *GlobalRegister; // eax
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v77; // ecx
  Scaleform::GFx::AS2::Environment *v78; // eax
  int v79; // edx
  int v80; // ebp
  int v81; // eax
  unsigned __int16 Function2Flags; // ax
  Scaleform::GFx::AS2::Object *v83; // ebp
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *Owner; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v85; // edi
  Scaleform::GFx::ASStringNode *v86; // eax
  unsigned int v87; // eax
  unsigned int v88; // eax
  Scaleform::GFx::AS2::SuperObject *v89; // eax
  Scaleform::GFx::AS2::ObjectInterface *v90; // ebx
  Scaleform::GFx::AS2::SuperObject *v91; // eax
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
  int i; // ebp
  const Scaleform::GFx::AS2::FnCall *v114; // ecx
  int v115; // eax
  _DWORD *v116; // ecx
  int v117; // edx
  int v118; // ebx
  _DWORD *v119; // ecx
  unsigned int v120; // eax
  Scaleform::GFx::AS2::ObjectInterface *v121; // ebx
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // edx
  Scaleform::GFx::AS2::RefCountCollector<323>_vtbl *v123; // eax
  unsigned int v124; // ebp
  Scaleform::GFx::AS2::Environment *v125; // edi
  unsigned int v126; // eax
  Scaleform::GFx::AS2::Value *v127; // eax
  Scaleform::GFx::ASMovieRootBase *v128; // ebx
  Scaleform::GFx::AS2::Environment *v129; // ecx
  unsigned int v130; // edx
  Scaleform::GFx::AS2::ObjectInterface *v131; // eax
  int v132; // edi
  int v133; // edi
  int v134; // eax
  Scaleform::GFx::AS2::Environment *v135; // ecx
  unsigned int v136; // eax
  Scaleform::GFx::AS2::ObjectInterface *v137; // edi
  Scaleform::GFx::AS2::Environment *v138; // ecx
  int v139; // eax
  Scaleform::GFx::AS2::Object **v140; // edx
  Scaleform::GFx::AS2::Environment *v141; // edi
  unsigned int v142; // eax
  Scaleform::GFx::AS2::Value *v143; // eax
  Scaleform::GFx::AS2::Environment *v144; // eax
  int v145; // edx
  Scaleform::GFx::ASString *p_pASSupport; // edi
  Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *v147; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_mHash; // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v149; // ecx
  int v150; // eax
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
  Scaleform::GFx::AS2::ArrayObject *v165; // ecx
  unsigned int v166; // eax
  Scaleform::GFx::AS2::SuperObject *v167; // ecx
  unsigned int v168; // eax
  int v169; // [esp+20h] [ebp-4Ch]
  unsigned int HashFlags; // [esp+20h] [ebp-4Ch]
  int v171; // [esp+34h] [ebp-38h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::ArrayObject> pargArray; // [esp+38h] [ebp-34h]
  Scaleform::Ptr<Scaleform::GFx::AS2::SuperObject> superObj; // [esp+3Ch] [ebp-30h]
  int ArgsToPass; // [esp+40h] [ebp-2Ch] BYREF
  int n; // [esp+44h] [ebp-28h]
  Scaleform::GFx::AS2::ObjectInterface *passedThis; // [esp+48h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::Value *p_parent; // [esp+4Ch] [ebp-20h]
  Scaleform::GFx::AS2::FunctionRef __ctor__; // [esp+50h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value parent; // [esp+5Ch] [ebp-10h] BYREF

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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pThis->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pThis);
    }
  }
  v8 = this->pOurEnv;
  ThisPtr = (Scaleform::GFx::AS2::ArrayObject *)this->mFnCall->ThisPtr;
  Size = v8->LocalFrames.Data.Size;
  n = (int)v8->StringContext.pContext->pHeap;
  v11 = this->pThis;
  this->LocalStackTop = Size;
  ExecType = v11->ExecType;
  pargArray.pObject = ThisPtr;
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
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v18) != 0 )
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
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
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
  v23 = (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr;
  passedThis = (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr;
  if ( ThisPtr )
  {
    if ( (unsigned int)(((int (__thiscall *)(Scaleform::GFx::AS2::ArrayObject *))ThisPtr->~Scaleform::GFx::AS2::ArrayObject)(ThisPtr)
                      - 2) > 3 )
      v24 = 0;
    else
      v24 = (Scaleform::GFx::InteractiveObject *)ThisPtr->RefCount;
    if ( v24 )
      ++v24->RefCount;
    v25 = this->PassedThisCh.pObject;
    if ( v25 )
      Scaleform::RefCountNTSImpl::Release(v25);
    this->PassedThisCh.pObject = v24;
    if ( (unsigned int)(((int (__thiscall *)(Scaleform::GFx::AS2::ArrayObject *))ThisPtr->~Scaleform::GFx::AS2::ArrayObject)(ThisPtr)
                      - 6) > 0x26 )
      v26 = 0;
    else
      v26 = (Scaleform::GFx::AS2::ArrayObject *)((char *)ThisPtr - 16);
    if ( v26 )
      v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
    v27 = this->PassedThisObj.pObject;
    if ( v27 )
    {
      v28 = v27->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v28) != 0 )
      {
        v27->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
      }
    }
    this->PassedThisObj.pObject = v26;
    if ( ThisPtr->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable[1].GetASCharacter(ThisPtr) )
    {
      ThisPtr = (Scaleform::GFx::AS2::ArrayObject *)ThisPtr->pWatchpoints;
      pargArray.pObject = ThisPtr;
    }
  }
  v29 = this->pOurEnv;
  if ( this->pThis->ExecType == 2 )
  {
    Scaleform::GFx::AS2::Environment::AddLocalRegisters(v29, this->pThis->LocalRegisterCount);
    NArgs = this->pThis->Args.Data.Size;
    if ( this->mFnCall->NArgs >= NArgs )
    {
      ArgsToPass = this->pThis->Args.Data.Size;
    }
    else
    {
      NArgs = this->mFnCall->NArgs;
      ArgsToPass = NArgs;
    }
    v62 = 0;
    if ( NArgs > 0 )
    {
      do
      {
        Data = this->pThis->Args.Data.Data;
        Register = (const Scaleform::GFx::AS2::Value *)Data[v62].Register;
        mFnCall = this->mFnCall;
        superObj.pObject = (Scaleform::GFx::AS2::SuperObject *)&Data[v62];
        FirstArgBottomIndex = mFnCall->FirstArgBottomIndex;
        v67 = &mFnCall->Env->__vftable;
        v68 = v67[1] - v67[2];
        v69 = v67[6];
        v70 = v67 + 1;
        v71 = FirstArgBottomIndex - v62;
        v72 = 32 * (v69 - 1) + (v68 >> 4);
        if ( Register )
        {
          superObj.pObject = 0;
          if ( v71 > v72 )
            v73 = superObj.pObject;
          else
            v73 = (Scaleform::GFx::AS2::SuperObject *)(*(_DWORD *)(v70[4] + 4 * (v71 >> 5)) + 16 * (v71 & 0x1F));
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
          Scaleform::GFx::AS2::Environment::AddLocal(
            this->pOurEnv,
            (const Scaleform::GFx::ASString *)&superObj.pObject->4,
            Register);
        }
        ++v62;
      }
      while ( v62 < ArgsToPass );
    }
    for ( ArgsToPass = this->pThis->Args.Data.Size; v62 < ArgsToPass; ++v62 )
    {
      v77 = this->pThis->Args.Data.Data;
      if ( !v77[v62].Register )
      {
        v78 = this->pOurEnv;
        parent.T.Type = 0;
        v79 = (int)&v78->LocalFrames.Data.Data[v78->LocalFrames.Data.Size - 1];
        if ( *(_DWORD *)v79 )
          *(_DWORD *)(*(_DWORD *)v79 + 12) = (*(_DWORD *)(*(_DWORD *)v79 + 12) + 1) & 0x8FFFFFFF;
        v80 = *(_DWORD *)v79;
        if ( *(_DWORD *)v79 )
        {
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v80 + 16),
            &v77[v62].Name,
            &parent,
            v78->StringContext.SWFVersion > 6u);
          v81 = *(_DWORD *)(v80 + 12);
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v81) != 0 )
          {
            *(_DWORD *)(v80 + 12) = v81 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v80);
          }
        }
        if ( parent.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&parent);
      }
    }
    Function2Flags = this->pThis->Function2Flags;
    superObj.pObject = 0;
    if ( ((Function2Flags & 0x10) != 0 || (Function2Flags & 0x20) == 0) && (v83 = passedThis->pProto.pObject) != 0 )
    {
      v83->RefCount = (v83->RefCount + 1) & 0x8FFFFFFF;
      if ( this->pMethodName )
      {
        ArgsToPass = (int)Scaleform::GFx::ASStringManager::CreateStringNode(
                            (Scaleform::GFx::ASStringManager *)this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                            (char *)this->pMethodName);
        ++*(_DWORD *)(ArgsToPass + 12);
        Owner = Scaleform::GFx::AS2::ObjectInterface::FindOwner(
                  &v83->Scaleform::GFx::AS2::ObjectInterface,
                  &this->pOurEnv->StringContext,
                  (const Scaleform::GFx::ASString *)&ArgsToPass);
        v85 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)Owner;
        if ( Owner )
          Owner[3].pObject = (Scaleform::GFx::AS2::Object *)(((int)&Owner[3].pObject->__vftable + 1) & 0x8FFFFFFF);
        v86 = (Scaleform::GFx::ASStringNode *)ArgsToPass;
        --*(_DWORD *)(ArgsToPass + 12);
        if ( !v86->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v86);
        if ( v85 )
        {
          v85->RefCount = (v85->RefCount + 1) & 0x8FFFFFFF;
          v87 = v83->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v87) != 0 )
          {
            v83->RefCount = v87 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v83);
          }
          v88 = v85->RefCount;
          v83 = (Scaleform::GFx::AS2::Object *)v85;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v88) != 0 )
          {
            v85->RefCount = v88 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v85);
          }
        }
      }
      v83->Get__constructor__(&v83->Scaleform::GFx::AS2::ObjectInterface, &__ctor__, &this->pOurEnv->StringContext);
      v89 = (Scaleform::GFx::AS2::SuperObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)n + 40))(n, 76, 0);
      v90 = (Scaleform::GFx::AS2::ObjectInterface *)pargArray.pObject;
      if ( v89 )
        Scaleform::GFx::AS2::SuperObject::SuperObject(
          v89,
          v83->pProto.pObject,
          (Scaleform::GFx::AS2::ObjectInterface *)pargArray.pObject,
          &__ctor__);
      else
        v91 = 0;
      superObj.pObject = v91;
      if ( (__ctor__.Flags & 2) == 0 )
      {
        if ( __ctor__.Function )
        {
          v92 = __ctor__.Function->RefCount;
          Function = __ctor__.Function;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v92) != 0 )
          {
            __ctor__.Function->RefCount = v92 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      __ctor__.Function = 0;
      if ( (__ctor__.Flags & 1) == 0 )
      {
        if ( __ctor__.pLocalFrame )
        {
          v94 = __ctor__.pLocalFrame->RefCount;
          v95 = __ctor__.pLocalFrame;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v94) != 0 )
          {
            __ctor__.pLocalFrame->RefCount = v94 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v95);
          }
        }
      }
      __ctor__.pLocalFrame = 0;
      v96 = v83->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v96) != 0 )
      {
        v83->RefCount = v96 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v83);
      }
    }
    else
    {
      v90 = (Scaleform::GFx::AS2::ObjectInterface *)pargArray.pObject;
    }
    v97 = (this->pThis->Function2Flags & 1) == 0;
    ArgsToPass = 1;
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
      ArgsToPass = 2;
    }
    if ( (this->pThis->Function2Flags & 2) == 0 )
    {
      parent.T.Type = 0;
      if ( v90 )
        Scaleform::GFx::AS2::Value::SetAsObjectInterface(&parent, v90);
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
          &parent,
          v103->StringContext.SWFVersion > 6u);
        v107 = *(_DWORD *)(v106 + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v107) != 0 )
        {
          *(_DWORD *)(v106 + 12) = v107 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v106);
        }
      }
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
    }
    v108 = this->pThis->Function2Flags;
    pargArray.pObject = 0;
    if ( (v108 & 4) != 0 || (v108 & 8) == 0 )
    {
      v109 = (Scaleform::GFx::AS2::Object *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)n + 40))(n, 80, 0);
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
      v169 = this->mFnCall->NArgs;
      pargArray.pObject = (Scaleform::GFx::AS2::ArrayObject *)v110;
      Scaleform::GFx::AS2::ArrayObject::Resize((Scaleform::GFx::AS2::ArrayObject *)v110, v169);
      for ( i = 0; i < this->mFnCall->NArgs; ++i )
      {
        v114 = this->mFnCall;
        v115 = v114->FirstArgBottomIndex;
        v116 = &v114->Env->__vftable;
        v117 = v116[1] - v116[2];
        v118 = v116[6];
        v119 = v116 + 1;
        v120 = v115 - i;
        passedThis = 0;
        if ( v120 > 32 * (v118 - 1) + (v117 >> 4) )
          v121 = passedThis;
        else
          v121 = (Scaleform::GFx::AS2::ObjectInterface *)(*(_DWORD *)(v119[4] + 4 * (v120 >> 5)) + 16 * (v120 & 0x1F));
        if ( i >= 0 && i < (signed int)v110[1].RootIndex )
        {
          pRCC = v110[1].pRCC;
          LOBYTE(v110[1].pProto.pObject) = 0;
          if ( !(&pRCC->__vftable)[i] )
          {
            passedThis = (Scaleform::GFx::AS2::ObjectInterface *)323;
            v123 = (Scaleform::GFx::AS2::RefCountCollector<323>_vtbl *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                         Scaleform::Memory::pGlobalHeap,
                                                                         v110,
                                                                         16,
                                                                         &passedThis);
            if ( v123 )
              LOBYTE(v123->~Scaleform::GFx::AS2::RefCountCollector<323>) = 0;
            else
              v123 = 0;
            (&v110[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[i] = v123;
          }
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)(&v110[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[i],
            (const Scaleform::GFx::AS2::Value *)v121);
        }
      }
    }
    v124 = ArgsToPass;
    if ( (this->pThis->Function2Flags & 4) != 0 )
    {
      v125 = this->pOurEnv;
      v126 = v125->LocalRegister.Data.Size;
      if ( ArgsToPass < v126 )
      {
        v127 = &v125->LocalRegister.Data.Data[v126 - ArgsToPass - 1];
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogError(
          v125,
          "Invalid local register %d, stack only has %d entries",
          ArgsToPass,
          v125->LocalRegister.Data.Size);
        v127 = v125->GlobalRegister;
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v127, pargArray.pObject);
      ++v124;
    }
    if ( (this->pThis->Function2Flags & 8) == 0 )
    {
      v128 = this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
      Scaleform::GFx::AS2::Value::Value(&parent, pargArray.pObject);
      v129 = this->pOurEnv;
      v130 = v129->LocalFrames.Data.Size;
      passedThis = v131;
      v132 = (int)&v129->LocalFrames.Data.Data[v130 - 1];
      if ( *(_DWORD *)v132 )
        *(_DWORD *)(*(_DWORD *)v132 + 12) = (*(_DWORD *)(*(_DWORD *)v132 + 12) + 1) & 0x8FFFFFFF;
      v133 = *(_DWORD *)v132;
      if ( v133 )
      {
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
          (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v133 + 16),
          (const Scaleform::GFx::ASString *)&v128[21].AVMVersion,
          (const Scaleform::GFx::AS2::Value *)passedThis,
          v129->StringContext.SWFVersion > 6u);
        v134 = *(_DWORD *)(v133 + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v134) != 0 )
        {
          *(_DWORD *)(v133 + 12) = v134 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v133);
        }
      }
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
      v135 = this->pOurEnv;
      HIBYTE(v171) = 7;
      v136 = 32 * (v135->CallStack.Pages.Data.Size - 1) + v135->CallStack.pCurrent - v135->CallStack.pPageStart;
      v137 = &pargArray.pObject->Scaleform::GFx::AS2::ObjectInterface;
      Scaleform::GFx::AS2::Value::Value(
        &parent,
        v135->CallStack.Pages.Data.Data[v136 >> 5]->Values[v136 & 0x1F].pObject);
      v137->SetMemberRaw(
        v137,
        &this->pOurEnv->StringContext,
        (const Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[22],
        &parent,
        (const Scaleform::GFx::AS2::PropFlags *)&v171 + 3);
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
      v138 = this->pOurEnv;
      HIBYTE(v171) = 7;
      if ( 32 * (v138->CallStack.Pages.Data.Size - 1) + v138->CallStack.pCurrent - v138->CallStack.pPageStart )
      {
        v139 = 32 * (v138->CallStack.Pages.Data.Size - 1) + v138->CallStack.pCurrent - v138->CallStack.pPageStart;
        v140 = 0;
        if ( v139 )
          v140 = &v138->CallStack.Pages.Data.Data[(unsigned int)(v139 - 1) >> 5]->Values[(v139 - 1) & 0x1F].pObject;
        Scaleform::GFx::AS2::Value::Value(&parent, *v140);
      }
      else
      {
        parent.T.Type = 1;
      }
      v137->SetMemberRaw(
        v137,
        &this->pOurEnv->StringContext,
        (const Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[22].RefCount,
        &parent,
        (const Scaleform::GFx::AS2::PropFlags *)&v171 + 3);
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
    }
    if ( (this->pThis->Function2Flags & 0x10) != 0 )
    {
      v141 = this->pOurEnv;
      v142 = v141->LocalRegister.Data.Size;
      if ( v124 < v142 )
      {
        v143 = &v141->LocalRegister.Data.Data[v142 - v124 - 1];
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
      Scaleform::GFx::AS2::Value::SetAsObject(v143, superObj.pObject);
      ++v124;
    }
    if ( (this->pThis->Function2Flags & 0x20) == 0 )
    {
      parent.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObject(&parent, superObj.pObject);
      v144 = this->pOurEnv;
      v145 = (int)&v144->LocalFrames.Data.Data[v144->LocalFrames.Data.Size - 1];
      p_pASSupport = (Scaleform::GFx::ASString *)&v144->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pASSupport;
      if ( *(_DWORD *)v145 )
        *(_DWORD *)(*(_DWORD *)v145 + 12) = (*(_DWORD *)(*(_DWORD *)v145 + 12) + 1) & 0x8FFFFFFF;
      v147 = *(Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > **)v145;
      n = (int)v147;
      if ( v147 )
      {
        p_mHash = &v147[4].mHash;
        Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Member,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor,324>>::FindCaseCheck(
          v147 + 4,
          (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::Iterator *)&passedThis,
          p_pASSupport,
          v144->StringContext.SWFVersion > 6u);
        if ( passedThis && passedThis->__vftable && (int)p_parent <= (int)passedThis->GetTextValue )
        {
          Scaleform::GFx::AS2::Value::operator=(
            (Scaleform::GFx::AS2::Value *)(&passedThis->GetMember + 6 * (_DWORD)p_parent),
            &parent);
        }
        else
        {
          HashFlags = p_pASSupport->pNode->HashFlags;
          p_parent = &parent;
          passedThis = (Scaleform::GFx::AS2::ObjectInterface *)p_pASSupport;
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
            p_mHash,
            p_mHash,
            (const Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&passedThis,
            HashFlags);
        }
        v149 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)n;
        v150 = *(_DWORD *)(n + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v150) != 0 )
        {
          *(_DWORD *)(n + 12) = v150 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v149);
        }
      }
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
    }
    if ( (this->pThis->Function2Flags & 0x40) != 0 )
    {
      v151 = this->pOurEnv;
      v152 = v151->LocalRegister.Data.Size;
      Target = v151->Target;
      if ( v124 < v152 )
      {
        v154 = &v151->LocalRegister.Data.Data[v152 - v124 - 1];
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
      ++v124;
    }
    if ( SLOBYTE(this->pThis->Function2Flags) < 0 )
    {
      v157 = this->pOurEnv;
      parent.T.Type = 0;
      Scaleform::GFx::AS2::Environment::GetVariable(
        v157,
        (const Scaleform::GFx::ASString *)&v157->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[21].RefCount,
        &parent,
        0,
        0,
        0,
        0);
      v158 = this->pOurEnv;
      v159 = v158->LocalRegister.Data.Size;
      if ( v124 < v159 )
      {
        v160 = &v158->LocalRegister.Data.Data[v159 - v124 - 1];
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
      Scaleform::GFx::AS2::Value::operator=(v160, &parent);
      ++v124;
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
    }
    if ( (this->pThis->Function2Flags & 0x100) != 0 )
    {
      v161 = this->pOurEnv;
      v162 = v161->LocalRegister.Data.Size;
      v163 = v161->StringContext.pContext->pGlobal.pObject;
      if ( v124 < v162 )
      {
        v164 = &v161->LocalRegister.Data.Data[v162 - v124 - 1];
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
    v165 = pargArray.pObject;
    if ( pargArray.pObject )
    {
      v166 = pargArray.pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v166) != 0 )
      {
        pargArray.pObject->RefCount = v166 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v165);
      }
    }
    v167 = superObj.pObject;
    if ( superObj.pObject )
    {
      v168 = superObj.pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v168) != 0 )
      {
        superObj.pObject->RefCount = v168 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v167);
      }
    }
  }
  else
  {
    SWFVersion = v29->StringContext.SWFVersion;
    if ( ThisPtr )
    {
      parent.T.Type = 0;
      Scaleform::GFx::AS2::Value::SetAsObjectInterface(&parent, (Scaleform::GFx::AS2::ObjectInterface *)ThisPtr);
      Scaleform::GFx::AS2::Environment::AddLocal(
        this->pOurEnv,
        (const Scaleform::GFx::ASString *)&this->pOurEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl,
        &parent);
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
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
          Scaleform::GFx::AS2::Value::Value(
            &parent,
            v35->CallStack.Pages.Data.Data[v36 >> 5]->Values[v36 & 0x1F].pObject);
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Callee, &parent);
          if ( parent.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&parent);
          v37 = this->pOurEnv;
          if ( 32 * (v37->CallStack.Pages.Data.Size - 1) + v37->CallStack.pCurrent - v37->CallStack.pPageStart )
          {
            v38 = 32 * (v37->CallStack.Pages.Data.Size - 1) + v37->CallStack.pCurrent - v37->CallStack.pPageStart;
            v39 = 0;
            if ( v38 )
              v39 = &v37->CallStack.Pages.Data.Data[(unsigned int)(v38 - 1) >> 5]->Values[(v38 - 1) & 0x1F].pObject;
            Scaleform::GFx::AS2::Value::Value(&parent, *v39);
          }
          else
          {
            parent.T.Type = 1;
          }
          Scaleform::GFx::AS2::Value::operator=(&this->CurLocalFrame.pObject->Caller, &parent);
          if ( parent.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&parent);
        }
      }
    }
    v40 = this->pThis->Args.Data.Size;
    if ( this->mFnCall->NArgs >= v40 )
    {
      ArgsToPass = this->pThis->Args.Data.Size;
    }
    else
    {
      v40 = this->mFnCall->NArgs;
      ArgsToPass = v40;
    }
    v41 = 0;
    if ( v40 > 0 )
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
        n = (int)&this->pThis->Args.Data.Data[v41].Name;
        v52 = (int)&v50->LocalFrames.Data.Data[v51 - 1];
        if ( *(_DWORD *)v52 )
          *(_DWORD *)(*(_DWORD *)v52 + 12) = (*(_DWORD *)(*(_DWORD *)v52 + 12) + 1) & 0x8FFFFFFF;
        v53 = *(_DWORD *)v52;
        if ( *(_DWORD *)v52 )
        {
          Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324>>::SetCaseCheck(
            (Scaleform::GFx::ASStringHashBase<Scaleform::GFx::AS2::Value,Scaleform::GFx::HashUncachedLH_GC<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Value,Scaleform::GFx::ASStringHashFunctor,324> > *)(v53 + 16),
            (const Scaleform::GFx::ASString *)n,
            v49,
            v50->StringContext.SWFVersion > 6u);
          v54 = *(_DWORD *)(v53 + 12);
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v54) != 0 )
          {
            *(_DWORD *)(v53 + 12) = v54 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v53);
          }
        }
        ++v41;
      }
      while ( v41 < ArgsToPass );
    }
    for ( n = this->pThis->Args.Data.Size; v41 < n; ++v41 )
    {
      v55 = this->pThis;
      parent.T.Type = 0;
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
          &parent,
          v57->StringContext.SWFVersion > 6u);
        v60 = *(_DWORD *)(v59 + 12);
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v60) != 0 )
        {
          *(_DWORD *)(v59 + 12) = v60 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v59);
        }
      }
      if ( parent.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&parent);
    }
  }
}
