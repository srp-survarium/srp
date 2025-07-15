void __thiscall Scaleform::GFx::ASIMEManager::ASRootMovieCreated(
        Scaleform::GFx::ASIMEManager *this,
        Scaleform::Ptr<Scaleform::GFx::Sprite> spr)
{
  if ( spr.pObject )
    Scaleform::RefCountNTSImpl::Release(spr.pObject);
}
