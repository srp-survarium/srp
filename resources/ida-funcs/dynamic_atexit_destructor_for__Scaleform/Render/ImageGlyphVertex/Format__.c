void dynamic_atexit_destructor_for__Scaleform::Render::ImageGlyphVertex::Format__()
{
  if ( Scaleform::Render::ImageGlyphVertex::Format.pSysFormat.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)Scaleform::Render::ImageGlyphVertex::Format.pSysFormat.pObject);
}
