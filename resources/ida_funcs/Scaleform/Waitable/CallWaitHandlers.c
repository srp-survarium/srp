void __thiscall Scaleform::Waitable::CallWaitHandlers(Scaleform::Waitable *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // ecx

  pHandlers = this->pHandlers;
  if ( pHandlers )
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(pHandlers);
}
