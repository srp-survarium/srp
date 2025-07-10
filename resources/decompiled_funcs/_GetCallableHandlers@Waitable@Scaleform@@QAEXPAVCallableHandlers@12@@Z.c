void __thiscall Scaleform::Waitable::GetCallableHandlers(
        Scaleform::Waitable *this,
        Scaleform::Waitable::CallableHandlers *ph)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // esi

  pHandlers = this->pHandlers;
  if ( pHandlers )
  {
    InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1);
    if ( ph->pArray.pObject )
      Scaleform::Waitable::HandlerArray::Release(ph->pArray.pObject);
    ph->pArray.pObject = pHandlers;
  }
}
