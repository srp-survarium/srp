int __cdecl Scaleform::GFx::AMP::ThreadMgr::BroadcastRecvThreadLoop(
        Scaleform::Thread *a1,
        Scaleform::GFx::AMP::ThreadMgr *a2)
{
  if ( !a2 )
    return 1;
  Scaleform::GFx::AMP::ThreadMgr::BroadcastRecvLoop(a2);
  return 0;
}
