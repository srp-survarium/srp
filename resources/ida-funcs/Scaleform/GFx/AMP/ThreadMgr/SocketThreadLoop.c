int __usercall Scaleform::GFx::AMP::ThreadMgr::SocketThreadLoop@<eax>(
        _DWORD *a1@<ebp>,
        Scaleform::Thread *a2,
        Scaleform::GFx::AMP::ThreadMgr *a3)
{
  if ( !a3 )
    return 1;
  while ( Scaleform::GFx::AMP::ThreadMgr::SendReceiveLoop(a3, a1) )
    Scaleform::Thread::Sleep(1u);
  return 0;
}
