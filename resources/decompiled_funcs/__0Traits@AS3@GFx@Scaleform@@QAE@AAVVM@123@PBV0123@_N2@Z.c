void __thiscall Scaleform::GFx::AS3::Traits::Traits(
        Scaleform::GFx::AS3::Traits *this,
        Scaleform::GFx::AS3::VM *_vm,
        const Scaleform::GFx::AS3::Traits *pt,
        bool isDynamic,
        bool isFinal)
{
  Scaleform::GFx::AS3::BuiltinTraitsType TraitsType; // edi
  const Scaleform::MemoryHeap *MHeap; // edx
  unsigned __int8 v8; // cl
  const Scaleform::GFx::AS3::Traits *pObject; // ecx

  this->pRCCRaw = (unsigned int)_vm->GC.GC;
  this->RefCount = 1;
  this->FirstOwnSlotNum = 0;
  this->Parent = 0;
  this->VArray.Data.Data = 0;
  this->VArray.Data.Size = 0;
  this->VArray.Data.Policy.Capacity = 0;
  this->Set.mHash.pTable = 0;
  this->__vftable = (Scaleform::GFx::AS3::Traits_vtbl *)&Scaleform::GFx::AS3::Traits::`vftable';
  this->FirstOwnSlotInd.Index = 0;
  this->FixedValueSlotNumber = 0;
  this->MemSize = 0;
  this->Flags = 0;
  if ( pt )
    TraitsType = pt->TraitsType;
  else
    TraitsType = Traits_Unknown;
  this->TraitsType = TraitsType;
  this->pVM = _vm;
  this->pConstructor.pObject = 0;
  this->pParent.pObject = pt;
  if ( pt )
    pt->RefCount = (pt->RefCount + 1) & 0x8FBFFFFF;
  this->pVTable.pObject = 0;
  this->pVTable.Owner = 1;
  MHeap = _vm->MHeap;
  this->InitScope.Data.Data = 0;
  this->InitScope.Data.Size = 0;
  this->InitScope.Data.Policy.Capacity = 0;
  this->InitScope.Data.pHeap = MHeap;
  if ( pt )
    v8 = pt->Flags & 1;
  else
    v8 = 0;
  this->RefCount |= 0x8000000u;
  this->Flags = this->Flags & 0xFFFFFFBC | (isDynamic ? 2 : 0) | (isFinal ? 0x40 : 0) | -v8 & 1;
  pObject = this->pParent.pObject;
  if ( pObject )
  {
    this->Parent = &pObject->Scaleform::GFx::AS3::Slots;
    this->FirstOwnSlotNum = pObject->FirstOwnSlotNum + pObject->VArray.Data.Size;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,333>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>,Scaleform::HashNode<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,unsigned long,Scaleform::GFx::AS3::ASStringNodePtrHashFunc>::NodeHashF>>::Assign(
      &this->Set.mHash,
      &this->Set,
      &pObject->Set.mHash);
    this->FirstOwnSlotInd.Index = this->FirstOwnSlotNum + this->VArray.Data.Size;
    this->FixedValueSlotNumber = this->pParent.pObject->FixedValueSlotNumber;
  }
}
