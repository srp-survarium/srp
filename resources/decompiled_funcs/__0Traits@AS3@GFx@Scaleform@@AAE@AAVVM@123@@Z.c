void __thiscall Scaleform::GFx::AS3::Traits::Traits(Scaleform::GFx::AS3::Traits *this, Scaleform::GFx::AS3::VM *_vm)
{
  const Scaleform::MemoryHeap *MHeap; // edx

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
  this->TraitsType = Traits_Unknown;
  this->pVM = _vm;
  this->pConstructor.pObject = 0;
  this->pParent.pObject = 0;
  this->pVTable.pObject = 0;
  this->pVTable.Owner = 1;
  MHeap = _vm->MHeap;
  this->InitScope.Data.Data = 0;
  this->InitScope.Data.Size = 0;
  this->InitScope.Data.Policy.Capacity = 0;
  this->InitScope.Data.pHeap = MHeap;
  this->RefCount |= 0x8000000u;
}
