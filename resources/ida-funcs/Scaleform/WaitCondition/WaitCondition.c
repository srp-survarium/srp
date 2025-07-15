void __thiscall Scaleform::WaitCondition::WaitCondition(Scaleform::WaitCondition *this)
{
  Scaleform::Lock *v2; // eax
  Scaleform::WaitConditionImpl *v3; // esi

  v2 = (Scaleform::Lock *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
  v3 = (Scaleform::WaitConditionImpl *)v2;
  if ( v2 )
  {
    Scaleform::Lock::Lock(v2, 0);
    v3->pFreeEventList = 0;
    v3->pQueueTail = 0;
    v3->pQueueHead = 0;
    this->pImpl = v3;
  }
  else
  {
    this->pImpl = 0;
  }
}
