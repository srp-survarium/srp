void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::GFx::AS2::Value *val)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Data,
    this,
    this->Data.Size + 1);
  if ( &this->Data.Data[this->Data.Size] != (Scaleform::GFx::AS2::Value *)16 )
    Scaleform::GFx::AS2::Value::Value(&this->Data.Data[this->Data.Size - 1], val);
}
