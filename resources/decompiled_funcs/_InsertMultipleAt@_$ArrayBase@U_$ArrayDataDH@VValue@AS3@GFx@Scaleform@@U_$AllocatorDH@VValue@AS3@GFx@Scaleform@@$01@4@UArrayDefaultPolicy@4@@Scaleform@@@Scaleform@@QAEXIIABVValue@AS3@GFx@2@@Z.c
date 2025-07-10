void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int num,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned int v4; // edi
  unsigned int v6; // ebp
  Scaleform::GFx::AS3::Value *v7; // eax

  v4 = num;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    num + this->Data.Size);
  if ( index < this->Data.Size - num )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + num],
      (unsigned __int8 *)&this->Data.Data[index],
      16 * (this->Data.Size - index - num));
  if ( num )
  {
    v6 = index;
    do
    {
      v7 = &this->Data.Data[v6];
      if ( v7 )
      {
        *v7 = *val;
        if ( (val->Flags & 0x1F) > 9 )
        {
          if ( (val->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(val);
        }
      }
      ++v6;
      --v4;
    }
    while ( v4 );
  }
}
