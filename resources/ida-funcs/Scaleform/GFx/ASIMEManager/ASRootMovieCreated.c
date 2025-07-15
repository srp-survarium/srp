void __thiscall Scaleform::GFx::ASIMEManager::ASRootMovieCreated(
        Scaleform::GFx::ASIMEManager *this,
        Scaleform::RefCountNTSImpl *spr)
{
  if ( spr )
    Scaleform::RefCountNTSImpl::Release(spr);
}
