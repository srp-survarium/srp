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
  Scaleform::GFx::AS3::VMAppDomain *p_RegisterFile; // edi
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v13; // eax
  const Scaleform::MemoryHeap *MHeap; // eax
  Scaleform::MemoryHeap *v15; // eax
  Scaleform::MemoryHeap *v16; // ecx
  Scaleform::GFx::AS3::VMAppDomain *v17; // eax
  Scaleform::MemoryHeap *v18; // ecx
  Scaleform::GFx::AS3::VMAppDomain *v19; // eax
  Scaleform::GFx::AS3::VMAppDomain *SystemDomain; // ecx
  Scaleform::MemoryHeap *v21; // eax
  Scaleform::MemoryHeap *v22; // ecx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v23; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v24; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v25; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v26; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v27; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v28; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v29; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v30; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v31; // eax
  Scaleform::GFx::AS3::StringManager *v32; // eax
  Scaleform::GFx::AS3::StringManager *v33; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  int (__thiscall *v35)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // eax
  Scaleform::GFx::AS3::VMAppDomain *v36; // ebp
  const Scaleform::GFx::ASString *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v39; // eax
  Scaleform::GFx::AS3::StringManager *v40; // eax
  Scaleform::GFx::AS3::StringManager *v41; // edi
  Scaleform::GFx::ASStringNode *v42; // ecx
  int (__thiscall *v43)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v44; // ebp
  const Scaleform::GFx::ASString *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v47; // eax
  Scaleform::GFx::AS3::StringManager *v48; // eax
  Scaleform::GFx::AS3::StringManager *v49; // edi
  Scaleform::GFx::ASStringNode *v50; // ecx
  int (__thiscall *v51)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v52; // ebp
  const Scaleform::GFx::ASString *v53; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  Scaleform::GFx::AS3::ClassTraits::Function *v55; // eax
  Scaleform::GFx::AS3::StringManager *v56; // eax
  Scaleform::GFx::AS3::StringManager *v57; // edi
  Scaleform::GFx::ASStringNode *v58; // ecx
  int (__thiscall *v59)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v60; // ebp
  const Scaleform::GFx::ASString *v61; // eax
  Scaleform::GFx::ASStringNode *v62; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v63; // eax
  Scaleform::GFx::AS3::StringManager *v64; // eax
  Scaleform::GFx::AS3::StringManager *v65; // edi
  Scaleform::GFx::ASStringNode *v66; // ecx
  int (__thiscall *v67)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v68; // ebp
  const Scaleform::GFx::ASString *v69; // eax
  Scaleform::GFx::ASStringNode *v70; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v71; // eax
  Scaleform::GFx::AS3::StringManager *v72; // eax
  Scaleform::GFx::AS3::StringManager *v73; // edi
  Scaleform::GFx::ASStringNode *v74; // ecx
  int (__thiscall *v75)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v76; // ebp
  const Scaleform::GFx::ASString *v77; // eax
  Scaleform::GFx::ASStringNode *v78; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v79; // eax
  Scaleform::GFx::AS3::StringManager *v80; // eax
  Scaleform::GFx::AS3::StringManager *v81; // edi
  Scaleform::GFx::ASStringNode *v82; // ecx
  int (__thiscall *v83)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v84; // ebp
  const Scaleform::GFx::ASString *v85; // eax
  Scaleform::GFx::ASStringNode *v86; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v87; // eax
  Scaleform::GFx::AS3::StringManager *v88; // eax
  Scaleform::GFx::AS3::StringManager *v89; // edi
  Scaleform::GFx::ASStringNode *v90; // ecx
  int (__thiscall *v91)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v92; // ebp
  const Scaleform::GFx::ASString *v93; // eax
  Scaleform::GFx::ASStringNode *v94; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::String *v95; // eax
  Scaleform::GFx::AS3::StringManager *v96; // eax
  Scaleform::GFx::AS3::StringManager *v97; // edi
  Scaleform::GFx::ASStringNode *v98; // ecx
  int (__thiscall *v99)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v100; // ebp
  const Scaleform::GFx::ASString *v101; // eax
  Scaleform::GFx::ASStringNode *v102; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Array *v103; // eax
  Scaleform::GFx::AS3::StringManager *v104; // eax
  Scaleform::GFx::AS3::StringManager *v105; // edi
  Scaleform::GFx::ASStringNode *v106; // ecx
  int (__thiscall *v107)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v108; // ebp
  const Scaleform::GFx::ASString *v109; // eax
  Scaleform::GFx::ASStringNode *v110; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::QName *v111; // eax
  Scaleform::GFx::AS3::StringManager *v112; // eax
  Scaleform::GFx::AS3::StringManager *v113; // edi
  Scaleform::GFx::ASStringNode *v114; // ecx
  int (__thiscall *v115)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v116; // ebp
  const Scaleform::GFx::ASString *v117; // eax
  Scaleform::GFx::ASStringNode *v118; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Catch *v119; // eax
  Scaleform::GFx::AS3::StringManager *v120; // eax
  Scaleform::GFx::AS3::StringManager *v121; // edi
  Scaleform::GFx::ASStringNode *v122; // ecx
  int (__thiscall *v123)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v124; // ebp
  const Scaleform::GFx::ASString *v125; // eax
  Scaleform::GFx::ASStringNode *v126; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v127; // eax
  Scaleform::GFx::AS3::StringManager *v128; // eax
  Scaleform::GFx::AS3::StringManager *v129; // edi
  Scaleform::GFx::ASStringNode *v130; // ecx
  int (__thiscall *v131)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v132; // ebp
  const Scaleform::GFx::ASString *v133; // eax
  Scaleform::GFx::ASStringNode *v134; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *v135; // eax
  Scaleform::GFx::AS3::StringManager *v136; // eax
  Scaleform::GFx::AS3::StringManager *v137; // edi
  Scaleform::GFx::ASStringNode *v138; // ecx
  int (__thiscall *v139)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v140; // ebp
  const Scaleform::GFx::ASString *v141; // eax
  Scaleform::GFx::ASStringNode *v142; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *v143; // eax
  Scaleform::GFx::AS3::StringManager *v144; // eax
  Scaleform::GFx::AS3::StringManager *v145; // edi
  Scaleform::GFx::ASStringNode *v146; // ecx
  int (__thiscall *v147)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v148; // ebp
  const Scaleform::GFx::ASString *v149; // eax
  Scaleform::GFx::ASStringNode *v150; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *v151; // eax
  Scaleform::GFx::AS3::StringManager *v152; // eax
  Scaleform::GFx::AS3::StringManager *v153; // edi
  Scaleform::GFx::ASStringNode *v154; // ecx
  int (__thiscall *v155)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v156; // ebp
  const Scaleform::GFx::ASString *v157; // eax
  Scaleform::GFx::ASStringNode *v158; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *v159; // eax
  Scaleform::GFx::AS3::StringManager *v160; // eax
  Scaleform::GFx::AS3::StringManager *v161; // edi
  Scaleform::GFx::ASStringNode *v162; // ecx
  int (__thiscall *v163)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v164; // ebp
  const Scaleform::GFx::ASString *v165; // eax
  Scaleform::GFx::ASStringNode *v166; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *v167; // eax
  Scaleform::GFx::AS3::StringManager *v168; // eax
  Scaleform::GFx::AS3::StringManager *v169; // edi
  Scaleform::GFx::ASStringNode *v170; // ecx
  int (__thiscall *v171)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v172; // ebp
  const Scaleform::GFx::ASString *v173; // eax
  Scaleform::GFx::ASStringNode *v174; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *v175; // eax
  Scaleform::GFx::AS3::StringManager *v176; // eax
  Scaleform::GFx::AS3::StringManager *v177; // edi
  Scaleform::GFx::ASStringNode *v178; // ecx
  int (__thiscall *v179)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **); // edx
  Scaleform::GFx::AS3::VMAppDomain *v180; // ebp
  const Scaleform::GFx::ASString *v181; // eax
  Scaleform::GFx::ASStringNode *v182; // eax
  Scaleform::GFx::AS3::InstanceTraits::Anonimous *v183; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v184; // eax
  Scaleform::GFx::AS3::InstanceTraits::Void *v185; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v186; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v187; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v188; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v189; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v190; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v191; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *v192; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *pObject; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v194; // edi
  Scaleform::GFx::AS3::Class *v195; // ebp
  Scaleform::GFx::AS3::InstanceTraits::Function *v196; // edi
  Scaleform::GFx::AS3::Class *v197; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Class> *p_pConstructor; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::StringManager *v200; // ecx
  unsigned int v201; // edi
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **Data; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObject **v203; // edi
  Scaleform::GFx::AS3::ASRefCountCollector *v204; // eax
  unsigned int v205; // edi
  char *v206; // ebp
  const Scaleform::Ptr<Scaleform::GFx::AS3::Abc::File> *v207; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v208; // ecx
  Scaleform::GFx::ASStringNode *v209; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v210; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Traits const > *p_pParent; // edi
  const Scaleform::GFx::AS3::Traits *v212; // ecx
  unsigned int v213; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v214; // ecx
  Scaleform::GFx::AS3::Classes::ClassClass **v215; // edi
  Scaleform::GFx::AS3::Value::V2U v216; // [esp+148h] [ebp-64h]
  Scaleform::GFx::AS3::CallFrame other; // [esp+14Ch] [ebp-60h] BYREF

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
  Scaleform::GFx::AS3::ValueStack::ValueStack(&this->OpStack);
  p_RegisterFile = (Scaleform::GFx::AS3::VMAppDomain *)&this->RegisterFile;
  this->RegisterFile.ReservedNum = 0;
  this->RegisterFile.pRF = 0;
  this->RegisterFile.MaxReservedPageSize = 0;
  this->RegisterFile.MaxAllocatedPageSize = 0;
  this->RegisterFile.pCurrentPage = 0;
  this->RegisterFile.pReserved = 0;
  v13 = Scaleform::GFx::AS3::ValueRegisterFile::NewPage(&this->RegisterFile, 0);
  this->RegisterFile.pCurrentPage = v13;
  v13->pNext = 0;
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
  v15 = this->MHeap;
  other.DiscardResult = 0;
  other.ACopy = 0;
  other.RegisteredFunction = 0;
  memset(&other.ScopeStackBaseInd, 0, 12);
  other.pHeap = v15;
  memset(&other.pFile, 0, 34);
  memset(&other.Name, 0, 12);
  memset(&other.StartTicks, 0, 16);
  this->CallStack.Size = 0;
  this->CallStack.NumPages = 0;
  this->CallStack.MaxPages = 0;
  this->CallStack.Pages = 0;
  Scaleform::GFx::AS3::CallFrame::CallFrame(&this->CallStack.DefaultValue, &other);
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&other);
  v16 = this->MHeap;
  LODWORD(this->ActiveLineTimestamp) = 0;
  HIDWORD(this->ActiveLineTimestamp) = 0;
  v17 = (Scaleform::GFx::AS3::VMAppDomain *)v16->Alloc(v16, 28u, 0);
  if ( v17 )
  {
    v17->__vftable = (Scaleform::GFx::AS3::VMAppDomain_vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable';
    v18 = this->MHeap;
    v17->ClassTraitsSet.Entries.mHash.pTable = 0;
    v17->ClassTraitsSet.Entries.mHash.pHeap = v18;
    v17->ParentDomain = 0;
    v17->ChildDomains.Data.Data = 0;
    v17->ChildDomains.Data.Size = 0;
    v17->ChildDomains.Data.Policy.Capacity = 0;
  }
  else
  {
    v17 = 0;
  }
  this->SystemDomain = v17;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    v19 = (Scaleform::GFx::AS3::VMAppDomain *)this->MHeap->Alloc(this->MHeap, 28, 0);
    p_RegisterFile = v19;
    if ( v19 )
    {
      SystemDomain = this->SystemDomain;
      v19->__vftable = (Scaleform::GFx::AS3::VMAppDomain_vtbl *)&Scaleform::GFx::AS3::VMAppDomain::`vftable';
      v21 = this->MHeap;
      p_RegisterFile->ClassTraitsSet.Entries.mHash.pTable = 0;
      p_RegisterFile->ClassTraitsSet.Entries.mHash.pHeap = v21;
      p_RegisterFile->ParentDomain = 0;
      p_RegisterFile->ChildDomains.Data.Data = 0;
      p_RegisterFile->ChildDomains.Data.Size = 0;
      p_RegisterFile->ChildDomains.Data.Policy.Capacity = 0;
      if ( SystemDomain )
        Scaleform::GFx::AS3::VMAppDomain::AddChild(SystemDomain, p_RegisterFile);
      v17 = p_RegisterFile;
    }
    else
    {
      v17 = 0;
    }
  }
  v22 = this->MHeap;
  this->CurrentDomain = v17;
  v23 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)v22->Alloc(v22, 56u, 0);
  if ( v23 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v23, this, NS_Public, (char *)uri);
  else
    v24 = 0;
  this->PublicNamespace.pObject = v24;
  v25 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v25 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v25, this, NS_Public, (char *)Scaleform::GFx::AS3::NS_AS3);
  else
    v26 = 0;
  this->AS3Namespace.pObject = v26;
  v27 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v27 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
      v27,
      this,
      NS_Public,
      (char *)Scaleform::GFx::AS3::NS_Vector);
  else
    v28 = 0;
  this->VectorNamespace.pObject = v28;
  v29 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 56, 0);
  if ( v29 )
    Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(v29, this, NS_Public, (char *)Scaleform::GFx::AS3::NS_XML);
  else
    v30 = 0;
  this->XMLNamespace.pObject = v30;
  v31 = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v31 )
  {
    Scaleform::GFx::AS3::ClassTraits::ClassClass::ClassClass(v31, (int)p_RegisterFile, this);
    v33 = v32;
  }
  else
  {
    v33 = 0;
  }
  pNode = v33->Builtins[25].pNode;
  v35 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)pNode->pData + 7);
  v36 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)pNode[4].pManager;
  v37 = (const Scaleform::GFx::ASString *)v35(pNode, &_ui);
  sm = v33;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v36->ClassTraitsSet,
    v37,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v38 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  this->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)v33;
  v39 = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v39 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Object::Object(v39, this);
    v41 = v40;
  }
  else
  {
    v41 = 0;
  }
  v42 = v41->Builtins[25].pNode;
  v43 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v42->pData + 7);
  v44 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v42[4].pManager;
  v45 = (const Scaleform::GFx::ASString *)v43(v42, &_ui);
  sm = v41;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v44->ClassTraitsSet,
    v45,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v46 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  this->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)v41;
  v47 = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v47 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Namespace::Namespace(v47, this);
    v49 = v48;
  }
  else
  {
    v49 = 0;
  }
  v50 = v49->Builtins[25].pNode;
  v51 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v50->pData + 7);
  v52 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v50[4].pManager;
  v53 = (const Scaleform::GFx::ASString *)v51(v50, &_ui);
  sm = v49;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v52->ClassTraitsSet,
    v53,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v54 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  this->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)v49;
  v55 = (Scaleform::GFx::AS3::ClassTraits::Function *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v55 )
  {
    Scaleform::GFx::AS3::ClassTraits::Function::Function(v55, this, &Scaleform::GFx::AS3::fl::FunctionCI);
    v57 = v56;
  }
  else
  {
    v57 = 0;
  }
  v58 = v57->Builtins[25].pNode;
  v59 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v58->pData + 7);
  v60 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v58[4].pManager;
  v61 = (const Scaleform::GFx::ASString *)v59(v58, &_ui);
  sm = v57;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v60->ClassTraitsSet,
    v61,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v62 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v62->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v62);
  this->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)v57;
  v63 = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v63 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Boolean::Boolean(v63, this);
    v65 = v64;
  }
  else
  {
    v65 = 0;
  }
  v66 = v65->Builtins[25].pNode;
  v67 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v66->pData + 7);
  v68 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v66[4].pManager;
  v69 = (const Scaleform::GFx::ASString *)v67(v66, &_ui);
  sm = v65;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v68->ClassTraitsSet,
    v69,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v70 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v70->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v70);
  this->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)v65;
  v71 = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v71 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Number::Number(v71, this);
    v73 = v72;
  }
  else
  {
    v73 = 0;
  }
  v74 = v73->Builtins[25].pNode;
  v75 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v74->pData + 7);
  v76 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v74[4].pManager;
  v77 = (const Scaleform::GFx::ASString *)v75(v74, &_ui);
  sm = v73;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v76->ClassTraitsSet,
    v77,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v78 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v78->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v78);
  this->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)v73;
  v79 = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v79 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::int_::int_(v79, this);
    v81 = v80;
  }
  else
  {
    v81 = 0;
  }
  v82 = v81->Builtins[25].pNode;
  v83 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v82->pData + 7);
  v84 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v82[4].pManager;
  v85 = (const Scaleform::GFx::ASString *)v83(v82, &_ui);
  sm = v81;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v84->ClassTraitsSet,
    v85,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v86 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v86->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v86);
  this->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)v81;
  v87 = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v87 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::uint::uint(v87, this);
    v89 = v88;
  }
  else
  {
    v89 = 0;
  }
  v90 = v89->Builtins[25].pNode;
  v91 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v90->pData + 7);
  v92 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v90[4].pManager;
  v93 = (const Scaleform::GFx::ASString *)v91(v90, &_ui);
  sm = v89;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v92->ClassTraitsSet,
    v93,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v94 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v94->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v94);
  this->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)v89;
  v95 = (Scaleform::GFx::AS3::ClassTraits::fl::String *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v95 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::String::String(v95, this);
    v97 = v96;
  }
  else
  {
    v97 = 0;
  }
  v98 = v97->Builtins[25].pNode;
  v99 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v98->pData + 7);
  v100 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v98[4].pManager;
  v101 = (const Scaleform::GFx::ASString *)v99(v98, &_ui);
  sm = v97;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v100->ClassTraitsSet,
    v101,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v102 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v102->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v102);
  this->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)v97;
  v103 = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v103 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Array::Array(v103, this);
    v105 = v104;
  }
  else
  {
    v105 = 0;
  }
  v106 = v105->Builtins[25].pNode;
  v107 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v106->pData + 7);
  v108 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v106[4].pManager;
  v109 = (const Scaleform::GFx::ASString *)v107(v106, &_ui);
  sm = v105;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v108->ClassTraitsSet,
    v109,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v110 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v110->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v110);
  this->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)v105;
  v111 = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v111 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::QName::QName(v111, this);
    v113 = v112;
  }
  else
  {
    v113 = 0;
  }
  v114 = v113->Builtins[25].pNode;
  v115 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v114->pData + 7);
  v116 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v114[4].pManager;
  v117 = (const Scaleform::GFx::ASString *)v115(v114, &_ui);
  sm = v113;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v116->ClassTraitsSet,
    v117,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v118 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v118->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v118);
  this->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)v113;
  v119 = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v119 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl::Catch::Catch(v119, this);
    v121 = v120;
  }
  else
  {
    v121 = 0;
  }
  v122 = v121->Builtins[25].pNode;
  v123 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v122->pData + 7);
  v124 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v122[4].pManager;
  v125 = (const Scaleform::GFx::ASString *)v123(v122, &_ui);
  sm = v121;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v124->ClassTraitsSet,
    v125,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v126 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v126->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v126);
  this->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)v121;
  v127 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v127 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector::Vector(v127, this);
    v129 = v128;
  }
  else
  {
    v129 = 0;
  }
  v130 = v129->Builtins[25].pNode;
  v131 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v130->pData + 7);
  v132 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v130[4].pManager;
  v133 = (const Scaleform::GFx::ASString *)v131(v130, &_ui);
  sm = v129;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v132->ClassTraitsSet,
    v133,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v134 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v134->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v134);
  this->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)v129;
  v135 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v135 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int::Vector_int(v135, this);
    v137 = v136;
  }
  else
  {
    v137 = 0;
  }
  v138 = v137->Builtins[25].pNode;
  v139 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v138->pData + 7);
  v140 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v138[4].pManager;
  v141 = (const Scaleform::GFx::ASString *)v139(v138, &_ui);
  sm = v137;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v140->ClassTraitsSet,
    v141,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v142 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v142->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v142);
  this->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)v137;
  v143 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v143 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint::Vector_uint(v143, this);
    v145 = v144;
  }
  else
  {
    v145 = 0;
  }
  v146 = v145->Builtins[25].pNode;
  v147 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v146->pData + 7);
  v148 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v146[4].pManager;
  v149 = (const Scaleform::GFx::ASString *)v147(v146, &_ui);
  sm = v145;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v148->ClassTraitsSet,
    v149,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v150 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v150->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v150);
  this->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)v145;
  v151 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v151 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double::Vector_double(v151, this);
    v153 = v152;
  }
  else
  {
    v153 = 0;
  }
  v154 = v153->Builtins[25].pNode;
  v155 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v154->pData + 7);
  v156 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v154[4].pManager;
  v157 = (const Scaleform::GFx::ASString *)v155(v154, &_ui);
  sm = v153;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v156->ClassTraitsSet,
    v157,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v158 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v158->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v158);
  this->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)v153;
  v159 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v159 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String::Vector_String(v159, this);
    v161 = v160;
  }
  else
  {
    v161 = 0;
  }
  v162 = v161->Builtins[25].pNode;
  v163 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v162->pData + 7);
  v164 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v162[4].pManager;
  v165 = (const Scaleform::GFx::ASString *)v163(v162, &_ui);
  sm = v161;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v164->ClassTraitsSet,
    v165,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v166 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v166->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v166);
  this->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)v161;
  v167 = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v167 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain::ApplicationDomain(v167, this);
    v169 = v168;
  }
  else
  {
    v169 = 0;
  }
  v170 = v169->Builtins[25].pNode;
  v171 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v170->pData + 7);
  v172 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v170[4].pManager;
  v173 = (const Scaleform::GFx::ASString *)v171(v170, &_ui);
  sm = v169;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v172->ClassTraitsSet,
    v173,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v174 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v174->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v174);
  this->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)v169;
  v175 = (Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *)this->MHeap->Alloc(this->MHeap, 104, 0);
  if ( v175 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_system::Domain::Domain(v175, this);
    v177 = v176;
  }
  else
  {
    v177 = 0;
  }
  v178 = v177->Builtins[25].pNode;
  v179 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::FlashUI **))*((_DWORD *)v178->pData + 7);
  v180 = this->SystemDomain;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v178[4].pManager;
  v181 = (const Scaleform::GFx::ASString *)v179(v178, &_ui);
  sm = v177;
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
    &v180->ClassTraitsSet,
    v181,
    gc,
    (Scaleform::GFx::AS3::ClassTraits::Traits *const *)&sm);
  v182 = (Scaleform::GFx::ASStringNode *)_ui;
  --_ui[1].__vftable;
  if ( !v182->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v182);
  this->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *)v177;
  v183 = (Scaleform::GFx::AS3::InstanceTraits::Anonimous *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v183 )
    Scaleform::GFx::AS3::InstanceTraits::Anonimous::Anonimous(v183, this);
  else
    v184 = 0;
  this->TraitsNull.pObject = v184;
  v185 = (Scaleform::GFx::AS3::InstanceTraits::Void *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v185 )
    Scaleform::GFx::AS3::InstanceTraits::Void::Void(v185, this);
  else
    v186 = 0;
  this->TraitsVoid.pObject = v186;
  v187 = (Scaleform::GFx::AS3::InstanceTraits::Function *)this->MHeap->Alloc(this->MHeap, 132, 0);
  if ( v187 )
    Scaleform::GFx::AS3::InstanceTraits::Function::Function(v187, this, &Scaleform::GFx::AS3::fl::FunctionCICpp);
  else
    v188 = 0;
  this->NoFunctionTraits.pObject = v188;
  this->DefXMLNamespace.pObject = 0;
  v189 = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)this->MHeap->Alloc(this->MHeap, 120, 0);
  if ( v189 )
    Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject::GlobalObject(v189, this);
  else
    v190 = 0;
  this->TraitaGlobalObject.pObject = v190;
  v191 = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)this->MHeap->Alloc(this->MHeap, 152, 0);
  if ( v191 )
    Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GlobalObjectCPP(v191, this, this->TraitaGlobalObject.pObject);
  else
    v192 = 0;
  this->GlobalObject.pObject = v192;
  this->GlobalObjectValue.Flags = 0;
  this->GlobalObjectValue.Bonus.pWeakProxy = 0;
  pObject = this->GlobalObject.pObject;
  this->GlobalObjectValue.Flags = this->GlobalObjectValue.Flags & 0xFFFFFFE0 | 0xC;
  this->GlobalObjectValue.value.VS._1.VInt = (int)pObject;
  this->GlobalObjectValue.value.VS._2 = v216;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
  this->VMAbcFilesWeak.Data.Data = 0;
  this->VMAbcFilesWeak.Data.Size = 0;
  this->VMAbcFilesWeak.Data.Policy.Capacity = 0;
  Scaleform::GFx::AS3::VM::EnableXMLSupport(this, (int)v180);
  v194 = this->TraitsFunction.pObject->ITraits.pObject;
  if ( !v194->pConstructor.pObject )
    v194->InitOnDemand(v194);
  v195 = v194->pConstructor.pObject;
  if ( v195 )
    v195->RefCount = (v195->RefCount + 1) & 0x8FBFFFFF;
  v196 = this->NoFunctionTraits.pObject;
  v197 = v196->pConstructor.pObject;
  p_pConstructor = &v196->pConstructor;
  if ( v195 != v197 )
  {
    if ( v197 )
    {
      if ( ((unsigned __int8)v197 & 1) != 0 )
      {
        p_pConstructor->pObject = (Scaleform::GFx::AS3::Class *)((char *)v197 - 1);
      }
      else
      {
        RefCount = v197->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v197->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v197);
        }
      }
    }
    p_pConstructor->pObject = v195;
  }
  v200 = (Scaleform::GFx::AS3::StringManager *)this->GlobalObject.pObject;
  this->Initialized = 1;
  v201 = this->GlobalObjects.Data.Size + 1;
  sm = v200;
  if ( v201 >= this->GlobalObjects.Data.Size )
  {
    if ( v201 >= this->GlobalObjects.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
        &this->GlobalObjects,
        v201 + (v201 >> 2));
  }
  else if ( v201 < this->GlobalObjects.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->GlobalObjects,
      &this->GlobalObjects,
      v201);
  }
  Data = this->GlobalObjects.Data.Data;
  this->GlobalObjects.Data.Size = v201;
  v203 = &Data[v201 - 1];
  if ( v203 )
    *v203 = (Scaleform::GFx::AS3::Instances::fl::GlobalObject *)sm;
  v204 = (Scaleform::GFx::AS3::ASRefCountCollector *)this->Loader->GetSize(this->Loader);
  v205 = 0;
  gc = (const Scaleform::GFx::AS3::Instances::fl::Namespace *)v204;
  if ( v204 )
  {
    v206 = (char *)(&v204[-1].SuspendCnt + 3);
    do
    {
      v207 = this->Loader->GetFile(this->Loader, v205);
      Scaleform::GFx::AS3::VM::LoadFile(
        this,
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)&sm,
        v207,
        this->CurrentDomain,
        v205 == (_DWORD)v206);
      v208 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)sm;
      if ( sm )
      {
        if ( ((unsigned __int8)sm & 1) != 0 )
        {
          sm = (Scaleform::GFx::AS3::StringManager *)((char *)sm - 1);
        }
        else
        {
          v209 = sm->Builtins[4].pNode;
          if ( ((unsigned int)v209 & 0x3FFFFF) != 0 )
          {
            sm->Builtins[4].pNode = (Scaleform::GFx::ASStringNode *)((char *)v209 - 1);
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v208);
          }
        }
      }
      ++v205;
    }
    while ( v205 < (unsigned int)gc );
  }
  v210 = this->TraitsObject.pObject;
  p_pParent = &this->TraitsClassClass.pObject->pParent;
  if ( v210 != p_pParent->pObject )
  {
    if ( v210 )
      v210->RefCount = (v210->RefCount + 1) & 0x8FBFFFFF;
    v212 = p_pParent->pObject;
    if ( p_pParent->pObject )
    {
      if ( ((unsigned __int8)v212 & 1) != 0 )
      {
        p_pParent->pObject = (const Scaleform::GFx::AS3::Traits *)((char *)v212 - 1);
      }
      else
      {
        v213 = v212->RefCount;
        if ( (v213 & 0x3FFFFF) != 0 )
        {
          v212->RefCount = v213 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v212);
        }
      }
    }
    p_pParent->pObject = v210;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsClassClass.pObject);
  v214 = this->TraitsClassClass.pObject;
  v215 = (Scaleform::GFx::AS3::Classes::ClassClass **)v214->ITraits.pObject;
  if ( !v215[17] )
    ((void (__thiscall *)(Scaleform::GFx::AS3::InstanceTraits::Traits *))(*v215)[1].RefCount)(v214->ITraits.pObject);
  Scaleform::GFx::AS3::Classes::ClassClass::SetupPrototype(v215[17]);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsObject.pObject);
  Scaleform::GFx::AS3::ClassTraits::Traits::RegisterSlots(this->TraitsNamespace.pObject);
}
