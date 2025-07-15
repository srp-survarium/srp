const Scaleform::GFx::AS3::ClassTraits::Traits *__thiscall Scaleform::GFx::AS3::Classes::fl_vec::Vector::Resolve2Vector(
        Scaleform::GFx::AS3::Classes::fl_vec::Vector *this,
        const Scaleform::GFx::AS3::ClassTraits::Traits *elem)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *v4; // esi
  Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v9; // ebx
  Scaleform::GFx::AS3::VMAppDomain *FrameAppDomain; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *RegisteredClassTraits; // ebx
  Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *v12; // eax
  const Scaleform::GFx::AS3::ClassTraits::Traits *v13; // eax
  int v14; // eax
  int v15; // ebp
  _DWORD *v16; // esi
  int v17; // edx
  Scaleform::GFx::AS3::Traits *v18; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Namespace const > v20; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  const Scaleform::GFx::ASString *v24; // [esp+4h] [ebp-20h]
  Scaleform::GFx::ASString name; // [esp+14h] [ebp-10h] BYREF
  Scaleform::GFx::ASString v26; // [esp+18h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString result; // [esp+1Ch] [ebp-8h] BYREF
  Scaleform::GFx::ASStringNode *v28; // [esp+20h] [ebp-4h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  ((void (__stdcall *)(Scaleform::GFx::ASString *))pObject->GetName)(&v26);
  v4 = elem;
  v24 = elem->GetQualifiedName(elem, &v28, 0);
  v5 = Scaleform::GFx::ASString::operator+(&v26, &result, "$");
  Scaleform::GFx::ASString::operator+(v5, &name, v24);
  pNode = result.pNode;
  --result.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v7 = v26.pNode;
  --v26.pNode->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v8 = v28;
  --v28->RefCount;
  if ( !v8->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = pVM->VectorNamespace.pObject;
  FrameAppDomain = Scaleform::GFx::AS3::VM::GetFrameAppDomain(pVM);
  RegisteredClassTraits = Scaleform::GFx::AS3::VM::GetRegisteredClassTraits(pVM, &name, v9, FrameAppDomain);
  if ( !RegisteredClassTraits )
  {
    v12 = (Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object *)pVM->MHeap->Alloc(pVM->MHeap, 108u, 0);
    if ( v12 )
    {
      Scaleform::GFx::AS3::ClassTraits::fl_vec::Vector_object::Vector_object(v12, pVM, &name, v4);
      RegisteredClassTraits = v13;
    }
    else
    {
      RegisteredClassTraits = 0;
    }
    v14 = (int)v4->GetFilePtr(&v4->Scaleform::GFx::AS3::Traits);
    v15 = v14;
    if ( v14 )
    {
      v16 = (_DWORD *)(v14 + 88);
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)(v14 + 88),
        (const void *)(v14 + 88),
        *(_DWORD *)(v14 + 92) + 1);
      v17 = *(_DWORD *)(v15 + 92);
      if ( *v16 + 4 * v17 != 4 )
      {
        *(_DWORD *)(*v16 + 4 * v17 - 4) = RegisteredClassTraits;
        if ( RegisteredClassTraits )
          RegisteredClassTraits->RefCount = (RegisteredClassTraits->RefCount + 1) & 0x8FBFFFFF;
      }
      Scaleform::GFx::AS3::VMAppDomain::AddClassTrait(
        *(Scaleform::GFx::AS3::VMAppDomain **)(v15 + 24),
        &name,
        pVM->VectorNamespace.pObject,
        RegisteredClassTraits);
    }
    else
    {
      v18 = RegisteredClassTraits->ITraits.pObject;
      elem = 0;
      Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(v18);
      v20.pV = pVM->VectorNamespace.pObject;
      if ( v20.pV )
        v20.pV->RefCount = (v20.pV->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::AddFixedSlot(
        pVM->GlobalObject.pObject,
        Constructor,
        v20,
        (unsigned int *)&elem);
    }
    if ( RegisteredClassTraits )
    {
      if ( ((unsigned __int8)RegisteredClassTraits & 1) == 0 )
      {
        RefCount = RegisteredClassTraits->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          RegisteredClassTraits->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(RegisteredClassTraits);
        }
      }
    }
  }
  v22 = name.pNode;
  --name.pNode->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  return RegisteredClassTraits;
}
