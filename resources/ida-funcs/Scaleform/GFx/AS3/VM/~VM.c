void __usercall Scaleform::GFx::AS3::VM::~VM(Scaleform::GFx::AS3::VM *this@<ecx>, int a2@<edi>)
{
  Scaleform::GFx::AS3::VMAppDomain *SystemDomain; // ecx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v5; // zf
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v10; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::InstanceTraits::Function *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v14; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *v16; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *v18; // ecx
  unsigned int v19; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *v20; // ecx
  unsigned int v21; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *v22; // ecx
  unsigned int v23; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *v24; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *v26; // ecx
  unsigned int v27; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *v28; // ecx
  unsigned int v29; // eax
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *v30; // ecx
  unsigned int v31; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Catch *v32; // ecx
  unsigned int v33; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::QName *v34; // ecx
  unsigned int v35; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Array *v36; // ecx
  unsigned int v37; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::String *v38; // ecx
  unsigned int v39; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::uint *v40; // ecx
  unsigned int v41; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::int_ *v42; // ecx
  unsigned int v43; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Number *v44; // ecx
  unsigned int v45; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Boolean *v46; // ecx
  unsigned int v47; // eax
  Scaleform::GFx::AS3::ClassTraits::Function *v48; // ecx
  unsigned int v49; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Namespace *v50; // ecx
  unsigned int v51; // eax
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v52; // ecx
  unsigned int v53; // eax
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v54; // ecx
  unsigned int v55; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v56; // ecx
  unsigned int v57; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v58; // ecx
  unsigned int v59; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v60; // ecx
  unsigned int v61; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v62; // ecx
  unsigned int v63; // eax
  Scaleform::GFx::AS3::WeakProxy *v64; // eax
  Scaleform::GFx::AS3::XMLSupport *v65; // ecx
  unsigned int v66; // eax

  this->__vftable = (Scaleform::GFx::AS3::VM_vtbl *)&Scaleform::GFx::AS3::VM::`vftable';
  this->InDestructor = 1;
  Scaleform::GFx::AS3::VM::UnregisterAllAbcFiles(this);
  SystemDomain = this->SystemDomain;
  if ( SystemDomain )
    ((void (__thiscall *)(Scaleform::GFx::AS3::VMAppDomain *, int))SystemDomain->~Scaleform::GFx::AS3::VMAppDomain)(
      SystemDomain,
      1);
  ((void (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::VMAbcFile **, int))Scaleform::Memory::pGlobalHeap->Free)(
    Scaleform::Memory::pGlobalHeap,
    this->VMAbcFilesWeak.Data.Data,
    a2);
  if ( (this->GlobalObjectValue.Flags & 0x1F) > 9 )
  {
    if ( (this->GlobalObjectValue.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->GlobalObjectValue.Bonus.pWeakProxy;
      v5 = pWeakProxy->RefCount-- == 1;
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      this->GlobalObjectValue.Flags &= 0xFFFFFDE0;
      this->GlobalObjectValue.Bonus.pWeakProxy = 0;
      this->GlobalObjectValue.value.VS._1.VInt = 0;
      this->GlobalObjectValue.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->GlobalObjectValue);
    }
  }
  pObject = this->GlobalObject.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->GlobalObject.pObject = (Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v8 = this->TraitaGlobalObject.pObject;
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      this->TraitaGlobalObject.pObject = (Scaleform::GFx::AS3::InstanceTraits::fl::GlobalObject *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
  }
  v10 = this->DefXMLNamespace.pObject;
  if ( v10 )
  {
    if ( ((unsigned __int8)v10 & 1) != 0 )
    {
      this->DefXMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v10 - 1);
    }
    else
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v10);
      }
    }
  }
  v12 = this->NoFunctionTraits.pObject;
  if ( v12 )
  {
    if ( ((unsigned __int8)v12 & 1) != 0 )
    {
      this->NoFunctionTraits.pObject = (Scaleform::GFx::AS3::InstanceTraits::Function *)((char *)v12 - 1);
    }
    else
    {
      v13 = v12->RefCount;
      if ( (v13 & 0x3FFFFF) != 0 )
      {
        v12->RefCount = v13 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
  v14 = this->TraitsVoid.pObject;
  if ( v14 )
  {
    if ( ((unsigned __int8)v14 & 1) != 0 )
    {
      this->TraitsVoid.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v14 - 1);
    }
    else
    {
      v15 = v14->RefCount;
      if ( (v15 & 0x3FFFFF) != 0 )
      {
        v14->RefCount = v15 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v14);
      }
    }
  }
  v16 = this->TraitsNull.pObject;
  if ( v16 )
  {
    if ( ((unsigned __int8)v16 & 1) != 0 )
    {
      this->TraitsNull.pObject = (Scaleform::GFx::AS3::InstanceTraits::Traits *)((char *)v16 - 1);
    }
    else
    {
      v17 = v16->RefCount;
      if ( (v17 & 0x3FFFFF) != 0 )
      {
        v16->RefCount = v17 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
      }
    }
  }
  v18 = this->TraitsDomain.pObject;
  if ( v18 )
  {
    if ( ((unsigned __int8)v18 & 1) != 0 )
    {
      this->TraitsDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::Domain *)((char *)v18 - 1);
    }
    else
    {
      v19 = v18->RefCount;
      if ( (v19 & 0x3FFFFF) != 0 )
      {
        v18->RefCount = v19 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
      }
    }
  }
  v20 = this->TraitsApplicationDomain.pObject;
  if ( v20 )
  {
    if ( ((unsigned __int8)v20 & 1) != 0 )
    {
      this->TraitsApplicationDomain.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_system::ApplicationDomain *)((char *)v20 - 1);
    }
    else
    {
      v21 = v20->RefCount;
      if ( (v21 & 0x3FFFFF) != 0 )
      {
        v20->RefCount = v21 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
  v22 = this->TraitsVector_String.pObject;
  if ( v22 )
  {
    if ( ((unsigned __int8)v22 & 1) != 0 )
    {
      this->TraitsVector_String.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_String *)((char *)v22 - 1);
    }
    else
    {
      v23 = v22->RefCount;
      if ( (v23 & 0x3FFFFF) != 0 )
      {
        v22->RefCount = v23 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
      }
    }
  }
  v24 = this->TraitsVector_Number.pObject;
  if ( v24 )
  {
    if ( ((unsigned __int8)v24 & 1) != 0 )
    {
      this->TraitsVector_Number.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_double *)((char *)v24 - 1);
    }
    else
    {
      v25 = v24->RefCount;
      if ( (v25 & 0x3FFFFF) != 0 )
      {
        v24->RefCount = v25 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
      }
    }
  }
  v26 = this->TraitsVector_uint.pObject;
  if ( v26 )
  {
    if ( ((unsigned __int8)v26 & 1) != 0 )
    {
      this->TraitsVector_uint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_uint *)((char *)v26 - 1);
    }
    else
    {
      v27 = v26->RefCount;
      if ( (v27 & 0x3FFFFF) != 0 )
      {
        v26->RefCount = v27 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
      }
    }
  }
  v28 = this->TraitsVector_int.pObject;
  if ( v28 )
  {
    if ( ((unsigned __int8)v28 & 1) != 0 )
    {
      this->TraitsVector_int.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_int *)((char *)v28 - 1);
    }
    else
    {
      v29 = v28->RefCount;
      if ( (v29 & 0x3FFFFF) != 0 )
      {
        v28->RefCount = v29 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
      }
    }
  }
  v30 = this->TraitsVector.pObject;
  if ( v30 )
  {
    if ( ((unsigned __int8)v30 & 1) != 0 )
    {
      this->TraitsVector.pObject = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector *)((char *)v30 - 1);
    }
    else
    {
      v31 = v30->RefCount;
      if ( (v31 & 0x3FFFFF) != 0 )
      {
        v30->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
  v32 = this->TraitsCatch.pObject;
  if ( v32 )
  {
    if ( ((unsigned __int8)v32 & 1) != 0 )
    {
      this->TraitsCatch.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Catch *)((char *)v32 - 1);
    }
    else
    {
      v33 = v32->RefCount;
      if ( (v33 & 0x3FFFFF) != 0 )
      {
        v32->RefCount = v33 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v32);
      }
    }
  }
  v34 = this->TraitsQName.pObject;
  if ( v34 )
  {
    if ( ((unsigned __int8)v34 & 1) != 0 )
    {
      this->TraitsQName.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::QName *)((char *)v34 - 1);
    }
    else
    {
      v35 = v34->RefCount;
      if ( (v35 & 0x3FFFFF) != 0 )
      {
        v34->RefCount = v35 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
      }
    }
  }
  v36 = this->TraitsArray.pObject;
  if ( v36 )
  {
    if ( ((unsigned __int8)v36 & 1) != 0 )
    {
      this->TraitsArray.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Array *)((char *)v36 - 1);
    }
    else
    {
      v37 = v36->RefCount;
      if ( (v37 & 0x3FFFFF) != 0 )
      {
        v36->RefCount = v37 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v36);
      }
    }
  }
  v38 = this->TraitsString.pObject;
  if ( v38 )
  {
    if ( ((unsigned __int8)v38 & 1) != 0 )
    {
      this->TraitsString.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::String *)((char *)v38 - 1);
    }
    else
    {
      v39 = v38->RefCount;
      if ( (v39 & 0x3FFFFF) != 0 )
      {
        v38->RefCount = v39 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v38);
      }
    }
  }
  v40 = this->TraitsUint.pObject;
  if ( v40 )
  {
    if ( ((unsigned __int8)v40 & 1) != 0 )
    {
      this->TraitsUint.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::uint *)((char *)v40 - 1);
    }
    else
    {
      v41 = v40->RefCount;
      if ( (v41 & 0x3FFFFF) != 0 )
      {
        v40->RefCount = v41 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v40);
      }
    }
  }
  v42 = this->TraitsInt.pObject;
  if ( v42 )
  {
    if ( ((unsigned __int8)v42 & 1) != 0 )
    {
      this->TraitsInt.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::int_ *)((char *)v42 - 1);
    }
    else
    {
      v43 = v42->RefCount;
      if ( (v43 & 0x3FFFFF) != 0 )
      {
        v42->RefCount = v43 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v42);
      }
    }
  }
  v44 = this->TraitsNumber.pObject;
  if ( v44 )
  {
    if ( ((unsigned __int8)v44 & 1) != 0 )
    {
      this->TraitsNumber.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Number *)((char *)v44 - 1);
    }
    else
    {
      v45 = v44->RefCount;
      if ( (v45 & 0x3FFFFF) != 0 )
      {
        v44->RefCount = v45 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v44);
      }
    }
  }
  v46 = this->TraitsBoolean.pObject;
  if ( v46 )
  {
    if ( ((unsigned __int8)v46 & 1) != 0 )
    {
      this->TraitsBoolean.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Boolean *)((char *)v46 - 1);
    }
    else
    {
      v47 = v46->RefCount;
      if ( (v47 & 0x3FFFFF) != 0 )
      {
        v46->RefCount = v47 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v46);
      }
    }
  }
  v48 = this->TraitsFunction.pObject;
  if ( v48 )
  {
    if ( ((unsigned __int8)v48 & 1) != 0 )
    {
      this->TraitsFunction.pObject = (Scaleform::GFx::AS3::ClassTraits::Function *)((char *)v48 - 1);
    }
    else
    {
      v49 = v48->RefCount;
      if ( (v49 & 0x3FFFFF) != 0 )
      {
        v48->RefCount = v49 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v48);
      }
    }
  }
  v50 = this->TraitsNamespace.pObject;
  if ( v50 )
  {
    if ( ((unsigned __int8)v50 & 1) != 0 )
    {
      this->TraitsNamespace.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Namespace *)((char *)v50 - 1);
    }
    else
    {
      v51 = v50->RefCount;
      if ( (v51 & 0x3FFFFF) != 0 )
      {
        v50->RefCount = v51 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v50);
      }
    }
  }
  v52 = this->TraitsObject.pObject;
  if ( v52 )
  {
    if ( ((unsigned __int8)v52 & 1) != 0 )
    {
      this->TraitsObject.pObject = (Scaleform::GFx::AS3::ClassTraits::fl::Object *)((char *)v52 - 1);
    }
    else
    {
      v53 = v52->RefCount;
      if ( (v53 & 0x3FFFFF) != 0 )
      {
        v52->RefCount = v53 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v52);
      }
    }
  }
  v54 = this->TraitsClassClass.pObject;
  if ( v54 )
  {
    if ( ((unsigned __int8)v54 & 1) != 0 )
    {
      this->TraitsClassClass.pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)((char *)v54 - 1);
    }
    else
    {
      v55 = v54->RefCount;
      if ( (v55 & 0x3FFFFF) != 0 )
      {
        v54->RefCount = v55 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v54);
      }
    }
  }
  v56 = this->XMLNamespace.pObject;
  if ( v56 )
  {
    if ( ((unsigned __int8)v56 & 1) != 0 )
    {
      this->XMLNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v56 - 1);
    }
    else
    {
      v57 = v56->RefCount;
      if ( (v57 & 0x3FFFFF) != 0 )
      {
        v56->RefCount = v57 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v56);
      }
    }
  }
  v58 = this->VectorNamespace.pObject;
  if ( v58 )
  {
    if ( ((unsigned __int8)v58 & 1) != 0 )
    {
      this->VectorNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v58 - 1);
    }
    else
    {
      v59 = v58->RefCount;
      if ( (v59 & 0x3FFFFF) != 0 )
      {
        v58->RefCount = v59 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v58);
      }
    }
  }
  v60 = this->AS3Namespace.pObject;
  if ( v60 )
  {
    if ( ((unsigned __int8)v60 & 1) != 0 )
    {
      this->AS3Namespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v60 - 1);
    }
    else
    {
      v61 = v60->RefCount;
      if ( (v61 & 0x3FFFFF) != 0 )
      {
        v60->RefCount = v61 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v60);
      }
    }
  }
  v62 = this->PublicNamespace.pObject;
  if ( v62 )
  {
    if ( ((unsigned __int8)v62 & 1) != 0 )
    {
      this->PublicNamespace.pObject = (Scaleform::GFx::AS3::Instances::fl::Namespace *)((char *)v62 - 1);
    }
    else
    {
      v63 = v62->RefCount;
      if ( (v63 & 0x3FFFFF) != 0 )
      {
        v62->RefCount = v63 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v62);
      }
    }
  }
  Scaleform::GFx::AS3::CallFrame::~CallFrame(&this->CallStack.DefaultValue);
  Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::ClearAndRelease(&this->CallStack);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->GlobalObjects.Data.Data);
  if ( (this->ExceptionObj.Flags & 0x1F) > 9 )
  {
    if ( (this->ExceptionObj.Flags & 0x200) != 0 )
    {
      v64 = this->ExceptionObj.Bonus.pWeakProxy;
      v5 = v64->RefCount-- == 1;
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v64);
      this->ExceptionObj.Flags &= 0xFFFFFDE0;
      this->ExceptionObj.Bonus.pWeakProxy = 0;
      this->ExceptionObj.value.VS._1.VInt = 0;
      this->ExceptionObj.value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExceptionObj);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->ScopeStack.Data.Data,
    this->ScopeStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->ScopeStack.Data.Data);
  Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(&this->RegisterFile);
  Scaleform::GFx::AS3::ValueStack::~ValueStack(&this->OpStack);
  v65 = this->XMLSupport_.pObject;
  if ( v65 )
  {
    if ( ((unsigned __int8)v65 & 1) != 0 )
    {
      this->XMLSupport_.pObject = (Scaleform::GFx::AS3::XMLSupport *)((char *)v65 - 1);
      Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->GC.GC, 0, 1u);
      return;
    }
    v66 = v65->RefCount;
    if ( (v66 & 0x3FFFFF) != 0 )
    {
      v65->RefCount = v66 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v65);
    }
  }
  Scaleform::GFx::AS3::ASRefCountCollector::ForceCollect(this->GC.GC, 0, 1u);
}
