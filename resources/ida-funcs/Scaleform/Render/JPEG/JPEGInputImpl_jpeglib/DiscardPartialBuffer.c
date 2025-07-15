void __thiscall Scaleform::Render::JPEG::JPEGInputImpl_jpeglib::DiscardPartialBuffer(
        Scaleform::Render::JPEG::JPEGInputImpl_jpeglib *this)
{
  jpeg_source_mgr *src; // eax

  src = this->CInfo.src;
  if ( src )
  {
    src->bytes_in_buffer = 0;
    src->next_input_byte = 0;
  }
}
