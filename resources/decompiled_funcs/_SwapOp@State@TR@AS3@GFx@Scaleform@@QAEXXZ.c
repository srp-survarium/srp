void __thiscall Scaleform::GFx::AS3::TR::State::SwapOp(Scaleform::GFx::AS3::TR::State *this)
{
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *Data; // ecx
  unsigned int v4; // edi
  Scaleform::GFx::AS3::Value::V1U v5; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ebp
  Scaleform::GFx::AS3::Value *v8; // ecx
  void *v9; // eax
  Scaleform::GFx::AS3::Value _2; // [esp+Ch] [ebp-10h] BYREF

  Size = this->OpStack.Data.Size;
  Data = this->OpStack.Data.Data;
  v4 = Size - 1;
  v5 = Data[v4].value.VS._1;
  Flags = Data[v4].Flags;
  pWeakProxy = Data[v4].Bonus.pWeakProxy;
  v8 = &Data[v4];
  _2.value.VS._1 = v5;
  _2.value.VS._2.VObj = v8->value.VS._2.VObj;
  _2.Flags = Flags;
  _2.Bonus.pWeakProxy = pWeakProxy;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      ++pWeakProxy->RefCount;
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v8);
  }
  Scaleform::GFx::AS3::Value::Assign(&this->OpStack.Data.Data[v4], &this->OpStack.Data.Data[v4 - 1]);
  Scaleform::GFx::AS3::Value::Assign(&this->OpStack.Data.Data[v4 - 1], &_2);
  if ( (_2.Flags & 0x1F) > 9 )
  {
    if ( (_2.Flags & 0x200) != 0 )
    {
      v9 = _2.Bonus.pWeakProxy;
      if ( _2.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&_2);
    }
  }
}
