Scaleform::WaitConditionImpl::EventPoolEntry *__thiscall Scaleform::WaitConditionImpl::GetNewEvent(
        Scaleform::WaitConditionImpl *this)
{
  Scaleform::WaitConditionImpl::EventPoolEntry *result; // eax
  HANDLE *v2; // esi

  result = this->pFreeEventList;
  if ( result )
  {
    this->pFreeEventList = result->pNext;
  }
  else
  {
    v2 = (HANDLE *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
    v2[1] = 0;
    v2[2] = 0;
    *v2 = CreateEventA(0, 1, 0, 0);
    return (Scaleform::WaitConditionImpl::EventPoolEntry *)v2;
  }
  return result;
}
