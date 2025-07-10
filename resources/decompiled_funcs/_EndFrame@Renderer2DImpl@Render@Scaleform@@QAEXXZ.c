void __thiscall Scaleform::Render::Renderer2DImpl::EndFrame(Scaleform::Render::Renderer2DImpl *this)
{
  Scaleform::Render::GlyphCache *pObject; // ecx

  this->pHal.pObject->EndFrame(this->pHal.pObject);
  Scaleform::Render::ContextImpl::RenderNotify::EndFrameContextNotify(this);
  pObject = this->pGlyphCache.pObject;
  if ( pObject )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pObject);
}
