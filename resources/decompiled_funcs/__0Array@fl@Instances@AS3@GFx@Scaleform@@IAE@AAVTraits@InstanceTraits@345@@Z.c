void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::Array(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::MemoryHeap *MHeap; // ecx

  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->__vftable = (Scaleform::GFx::AS3::Instances::fl::Array_vtbl *)&Scaleform::GFx::AS3::Instances::fl::Array::`vftable';
  MHeap = t->pVM->MHeap;
  this->SA.Length = 0;
  this->SA.ValueHLowInd = 0;
  this->SA.ValueHHighInd = 0;
  this->SA.DefaultValue.Flags = 0;
  this->SA.DefaultValue.Bonus.pWeakProxy = 0;
  this->SA.ValueA.Data.Data = 0;
  this->SA.ValueA.Data.Size = 0;
  this->SA.ValueA.Data.Policy.Capacity = 0;
  this->SA.ValueA.Data.pHeap = MHeap;
  this->SA.ValueH.mHash.pTable = 0;
  this->SA.ValueH.mHash.pHeap = MHeap;
}
