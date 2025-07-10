void __thiscall Scaleform::GFx::AS3::TR::ReadArgs::~ReadArgs(Scaleform::GFx::AS3::TR::ReadArgs *this)
{
  Scaleform::GFx::AS3::Value *v2; // esi
  int i; // ebp
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  v2 = (Scaleform::GFx::AS3::Value *)&this[1];
  for ( i = 7; i >= 0; --i )
  {
    Flags = v2[-1].Flags;
    --v2;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
      {
        pWeakProxy = v2->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        v2->Flags &= 0xFFFFFDE0;
        v2->Bonus.pWeakProxy = 0;
        v2->value.VS._1.VInt = 0;
        v2->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(v2);
      }
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->CallArgs.Data.Data,
    this->CallArgs.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CallArgs.Data.Data);
}
