char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Startup(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  WSAData wsaData; // [esp+0h] [ebp-190h] BYREF

  EnterCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
  if ( Scaleform::GFx::AMP::GFxSocketImpl::LibRefs || !WSAStartup(2u, &wsaData) )
  {
    ++Scaleform::GFx::AMP::GFxSocketImpl::LibRefs;
    LeaveCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
    return 1;
  }
  else
  {
    LeaveCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
    return 0;
  }
}
