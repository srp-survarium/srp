int __cdecl Scaleform::GFx::AS3::SocketThreadMgr::SocketThreadLoop(
        Scaleform::Thread *sendThread,
        Scaleform::GFx::AS3::SocketThreadMgr *param)
{
  if ( !param )
    return 1;
  while ( Scaleform::GFx::AS3::SocketThreadMgr::SendReceiveLoop(param) )
    Scaleform::Thread::Sleep(1u);
  return 0;
}
