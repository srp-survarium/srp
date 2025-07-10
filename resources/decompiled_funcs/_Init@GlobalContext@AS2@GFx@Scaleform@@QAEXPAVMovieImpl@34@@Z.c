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
  Scaleform::GFx::AS2::Object *v62; // ecx
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
  int v78; // [esp+94h] [ebp-68h]
  Scaleform::GFx::AS2::Object *v79; // [esp+94h] [ebp-68h]
  Scaleform::GFx::AS2::Object *v80; // [esp+94h] [ebp-68h]
  Scaleform::GFx::AS2::Object *v81; // [esp+94h] [ebp-68h]
  Scaleform::GFx::AS2::Object *v82; // [esp+94h] [ebp-68h]
  Scaleform::GFx::AS2::Object *v83; // [esp+94h] [ebp-68h]
  int v84; // [esp+98h] [ebp-64h]
  Scaleform::GFx::AS2::PropFlags flags[4]; // [esp+A4h] [ebp-58h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objProto; // [esp+A8h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v87; // [esp+ACh] [ebp-50h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v88; // [esp+B0h] [ebp-4Ch]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v89; // [esp+B4h] [ebp-48h]
  Scaleform::GFx::AS2::ASBuiltinType key; // [esp+B8h] [ebp-44h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> functionProto; // [esp+BCh] [ebp-40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> movieClipProto; // [esp+C0h] [ebp-3Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> keyProto; // [esp+C4h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::ASBuiltinType v94; // [esp+C8h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::ASStringContext sc; // [esp+CCh] [ebp-30h] BYREF
  Scaleform::GFx::AS2::GlobalContext::Init::__l4::MemberVisitor visitor; // [esp+D4h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::FunctionRef objCtor; // [esp+E0h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::FunctionRef functionCtor; // [esp+ECh] [ebp-10h] BYREF
  char v99; // [esp+F8h] [ebp-4h]
  Scaleform::GFx::AS2::LocalFrame *savedregs; // [esp+FCh] [ebp+0h] BYREF

  this->pMovieRoot = proot;
  pHeap = proot->pHeap;
  this->pHeap = pHeap;
  sc.pContext = this;
  sc.SWFVersion = 8;
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
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
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
    Scaleform::GFx::AS2::ObjectCtorFunction::ObjectCtorFunction(v9, &savedregs, &sc);
    v88 = v10;
  }
  else
  {
    v88 = 0;
  }
  v11 = this->pHeap;
  v12 = v11->__vftable;
  objCtor.Function = (Scaleform::GFx::AS2::FunctionObject *)v88;
  Alloc = v12->Alloc;
  objCtor.Flags = 0;
  objCtor.pLocalFrame = 0;
  v14 = (Scaleform::GFx::AS2::FunctionCtorFunction *)Alloc(v11, 56u, 0);
  if ( v14 )
  {
    Scaleform::GFx::AS2::FunctionCtorFunction::FunctionCtorFunction(v14, &sc);
    v87 = v15;
  }
  else
  {
    v87 = 0;
  }
  v16 = this->pHeap;
  v17 = v16->__vftable;
  functionCtor.Function = (Scaleform::GFx::AS2::FunctionObject *)v87;
  v18 = v17->Alloc;
  functionCtor.Flags = 0;
  functionCtor.pLocalFrame = 0;
  v19 = (int)v18(v16, 84u, 0);
  if ( v19 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v19, &sc);
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
      &sc,
      &objCtor);
    *(_DWORD *)v19 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_DWORD *)(v19 + 16) = &Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    *(_DWORD *)(v19 + 52) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    flags[3].Flags = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v19 + 52),
      v19,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      (Scaleform::GFx::AS2::Object *)v19,
      &sc,
      GAS_ObjectFunctionTable,
      (Scaleform::GFx::ASStringNode *)&flags[3],
      v78,
      v84);
  }
  else
  {
    v19 = 0;
  }
  v20 = this->pHeap;
  objProto.pObject = (Scaleform::GFx::AS2::Object *)v19;
  v21 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *)v20->Alloc(v20, 84u, 0);
  if ( v21 )
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>(
      v21,
      &sc,
      objProto.pObject,
      &functionCtor);
    v21->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v21->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v21->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Selection,Scaleform::GFx::AS2::Environment>::`vftable';
    flags[3].Flags = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v21->Scaleform::GFx::AS2::GASPrototypeBase,
      (int)v21,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      v21,
      &sc,
      GAS_FunctionObjectTable,
      (Scaleform::GFx::ASStringNode *)&flags[3],
      v78,
      v84);
  }
  else
  {
    v21 = 0;
  }
  functionProto.pObject = v21;
  ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Object,Scaleform::GFx::AS2::Environment> *))v88[1].__vftable[4].Finalize_GC)(
    &v88[1],
    &sc,
    v21);
  ((void (__thiscall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))v87[1].__vftable[4].Finalize_GC)(
    &v87[1],
    &sc,
    functionProto.pObject);
  key = ASBuiltin_Object;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &key,
    &objProto);
  key = ASBuiltin_Function;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &key,
    &functionProto);
  v22 = (Scaleform::GFx::AS2::MovieClipCtorFunction *)this->pHeap->Alloc(this->pHeap, 56, 0);
  if ( v22 )
  {
    Scaleform::GFx::AS2::MovieClipCtorFunction::MovieClipCtorFunction(v22, &sc);
    v89 = v23;
  }
  else
  {
    v89 = 0;
  }
  v24 = this->pHeap;
  v25 = v24->__vftable;
  objCtor.Function = (Scaleform::GFx::AS2::FunctionObject *)v89;
  v26 = v25->Alloc;
  objCtor.Flags = 0;
  objCtor.pLocalFrame = 0;
  v27 = (Scaleform::GFx::AS2::KeyCtorFunction *)v26(v24, 256u, 0);
  if ( v27 )
  {
    Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction(v27, 0, &sc, proot);
    key = v28;
  }
  else
  {
    key = ASBuiltin_empty_;
  }
  v29 = this->pHeap;
  v30 = v29->__vftable;
  functionCtor.Function = (Scaleform::GFx::AS2::FunctionObject *)key;
  v31 = v30->Alloc;
  functionCtor.Flags = 0;
  functionCtor.pLocalFrame = 0;
  v32 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment> *)v31(v29, 84u, 0);
  if ( v32 )
  {
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>(
      v32,
      &sc,
      objProto.pObject,
      &functionCtor);
    v32->Scaleform::GFx::AS2::KeyObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>_vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v32->Scaleform::GFx::AS2::KeyObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::KeyObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v32->Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::KeyProto::`vftable';
    flags[3].Flags = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      &v32->Scaleform::GFx::AS2::GASPrototypeBase,
      (int)v32,
      (Scaleform::GFx::AS2::LocalFrame **)this,
      v32,
      &sc,
      GAS_KeyFunctionTable,
      (Scaleform::GFx::ASStringNode *)&flags[3],
      v78,
      v84);
  }
  else
  {
    v32 = 0;
  }
  keyProto.pObject = v32;
  v94 = ASBuiltin_Key;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &v94,
    &keyProto);
  v33 = (Scaleform::GFx::AS2::MovieClipProto *)this->pHeap->Alloc(this->pHeap, 92, 0);
  if ( v33 )
    Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(v33, &sc, objProto.pObject, &objCtor);
  else
    v34 = 0;
  movieClipProto.pObject = v34;
  v94 = ASBuiltin_MovieClip;
  Scaleform::Hash<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>>::Add(
    &this->Prototypes,
    &v94,
    &movieClipProto);
  v35 = this->pGlobal.pObject;
  if ( v35 )
    v36 = &v35->Scaleform::GFx::AS2::ObjectInterface;
  else
    v36 = 0;
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (unsigned __int8 *)v32,
    &savedregs,
    v36,
    &sc,
    Scaleform::GFx::AS2::GFxAction_Global_StaticFunctions,
    0,
    v78);
  v37 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)&functionCtor,
    &sc,
    Scaleform::GFx::AS2::GAS_GlobalIMECommand);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v37->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    "imecommand",
    v38);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v39 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)&functionCtor,
    &sc,
    Scaleform::GFx::AS2::GAS_SetIMECandidateListStyle);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v39->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    "setIMECandidateListStyle",
    v40);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v41 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)&functionCtor,
    &sc,
    Scaleform::GFx::AS2::GAS_GetInputLanguage);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v41->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    "getInputLanguage",
    v42);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v43 = this->pGlobal.pObject;
  Scaleform::GFx::AS2::Value::Value(
    (Scaleform::GFx::AS2::Value *)&functionCtor,
    &sc,
    Scaleform::GFx::AS2::GAS_GetIMECandidateListStyle);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &v43->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    "getIMECandidateListStyle",
    v44);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v45 = this->pGlobal.pObject;
  functionCtor.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v88;
  flags[3].Flags = 0;
  LOBYTE(functionCtor.Function) = 8;
  v99 = 0;
  v88->RefCount = (v88->RefCount + 1) & 0x8FFFFFFF;
  pMovieRoot = this->pMovieRoot;
  *(_DWORD *)&functionCtor.Flags = 0;
  v45->SetMemberRaw(
    &v45->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
    (const Scaleform::GFx::AS2::Value *)&functionCtor,
    &flags[3]);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v47 = this->pGlobal.pObject;
  functionCtor.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v87;
  flags[3].Flags = 0;
  LOBYTE(functionCtor.Function) = 8;
  v99 = 0;
  v87->RefCount = (v87->RefCount + 1) & 0x8FFFFFFF;
  v48 = this->pMovieRoot;
  *(_DWORD *)&functionCtor.Flags = 0;
  v47->SetMemberRaw(
    &v47->Scaleform::GFx::AS2::ObjectInterface,
    &sc,
    (const Scaleform::GFx::ASString *)&v48->pASMovieRoot.pObject[9].pASSupport,
    (const Scaleform::GFx::AS2::Value *)&functionCtor,
    &flags[3]);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v49 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  flags[3].Flags = 0;
  LOBYTE(functionCtor.Function) = 8;
  v99 = 0;
  functionCtor.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v89;
  if ( v89 )
    v89->RefCount = (v89->RefCount + 1) & 0x8FFFFFFF;
  v50 = this->pMovieRoot;
  *(_DWORD *)&functionCtor.Flags = 0;
  v49->SetMemberRaw(
    v49,
    &sc,
    (const Scaleform::GFx::ASString *)&v50->pASMovieRoot.pObject[9].pMovieImpl,
    (const Scaleform::GFx::AS2::Value *)&functionCtor,
    &flags[3]);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  v51 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)key;
  v52 = &this->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface;
  flags[3].Flags = 0;
  LOBYTE(functionCtor.Function) = 8;
  v99 = 0;
  functionCtor.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)key;
  if ( key )
    *(_DWORD *)(key + 12) = (*(_DWORD *)(key + 12) + 1) & 0x8FFFFFFF;
  v53 = this->pMovieRoot;
  *(_DWORD *)&functionCtor.Flags = 0;
  v52->SetMemberRaw(
    v52,
    &sc,
    (const Scaleform::GFx::ASString *)&v53->pASMovieRoot.pObject[13].pMovieImpl,
    (const Scaleform::GFx::AS2::Value *)&functionCtor,
    &flags[3]);
  if ( LOBYTE(functionCtor.Function) >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&functionCtor);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<25,Scaleform::GFx::AS2::MathCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<2,Scaleform::GFx::AS2::ArrayCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<4,Scaleform::GFx::AS2::NumberCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<3,Scaleform::GFx::AS2::StringCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<5,Scaleform::GFx::AS2::BooleanCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<9,Scaleform::GFx::AS2::ButtonCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<29,Scaleform::GFx::AS2::MovieClipLoaderCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<31,Scaleform::GFx::AS2::GASLoadVarsLoaderCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<18,Scaleform::GFx::AS2::StageCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<21,Scaleform::GFx::AS2::SelectionCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<19,Scaleform::GFx::AS2::AsBroadcasterCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<27,Scaleform::GFx::AS2::MouseCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<10,Scaleform::GFx::AS2::TextFieldCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<32,Scaleform::GFx::AS2::TextFormatCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<43,Scaleform::GFx::AS2::TextSnapshotCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<20,Scaleform::GFx::AS2::DateCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<44,Scaleform::GFx::AS2::SharedObjectCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<154,Scaleform::GFx::AS2::AmpMarkerCtorFunction>(
    this,
    &sc,
    this->pGlobal.pObject);
  v54 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &sc,
          this->pGlobal.pObject,
          objProto.pObject,
          "flash.geom",
          v79);
  this->FlashGeomPackage = v54;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<12,Scaleform::GFx::AS2::TransformCtorFunction>(
    this,
    &sc,
    v54);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<13,Scaleform::GFx::AS2::GASMatrixCtorFunction>(
    this,
    &sc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<14,Scaleform::GFx::AS2::PointCtorFunction>(
    this,
    &sc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<15,Scaleform::GFx::AS2::RectangleCtorFunction>(
    this,
    &sc,
    this->FlashGeomPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<16,Scaleform::GFx::AS2::ColorTransformCtorFunction>(
    this,
    &sc,
    this->FlashGeomPackage);
  v55 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &sc,
          this->pGlobal.pObject,
          objProto.pObject,
          "System",
          v80);
  this->SystemPackage = v55;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<17,Scaleform::GFx::AS2::CapabilitiesCtorFunction>(
    this,
    &sc,
    v55);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<22,Scaleform::GFx::AS2::GASImeCtorFunction>(
    this,
    &sc,
    this->SystemPackage);
  v56 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &sc,
          this->pGlobal.pObject,
          objProto.pObject,
          "flash.external",
          v81);
  this->FlashExternalPackage = v56;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<28,Scaleform::GFx::AS2::ExternalInterfaceCtorFunction>(
    this,
    &sc,
    v56);
  v57 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &sc,
          this->pGlobal.pObject,
          objProto.pObject,
          "flash.display",
          v82);
  this->FlashDisplayPackage = v57;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<30,Scaleform::GFx::AS2::BitmapDataCtorFunction>(
    this,
    &sc,
    v57);
  v58 = Scaleform::GFx::AS2::GlobalContext::AddPackage(
          (char *)&savedregs,
          (int)v51,
          &sc,
          this->pGlobal.pObject,
          objProto.pObject,
          "flash.filters",
          v83);
  this->FlashFiltersPackage = v58;
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<37,Scaleform::GFx::AS2::BitmapFilterCtorFunction>(
    this,
    &sc,
    v58);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<38,Scaleform::GFx::AS2::DropShadowFilterCtorFunction>(
    this,
    &sc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<39,Scaleform::GFx::AS2::GlowFilterCtorFunction>(
    this,
    &sc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<40,Scaleform::GFx::AS2::BlurFilterCtorFunction>(
    this,
    &sc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<41,Scaleform::GFx::AS2::BevelFilterCtorFunction>(
    this,
    &sc,
    this->FlashFiltersPackage);
  Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<42,Scaleform::GFx::AS2::ColorMatrixFilterCtorFunction>(
    this,
    &sc,
    this->FlashFiltersPackage);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->StandardMemberMap);
  Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(this);
  v59 = this->pGlobal.pObject;
  visitor.__vftable = (Scaleform::GFx::AS2::GlobalContext::Init::__l4::MemberVisitor_vtbl *)&`Scaleform::GFx::AS2::GlobalContext::Init'::`4'::MemberVisitor::`vftable';
  if ( v59 )
    v59->RefCount = (v59->RefCount + 1) & 0x8FFFFFFF;
  v60 = this->pGlobal.pObject;
  visitor.obj.pObject = v59;
  visitor.psc = &sc;
  v60->VisitMembers(&v60->Scaleform::GFx::AS2::ObjectInterface, &sc, &visitor, 4u, 0);
  if ( visitor.obj.pObject )
  {
    v61 = visitor.obj.pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v61) != 0 )
    {
      v62 = visitor.obj.pObject;
      visitor.obj.pObject->RefCount = v61 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v62);
    }
  }
  visitor.__vftable = (Scaleform::GFx::AS2::GlobalContext::Init::__l4::MemberVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  if ( movieClipProto.pObject )
  {
    v63 = movieClipProto.pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v63) != 0 )
    {
      v64 = movieClipProto.pObject;
      movieClipProto.pObject->RefCount = v63 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v64);
    }
  }
  if ( keyProto.pObject )
  {
    v65 = keyProto.pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v65) != 0 )
    {
      v66 = keyProto.pObject;
      keyProto.pObject->RefCount = v65 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v66);
    }
  }
  if ( v51 )
  {
    v67 = v51->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v67) != 0 )
    {
      v51->RefCount = v67 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v51);
    }
  }
  v68 = v89;
  if ( v89 )
  {
    v69 = v89->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v69) != 0 )
    {
      v89->RefCount = v69 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v68);
    }
  }
  if ( functionProto.pObject )
  {
    v70 = functionProto.pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v70) != 0 )
    {
      v71 = functionProto.pObject;
      functionProto.pObject->RefCount = v70 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v71);
    }
  }
  if ( objProto.pObject )
  {
    v72 = objProto.pObject->RefCount;
    v73 = objProto.pObject;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v72) != 0 )
    {
      objProto.pObject->RefCount = v72 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v73);
    }
  }
  v74 = v87;
  v75 = v87->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v75) != 0 )
  {
    v87->RefCount = v75 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v74);
  }
  v76 = v88;
  v77 = v88->RefCount;
  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v77) != 0 )
  {
    v88->RefCount = v77 - 1;
    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v76);
  }
}
