void __userpurge Scaleform::GFx::AS2::ExecutionContext::Function2OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Scaleform::GFx::AS2::ActionBuffer *pActions,
        int a5,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AsFunctionObject *v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // esi
  unsigned int v12; // ebp
  const unsigned __int8 *pBuffer; // esi
  int v14; // eax
  int v15; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // eax
  __int16 v17; // dx
  int v18; // ebp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *v19; // ebx
  const unsigned __int8 *v20; // eax
  int v21; // edx
  int v22; // ebp
  Scaleform::GFx::AS2::ActionBuffer *StringNode; // eax
  unsigned int Size; // ecx
  unsigned int v25; // esi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // edx
  bool v27; // zf
  unsigned int v28; // ecx
  int v29; // ecx
  Scaleform::GFx::ASStringNode **v30; // ecx
  Scaleform::GFx::ASStringNode *v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // esi
  _DWORD *i; // ecx
  unsigned int v35; // edx
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v36; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int Capacity; // ecx
  int v39; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned int v41; // ecx
  Scaleform::GFx::AS2::LocalFrame *v42; // edx
  Scaleform::GFx::AS2::LocalFrame *pObject; // ecx
  Scaleform::GFx::InteractiveObject *Target; // eax
  int *p_RefCount; // ecx
  Scaleform::GFx::AS2::Environment *v46; // eax
  Scaleform::MemoryHeap *v47; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  int v50; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Object *v53; // eax
  Scaleform::GFx::AS2::GlobalContext *v54; // edx
  Scaleform::GFx::AS2::FunctionObject *v55; // eax
  Scaleform::GFx::AS2::Environment *v56; // edi
  Scaleform::GFx::AS2::Value *v57; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v59; // ecx
  unsigned int RefCount; // eax
  int v61; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v63; // eax
  Scaleform::GFx::ASStringNode *v64; // eax
  int v65; // eax
  int v66; // [esp+20h] [ebp-58h]
  Scaleform::GFx::AS2::ASStringContext *v67; // [esp+20h] [ebp-58h]
  int v68; // [esp+24h] [ebp-54h]
  Scaleform::GFx::ASString name; // [esp+30h] [ebp-48h] BYREF
  int v70; // [esp+34h] [ebp-44h]
  Scaleform::GFx::ASStringNode **v71; // [esp+38h] [ebp-40h]
  unsigned int v72; // [esp+3Ch] [ebp-3Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v73; // [esp+40h] [ebp-38h]
  unsigned int v74; // [esp+44h] [ebp-34h]
  int ArgRegister; // [esp+48h] [ebp-30h]
  Scaleform::GFx::AS2::FunctionRef funcRef; // [esp+4Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value FunctionValue; // [esp+58h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v78; // [esp+68h] [ebp-10h] BYREF

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
      Exec_Function2);
    v10 = v9;
    v70 = v9;
  }
  else
  {
    v70 = 0;
    v10 = 0;
  }
  v68 = a2;
  v66 = a3;
  v11 = this->PC + 3;
  name.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (char *)&this->pBuffer[v11]);
  ++name.pNode->RefCount;
  v12 = v11 + name.pNode->Size + 1;
  pBuffer = this->pBuffer;
  v14 = pBuffer[v12 + 1];
  v15 = pBuffer[v12];
  v12 += 2;
  v16 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(v15 | (v14 << 8));
  *(_BYTE *)(v10 + 107) = pBuffer[v12++];
  v17 = *(_WORD *)&this->pBuffer[v12];
  v18 = v12 + 2;
  *(_WORD *)(v10 + 104) = v17;
  if ( (int)v16 > 0 )
  {
    v19 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v10 + 84);
    v73 = v16;
    while ( 1 )
    {
      v20 = this->pBuffer;
      v21 = v20[v18];
      v22 = v18 + 1;
      ArgRegister = v21;
      StringNode = (Scaleform::GFx::AS2::ActionBuffer *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                          (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                          (char *)&v20[v22],
                                                          strlen((const char *)&v20[v22]));
      ++StringNode->Dictionary.Data.Data;
      Size = v19->Size;
      v25 = *(_DWORD *)(v70 + 88) + 1;
      pActions = StringNode;
      v74 = Size;
      if ( v25 >= Size )
      {
        if ( v25 < v19->Policy.Capacity )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v19,
          v19,
          v25 + (v25 >> 2));
      }
      else
      {
        Data = v19->Data;
        v28 = Size - v25;
        v27 = v28 == 0;
        v72 = v28;
        v29 = (int)&Data[v28 - 1 + v25];
        if ( !v27 )
        {
          v30 = (Scaleform::GFx::ASStringNode **)(v29 + 4);
          v71 = v30;
          do
          {
            v31 = *v30;
            v27 = v31->RefCount-- == 1;
            if ( v27 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v31);
              StringNode = pActions;
            }
            v30 = v71 - 2;
            v27 = v72-- == 1;
            v71 -= 2;
          }
          while ( !v27 );
        }
        if ( v25 >= v19->Policy.Capacity >> 1 )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v19,
          v19,
          v25);
      }
      StringNode = pActions;
