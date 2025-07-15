void __thiscall Scaleform::GFx::AS2::GlobalContext::Init(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::GFx::AS2::GASGlobalObject *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // ebx
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ObjectCtorFunction *v9; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // eax
  Scaleform::MemoryHeap *v11; // ecx
  Scaleform::MemoryHeap_vtbl *v12; // eax
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::GFx::AS2::FunctionCtorFunction *v14; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // eax
  Scaleform::MemoryHeap *v16; // ecx
  Scaleform::MemoryHeap_vtbl *v17; // eax
  void *(__thiscall *v18)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  int v19; // ebx
  Scaleform::MemoryHeap *v20; // ecx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *v21; // ebx
  Scaleform::GFx::AS2::MovieClipCtorFunction *v22; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // eax
  Scaleform::MemoryHeap *v24; // ecx
  Scaleform::MemoryHeap_vtbl *v25; // eax
  void *(__thiscall *v26)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::GFx::AS2::KeyCtorFunction *v27; // eax
  Scaleform::GFx::AS2::ASBuiltinType v28; // eax
  Scaleform::MemoryHeap *v29; // ecx
  Scaleform::MemoryHeap_vtbl *v30; // edx
  void *(__thiscall *v31)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // eax
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment> *v32; // ebx
  Scaleform::GFx::AS2::MovieClipProto *v33; // eax
  Scaleform::GFx::AS2::Object *v34; // eax
  Scaleform::GFx::AS2::Object *v35; // eax
  Scaleform::GFx::AS2::ObjectInterface *v36; // eax
  Scaleform::GFx::AS2::Object *v37; // edi
  const Scaleform::GFx::AS2::Value *v38; // eax
  Scaleform::GFx::AS2::Object *v39; // edi
  const Scaleform::GFx::AS2::Value *v40; // eax
  Scaleform::GFx::AS2::Object *v41; // edi
  const Scaleform::GFx::AS2::Value *v42; // eax
  Scaleform::GFx::AS2::Object *v43; // edi
  const Scaleform::GFx::AS2::Value *v44; // eax
  Scaleform::GFx::AS2::Object *v45; // ecx
  Scaleform::GFx::MovieImpl *pMovieRoot; // edx
  Scaleform::GFx::AS2::Object *v47; // ecx
  Scaleform::GFx::MovieImpl *v48; // edx
  Scaleform::GFx::AS2::ObjectInterface *v49; // ecx
  Scaleform::GFx::MovieImpl *v50; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v51; // edi
  Scaleform::GFx::AS2::ObjectInterface *v52; // ecx
  Scaleform::GFx::MovieImpl *v53; // edx
  Scaleform::GFx::AS2::Object *v54; // eax
  Scaleform::GFx::AS2::Object *v55; // eax
  Scaleform::GFx::AS2::Object *v56; // eax
  Scaleform::GFx::AS2::Object *v57; // eax
  Scaleform::GFx::AS2::Object *v58; // eax
  Scaleform::GFx::AS2::Object *v59; // eax
  Scaleform::GFx::AS2::Object *v60; // esi
  unsigned int v61; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v62; // ecx
  unsigned int v63; // edx
  Scaleform::GFx::AS2::Object *v64; // ecx
  unsigned int v65; // edx
  Scaleform::GFx::AS2::Object *v66; // ecx
  unsigned int v67; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v68; // ecx
  unsigned int v69; // eax
  unsigned int v70; // edx
  Scaleform::GFx::AS2::Object *v71; // ecx
  unsigned int v72; // edx
  Scaleform::GFx::AS2::Object *v73; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v74; // ecx
  unsigned int v75; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v76; // ecx
  unsigned int v77; // eax
  Scaleform::GFx::ASStringNode v78; // [esp+90h] [ebp-6Ch] BYREF
  Scaleform::GFx::AS2::Object *pprototype; // [esp+A8h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v80; // [esp+ACh] [ebp-50h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v81; // [esp+B0h] [ebp-4Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v82; // [esp+B4h] [ebp-48h]
  Scaleform::GFx::AS2::ASBuiltinType key; // [esp+B8h] [ebp-44h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> value; // [esp+BCh] [ebp-40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> v85; // [esp+C0h] [ebp-3Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> v86; // [esp+C4h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ASBuiltinType v87; // [esp+C8h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::ASStringContext psc; // [esp+CCh] [ebp-30h] BYREF
  void **v89; // [esp+D4h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v90; // [esp+D8h] [ebp-24h]
  Scaleform::GFx::AS2::ASStringContext *p_psc; // [esp+DCh] [ebp-20h]
  Scaleform::GFx::AS2::FunctionRef constructor; // [esp+E0h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v93; // [esp+ECh] [ebp-10h] BYREF
  Scaleform::GFx::AS2::LocalFrame *savedregs; // [esp+FCh] [ebp+0h] BYREF

  this->pMovieRoot = proot;
  pHeap = proot->pHeap;
  this->pHeap = pHeap;
  psc.pContext = this;
  psc.SWFVersion = 8;
  if ( !this->pGlobal.pObject )
  {
    v4 = (Scaleform::GFx::AS2::GASGlobalObject *)pHeap->Alloc(pHeap, 56u, 0);
    if ( v4 )
    {
      Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(v4, this);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    pObject = this->pGlobal.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    this->pGlobal.pObject = v6;
  }
  v9 = (Scaleform::GFx::AS2::ObjectCtorFunction *)this->pHeap->Alloc(this->pHeap, 56, 0);
  if ( v9 )
  {
    Scaleform::GFx::AS2::ObjectCtorFunction::ObjectCtorFunction(v9, &savedregs, &psc);
    v81 = v10;
  }
  else
  {
    v81 = 0;
  }
  v11 = this->pHeap;
  v12 = v11->__vftable;
  v78.pData = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v81;
  Alloc = v12->Alloc;
  constructor.Flags = 0;
  constructor.pLocalFrame = 0;
  v14 = (Scaleform::GFx::AS2::FunctionCtorFunction *)Alloc(v11, 56u, 0);
  if ( v14 )
  {
    Scaleform::GFx::AS2::FunctionCtorFunction::FunctionCtorFunction(v14, &psc);
    v80 = v15;
  }
  else
  {
    v80 = 0;
  }
  v16 = this->pHeap;
  v17 = v16->__vftable;
  v78.pData = 0;
  *(_QWORD *)&v93.T.Type = (unsigned int)v80;
  v18 = v17->Alloc;
  BYTE4(v93.NV.NumberValue) = 0;
  v19 = (int)v18(v16, 84u, 0);
  if ( v19 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v19, &psc);
    *(_DWORD *)(v19 + 52) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    *(_BYTE *)(v19 + 64) = 0;
    *(_DWORD *)(v19 + 56) = 0;
    *(_DWORD *)(v19 + 60) = 0;
    *(_BYTE *)(v19 + 76) = 0;
    *(_DWORD *)(v19 + 68) = 0;
    *(_DWORD *)(v19 + 72) = 0;
    *(_DWORD *)(v19 + 80) = 0;
    *(_DWORD *)v19 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v19 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v19 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v19 + 52),
      (Scaleform::GFx::AS2::Object *)v19,
      &psc,
      &constructor);
    *(_DWORD *)v19 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v19 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v19 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    HIBYTE(v78.Size) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v19 + 52),
      v19,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      (Scaleform::GFx::AS2::Object *)v19,
      &psc,
      GAS_ObjectFunctionTable,
      (Scaleform::GFx::ASStringNode *)((char *)&v78.Size + 3),
      (int)v78.pManager,
      (int)v78.pLower);
  }
  else
  {
    v19 = 0;
  }
  v20 = this->pHeap;
  pprototype = (Scaleform::GFx::AS2::Object *)v19;
  v21 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *)v20->Alloc(v20, 84u, 0);
  if ( v21 )
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(
      v21,
      &psc,
      pprototype,
      (const Scaleform::GFx::AS2::FunctionRef *)&v93);
    v21->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v21->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v21->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    HIBYTE(v78.Size) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v21->Scaleform::GFx::AS2::GASPrototypeBase,
      (int)v21,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      v21,
      &psc,
      GAS_FunctionObjectTable,
      (Scaleform::GFx::ASStringNode *)((char *)&v78.Size + 3),
      (int)v78.pManager,
      (int)v78.pLower);
  }
  else
  {
    v21 = 0;
  }
  value.pObject = v21;
  ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *))v81[1].__vftable[4].Finalize_GC)(
    &v81[1],
    &psc,
    v21);
  ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v80[1].__vftable[4].Finalize_GC)(
    &v80[1],
    &psc,
    value.pObject);
  key = ASBuiltin_Object;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &key,
    (const Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)&pprototype);
  key = ASBuiltin_Function;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &key,
    &value);
  v22 = (Scaleform::GFx::AS2::MovieClipCtorFunction *)this->pHeap->Alloc(this->pHeap, 56, 0);
  if ( v22 )
  {
    Scaleform::GFx::AS2::MovieClipCtorFunction::MovieClipCtorFunction(v22, &psc);
    v82 = v23;
  }
  else
  {
    v82 = 0;
  }
  v24 = this->pHeap;
  v25 = v24->__vftable;
  v78.pData = 0;
  constructor.Function = (Scaleform::GFx::AS2::FunctionObject *)v82;
  v26 = v25->Alloc;
  constructor.Flags = 0;
  constructor.pLocalFrame = 0;
  v27 = (Scaleform::GFx::AS2::KeyCtorFunction *)v26(v24, 256u, 0);
  if ( v27 )
  {
    Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction(v27, 0, &psc, proot);
    key = v28;
  }
  else
  {
    key = ASBuiltin_empty_;
  }
  v29 = this->pHeap;
  v30 = v29->__vftable;
  v78.pData = 0;
  *(_QWORD *)&v93.T.Type = (unsigned int)key;
  v31 = v30->Alloc;
  BYTE4(v93.NV.NumberValue) = 0;
  v32 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment> *)v31(v29, 84u, 0);
  if ( v32 )
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>(
      v32,
      &psc,
      pprototype,
      (const Scaleform::GFx::AS2::FunctionRef *)&v93);
    v32->Scaleform::GFx::AS2::KeyObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v32->Scaleform::GFx::AS2::KeyObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v32->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable';
    HIBYTE(v78.Size) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v32->Scaleform::GFx::AS2::GASPrototypeBase,
      (int)v32,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      v32,
      &psc,
      GAS_KeyFunctionTable,
      (Scaleform::GFx::ASStringNode *)((char *)&v78.Size + 3),
      (int)v78.pManager,
      (int)v78.pLower);
  }
  else
  {
    v32 = 0;
  }
  v86.pObject = v32;
  v87 = ASBuiltin_Key;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &v87,
    &v86);
  v33 = (Scaleform::GFx::AS2::MovieClipProto *)this->pHeap->Alloc(this->pHeap, 92, 0);
  if ( v33 )
  {
    v78.pData = (const char *)&constructor;
    Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(v33, &psc, pprototype, v78);
  }
  else
  {
    v34 = 0;
  }
  v85.pObject = v34;
  v87 = ASBuiltin_MovieClip;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &v87,
    &v85);
  v35 = this->pGlobal.pObject;
  if ( v35 )
    v36 = &v35->Scaleform::GFx::AS2::ObjectInterface;
  else
    v36 = 0;
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (unsigned __int8 *)v32,
    &savedregs,
    v36,
    &psc,
    Scaleform::GFx::AS2::GFxAction_Global_StaticFunctions,
    0,
    (int)v78.pManager);
  v37 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(&v93, &psc, Scaleform::GFx::AS2::GAS_GlobalIMECommand);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v37->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&psc,
    "imecommand",
    v38);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v39 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(&v93, &psc, Scaleform::GFx::AS2::GAS_SetIMECandidateListStyle);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v39->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&psc,
    "setIMECandidateListStyle",
    v40);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v41 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(&v93, &psc, Scaleform::GFx::AS2::GAS_GetInputLanguage);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v41->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&psc,
    "getInputLanguage",
    v42);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v43 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(&v93, &psc, Scaleform::GFx::AS2::GAS_GetIMECandidateListStyle);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v43->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)&psc,
    "getIMECandidateListStyle",
    v44);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v45 = this->pGlobal.pObject;
  v93.NV.Int32Value = (int)v81;
  HIBYTE(v78.Size) = 0;
  v93.T.Type = 8;
  v93.V.FunctionValue.Flags = 0;
  v81->RefCount = (v81->RefCount + 1) & 0x8FFFFFFF;
  v78.pData = (char *)&v78.Size + 3;
  pMovieRoot = this->pMovieRoot;
  v93.V.FunctionValue.pLocalFrame = 0;
  v45->SetMemberRaw(
    &v45->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
    &v93,
    (const Scaleform::GFx::AS2::PropFlags *)&v78.Size + 3);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v47 = this->pGlobal.pObject;
  v93.NV.Int32Value = (int)v80;
  HIBYTE(v78.Size) = 0;
  v93.T.Type = 8;
  v93.V.FunctionValue.Flags = 0;
  v80->RefCount = (v80->RefCount + 1) & 0x8FFFFFFF;
  v78.pData = (char *)&v78.Size + 3;
  v48 = this->pMovieRoot;
  v93.V.FunctionValue.pLocalFrame = 0;
  v47->SetMemberRaw(
    &v47->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (const Scaleform::GFx::ASString *)&v48->pASMovieRoot.pObject[9].pASSupport,
    &v93,
    (const Scaleform::GFx::AS2::PropFlags *)&v78.Size + 3);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v49 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  HIBYTE(v78.Size) = 0;
  v93.T.Type = 8;
  v93.V.FunctionValue.Flags = 0;
  v93.NV.Int32Value = (int)v82;
  if ( v82 )
    v82->RefCount = (v82->RefCount + 1) & 0x8FFFFFFF;
  v78.pData = (char *)&v78.Size + 3;
  v50 = this->pMovieRoot;
  v93.V.FunctionValue.pLocalFrame = 0;
  v49->SetMemberRaw(
    v49,
    &psc,
    (const Scaleform::GFx::ASString *)&v50->pASMovieRoot.pObject[9].pMovieImpl,
    &v93,
    (const Scaleform::GFx::AS2::PropFlags *)&v78.Size + 3);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  v51 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)key;
  v52 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  HIBYTE(v78.Size) = 0;
  v93.T.Type = 8;
  v93.V.FunctionValue.Flags = 0;
  v93.NV.Int32Value = key;
  if ( key )
    *(_DWORD *)(key + 12) = (*(_DWORD *)(key + 12) + 1) & 0x8FFFFFFF;
  v78.pData = (char *)&v78.Size + 3;
  v53 = this->pMovieRoot;
  v93.V.FunctionValue.pLocalFrame = 0;
  v52->SetMemberRaw(
    v52,
    &psc,
    (const Scaleform::GFx::ASString *)&v53->pASMovieRoot.pObject[13].pMovieImpl,
    &v93,
    (const Scaleform::GFx::AS2::PropFlags *)&v78.Size + 3);
  if ( v93.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v93);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<25,Scaleform::GFx::AS2::MathCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<2,Scaleform::GFx::AS2::ArrayCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<4,Scaleform::GFx::AS2::NumberCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<3,Scaleform::GFx::AS2::StringCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<5,Scaleform::GFx::AS2::BooleanCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<9,Scaleform::GFx::AS2::ButtonCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<29,Scaleform::GFx::AS2::MovieClipLoaderCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<31,Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<18,Scaleform::GFx::AS2::StageCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<21,Scaleform::GFx::AS2::SelectionCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<19,Scaleform::GFx::AS2::AsBroadcasterCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<27,Scaleform::GFx::AS2::MouseCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<10,Scaleform::GFx::AS2::TextFieldCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<32,Scaleform::GFx::AS2::TextFormatCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<43,Scaleform::GFx::AS2::TextSnapshotCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<20,Scaleform::GFx::AS2::DateCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<44,Scaleform::GFx::AS2::SharedObjectCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<154,Scaleform::GFx::AS2::AmpMarkerCtorFunction>(
    this,
    &psc,
    this->pGlobal.pObject);
  v54 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &psc,
          this->pGlobal.pObject,
          pprototype,
          (__m128i *)"flash.geom",
          (Scaleform::GFx::AS2::Object *)v78.pManager);
  this->FlashGeomPackage = v54;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<12,Scaleform::GFx::AS2::TransformCtorFunction>(
    this,
    &psc,
    v54);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<13,Scaleform::GFx::AS2::GASMatrixCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<14,Scaleform::GFx::AS2::PointCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<15,Scaleform::GFx::AS2::RectangleCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<16,Scaleform::GFx::AS2::ColorTransformCtorFunction>(
    this,
    &psc,
    this->FlashGeomPackage);
  v55 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &psc,
          this->pGlobal.pObject,
          pprototype,
          (__m128i *)"System",
          (Scaleform::GFx::AS2::Object *)v78.pManager);
  this->SystemPackage = v55;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<17,Scaleform::GFx::AS2::CapabilitiesCtorFunction>(
    this,
    &psc,
    v55);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<22,Scaleform::GFx::AS2::GASImeCtorFunction>(
    this,
    &psc,
    this->SystemPackage);
  v56 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &psc,
          this->pGlobal.pObject,
          pprototype,
          (__m128i *)"flash.external",
          (Scaleform::GFx::AS2::Object *)v78.pManager);
  this->FlashExternalPackage = v56;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<28,Scaleform::GFx::AS2::ExternalInterfaceCtorFunction>(
    this,
    &psc,
    v56);
  v57 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &psc,
          this->pGlobal.pObject,
          pprototype,
          (__m128i *)"flash.display",
          (Scaleform::GFx::AS2::Object *)v78.pManager);
  this->FlashDisplayPackage = v57;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<30,Scaleform::GFx::AS2::BitmapDataCtorFunction>(
    this,
    &psc,
    v57);
  v58 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &psc,
          this->pGlobal.pObject,
          pprototype,
          (__m128i *)"flash.filters",
          (Scaleform::GFx::AS2::Object *)v78.pManager);
  this->FlashFiltersPackage = v58;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<37,Scaleform::GFx::AS2::BitmapFilterCtorFunction>(
    this,
    &psc,
    v58);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<38,Scaleform::GFx::AS2::DropShadowFilterCtorFunction>(
    this,
    &psc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<39,Scaleform::GFx::AS2::GlowFilterCtorFunction>(
    this,
    &psc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<40,Scaleform::GFx::AS2::BlurFilterCtorFunction>(
    this,
    &psc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<41,Scaleform::GFx::AS2::BevelFilterCtorFunction>(
    this,
    &psc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<42,Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction>(
    this,
    &psc,
    this->FlashFiltersPackage);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StandardMemberMap);
  Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(this);
  v59 = this->pGlobal.pObject;
  v89 = (void **)&`Scaleform::GFx::AS2::GlobalContext::Init'::`4'::MemberVisitor::`vftable';
  if ( v59 )
    v59->RefCount = (v59->RefCount + 1) & 0x8FFFFFFF;
  v60 = this->pGlobal.pObject;
  v90 = v59;
  p_psc = &psc;
  v60->VisitMembers(
    &v60->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *)&v89,
    4u,
    0);
  if ( v90 )
  {
    v61 = v90->RefCount;
    if ( (v61 & 0x3FFFFFF) != 0 )
    {
      v62 = v90;
      v90->RefCount = v61 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v62);
    }
  }
  v89 = &Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( v85.pObject )
  {
    v63 = v85.pObject->RefCount;
    if ( (v63 & 0x3FFFFFF) != 0 )
    {
      v64 = v85.pObject;
      v85.pObject->RefCount = v63 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v64);
    }
  }
  if ( v86.pObject )
  {
    v65 = v86.pObject->RefCount;
    if ( (v65 & 0x3FFFFFF) != 0 )
    {
      v66 = v86.pObject;
      v86.pObject->RefCount = v65 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v66);
    }
  }
  if ( v51 )
  {
    v67 = v51->RefCount;
    if ( (v67 & 0x3FFFFFF) != 0 )
    {
      v51->RefCount = v67 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
    }
  }
  v68 = v82;
  if ( v82 )
  {
    v69 = v82->RefCount;
    if ( (v69 & 0x3FFFFFF) != 0 )
    {
      v82->RefCount = v69 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v68);
    }
  }
  if ( value.pObject )
  {
    v70 = value.pObject->RefCount;
    if ( (v70 & 0x3FFFFFF) != 0 )
    {
      v71 = value.pObject;
      value.pObject->RefCount = v70 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v71);
    }
  }
  if ( pprototype )
  {
    v72 = pprototype->RefCount;
    v73 = pprototype;
    if ( (v72 & 0x3FFFFFF) != 0 )
    {
      pprototype->RefCount = v72 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v73);
    }
  }
  v74 = v80;
  v75 = v80->RefCount;
  if ( (v75 & 0x3FFFFFF) != 0 )
  {
    v80->RefCount = v75 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v74);
  }
  v76 = v81;
  v77 = v81->RefCount;
  if ( (v77 & 0x3FFFFFF) != 0 )
  {
    v81->RefCount = v77 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v76);
  }
}
