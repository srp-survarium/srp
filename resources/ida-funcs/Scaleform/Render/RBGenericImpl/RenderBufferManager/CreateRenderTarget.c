Scaleform::Render::RBGenericImpl::RenderTarget *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::CreateRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        Scaleform::GFx::Resource *texture)
{
  if ( this->pTextureManager.pObject )
    return Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(this, size, type, format, texture);
  else
    return 0;
}
