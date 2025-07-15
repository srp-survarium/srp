void __userpurge Scaleform::GFx::AS2::ExecutionContext::Function2OpCode(
        Scaleform::GFx::AS2::ExecutionContext *this@<ecx>,
        int a2@<ebp>,
        int a3@<esi>,
        Scaleform::GFx::AS2::ActionBuffer *pActions)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::AsFunctionObject *v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // esi
  unsigned int v10; // ebp
  const unsigned __int8 *pBuffer; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  __int16 v15; // dx
  int v16; // ebp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *v17; // ebx
  const unsigned __int8 *v18; // eax
  Scaleform::GFx::AS2::ASStringContext *v19; // edx
  int v20; // ebp
  Scaleform::GFx::ASStringNode *v21; // eax
  unsigned int Size; // ecx
  unsigned int v23; // esi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *Data; // edx
  bool v25; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // ecx
  int v27; // ecx
  Scaleform::GFx::ASStringNode **v28; // ecx
  Scaleform::GFx::ASStringNode *v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // esi
  _DWORD *i; // ecx
  unsigned int v33; // edx
  _DWORD *p_Register; // esi
  Scaleform::GFx::ASStringNode *v35; // ecx
  unsigned int v36; // ecx
  int v37; // eax
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  unsigned int v39; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v40; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // ecx
  Scaleform::GFx::InteractiveObject *Target; // eax
  int *p_RefCount; // ecx
  Scaleform::GFx::AS2::Environment *v44; // eax
  Scaleform::MemoryHeap *v45; // ecx
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  int v48; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::Object *v51; // eax
  Scaleform::GFx::AS2::GlobalContext *v52; // edx
  int v53; // eax
  Scaleform::GFx::AS2::Environment *v54; // esi
  Scaleform::GFx::AS2::Value *v55; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v58; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v59; // ecx
  unsigned int RefCount; // eax
  int v61; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v62; // ecx
  unsigned int v63; // eax
  Scaleform::GFx::ASStringNode *v64; // eax
  int v65; // eax
  int v66; // [esp+1Ch] [ebp-60h]
  Scaleform::GFx::AS2::ASStringContext *v67; // [esp+1Ch] [ebp-60h]
  int v68; // [esp+20h] [ebp-5Ch]
  int v69; // [esp+2Ch] [ebp-50h] BYREF
  Scaleform::GFx::ASStringNode *StringNode; // [esp+30h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASStringNode *v71; // [esp+34h] [ebp-48h]
  int v72; // [esp+38h] [ebp-44h]
  Scaleform::GFx::ASStringNode **v73; // [esp+3Ch] [ebp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v74; // [esp+40h] [ebp-3Ch]
  Scaleform::GFx::AS2::ASStringContext *v75; // [esp+44h] [ebp-38h]
  int v76; // [esp+48h] [ebp-34h]
  Scaleform::GFx::AS2::ASStringContext *psc; // [esp+4Ch] [ebp-30h]
  int v78; // [esp+50h] [ebp-2Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v79; // [esp+54h] [ebp-28h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [esp+58h] [ebp-24h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v81; // [esp+64h] [ebp-18h]
  char v82; // [esp+68h] [ebp-14h]
  Scaleform::GFx::AS2::Value v83; // [esp+6Ch] [ebp-10h] BYREF

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
      Exec_Function2);
    v8 = v7;
    v72 = v7;
  }
  else
  {
    v72 = 0;
    v8 = 0;
  }
  v68 = a2;
  v66 = a3;
  v9 = this->PC + 3;
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                 (__m128i *)&this->pBuffer[v9]);
  ++StringNode->RefCount;
  v10 = v9 + StringNode->Size + 1;
  pBuffer = this->pBuffer;
  v12 = pBuffer[v10 + 1];
  v13 = pBuffer[v10];
  v10 += 2;
  v14 = v13 | (v12 << 8);
  *(_BYTE *)(v8 + 107) = pBuffer[v10++];
  v15 = *(_WORD *)&this->pBuffer[v10];
  v16 = v10 + 2;
  *(_WORD *)(v8 + 104) = v15;
  if ( v14 > 0 )
  {
    v17 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)(v8 + 84);
    v75 = (Scaleform::GFx::AS2::ASStringContext *)v14;
    while ( 1 )
    {
      v18 = this->pBuffer;
      v19 = (Scaleform::GFx::AS2::ASStringContext *)v18[v16];
      v20 = v16 + 1;
      psc = v19;
      v21 = Scaleform::GFx::ASStringManager::CreateStringNode(
              (Scaleform::GFx::ASStringManager *)this->pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
              (__m128i *)&v18[v20],
              strlen((const char *)&v18[v20]));
      ++v21->RefCount;
      Size = v17->Size;
      v23 = *(_DWORD *)(v72 + 88) + 1;
      v71 = v21;
      v76 = Size;
      if ( v23 >= Size )
      {
        if ( v23 < v17->Policy.Capacity )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v17,
          v17,
          v23 + (v23 >> 2));
      }
      else
      {
        Data = v17->Data;
        v26 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)(Size - v23);
        v25 = v26 == 0;
        v74 = v26;
        v27 = (int)&Data[(int)((int)v26 + v23) - 1];
        if ( !v25 )
        {
          v28 = (Scaleform::GFx::ASStringNode **)(v27 + 4);
          v73 = v28;
          do
          {
            v29 = *v28;
            v25 = v29->RefCount-- == 1;
            if ( v25 )
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v29);
              v21 = v71;
            }
            v28 = v73 - 2;
            v25 = v74 == (Scaleform::GFx::AS2::RefCountBaseGC<323> *)1;
            v74 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)((char *)v74 - 1);
            v73 -= 2;
          }
          while ( !v25 );
        }
        if ( v23 >= v17->Policy.Capacity >> 1 )
          goto LABEL_17;
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v17,
          v17,
          v23);
      }
      v21 = v71;
