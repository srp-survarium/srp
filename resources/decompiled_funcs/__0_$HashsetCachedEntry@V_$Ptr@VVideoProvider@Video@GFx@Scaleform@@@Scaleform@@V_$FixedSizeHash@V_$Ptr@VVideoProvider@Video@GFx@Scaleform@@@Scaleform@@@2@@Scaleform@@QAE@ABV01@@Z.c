void __thiscall Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>>>(
        Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > *this,
        const Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::GFx::Video::VideoProvider> > > *e)
{
  Scaleform::GFx::Video::VideoProvider *pObject; // edx

  this->NextInChain = e->NextInChain;
  this->HashValue = e->HashValue;
  pObject = e->Value.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->Value.pObject = e->Value.pObject;
}
