void __thiscall Scaleform::Render::JPEG::JPEGRwSource::JPEGRwSource(
        Scaleform::Render::JPEG::JPEGRwSource *this,
        Scaleform::GFx::Resource *pin)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  this->pInStream.pObject = 0;
  if ( pin )
    Scaleform::RefCountImpl::AddRef(pin);
  pObject = (Scaleform::RefCountVImpl *)this->pInStream.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pInStream.pObject = (Scaleform::File *)pin;
  this->StartOfFile = 1;
  this->SMgr.init_source = Scaleform::Render::JPEG::JPEGRwSource::InitSource;
  this->SMgr.fill_input_buffer = Scaleform::Render::JPEG::JPEGRwSource::FillInputBuffer;
  this->SMgr.skip_input_data = Scaleform::Render::JPEG::JPEGRwSource::SkipInputData;
  this->SMgr.resync_to_restart = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *, int))jpeg_resync_to_restart;
  this->SMgr.term_source = (void (__cdecl *)(jpeg_decompress_struct *))Scaleform::Render::JPEG::JPEGRwSource::TermSource;
  this->SMgr.bytes_in_buffer = 0;
  this->SMgr.next_input_byte = 0;
}
