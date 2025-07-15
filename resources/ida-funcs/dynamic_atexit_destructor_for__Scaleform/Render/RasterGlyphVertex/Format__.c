void dynamic_atexit_destructor_for__Scaleform::Render::RasterGlyphVertex::Format__()
{
  if ( Scaleform::Render::RasterGlyphVertex::Format.pSysFormat.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)Scaleform::Render::RasterGlyphVertex::Format.pSysFormat.pObject);
}
