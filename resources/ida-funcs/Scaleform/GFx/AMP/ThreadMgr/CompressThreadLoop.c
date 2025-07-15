int __cdecl Scaleform::GFx::AMP::ThreadMgr::CompressThreadLoop(
        Scaleform::Thread *a1,
        Scaleform::GFx::AMP::ThreadMgr *a2)
{
  if ( !a2 )
    return 1;
  Scaleform::GFx::AMP::ThreadMgr::CompressLoop(a2);
  return 0;
}
