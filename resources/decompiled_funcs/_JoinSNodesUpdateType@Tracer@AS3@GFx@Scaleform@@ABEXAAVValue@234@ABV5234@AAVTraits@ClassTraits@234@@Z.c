void __thiscall Scaleform::GFx::AS3::Tracer::JoinSNodesUpdateType(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::Value *to,
        const Scaleform::GFx::AS3::Value *from,
        Scaleform::GFx::AS3::ClassTraits::Traits *result_type)
{
  unsigned int CanBeNull; // eax
  void *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value other; // [esp+4h] [ebp-10h] BYREF

  CanBeNull = Scaleform::GFx::AS3::Tracer::CanBeNull(this, result_type->ITraits.pObject);
  if ( CanBeNull )
  {
    CanBeNull = (to->Flags >> 5) & 3;
    if ( CanBeNull != ((from->Flags >> 5) & 3) )
      CanBeNull = 2;
  }
  other.Flags = (32 * (CanBeNull & 0xFFFFFFF7)) | 9;
  other.Bonus.pWeakProxy = 0;
  other.value.VS._1.VInt = (int)result_type;
  Scaleform::GFx::AS3::Value::Assign(to, &other);
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
