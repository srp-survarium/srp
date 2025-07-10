void __userpurge Scaleform::GFx::AS2::ExecutionContext::Function1OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        Scaleform::GFx::AS2::ActionBuffer *pActions,
        int a5,
        char a6)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AsFunctionObject *v8; // eax
  Scaleform::GFx::AS2::FunctionObject *v9; // eax
  Scaleform::GFx::AS2::FunctionObject *v10; // ebx
  int v11; // edi
  unsigned int v12; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // eax
  Scaleform::GFx::AS2::ActionBuffer *v14; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *p_ResolveHandler; // ebp
  Scaleform::GFx::ASStringNode *StringNode; // ebx
  unsigned int Size; // edx
  unsigned int v18; // edi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // ecx
  int p_Name; // eax
  Scaleform::GFx::ASStringNode *v21; // ecx
  bool v22; // zf
  unsigned int v23; // edi
  _DWORD *i; // eax
  unsigned int v25; // ecx
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v26; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS2::ActionBuffer *v28; // eax
  unsigned int v29; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v30; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned int v32; // ecx
  Scaleform::GFx::AS2::LocalFrame *v33; // edx
  Scaleform::GFx::AS2::LocalFrame *pObject; // ecx
  Scaleform::GFx::InteractiveObject *Target; // eax
  int *p_RefCount; // ecx
  Scaleform::GFx::AS2::Environment *v37; // eax
  Scaleform::MemoryHeap *v38; // ecx
  int v39; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Object *v43; // eax
  Scaleform::GFx::AS2::GlobalContext *v44; // edx
  Scaleform::GFx::AS2::ASStringContext *v45; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v46; // eax
  Scaleform::GFx::AS2::Environment *v47; // esi
  Scaleform::GFx::AS2::Value *v48; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v50; // ecx
  unsigned int RefCount; // eax
  unsigned int v52; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v54; // eax
  Scaleform::GFx::ASStringNode *v55; // eax
  unsigned int v56; // eax
  int v57; // [esp+1Ch] [ebp-54h]
  int v58; // [esp+20h] [ebp-50h]
  Scaleform::GFx::AS2::FunctionObject *v59; // [esp+2Ch] [ebp-44h]
  Scaleform::GFx::ASString name; // [esp+30h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::FunctionObject *v61; // [esp+34h] [ebp-3Ch]
  int v62; // [esp+38h] [ebp-38h]
  char *v63; // [esp+3Ch] [ebp-34h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v64; // [esp+40h] [ebp-30h]
  Scaleform::GFx::AS2::FunctionRef funcRef; // [esp+44h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value FunctionValue; // [esp+50h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v67; // [esp+60h] [ebp-10h] BYREF

  pHeap = this->pEnv->StringContext.pContext->pHeap;
  v8 = (Scaleform::GFx::AS2::AsFunctionObject *)pHeap->Alloc(pHeap, 108u, 0);
  if ( v8 )
  {
    Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
      v8,
      this->pEnv,
      pActions,
      this->NextPC,
      0,
      this->WithStack.pWithStackArray,
      Exec_Function);
    v10 = v9;
    v59 = v9;
  }
  else
  {
    v59 = 0;
    v10 = 0;
  }
  v58 = a2;
  v57 = a3;
  v11 = this->PC + 3;
  name.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (char *)&this->pBuffer[v11]);
  ++name.pNode->RefCount;
  v12 = v11 + name.pNode->Size + 1;
  v13 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)*(unsigned __int16 *)&this->pBuffer[v12];
  v14 = (Scaleform::GFx::AS2::ActionBuffer *)(v12 + 2);
  pActions = v14;
  if ( (int)v13 > 0 )
  {
    p_ResolveHandler = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)&v10[1].ResolveHandler;
    v64 = v13;
    while ( 1 )
    {
      StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                     (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                     (char *)v14 + (unsigned int)this->pBuffer);
      ++StringNode->RefCount;
      Size = p_ResolveHandler->Size;
      v18 = (unsigned int)&v59[1].ResolveHandler.pLocalFrame->__vftable + 1;
      v61 = (Scaleform::GFx::AS2::FunctionObject *)Size;
      if ( v18 >= Size )
      {
        if ( v18 < p_ResolveHandler->Policy.Capacity )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ResolveHandler,
          p_ResolveHandler,
          v18 + (v18 >> 2));
      }
      else
      {
        Data = p_ResolveHandler->Data;
        v63 = (char *)(Size - v18);
        if ( Size != v18 )
        {
          p_Name = (int)&Data[Size - 1].Name;
          v62 = p_Name;
          do
          {
            v21 = *(Scaleform::GFx::ASStringNode **)p_Name;
            v22 = (*(_DWORD *)(*(_DWORD *)p_Name + 12))-- == 1;
            if ( v22 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v21);
              Size = (unsigned int)v61;
            }
            p_Name = v62 - 8;
            v22 = v63-- == (char *)1;
            v62 -= 8;
          }
          while ( !v22 );
        }
        if ( v18 >= p_ResolveHandler->Policy.Capacity >> 1 )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_ResolveHandler,
          p_ResolveHandler,
          v18);
      }
      Size = (unsigned int)v61;
