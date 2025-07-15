void __thiscall Scaleform::GFx::AS3::ReadArgs::~ReadArgs(Scaleform::GFx::AS3::ReadArgs *this)
{
  Scaleform::GFx::AS3::Value *p_CallArgs; // esi
  int i; // ebx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->CallArgs.Data.Data,
    this->CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CallArgs.Data.Data);
  p_CallArgs = (Scaleform::GFx::AS3::Value *)&this->CallArgs;
  for ( i = 7; i >= 0; --i )
  {
    Flags = p_CallArgs[-1].Flags;
    --p_CallArgs;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        pWeakProxy = p_CallArgs->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        p_CallArgs->Flags &= 0xFFFFFDE0;
        p_CallArgs->Bonus.pWeakProxy = 0;
        p_CallArgs->value.VS._1.VInt = 0;
        p_CallArgs->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(p_CallArgs);
      }
    }
  }
}
