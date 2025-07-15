int __thiscall Scaleform::Render::TextureImage::Unmap(Scaleform::Render::TextureImage *this)
{
  return ((int (__thiscall *)(Scaleform::Render::Texture *volatile))this->pTexture.Value->Unmap)(this->pTexture.Value);
}