LABEL_17:
      p_ResolveHandler->Size = v18;
      if ( v18 > Size )
      {
        v23 = v18 - Size;
        for ( i = &p_ResolveHandler->Data[Size].Register; v23; --v23 )
        {
          if ( i )
          {
            *i = p_ResolveHandler[1].Data;
            v25 = p_ResolveHandler[1].Size;
            i[1] = v25;
            ++*(_DWORD *)(v25 + 12);
          }
          i += 2;
        }
      }
      v26 = &p_ResolveHandler->Data[p_ResolveHandler->Size - 1];
      v26->Register = 0;
      ++StringNode->RefCount;
      pNode = v26->Name.pNode;
      v22 = pNode->RefCount-- == 1;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v28 = pActions;
      v26->Name.pNode = StringNode;
      v29 = StringNode->Size;
      v22 = StringNode->RefCount-- == 1;
      pActions = (Scaleform::GFx::AS2::ActionBuffer *)((char *)&v28->__vftable + v29 + 1);
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
      v22 = v64 == (Scaleform::GFx::AS2::RefCountBaseGC<323> *)1;
      v64 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v64 - 1);
      v14 = pActions;
      if ( v22 )
      {
        v10 = v59;
        break;
      }
    }
  }
  v30 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::Member,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *)*(unsigned __int16 *)((char *)&v14->__vftable + (unsigned int)this->pBuffer);
  v10[1].Members.mHash.pTable = v30;
  this->NextPC += (int)v30;
  v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  pEnv = this->pEnv;
  v32 = this->pEnv->LocalFrames.Data.Size;
  v33 = 0;
  funcRef.Flags = 0;
  funcRef.Function = v10;
  funcRef.pLocalFrame = 0;
  if ( v32 )
  {
    pObject = pEnv->LocalFrames.Data.Data[v32 - 1].pObject;
    if ( pObject )
    {
      funcRef.Flags = 0;
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
      funcRef.pLocalFrame = pObject;
      v33 = pObject;
    }
  }
  FunctionValue.T.Type = 8;
  FunctionValue.V.FunctionValue.Flags = 0;
  FunctionValue.NV.Int32Value = (int)v10;
  v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  FunctionValue.V.FunctionValue.pLocalFrame = 0;
  if ( v33 )
  {
    FunctionValue.V.FunctionValue.pLocalFrame = v33;
    FunctionValue.V.FunctionValue.Flags &= ~1u;
    if ( (FunctionValue.V.FunctionValue.Flags & 1) == 0 )
      v33->RefCount = (v33->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( name.pNode->Size )
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
    v37 = this->pEnv;
    LOBYTE(pActions) = 0;
    (*(void (__thiscall **)(int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ActionBuffer **))(*p_RefCount + 40))(
      p_RefCount,
      &v37->StringContext,
      &name,
      &FunctionValue,
      &pActions);
  }
  v38 = this->pEnv->StringContext.pContext->pHeap;
  v39 = ((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))v38->Alloc)(v38, 84, 0, v57, v58);
  if ( v39 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    p_StringContext = &this->pEnv->StringContext;
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v39, p_StringContext, Prototype);
    *(_DWORD *)(v39 + 52) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v39 + 64) = 0;
    *(_DWORD *)(v39 + 56) = 0;
    *(_DWORD *)(v39 + 60) = 0;
    *(_BYTE *)(v39 + 76) = 0;
    *(_DWORD *)(v39 + 68) = 0;
    *(_DWORD *)(v39 + 72) = 0;
    *(_DWORD *)(v39 + 80) = 0;
    *(_DWORD *)v39 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v39 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v39 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v39 + 52),
      (Scaleform::GFx::AS2::Object *)v39,
      p_StringContext,
      (const Scaleform::GFx::AS2::FunctionRef *)&funcRef.Flags);
    v10 = v61;
    *(_DWORD *)v39 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v39 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v39 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
  }
  else
  {
    v39 = 0;
  }
  pContext = this->pEnv->StringContext.pContext;
  funcRef.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v39;
  v43 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor(v10, &this->pEnv->StringContext, v43);
  v44 = this->pEnv->StringContext.pContext;
  v45 = &this->pEnv->StringContext;
  a6 = 0;
  v46 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable;
  funcRef.Function = (Scaleform::GFx::AS2::FunctionObject *)v44->pMovieRoot->pASMovieRoot.pObject;
  v64 = v46;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)((char *)&v67.NV.NumberValue + 4),
    (Scaleform::GFx::AS2::Object *)v39);
  ((void (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, $ADD6DCFDE39599335059E819E3D29E57 *))v64[2].RootIndex)(
    &v10->Scaleform::GFx::AS2::ObjectInterface,
    v45,
    &funcRef.Function[9].4);
  if ( v67.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v67);
  if ( !name.pNode->Size )
  {
    v47 = this->pEnv;
    v48 = ++v47->Stack.pCurrent;
    p_Stack = &v47->Stack;
    if ( v48 >= p_Stack->pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &FunctionValue);
  }
  v50 = v64;
  if ( v64 )
  {
    RefCount = v64->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v64->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v50);
    }
  }
  if ( FunctionValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&FunctionValue);
  v52 = v10->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v52) != 0 )
  {
    v10->RefCount = v52 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
  }
  pLocalFrame = funcRef.pLocalFrame;
  if ( funcRef.pLocalFrame )
  {
    v54 = funcRef.pLocalFrame->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v54) != 0 )
    {
      funcRef.pLocalFrame->RefCount = v54 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
  }
  v55 = name.pNode;
  --name.pNode->RefCount;
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  v56 = v10->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v56) != 0 )
  {
    v10->RefCount = v56 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
  }
}
