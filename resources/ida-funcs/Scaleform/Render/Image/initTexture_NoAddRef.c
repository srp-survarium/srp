void __thiscall Scaleform::Render::Image::initTexture_NoAddRef(
        Scaleform::Render::Image *this,
        Scaleform::Render::Texture *ptexture)
{
  InterlockedExchange((volatile LONG *)&this->pTexture, (LONG)ptexture);
}
