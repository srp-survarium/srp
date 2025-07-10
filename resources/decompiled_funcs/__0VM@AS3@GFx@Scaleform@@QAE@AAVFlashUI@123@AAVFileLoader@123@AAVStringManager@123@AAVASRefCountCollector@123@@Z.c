void __thiscall Scaleform::GFx::AS3::VM::VM(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::FlashUI *_ui,
        Scaleform::GFx::AS3::FileLoader *loader,
        Scaleform::GFx::AS3::StringManager *sm,
        const Scaleform::GFx::AS3::Instances::fl::Namespace *gc)
{
  Scaleform::GFx::AS3::FlashUI *v5; // edx
  Scaleform::GFx::AS3::ASRefCountCollector *v7; // ecx
  Scaleform::GFx::AS3::FileLoader *v8; // eax
  Scaleform::MemoryHeap *v9; // eax
  Scaleform::GFx::AS3::XMLSupport *v10; // eax
  Scaleform::GFx::AS3::ASRefCountCollector *v11; // ecx
  Scaleform::GFx::AS3::ValueStack::Page *v12; // eax
  Scaleform::GFx::AS3::Value *Values; // eax
  Scaleform::GFx::AS3::VMAppDomain *p_RegisterFile; // edi
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v15; // eax
  const Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::MemoryHeap *v17; // edx
  Scaleform::GFx::AS3::VMAppDomain *v18; // eax
  Scaleform::MemoryHeap *v19; // ecx
  Scaleform::GFx::AS3::VMAppDomain *v20; // eax
  Scaleform::GFx::AS3::VMAppDomain *SystemDomain; // ecx
  Scaleform::MemoryHeap *v22; // eax
  Scaleform::MemoryHeap *v23; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v25; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v28; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v29; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v30; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v31; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v32; // eax
  Scaleform::GFx::AS3::StringManager *v33; // eax
  Scaleform::GFx::AS3::StringManager *v34; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  int (__thiscall *v36)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // eax
  Scaleform::GFx::AS3::VMAppDomain *v37; // ebp
  const Scaleform::GFx::ASString *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v40; // eax
  Scaleform::GFx::AS3::StringManager *v41; // eax
  Scaleform::GFx::AS3::StringManager *v42; // edi
  Scaleform::GFx::ASStringNode *v43; // ecx
  int (__thiscall *v44)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v45; // ebp
  const Scaleform::GFx::ASString *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v48; // eax
  Scaleform::GFx::AS3::StringManager *v49; // eax
  Scaleform::GFx::AS3::StringManager *v50; // edi
  Scaleform::GFx::ASStringNode *v51; // ecx
  int (__thiscall *v52)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v53; // ebp
  const Scaleform::GFx::ASString *v54; // eax
  Scaleform::GFx::ASStringNode *v55; // eax
  Scaleform::GFx::AS3::ClassTraits::Function *v56; // eax
  Scaleform::GFx::AS3::StringManager *v57; // eax
  Scaleform::GFx::AS3::StringManager *v58; // edi
  Scaleform::GFx::ASStringNode *v59; // ecx
  int (__thiscall *v60)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v61; // ebp
  const Scaleform::GFx::ASString *v62; // eax
  Scaleform::GFx::ASStringNode *v63; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v64; // eax
  Scaleform::GFx::AS3::StringManager *v65; // eax
  Scaleform::GFx::AS3::StringManager *v66; // edi
  Scaleform::GFx::ASStringNode *v67; // ecx
  int (__thiscall *v68)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v69; // ebp
  const Scaleform::GFx::ASString *v70; // eax
  Scaleform::GFx::ASStringNode *v71; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v72; // eax
  Scaleform::GFx::AS3::StringManager *v73; // eax
  Scaleform::GFx::AS3::StringManager *v74; // edi
  Scaleform::GFx::ASStringNode *v75; // ecx
  int (__thiscall *v76)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v77; // ebp
  const Scaleform::GFx::ASString *v78; // eax
  Scaleform::GFx::ASStringNode *v79; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v80; // eax
  Scaleform::GFx::AS3::StringManager *v81; // eax
  Scaleform::GFx::AS3::StringManager *v82; // edi
  Scaleform::GFx::ASStringNode *v83; // ecx
  int (__thiscall *v84)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v85; // ebp
  const Scaleform::GFx::ASString *v86; // eax
  Scaleform::GFx::ASStringNode *v87; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v88; // eax
  Scaleform::GFx::AS3::StringManager *v89; // eax
  Scaleform::GFx::AS3::StringManager *v90; // edi
  Scaleform::GFx::ASStringNode *v91; // ecx
  int (__thiscall *v92)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v93; // ebp
  const Scaleform::GFx::ASString *v94; // eax
  Scaleform::GFx::ASStringNode *v95; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::String *v96; // eax
  Scaleform::GFx::AS3::StringManager *v97; // eax
  Scaleform::GFx::AS3::StringManager *v98; // edi
  Scaleform::GFx::ASStringNode *v99; // ecx
  int (__thiscall *v100)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v101; // ebp
  const Scaleform::GFx::ASString *v102; // eax
  Scaleform::GFx::ASStringNode *v103; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Array *v104; // eax
  Scaleform::GFx::AS3::StringManager *v105; // eax
  Scaleform::GFx::AS3::StringManager *v106; // edi
  Scaleform::GFx::ASStringNode *v107; // ecx
  int (__thiscall *v108)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v109; // ebp
  const Scaleform::GFx::ASString *v110; // eax
  Scaleform::GFx::ASStringNode *v111; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::QName *v112; // eax
  Scaleform::GFx::AS3::StringManager *v113; // eax
  Scaleform::GFx::AS3::StringManager *v114; // edi
  Scaleform::GFx::ASStringNode *v115; // ecx
  int (__thiscall *v116)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v117; // ebp
  const Scaleform::GFx::ASString *v118; // eax
  Scaleform::GFx::ASStringNode *v119; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Catch *v120; // eax
  Scaleform::GFx::AS3::StringManager *v121; // eax
  Scaleform::GFx::AS3::StringManager *v122; // edi
  Scaleform::GFx::ASStringNode *v123; // ecx
  int (__thiscall *v124)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v125; // ebp
  const Scaleform::GFx::ASString *v126; // eax
  Scaleform::GFx::ASStringNode *v127; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v128; // eax
  Scaleform::GFx::AS3::StringManager *v129; // eax
  Scaleform::GFx::AS3::StringManager *v130; // edi
  Scaleform::GFx::ASStringNode *v131; // ecx
  int (__thiscall *v132)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v133; // ebp
  const Scaleform::GFx::ASString *v134; // eax
  Scaleform::GFx::ASStringNode *v135; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *v136; // eax
  Scaleform::GFx::AS3::StringManager *v137; // eax
  Scaleform::GFx::AS3::StringManager *v138; // edi
  Scaleform::GFx::ASStringNode *v139; // ecx
  int (__thiscall *v140)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v141; // ebp
  const Scaleform::GFx::ASString *v142; // eax
  Scaleform::GFx::ASStringNode *v143; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *v144; // eax
  Scaleform::GFx::AS3::StringManager *v145; // eax
  Scaleform::GFx::AS3::StringManager *v146; // edi
  Scaleform::GFx::ASStringNode *v147; // ecx
  int (__thiscall *v148)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v149; // ebp
  const Scaleform::GFx::ASString *v150; // eax
  Scaleform::GFx::ASStringNode *v151; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *v152; // eax
  Scaleform::GFx::AS3::StringManager *v153; // eax
  Scaleform::GFx::AS3::StringManager *v154; // edi
  Scaleform::GFx::ASStringNode *v155; // ecx
  int (__thiscall *v156)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v157; // ebp
  const Scaleform::GFx::ASString *v158; // eax
  Scaleform::GFx::ASStringNode *v159; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *v160; // eax
  Scaleform::GFx::AS3::StringManager *v161; // eax
  Scaleform::GFx::AS3::StringManager *v162; // edi
  Scaleform::GFx::ASStringNode *v163; // ecx
  int (__thiscall *v164)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v165; // ebp
  const Scaleform::GFx::ASString *v166; // eax
  Scaleform::GFx::ASStringNode *v167; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *v168; // eax
  Scaleform::GFx::AS3::StringManager *v169; // eax
  Scaleform::GFx::AS3::StringManager *v170; // edi
  Scaleform::GFx::ASStringNode *v171; // ecx
  int (__thiscall *v172)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v173; // ebp
  const Scaleform::GFx::ASString *v174; // eax
  Scaleform::GFx::ASStringNode *v175; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *v176; // eax
  Scaleform::GFx::AS3::StringManager *v177; // eax
  Scaleform::GFx::AS3::StringManager *v178; // edi
  Scaleform::GFx::ASStringNode *v179; // ecx
  int (__thiscall *v180)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v181; // ebp
  const Scaleform::GFx::ASString *v182; // eax
  Scaleform::GFx::ASStringNode *v183; // eax
  Scaleform::GFx::AS3::InstanceTraits::Anonimous *v184; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v185; // eax
  Scaleform::GFx::AS3::InstanceTraits::Void *v186; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v187; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v188; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v189; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v190; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v191; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v192; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v193; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v195; // edi
  Scaleform::GFx::AS3::Class *v196; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Function *v197; // edi
  Scaleform::GFx::AS3::Class *v198; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *p_pConstructor; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::StringManager *v201; // ecx
  unsigned int v202; // edi
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **Data; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v204; // edi
  Scaleform::GFx::AS3::ASRefCountCollector *v205; // eax
  unsigned int v206; // edi
  char *v207; // ebp
  const Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *v208; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v209; // ecx
  Scaleform::GFx::ASStringNode *v210; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v211; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits const > *p_pParent; // edi
  Scaleform::GFx::AS3::Traits *v213; // ecx
  unsigned int v214; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v215; // ecx
  Scaleform::GFx::AS3::Classes::ClassClass **v216; // edi
  Scaleform::GFx::AS3::Value::V2U v217; // [esp+148h] [ebp-4Ch]
  Scaleform::GFx::AS3::CallFrame other; // [esp+14Ch] [ebp-48h] BYREF

  v5 = _ui;
  v7 = (Scaleform::GFx::AS3::ASRefCountCollector *)gc;
  this->StringManagerRef = sm;
  v8 = loader;
  this->__vftable = (Scaleform::GFx::AS3::VM_vtbl *)&Scaleform::GFx::AS3::VM::`vftable';
  this->Initialized = 0;
  this->InDestructor = 0;
  this->GC.GC = v7;
  this->Loader = v8;
  this->UI = v5;
  this->InInitializer = 0;
  v9 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  this->MHeap = v9;
  v10 = (Scaleform::GFx::AS3::XMLSupport *)v9->Alloc(v9, 24u, 0);
  if ( v10 )
  {
    v11 = this->GC.GC;
    v10->RefCount = 1;
    v10->pRCCRaw = (unsigned int)v11;
    v10->__vftable = (Scaleform::GFx::AS3::XMLSupport_vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
    v10->Enabled = 0;
  }
  else
  {
    v10 = 0;
  }
  this->XMLSupport_.pObject = v10;
  this->OpStack.pCurrent = (Scaleform::GFx::AS3::Value *)-16;
  this->OpStack.pStack = 0;
  this->OpStack.pCurrentPage = 0;
  this->OpStack.pReserved = 0;
  v12 = Scaleform::GFx::AS3::ValueStack::NewPage(&this->OpStack, 0x40u);
  this->OpStack.pCurrentPage = v12;
  v12->pNext = 0;
  this->OpStack.pCurrentPage->pPrev = 0;
  this->OpStack.pCurrentPage->pCurrent = 0;
  Values = this->OpStack.pCurrentPage->Values;
  this->OpStack.pStack = Values;
  this->OpStack.pCurrent = Values - 1;
  Scaleform::GFx::AS3::ValueStack::Reserve(&this->OpStack, 1u);
  p_RegisterFile = (Scaleform::GFx::AS3::VMAppDomain *)&this->RegisterFile;
  this->RegisterFile.MaxReservedPageSize = 0;
  this->RegisterFile.ReservedNum = 0;
  this->RegisterFile.pRF = 0;
  this->RegisterFile.MaxAllocatedPageSize = 0;
  this->RegisterFile.pCurrentPage = 0;
  this->RegisterFile.pReserved = 0;
  v15 = Scaleform::GFx::AS3::ValueRegisterFile::NewPage(&this->RegisterFile, 0);
  this->RegisterFile.pCurrentPage = v15;
  v15->pNext = 0;
  this->RegisterFile.pCurrentPage->pPrev = 0;
  this->RegisterFile.pRF = this->RegisterFile.pCurrentPage->Values;
  MHeap = this->MHeap;
  this->ScopeStack.Data.Data = 0;
  this->ScopeStack.Data.Size = 0;
  this->ScopeStack.Data.Policy.Capacity = 0;
  this->ScopeStack.Data.pHeap = MHeap;
  this->HandleException = 0;
  this->ExceptionObj.Flags = 0;
  this->ExceptionObj.Bonus.pWeakProxy = 0;
  this->GlobalObjects.Data.Data = 0;
  this->GlobalObjects.Data.Size = 0;
  this->GlobalObjects.Data.Policy.Capacity = 0;
  v17 = this->MHeap;
  other.DiscardResult = 0;
  other.ACopy = 0;
  memset(&other.ScopeStackBaseInd, 0, 12);
  other.pHeap = v17;
  memset(&other.pFile, 0, 32);
  other.Invoker.Flags = 0;
  other.Invoker.Bonus.pWeakProxy = 0;
  this->CallStack.Size = 0;
  this->CallStack.NumPages = 0;
  this->CallStack.MaxPages = 0;
  this->CallStack.Pages = 0;
  Scaleform::GFx::AS3::CallFrame::CallFrame(&this->CallStack.DefaultValue, &other);
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  v18 = (Scaleform::GFx::AS3::VMAppDomain *)this->MHeap->Alloc(this->MHeap, 28, 0);
  if ( v18 )
  {
    v18->__vftable = (Scaleform::GFx::AS3::VMAppDomain_vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable';
    v19 = this->MHeap;
    v18->ClassTraitsSet.Entries.mHash.pTable = 0;
    v18->ClassTraitsSet.Entries.mHash.pHeap = v19;
    v18->ParentDomain = 0;
    v18->ChildDomains.Data.Data = 0;
    v18->ChildDomains.Data.Size = 0;
    v18->ChildDomains.Data.Policy.Capacity = 0;
  }
  else
  {
    v18 = 0;
  }
  this->SystemDomain = v18;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    v20 = (Scaleform::GFx::AS3::VMAppDomain *)this->MHeap->Alloc(this->MHeap, 28, 0);
    p_RegisterFile = v20;
    if ( v20 )
    {
      SystemDomain = this->SystemDomain;
      v20->__vftable = (Scaleform::GFx::AS3::VMAppDomain_vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable';
      v22 = this->MHeap;
      p_RegisterFile->ClassTraitsSet.Entries.mHash.pTable = 0;
      p_RegisterFile->ClassTraitsSet.Entries.mHash.pHeap = v22;
      p_RegisterFile->ParentDomain = 0;
      p_RegisterFile->ChildDomains.Data.Data = 0;
      p_RegisterFile->ChildDomains.Data.Size = 0;
      p_RegisterFile->ChildDomains.Data.Policy.Capacity = 0;
      if ( SystemDomain )
        Scaleform::GFx::AS3::VMAppDomain::AddChild(SystemDomain, p_RegisterFile);
      v18 = p_RegisterFile;
    }
    else
    {
      v18 = 0;
    }
  }
  v23 = this->MHeap;
  this->CurrentDomain = v18;
  v24 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v23->Alloc(v23, 56u, 0);
  if ( v24 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v24, this, NS_Public, (char *)&buf);
  else
    v25 = 0;
  this->PublicNamespace.pObject = v25;
  v26 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v26 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v26, this, NS_Public, (char *)Scaleform::GFx::AS3::NS_AS3);
  else
    v27 = 0;
  this->AS3Namespace.pObject = v27;
  v28 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v28 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
      v28,
      this,
      NS_Public,
      (char *)Scaleform::GFx::AS3::NS_Vector);
  else
    v29 = 0;
  this->VectorNamespace.pObject = v29;
  v30 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v30 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v30, this, NS_Public, (char *)Scaleform::GFx::AS3::NS_XML);
  else
    v31 = 0;
  this->XMLNamespace.pObject = v31;
  v32 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v32 )
  {
    Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(v32, (int)p_RegisterFile, this);
    v34 = v33;
  }
  else
  {
    v34 = 0;
  }
  pNode = v34->Builtins[25].pNode;
  v36 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)pNode->pData + 4);
  v37 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)pNode[4].pManager;
  v38 = (const Scaleform::GFx::ASString *)v36(pNode, &_ui);
  sm = v34;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v37->ClassTraitsSet,
    v38,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v39 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  this->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v34;
  v40 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v40 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v40, this);
    v42 = v41;
  }
  else
  {
    v42 = 0;
  }
  v43 = v42->Builtins[25].pNode;
  v44 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v43->pData + 4);
  v45 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v43[4].pManager;
  v46 = (const Scaleform::GFx::ASString *)v44(v43, &_ui);
  sm = v42;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v45->ClassTraitsSet,
    v46,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v47 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  this->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v42;
  v48 = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v48 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Namespace::Namespace(v48, this);
    v50 = v49;
  }
  else
  {
    v50 = 0;
  }
  v51 = v50->Builtins[25].pNode;
  v52 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v51->pData + 4);
  v53 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v51[4].pManager;
  v54 = (const Scaleform::GFx::ASString *)v52(v51, &_ui);
  sm = v50;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v53->ClassTraitsSet,
    v54,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v55 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  this->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)v50;
  v56 = (Scaleform::GFx::AS3::ClassTraits::Function *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v56 )
  {
    Scaleform::GFx::AS3::ClassTraits::Function::Function(v56, this, &Scaleform::GFx::AS3::fl::FunctionCI);
    v58 = v57;
  }
  else
  {
    v58 = 0;
  }
  v59 = v58->Builtins[25].pNode;
  v60 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v59->pData + 4);
  v61 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v59[4].pManager;
  v62 = (const Scaleform::GFx::ASString *)v60(v59, &_ui);
  sm = v58;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v61->ClassTraitsSet,
    v62,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v63 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v63->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  this->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)v58;
  v64 = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v64 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Boolean::Boolean(v64, this);
    v66 = v65;
  }
  else
  {
    v66 = 0;
  }
  v67 = v66->Builtins[25].pNode;
  v68 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v67->pData + 4);
  v69 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v67[4].pManager;
  v70 = (const Scaleform::GFx::ASString *)v68(v67, &_ui);
  sm = v66;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v69->ClassTraitsSet,
    v70,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v71 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v71->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v71);
  this->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)v66;
  v72 = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v72 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Number::Number(v72, this);
    v74 = v73;
  }
  else
  {
    v74 = 0;
  }
  v75 = v74->Builtins[25].pNode;
  v76 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v75->pData + 4);
  v77 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v75[4].pManager;
  v78 = (const Scaleform::GFx::ASString *)v76(v75, &_ui);
  sm = v74;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v77->ClassTraitsSet,
    v78,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v79 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v79->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v79);
  this->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)v74;
  v80 = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v80 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::int_::int_(v80, this);
    v82 = v81;
  }
  else
  {
    v82 = 0;
  }
  v83 = v82->Builtins[25].pNode;
  v84 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v83->pData + 4);
  v85 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v83[4].pManager;
  v86 = (const Scaleform::GFx::ASString *)v84(v83, &_ui);
  sm = v82;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v85->ClassTraitsSet,
    v86,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v87 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v87->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v87);
  this->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)v82;
  v88 = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v88 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::uint::uint(v88, this);
    v90 = v89;
  }
  else
  {
    v90 = 0;
  }
  v91 = v90->Builtins[25].pNode;
  v92 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v91->pData + 4);
  v93 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v91[4].pManager;
  v94 = (const Scaleform::GFx::ASString *)v92(v91, &_ui);
  sm = v90;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v93->ClassTraitsSet,
    v94,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v95 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v95->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v95);
  this->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)v90;
  v96 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v96 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::String::String(v96, this);
    v98 = v97;
  }
  else
  {
    v98 = 0;
  }
  v99 = v98->Builtins[25].pNode;
  v100 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v99->pData + 4);
  v101 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v99[4].pManager;
  v102 = (const Scaleform::GFx::ASString *)v100(v99, &_ui);
  sm = v98;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v101->ClassTraitsSet,
    v102,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v103 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v103->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v103);
  this->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)v98;
  v104 = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v104 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Array::Array(v104, this);
    v106 = v105;
  }
  else
  {
    v106 = 0;
  }
  v107 = v106->Builtins[25].pNode;
  v108 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v107->pData + 4);
  v109 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v107[4].pManager;
  v110 = (const Scaleform::GFx::ASString *)v108(v107, &_ui);
  sm = v106;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v109->ClassTraitsSet,
    v110,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v111 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v111->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v111);
  this->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)v106;
  v112 = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v112 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::QName::QName(v112, this);
    v114 = v113;
  }
  else
  {
    v114 = 0;
  }
  v115 = v114->Builtins[25].pNode;
  v116 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v115->pData + 4);
  v117 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v115[4].pManager;
  v118 = (const Scaleform::GFx::ASString *)v116(v115, &_ui);
  sm = v114;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v117->ClassTraitsSet,
    v118,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v119 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v119->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v119);
  this->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)v114;
  v120 = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v120 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Catch::Catch(v120, this);
    v122 = v121;
  }
  else
  {
    v122 = 0;
  }
  v123 = v122->Builtins[25].pNode;
  v124 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v123->pData + 4);
  v125 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v123[4].pManager;
  v126 = (const Scaleform::GFx::ASString *)v124(v123, &_ui);
  sm = v122;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v125->ClassTraitsSet,
    v126,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v127 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v127->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v127);
  this->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)v122;
  v128 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v128 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::Vector(v128, this);
    v130 = v129;
  }
  else
  {
    v130 = 0;
  }
  v131 = v130->Builtins[25].pNode;
  v132 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v131->pData + 4);
  v133 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v131[4].pManager;
  v134 = (const Scaleform::GFx::ASString *)v132(v131, &_ui);
  sm = v130;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v133->ClassTraitsSet,
    v134,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v135 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v135->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v135);
  this->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)v130;
  v136 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v136 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int::Vector_int(v136, this);
    v138 = v137;
  }
  else
  {
    v138 = 0;
  }
  v139 = v138->Builtins[25].pNode;
  v140 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v139->pData + 4);
  v141 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v139[4].pManager;
  v142 = (const Scaleform::GFx::ASString *)v140(v139, &_ui);
  sm = v138;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v141->ClassTraitsSet,
    v142,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v143 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v143->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v143);
  this->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v138;
  v144 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v144 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint::Vector_uint(v144, this);
    v146 = v145;
  }
  else
  {
    v146 = 0;
  }
  v147 = v146->Builtins[25].pNode;
  v148 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v147->pData + 4);
  v149 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v147[4].pManager;
  v150 = (const Scaleform::GFx::ASString *)v148(v147, &_ui);
  sm = v146;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v149->ClassTraitsSet,
    v150,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v151 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v151->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v151);
  this->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)v146;
  v152 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v152 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::Vector_double(v152, this);
    v154 = v153;
  }
  else
  {
    v154 = 0;
  }
  v155 = v154->Builtins[25].pNode;
  v156 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v155->pData + 4);
  v157 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v155[4].pManager;
  v158 = (const Scaleform::GFx::ASString *)v156(v155, &_ui);
  sm = v154;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v157->ClassTraitsSet,
    v158,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v159 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v159->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v159);
  this->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)v154;
  v160 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v160 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::Vector_String(v160, this);
    v162 = v161;
  }
  else
  {
    v162 = 0;
  }
  v163 = v162->Builtins[25].pNode;
  v164 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v163->pData + 4);
  v165 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v163[4].pManager;
  v166 = (const Scaleform::GFx::ASString *)v164(v163, &_ui);
  sm = v162;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v165->ClassTraitsSet,
    v166,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v167 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v167->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v167);
  this->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)v162;
  v168 = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v168 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::ApplicationDomain(v168, this);
    v170 = v169;
  }
  else
  {
    v170 = 0;
  }
  v171 = v170->Builtins[25].pNode;
  v172 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v171->pData + 4);
  v173 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v171[4].pManager;
  v174 = (const Scaleform::GFx::ASString *)v172(v171, &_ui);
  sm = v170;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v173->ClassTraitsSet,
    v174,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v175 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v175->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v175);
  this->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)v170;
  v176 = (Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v176 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_system::Domain::Domain(v176, this);
    v178 = v177;
  }
  else
  {
    v178 = 0;
  }
  v179 = v178->Builtins[25].pNode;
  v180 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v179->pData + 4);
  v181 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v179[4].pManager;
  v182 = (const Scaleform::GFx::ASString *)v180(v179, &_ui);
  sm = v178;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v181->ClassTraitsSet,
    v182,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v183 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v183->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v183);
  this->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *)v178;
  v184 = (Scaleform::GFx::AS3::InstanceTraits::Anonimous *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v184 )
    Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(v184, this);
  else
    v185 = 0;
  this->TraitsNull.pObject = v185;
  v186 = (Scaleform::GFx::AS3::InstanceTraits::Void *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v186 )
    Scaleform::GFx::AS3::InstanceTraits::Void::Void(v186, this);
  else
    v187 = 0;
  this->TraitsVoid.pObject = v187;
  v188 = (Scaleform::GFx::AS3::InstanceTraits::Function *)this->MHeap->Alloc(this->MHeap, 132, 0);
  if ( v188 )
    Scaleform::GFx::AS3::InstanceTraits::Function::Function(v188, this, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  else
    v189 = 0;
  this->NoFunctionTraits.pObject = v189;
  this->DefXMLNamespace.pObject = 0;
  v190 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v190 )
    Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v190, this);
  else
    v191 = 0;
  this->TraitaGlobalObject.pObject = v191;
  v192 = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)this->MHeap->Alloc(this->MHeap, 152, 0);
  if ( v192 )
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GlobalObjectCPP(v192, this, this->TraitaGlobalObject.pObject);
  else
    v193 = 0;
  this->GlobalObject.pObject = v193;
  this->GlobalObjectValue.Flags = 0;
  this->GlobalObjectValue.Bonus.pWeakProxy = 0;
  pObject = this->GlobalObject.pObject;
  this->GlobalObjectValue.Flags = this->GlobalObjectValue.Flags & 0xFFFFFFE0 | 0xC;
  this->GlobalObjectValue.value.VS._1.VInt = (int)pObject;
  this->GlobalObjectValue.value.VS._2 = v217;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->VMAbcFilesWeak.Data.Data = 0;
  this->VMAbcFilesWeak.Data.Size = 0;
  this->VMAbcFilesWeak.Data.Policy.Capacity = 0;
  Scaleform::GFx::AS3::VM::EnableXMLSupport(this, (int)v181);
  v195 = this->TraitsFunction.pObject->ITraits.pObject;
  if ( !v195->pConstructor.pObject )
    v195->InitOnDemand(v195);
  v196 = v195->pConstructor.pObject;
  if ( v196 )
    v196->RefCount = (v196->RefCount + 1) & 0x8FBFFFFF;
  v197 = this->NoFunctionTraits.pObject;
  v198 = v197->pConstructor.pObject;
  p_pConstructor = &v197->pConstructor;
  if ( v196 != v198 )
  {
    if ( v198 )
    {
      if ( ((unsigned __int8)v198 & 1) != 0 )
      {
        p_pConstructor->pObject = (Scaleform::GFx::AS3::Class *)((char *)v198 - 1);
      }
      else
      {
        RefCount = v198->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v198->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v198);
        }
      }
    }
    p_pConstructor->pObject = v196;
  }
  v201 = (Scaleform::GFx::AS3::StringManager *)this->GlobalObject.pObject;
  this->Initialized = 1;
  v202 = this->GlobalObjects.Data.Size + 1;
  sm = v201;
  if ( v202 >= this->GlobalObjects.Data.Size )
  {
    if ( v202 >= this->GlobalObjects.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
        &this->GlobalObjects,
        v202 + (v202 >> 2));
  }
  else if ( v202 < this->GlobalObjects.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
      &this->GlobalObjects,
      v202);
  }
  Data = this->GlobalObjects.Data.Data;
  this->GlobalObjects.Data.Size = v202;
  v204 = &Data[v202 - 1];
  if ( v204 )
    *v204 = (Scaleform::GFx::AS3::Instances::fl::GlobalObject *)sm;
  v205 = (Scaleform::GFx::AS3::ASRefCountCollector *)this->Loader->GetSize(this->Loader);
  v206 = 0;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v205;
  if ( v205 )
  {
    v207 = (char *)(&v205[-1].SuspendCnt + 3);
    do
    {
      v208 = this->Loader->GetFile(this->Loader, v206);
      Scaleform::GFx::AS3::VM::LoadFile(
        this,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&sm,
        v208,
        this->CurrentDomain,
        v206 == (_DWORD)v207);
      v209 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)sm;
      if ( sm )
      {
        if ( ((unsigned __int8)sm & 1) != 0 )
        {
          sm = (Scaleform::GFx::AS3::StringManager *)((char *)sm - 1);
        }
        else
        {
          v210 = sm->Builtins[4].pNode;
          if ( ((unsigned int)&byte_3FFFFF & (unsigned int)v210) != 0 )
          {
            sm->Builtins[4].pNode = (Scaleform::GFx::ASStringNode *)((char *)v210 - 1);
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v209);
          }
        }
      }
      ++v206;
    }
    while ( v206 < (unsigned int)gc );
  }
  v211 = this->TraitsObject.pObject;
  p_pParent = &this->TraitsClassClass.pObject->pParent;
  if ( v211 != p_pParent->pObject )
  {
    if ( v211 )
      v211->RefCount = (v211->RefCount + 1) & 0x8FBFFFFF;
    v213 = (Scaleform::GFx::AS3::Traits *)p_pParent->pObject;
    if ( p_pParent->pObject )
    {
      if ( ((unsigned __int8)v213 & 1) != 0 )
      {
        p_pParent->pObject = (Scaleform::GFx::AS3::Traits *)((char *)v213 - 1);
      }
      else
      {
        v214 = v213->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v214) != 0 )
        {
          v213->RefCount = v214 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v213);
        }
      }
    }
    p_pParent->pObject = v211;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsClassClass.pObject);
  v215 = this->TraitsClassClass.pObject;
  v216 = (Scaleform::GFx::AS3::Classes::ClassClass **)v215->ITraits.pObject;
  if ( !v216[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v216)[1]._pRCC)(v215->ITraits.pObject);
  Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(v216[17]);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsObject.pObject);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsNamespace.pObject);
}
