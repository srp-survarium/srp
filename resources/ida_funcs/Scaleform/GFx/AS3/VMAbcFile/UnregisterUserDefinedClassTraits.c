void __thiscall Scaleform::GFx::AS3::VMAbcFile::UnregisterUserDefinedClassTraits(Scaleform::GFx::AS3::VMAbcFile *this)
{
  unsigned int Size; // ebp
  unsigned int i; // ebx
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329> *p_ClassTraitsSet; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **p_LoadedClasses; // esi
  Scaleform::GFx::ASString str_name; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::ClassTraits::Traits *v; // [esp+14h] [ebp-4h] BYREF

  Size = this->LoadedClasses.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    pObject = this->LoadedClasses.Data.Data[i].pObject->ITraits.pObject;
    if ( pObject )
    {
      pObject->GetName(pObject, &str_name);
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Remove(
        &this->AppDomain->ClassTraitsSet,
        &str_name,
        pObject->Ns.pObject);
      pNode = str_name.pNode;
      --str_name.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    else
    {
      p_ClassTraitsSet = &this->AppDomain->ClassTraitsSet;
      v = this->LoadedClasses.Data.Data[i].pObject;
      Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::RemoveValue(
        p_ClassTraitsSet,
        &v);
    }
  }
  p_LoadedClasses = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> **)&this->LoadedClasses;
  if ( !this->LoadedClasses.Data.Size )
  {
    if ( !this->LoadedClasses.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::NamespaceSet>,340>,Scaleform::ArrayDefaultPolicy> *)&this->LoadedClasses,
        &this->LoadedClasses,
        0);
    goto LABEL_14;
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    *p_LoadedClasses,
    this->LoadedClasses.Data.Size);
  if ( (this->LoadedClasses.Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_14:
    this->LoadedClasses.Data.Size = 0;
    return;
  }
  if ( *p_LoadedClasses )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_LoadedClasses);
    *p_LoadedClasses = 0;
  }
  this->LoadedClasses.Data.Policy.Capacity = 0;
  this->LoadedClasses.Data.Size = 0;
}
