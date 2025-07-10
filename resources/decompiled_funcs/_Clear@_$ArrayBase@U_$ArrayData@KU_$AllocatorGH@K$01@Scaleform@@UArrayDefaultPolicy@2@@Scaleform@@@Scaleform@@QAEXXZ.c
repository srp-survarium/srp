void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Clear(
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned long,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this)
{
  if ( !this->Data.Size )
  {
    if ( !this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        0);
    goto LABEL_8;
  }
  if ( (this->Data.Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
LABEL_8:
    this->Data.Size = 0;
    return;
  }
  if ( this->Data.Data )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data);
    this->Data.Data = 0;
  }
  this->Data.Policy.Capacity = 0;
  this->Data.Size = 0;
}
