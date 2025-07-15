void __thiscall Scaleform::GFx::AMP::MessageFontData::SetImageData(
        Scaleform::GFx::AMP::MessageFontData *this,
        Scaleform::GFx::Resource *imageData)
{
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->FontDataStream);
  this->FontDataStream = (Scaleform::GFx::AMP::AmpStream *)imageData;
  Scaleform::RefCountImpl::AddRef(imageData);
}
