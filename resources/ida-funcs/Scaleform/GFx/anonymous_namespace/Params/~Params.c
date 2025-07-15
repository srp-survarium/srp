void __thiscall Scaleform::GFx::`anonymous namespace'::Params::~Params(Scaleform::GFx::Params *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  pObject = (Scaleform::RefCountVImpl *)this->ZlibFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->FinalScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->ScanlineWithAlpha2);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->ScanlineWithAlpha1);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->ScanlineWithAlpha0);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->AlphaScanline);
  Scaleform::Render::ImageScanlineBufferImpl::~ImageScanlineBufferImpl(&this->SourceScanline);
}
