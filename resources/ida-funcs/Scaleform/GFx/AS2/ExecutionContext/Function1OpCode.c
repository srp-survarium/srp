void __userpurge Scaleform::GFx::AS2::ExecutionContext::Function1OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        Scaleform::GFx::AS2::ActionBuffer *pActions)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AsFunctionObject *v6; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // ebx
  int v9; // edi
  unsigned int v10; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // eax
  unsigned int v12; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *p_ResolveHandler; // ebp
  Scaleform::GFx::ASStringNode *v14; // ebx
  unsigned int Size; // edx
  unsigned int v16; // edi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // ecx
  int p_Name; // eax
  Scaleform::GFx::ASStringNode *v19; // ecx
  bool v20; // zf
  unsigned int v21; // edi
  _DWORD *i; // eax
  unsigned int v23; // ecx
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v24; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  int v26; // eax
  unsigned int v27; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v28; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned int v30; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v31; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  Scaleform::GFx::InteractiveObject *Target; // eax
  int *p_RefCount; // ecx
  Scaleform::GFx::AS2::Environment *v35; // eax
  Scaleform::MemoryHeap *v36; // ecx
  int v37; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Object *v41; // eax
  Scaleform::GFx::AS2::GlobalContext *v42; // edx
  Scaleform::GFx::AS2::ASStringContext *v43; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v44; // eax
  Scaleform::GFx::AS2::Environment *v45; // edi
  Scaleform::GFx::AS2::Value *v46; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v49; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v50; // ecx
  unsigned int RefCount; // eax
  unsigned int v52; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v53; // ecx
  unsigned int v54; // eax
  Scaleform::GFx::ASStringNode *v55; // eax
  unsigned int v56; // eax
  int v57; // [esp+1Ch] [ebp-5Ch]
  int v58; // [esp+20h] [ebp-58h]
  int v59; // [esp+2Ch] [ebp-4Ch] BYREF
  Scaleform::GFx::ASStringNode *StringNode; // [esp+30h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::FunctionObject *v61; // [esp+34h] [ebp-44h]
  int v62; // [esp+38h] [ebp-40h]
  Scaleform::GFx::AS2::FunctionObject *v63; // [esp+3Ch] [ebp-3Ch]
  int v64; // [esp+40h] [ebp-38h]
  char *v65; // [esp+44h] [ebp-34h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v66; // [esp+48h] [ebp-30h]
  char *v67; // [esp+4Ch] [ebp-2Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v68; // [esp+50h] [ebp-28h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [esp+54h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v70; // [esp+60h] [ebp-18h]
  char v71; // [esp+64h] [ebp-14h]
  Scaleform::GFx::AS2::Value v72; // [esp+68h] [ebp-10h] BYREF

  pHeap = this->pEnv->StringContext.pContext->pHeap;
  v6 = (Scaleform::GFx::AS2::AsFunctionObject *)pHeap->Alloc(pHeap, 108u, 0);
  if ( v6 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      v6,
      this->pEnv,
      pActions,
      this->NextPC,
      0,
      this->WithStack.pWithStackArray,
      Exec_Function);
    v8 = v7;
    v61 = v7;
  }
  else
  {
    v61 = 0;
    v8 = 0;
  }
  v58 = a2;
  v57 = a3;
  v9 = this->PC + 3;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (__m128i *)&this->pBuffer[v9]);
  ++StringNode->RefCount;
  v10 = v9 + StringNode->Size + 1;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)*(unsigned __int16 *)&this->pBuffer[v10];
  v12 = v10 + 2;
  v62 = v12;
  if ( (int)v11 > 0 )
  {
    p_ResolveHandler = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)&v8[1].ResolveHandler;
    v66 = v11;
    while ( 1 )
    {
      v14 = Scaleform::GFx::ASStringManager::CreateStringNode(
              (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
              (__m128i *)&this->pBuffer[v12]);
      ++v14->RefCount;
      Size = p_ResolveHandler->Size;
      v16 = (unsigned int)&v61[1].ResolveHandler.pLocalFrame->__vftable + 1;
      v63 = (Scaleform::GFx::AS2::FunctionObject *)Size;
      if ( v16 >= Size )
      {
        if ( v16 < p_ResolveHandler->Policy.Capacity )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ResolveHandler,
          p_ResolveHandler,
          v16 + (v16 >> 2));
      }
      else
      {
        Data = p_ResolveHandler->Data;
        v65 = (char *)(Size - v16);
        if ( Size != v16 )
        {
          p_Name = (int)&Data[Size - 1].Name;
          v64 = p_Name;
          do
          {
            v19 = *(Scaleform::GFx::ASStringNode **)p_Name;
            v20 = (*(_DWORD *)(*(_DWORD *)p_Name + 12))-- == 1;
            if ( v20 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
              Size = (unsigned int)v63;
            }
            p_Name = v64 - 8;
            v20 = v65-- == (char *)1;
            v64 -= 8;
          }
          while ( !v20 );
        }
        if ( v16 >= p_ResolveHandler->Policy.Capacity >> 1 )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ResolveHandler,
          p_ResolveHandler,
          v16);
      }
      Size = (unsigned int)v63;