LABEL_17:
      v32 = v74;
      v19->Size = v25;
      if ( v25 > v32 )
      {
        v33 = v25 - v32;
        for ( i = &v19->Data[v32].Register; v33; --v33 )
        {
          if ( i )
          {
            *i = v19[1].Data;
            v35 = v19[1].Size;
            i[1] = v35;
            ++*(_DWORD *)(v35 + 12);
          }
          i += 2;
        }
      }
      v36 = &v19->Data[v19->Size - 1];
      v36->Register = ArgRegister;
      ++StringNode->Dictionary.Data.Data;
      pNode = v36->Name.pNode;
      v27 = pNode->RefCount-- == 1;
      if ( v27 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        StringNode = pActions;
      }
      v36->Name.pNode = (Scaleform::GFx::ASStringNode *)StringNode;
      Capacity = StringNode->Dictionary.Data.Policy.Capacity;
      v27 = StringNode->Dictionary.Data.Data-- == (Scaleform::GFx::ASString *)1;
      v18 = Capacity + v22 + 1;
      if ( v27 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)StringNode);
      v73 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v73 - 1);
      if ( !v73 )
      {
        v10 = v70;
        break;
      }
    }
  }
  v39 = *(unsigned __int16 *)&this->pBuffer[v18];
  *(_DWORD *)(v10 + 80) = v39;
  this->NextPC += v39;
  *(_DWORD *)(v10 + 12) = (*(_DWORD *)(v10 + 12) + 1) & 0x8FFFFFFF;
  pEnv = this->pEnv;
  v41 = this->pEnv->LocalFrames.Data.Size;
  v42 = 0;
  funcRef.Flags = 0;
  funcRef.Function = (Scaleform::GFx::AS2::FunctionObject *)v10;
  funcRef.pLocalFrame = 0;
  if ( v41 )
  {
    pObject = pEnv->LocalFrames.Data.Data[v41 - 1].pObject;
    if ( pObject )
    {
      funcRef.Flags = 0;
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
      funcRef.pLocalFrame = pObject;
      v42 = pObject;
    }
  }
  FunctionValue.T.Type = 8;
  FunctionValue.V.FunctionValue.Flags = 0;
  FunctionValue.NV.Int32Value = v10;
  *(_DWORD *)(v10 + 12) = (*(_DWORD *)(v10 + 12) + 1) & 0x8FFFFFFF;
  FunctionValue.V.FunctionValue.pLocalFrame = 0;
  if ( v42 )
  {
    FunctionValue.V.FunctionValue.pLocalFrame = v42;
    FunctionValue.V.FunctionValue.Flags &= ~1u;
    if ( (FunctionValue.V.FunctionValue.Flags & 1) == 0 )
      v42->RefCount = (v42->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( name.pNode->Size )
  {
    Target = this->pEnv->Target;
    if ( Target )
      Target = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int, int, int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                           + Target->AvmObjOffset)
                                                                                         + 4))(
                                                      (int)Target + 4 * Target->AvmObjOffset,
                                                      v66,
                                                      v68);
    p_RefCount = &Target->RefCount;
    v46 = this->pEnv;
    LOBYTE(pActions) = 0;
    (*(void (__thiscall **)(int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ActionBuffer **))(*p_RefCount + 40))(
      p_RefCount,
      &v46->StringContext,
      &name,
      &FunctionValue,
      &pActions);
  }
  v47 = this->pEnv->StringContext.pContext->pHeap;
  Alloc = v47->Alloc;
  p_StringContext = &this->pEnv->StringContext;
  pActions = (Scaleform::GFx::AS2::ActionBuffer *)p_StringContext;
  v50 = ((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))Alloc)(v47, 84, 0, v66, v68);
  if ( v50 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v50, p_StringContext, Prototype);
    *(_DWORD *)(v50 + 52) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_DWORD *)(v50 + 56) = 0;
    *(_DWORD *)(v50 + 60) = 0;
    *(_BYTE *)(v50 + 64) = 0;
    *(_BYTE *)(v50 + 76) = 0;
    *(_DWORD *)(v50 + 68) = 0;
    *(_DWORD *)(v50 + 72) = 0;
    *(_DWORD *)(v50 + 80) = 0;
    v67 = psc;
    *(_DWORD *)v50 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v50 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v50 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v50 + 52),
      (Scaleform::GFx::AS2::Object *)v50,
      v67,
      (const Scaleform::GFx::AS2::FunctionRef *)&funcRef.Flags);
    *(_DWORD *)(v50 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    p_StringContext = psc;
    *(_DWORD *)v50 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v50 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v50 = 0;
  }
  pContext = this->pEnv->StringContext.pContext;
  ArgRegister = v50;
  v53 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor((Scaleform::GFx::AS2::FunctionObject *)v10, p_StringContext, v53);
  v54 = p_StringContext->pContext;
  LOBYTE(psc) = 0;
  v55 = *(Scaleform::GFx::AS2::FunctionObject **)(v10 + 16);
  funcRef.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v54->pMovieRoot->pASMovieRoot.pObject;
  funcRef.Function = v55;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)((char *)&v78.NV.NumberValue + 4),
    (Scaleform::GFx::AS2::Object *)v50);
  (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *))&funcRef.Function->ResolveHandler.Flags)(
    v10 + 16,
    p_StringContext,
    &funcRef.pLocalFrame[6].Callee);
  if ( v78.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v78);
  if ( !name.pNode->Size )
  {
    v56 = this->pEnv;
    v57 = ++v56->Stack.pCurrent;
    p_Stack = &v56->Stack;
    if ( v57 >= p_Stack->pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, &FunctionValue);
  }
  v59 = v73;
  if ( v73 )
  {
    RefCount = v73->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v73->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v59);
    }
  }
  if ( FunctionValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&FunctionValue);
  v61 = *(_DWORD *)(v10 + 12);
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v61) != 0 )
  {
    *(_DWORD *)(v10 + 12) = v61 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
  }
  pLocalFrame = funcRef.pLocalFrame;
  if ( funcRef.pLocalFrame )
  {
    v63 = funcRef.pLocalFrame->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v63) != 0 )
    {
      funcRef.pLocalFrame->RefCount = v63 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
  }
  v64 = name.pNode;
  --name.pNode->RefCount;
  if ( !v64->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  v65 = *(_DWORD *)(v10 + 12);
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v65) != 0 )
  {
    *(_DWORD *)(v10 + 12) = v65 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
  }
}
