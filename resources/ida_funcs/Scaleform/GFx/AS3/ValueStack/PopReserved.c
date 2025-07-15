void __thiscall Scaleform::GFx::AS3::ValueStack::PopReserved(
        Scaleform::GFx::AS3::ValueStack *this,
        Scaleform::GFx::AS3::Value *current)
{
  Scaleform::GFx::AS3::Value *pCurrent; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax

  for ( ; this->pCurrent > current; --this->pCurrent )
  {
    pCurrent = this->pCurrent;
    if ( this->pCurrent < this->pCurrentPage->Values )
      break;
    if ( (pCurrent->Flags & 0x1F) > 9 )
    {
      if ( (pCurrent->Flags & 0x200) != 0 )
      {
        pWeakProxy = pCurrent->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        pCurrent->Flags &= 0xFFFFFDE0;
        pCurrent->Bonus.pWeakProxy = 0;
        pCurrent->value.VS._1.VInt = 0;
        pCurrent->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this->pCurrent);
      }
    }
  }
}
