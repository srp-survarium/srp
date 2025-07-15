void __thiscall Scaleform::GFx::AS3::TR::State::ConvertOpTo(
        Scaleform::GFx::AS3::TR::State *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *tr,
        Scaleform::GFx::AS3::Value::TraceNullType isNull)
{
  Scaleform::GFx::AS3::Value *v3; // ecx
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value other; // [esp+0h] [ebp-10h] BYREF

  other.value.VS._1.VInt = (int)tr;
  other.Flags = (32 * (isNull & 0xFFFFFFF7)) | 8;
  v3 = &this->OpStack.Data.Data[this->OpStack.Data.Size - 1];
  other.Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::Value::Assign(v3, &other);
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
