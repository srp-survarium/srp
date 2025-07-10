Scaleform::Render::RBGenericImpl::RenderTarget *__thiscall Scaleform::Render::RBGenericImpl::RenderBufferManager::createRenderTarget(
        Scaleform::Render::RBGenericImpl::RenderBufferManager *this,
        const Scaleform::Render::Size<unsigned long> *size,
        Scaleform::Render::RenderBufferType type,
        Scaleform::Render::ImageFormat format,
        Scaleform::GFx::Resource *texture)
{
  Scaleform::Render::RenderTarget *v6; // eax
  _DWORD *v7; // esi
  Scaleform::RefCountVImpl *v8; // ecx
  unsigned int Width; // eax
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v11 = 75;
  v6 = (Scaleform::Render::RenderTarget *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            this,
                                            76,
                                            &v11);
  v7 = &v6->__vftable;
  if ( !v6 )
    return 0;
  Scaleform::Render::RenderTarget::RenderTarget(v6, this, type, size);
  v7[11] = 0;
  v7[12] = 0;
  v7[13] = v7;
  v7[14] = 0;
  v7[15] = 0;
  v7[16] = 0;
  *v7 = &Scaleform::Render::RBGenericImpl::RenderTarget::`vftable';
  v7[17] = 0;
  v7[18] = 0;
  v7[15] = format;
  if ( texture )
    Scaleform::RefCountImpl::AddRef(texture);
  v8 = (Scaleform::RefCountVImpl *)v7[17];
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v7[17] = texture;
  Width = size->Width;
  v7[10] = size->Height;
  v7[7] = 0;
  v7[8] = 0;
  v7[9] = Width;
  return (Scaleform::Render::RBGenericImpl::RenderTarget *)v7;
}
