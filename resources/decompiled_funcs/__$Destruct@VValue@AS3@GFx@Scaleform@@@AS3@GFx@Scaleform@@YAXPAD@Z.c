void __cdecl Scaleform::GFx::AS3::Destruct<Scaleform::GFx::AS3::Value>(Scaleform::GFx::AS3::Value *addr)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  if ( (addr->Flags & 0x1F) > 9 )
  {
    if ( (addr->Flags & 0x200) != 0 )
    {
      pWeakProxy = addr->Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      addr->Flags &= 0xFFFFFDE0;
      addr->Bonus.pWeakProxy = 0;
      addr->value.VS._1.VInt = 0;
      addr->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(addr);
    }
  }
}