LABEL_17:
      p_ResolveHandler->Size = v16;
      if ( v16 > Size )
      {
        v21 = v16 - Size;
        for ( i = &p_ResolveHandler->Data[Size].Register; v21; --v21 )
        {
          if ( i )
          {
            *i = p_ResolveHandler[1].Data;
            v23 = p_ResolveHandler[1].Size;
            i[1] = v23;
            ++*(_DWORD *)(v23 + 12);
          }
          i += 2;
        }
      }
      v24 = &p_ResolveHandler->Data[p_ResolveHandler->Size - 1];
      v24->Register = 0;
      ++v14->RefCount;
      pNode = v24->Name.pNode;
      v20 = pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v26 = v62;
      v24->Name.pNode = v14;
      v27 = v14->Size;
      v20 = v14->RefCount-- == 1;
      v62 = v26 + v27 + 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v20 = v66 == (Scaleform::GFx::AS2::RefCountBaseGC<323> *)1;
      v66 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v66 - 1);
      v12 = v62;
      if ( v20 )
      {
        v8 = v61;
        break;
      }
    }
  }
  v28 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)*(unsigned __int16 *)&this->pBuffer[v12];
  v8[1].Members.mHash.pTable = v28;
  this->NextPC += (int)v28;
  v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  pEnv = this->pEnv;
  v30 = this->pEnv->LocalFrames.Data.Size;
  v31 = 0;
  LOBYTE(constructor.Function) = 0;
  v67 = (char *)v8;
  v68 = 0;
  if ( v30 )
  {
    pObject = pEnv->LocalFrames.Data.Data[v30 - 1].pObject;
    if ( pObject )
    {
      LOBYTE(constructor.Function) = 0;
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
      v68 = pObject;
      v31 = pObject;
    }
  }
  LOBYTE(constructor.pLocalFrame) = 8;
  v71 = 0;
  *(_DWORD *)&constructor.Flags = v8;
  v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  v70 = 0;
  if ( v31 )
  {
    v70 = v31;
    v71 &= ~1u;
    if ( (v71 & 1) == 0 )
      v31->RefCount = (v31->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( StringNode->Size )
  {
    Target = this->pEnv->Target;
    if ( Target )
      Target = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int, int, int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                           + Target->AvmObjOffset)
                                                                                         + 4))(
                                                      (int)Target + 4 * Target->AvmObjOffset,
                                                      v57,
                                                      v58);
    p_RefCount = &Target->RefCount;
    v35 = this->pEnv;
    HIBYTE(v59) = 0;
    (*(void (__thiscall **)(int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::LocalFrame **, char *))(*p_RefCount + 40))(
      p_RefCount,
      &v35->StringContext,
      &StringNode,
      &constructor.pLocalFrame,
      (char *)&v59 + 3);
  }
  v36 = this->pEnv->StringContext.pContext->pHeap;
  v37 = ((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))v36->Alloc)(v36, 84, 0, v57, v58);
  if ( v37 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    p_StringContext = &this->pEnv->StringContext;
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v37, p_StringContext, Prototype);
    *(_DWORD *)(v37 + 52) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v37 + 64) = 0;
    *(_DWORD *)(v37 + 56) = 0;
    *(_DWORD *)(v37 + 60) = 0;
    *(_BYTE *)(v37 + 76) = 0;
    *(_DWORD *)(v37 + 68) = 0;
    *(_DWORD *)(v37 + 72) = 0;
    *(_DWORD *)(v37 + 80) = 0;
    *(_DWORD *)v37 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v37 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v37 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v37 + 52),
      (Scaleform::GFx::AS2::Object *)v37,
      p_StringContext,
      &constructor);
    v8 = v63;
    *(_DWORD *)v37 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v37 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v37 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
  }
  else
  {
    v37 = 0;
  }
  pContext = this->pEnv->StringContext.pContext;
  v68 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v37;
  v41 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(v8, &this->pEnv->StringContext, v41);
  v42 = this->pEnv->StringContext.pContext;
  v43 = &this->pEnv->StringContext;
  HIBYTE(v61) = 0;
  v44 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  v67 = (char *)v42->pMovieRoot->pASMovieRoot.pObject;
  v66 = v44;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)((char *)&v72.NV.NumberValue + 4),
    (Scaleform::GFx::AS2::Object *)v37);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, char *))v66[2].RootIndex)(
    &v8->Scaleform::GFx::AS2::ObjectInterface,
    v43,
    v67 + 472);
  if ( v72.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v72);
  if ( !StringNode->Size )
  {
    v45 = this->pEnv;
    v46 = ++v45->Stack.pCurrent;
    p_Stack = &v45->Stack;
    if ( v46 >= p_Stack->pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, (const Scaleform::GFx::AS2::Value *)&constructor.pLocalFrame);
  }
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsEnabled(Instance) )
  {
    if ( StringNode->Size )
    {
      v49 = Scaleform::AmpServer::GetInstance();
      if ( v49->GetProfileLevel(v49) >= Amp_Profile_Level_Medium )
        Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
          this->pEnv->Target->pASRoot->pMovieImpl->AdvanceStats.pObject,
          (Scaleform::RefCountVImpl *)pActions->pBufferData.pObject->SwdHandle,
          (unsigned int)v8[1].pProto.pObject + pActions->pBufferData.pObject->SWFFileOffset,
          (const __m128i *)StringNode->pData,
          (unsigned int)v8[1].Members.mHash.pTable,
          2u,
          0);
    }
  }
  v50 = v66;
  if ( v66 )
  {
    RefCount = v66->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v66->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v50);
    }
  }
  if ( LOBYTE(constructor.pLocalFrame) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&constructor.pLocalFrame);
  v52 = v8->RefCount;
  if ( (v52 & 0x3FFFFFF) != 0 )
  {
    v8->RefCount = v52 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
  }
  v53 = v68;
  if ( v68 )
  {
    v54 = v68->RefCount;
    if ( (v54 & 0x3FFFFFF) != 0 )
    {
      v68->RefCount = v54 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v53);
    }
  }
  v55 = StringNode;
  --StringNode->RefCount;
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  v56 = v8->RefCount;
  if ( (v56 & 0x3FFFFFF) != 0 )
  {
    v8->RefCount = v56 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
  }
}
