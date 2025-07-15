char __thiscall Scaleform::GFx::AMP::GFxSocketImpl::Startup(Scaleform::GFx::AMP::GFxSocketImpl *this)
{
  _BYTE v2[400]; // [esp+0h] [ebp-190h] BYREF

  EnterCriticalSection(&Scaleform::GFx::AMP::GFxSocketImpl::LibRefLock.cs);
  if ( Scaleform::GFx::AMP::GFxSocketImpl::LibRefs || !((int (__stdcall *)(int, _BYTE *))(&off_8E3A98 + 24))(2, v2) )
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
