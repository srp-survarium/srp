bool __thiscall Scaleform::Render::DrawableImage::createTextureFromManager(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::HAL *phal,
        Scaleform::Render::TextureManager *tmanager)
{
  unsigned int Height; // eax
  unsigned int v5; // ecx
  unsigned int Width; // eax
  Scaleform::Render::TextureManager_vtbl *v7; // ebx
  Scaleform::Render::ImageFormat (__thiscall *GetDrawableImageFormat)(Scaleform::Render::TextureManager *); // edx
  int v9; // eax
  unsigned int v10; // eax
  Scaleform::Render::DrawableImage *pObject; // eax
  Scaleform::Render::Texture *v12; // eax
  Scaleform::Render::Texture *v13; // edi
  Scaleform::Render::RenderTarget *v15; // eax
  Scaleform::Render::RenderTarget *v16; // ecx
  Scaleform::Render::RenderTarget *v17; // edi
  Scaleform::Render::Size<unsigned long> texSize; // [esp+14h] [ebp-8h] BYREF

  Height = this->ISize.Height;
  v5 = 1;
  if ( Height )
    v5 = Height;
  Width = this->ISize.Width;
  if ( !Width )
    Width = 1;
  v7 = tmanager->Scaleform::RefCountBase<Scaleform::Render::TextureManager,75>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  texSize.Width = Width;
  GetDrawableImageFormat = v7->GetDrawableImageFormat;
  texSize.Height = v5;
  v9 = ((int (__thiscall *)(Scaleform::Render::TextureManager *, int))GetDrawableImageFormat)(tmanager, 1152);
  if ( !((unsigned __int8 (__thiscall *)(Scaleform::Render::TextureManager *, int))v7->IsNonPow2Supported)(tmanager, v9) )
  {
    texSize.Width = (((((((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                       | ((texSize.Width - 1) >> 1)
                       | (texSize.Width - 1)) >> 4)
                     | ((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                     | ((texSize.Width - 1) >> 1)
                     | (texSize.Width - 1)) >> 8)
                   | ((((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                     | ((texSize.Width - 1) >> 1)
                     | (texSize.Width - 1)) >> 4)
                   | ((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                   | ((texSize.Width - 1) >> 1)
                   | (texSize.Width - 1)
                   | ((((((((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                         | ((texSize.Width - 1) >> 1)
                         | (texSize.Width - 1)) >> 4)
                       | ((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                       | ((texSize.Width - 1) >> 1)
                       | (texSize.Width - 1)) >> 8)
                     | ((((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                       | ((texSize.Width - 1) >> 1)
                       | (texSize.Width - 1)) >> 4)
                     | ((((texSize.Width - 1) >> 1) | (texSize.Width - 1)) >> 2)
                     | ((texSize.Width - 1) >> 1)
                     | (texSize.Width - 1)) >> 16))
                  + 1;
    v10 = ((((((((texSize.Height - 1) >> 1) | (texSize.Height - 1)) >> 2)
            | ((texSize.Height - 1) >> 1)
            | (texSize.Height - 1)) >> 4)
          | ((((texSize.Height - 1) >> 1) | (texSize.Height - 1)) >> 2)
          | ((texSize.Height - 1) >> 1)
          | (texSize.Height - 1)) >> 8)
        | ((((((texSize.Height - 1) >> 1) | (texSize.Height - 1)) >> 2)
          | ((texSize.Height - 1) >> 1)
          | (texSize.Height - 1)) >> 4)
        | ((((texSize.Height - 1) >> 1) | (texSize.Height - 1)) >> 2)
        | ((texSize.Height - 1) >> 1)
        | (texSize.Height - 1);
    texSize.Height = (v10 | HIWORD(v10)) + 1;
  }
  pObject = (Scaleform::Render::DrawableImage *)this->pDelegateImage.pObject;
  if ( !pObject )
    pObject = this;
  v12 = tmanager->CreateTexture(tmanager, this->Format, 1, &texSize, 1152, pObject, 0);
  v13 = v12;
  if ( !v12 )
    return 0;
  Scaleform::Render::Image::initTexture_NoAddRef(this, v12);
  v15 = phal->CreateRenderTarget(phal, v13, 0);
  v16 = this->pRT.pObject;
  v17 = v15;
  if ( v16 )
    v16->Release(v16);
  this->pRT.pObject = v17;
  return v17 != 0;
}
