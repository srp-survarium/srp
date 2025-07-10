void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int num)
{
  if ( this->Data.Size == num )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0);
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&this->Data.Data[index], num);
    memmove(
      (unsigned __int8 *)&this->Data.Data[index],
      (unsigned __int8 *)&this->Data.Data[num + index],
      16 * (this->Data.Size - index - num));
    this->Data.Size -= num;
  }
}
