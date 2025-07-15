void __thiscall Scaleform::GFx::AS3::TR::State::ConvertRegisterTo(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::AbsoluteIndex index,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr,
        Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  Scaleform::GFx::AS3::Value *v4; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value other; // [esp+0h] [ebp-10h] BYREF

  other.value.VS._1.VInt = (int)tr;
  v4 = &this->Registers.Data.Data[index.Index];
  other.Bonus.pWeakProxy = 0;
  other.Flags = (32 * (isNull & 0xFFFFFFF7)) | 8;
  Scaleform::GFx::AS3::Value::Assign(v4, &other);
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      pWeakProxy = other.Bonus.pWeakProxy;
      if ( other.Bonus.pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}