LABEL_17:
      v30 = v76;
      v17->Size = v23;
      if ( v23 > v30 )
      {
        v31 = v23 - v30;
        for ( i = &v17->Data[v30].Register; v31; --v31 )
        {
          if ( i )
          {
            *i = v17[1].Data;
            v33 = v17[1].Size;
            i[1] = v33;
            ++*(_DWORD *)(v33 + 12);
          }
          i += 2;
        }
      }
      p_Register = &v17->Data[v17->Size - 1].Register;
      *p_Register = psc;
      ++v21->RefCount;
      v35 = (Scaleform::GFx::ASStringNode *)p_Register[1];
      v25 = v35->RefCount-- == 1;
      if ( v25 )
      {
        Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        v21 = v71;
      }
      p_Register[1] = v21;
      v36 = v21->Size;
      v25 = v21->RefCount-- == 1;
      v16 = v36 + v20 + 1;
      if ( v25 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
      v75 = (Scaleform::GFx::AS2::ASStringContext *)((char *)v75 - 1);
      if ( !v75 )
      {
        v8 = v72;
        break;
      }
    }
  }
  v37 = *(unsigned __int16 *)&this->pBuffer[v16];
  *(_DWORD *)(v8 + 80) = v37;
  this->NextPC += v37;
  *(_DWORD *)(v8 + 12) = (*(_DWORD *)(v8 + 12) + 1) & 0x8FFFFFFF;
  pEnv = this->pEnv;
  v39 = this->pEnv->LocalFrames.Data.Size;
  v40 = 0;
  LOBYTE(constructor.Function) = 0;
  v78 = v8;
  v79 = 0;
  if ( v39 )
  {
    pObject = pEnv->LocalFrames.Data.Data[v39 - 1].pObject;
    if ( pObject )
    {
      LOBYTE(constructor.Function) = 0;
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
      v79 = pObject;
      v40 = pObject;
    }
  }
  LOBYTE(constructor.pLocalFrame) = 8;
  v82 = 0;
  *(_DWORD *)&constructor.Flags = v8;
  *(_DWORD *)(v8 + 12) = (*(_DWORD *)(v8 + 12) + 1) & 0x8FFFFFFF;
  v81 = 0;
  if ( v40 )
  {
    v81 = v40;
    v82 &= ~1u;
    if ( (v82 & 1) == 0 )
      v40->RefCount = (v40->RefCount + 1) & 0x8FFFFFFF;
  }
  if ( StringNode->Size )
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
    v44 = this->pEnv;
    HIBYTE(v69) = 0;
    (*(void (__thiscall **)(int *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::LocalFrame **, char *))(*p_RefCount + 40))(
      p_RefCount,
      &v44->StringContext,
      &StringNode,
      &constructor.pLocalFrame,
      (char *)&v69 + 3);
  }
  v45 = this->pEnv->StringContext.pContext->pHeap;
  Alloc = v45->Alloc;
  p_StringContext = &this->pEnv->StringContext;
  v75 = p_StringContext;
  v48 = ((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))Alloc)(v45, 84, 0, v66, v68);
  if ( v48 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(this->pEnv->StringContext.pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v48, p_StringContext, Prototype);
    *(_DWORD *)(v48 + 52) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_DWORD *)(v48 + 56) = 0;
    *(_DWORD *)(v48 + 60) = 0;
    *(_BYTE *)(v48 + 64) = 0;
    *(_BYTE *)(v48 + 76) = 0;
    *(_DWORD *)(v48 + 68) = 0;
    *(_DWORD *)(v48 + 72) = 0;
    *(_DWORD *)(v48 + 80) = 0;
    v67 = psc;
    *(_DWORD *)v48 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v48 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v48 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v48 + 52),
      (Scaleform::GFx::AS2::Object *)v48,
      v67,
      &constructor);
    *(_DWORD *)(v48 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    p_StringContext = psc;
    *(_DWORD *)v48 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v48 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v48 = 0;
  }
  pContext = this->pEnv->StringContext.pContext;
  v76 = v48;
  v51 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::FunctionObject::SetProtoAndCtor((Scaleform::GFx::AS2::FunctionObject *)v8, p_StringContext, v51);
  v52 = p_StringContext->pContext;
  HIBYTE(v71) = 0;
  v53 = *(_DWORD *)(v8 + 16);
  v79 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v52->pMovieRoot->pASMovieRoot.pObject;
  v78 = v53;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)((char *)&v83.NV.NumberValue + 4),
    (Scaleform::GFx::AS2::Object *)v48);
  (*(void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, $9B9E8CCB0B08DB90B6C18BC91DACC9F3 *))(v78 + 40))(
    v8 + 16,
    p_StringContext,
    &v79[29].8);
  if ( v83.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v83);
  if ( !StringNode->Size )
  {
    v54 = this->pEnv;
    v55 = ++v54->Stack.pCurrent;
    p_Stack = &v54->Stack;
    if ( v55 >= p_Stack->pPageEnd )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
    if ( p_Stack->pCurrent )
      Scaleform::GFx::AS2::Value::Value(p_Stack->pCurrent, (const Scaleform::GFx::AS2::Value *)&constructor.pLocalFrame);
  }
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsEnabled(Instance) )
  {
    if ( StringNode->Size )
    {
      v58 = Scaleform::AmpServer::GetInstance();
      if ( v58->GetProfileLevel(v58) >= Amp_Profile_Level_Medium )
        Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
          this->pEnv->Target->pASRoot->pMovieImpl->AdvanceStats.pObject,
          (Scaleform::RefCountVImpl *)pActions->pBufferData.pObject->SwdHandle,
          *(_DWORD *)(v8 + 76) + pActions->pBufferData.pObject->SWFFileOffset,
          (const __m128i *)StringNode->pData,
          *(_DWORD *)(v8 + 80),
          2u,
          0);
    }
  }
  v59 = v74;
  if ( v74 )
  {
    RefCount = v74->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v74->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v59);
    }
  }
  if ( LOBYTE(constructor.pLocalFrame) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&constructor.pLocalFrame);
  v61 = *(_DWORD *)(v8 + 12);
  if ( (v61 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v8 + 12) = v61 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8);
  }
  v62 = v79;
  if ( v79 )
  {
    v63 = v79->RefCount;
    if ( (v63 & 0x3FFFFFF) != 0 )
    {
      v79->RefCount = v63 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v62);
    }
  }
  v64 = StringNode;
  --StringNode->RefCount;
  if ( !v64->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  v65 = *(_DWORD *)(v8 + 12);
  if ( (v65 & 0x3FFFFFF) != 0 )
  {
    *(_DWORD *)(v8 + 12) = v65 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8);
  }
}
