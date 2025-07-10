void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>::Clear(
        Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > *this)
{
  Scaleform::GFx::Video::VideoProvider *pObject; // ecx

  pObject = this->Value.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->NextInChain = -2;
}
