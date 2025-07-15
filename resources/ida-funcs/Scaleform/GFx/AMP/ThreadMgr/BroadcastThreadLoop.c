int __usercall Scaleform::GFx::AMP::ThreadMgr::BroadcastThreadLoop@<eax>(
        bool *a1@<ebx>,
        int a2@<ebp>,
        Scaleform::GFx::AS3::SoundObject *a3@<edi>,
        Scaleform::Thread *a4,
        Scaleform::GFx::AMP::ThreadMgr *a5)
{
  if ( !a5 )
    return 1;
  Scaleform::GFx::AMP::ThreadMgr::BroadcastLoop(a5, a1, a2, a3);
  return 0;
}
