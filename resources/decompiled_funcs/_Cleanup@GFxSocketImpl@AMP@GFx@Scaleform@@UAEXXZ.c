void __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Cleanup(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  EnterCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
  if ( Scaleform::GFx::AMP::GFxSocketImpl::LibRefs )
  {
    if ( !--Scaleform::GFx::AMP::GFxSocketImpl::LibRefs )
      WSACleanup();
  }
  LeaveCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
}
