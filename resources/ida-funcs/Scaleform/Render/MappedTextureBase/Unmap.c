void __thiscall Scaleform::Render::MappedTextureBase::Unmap(Scaleform::Render::MappedTextureBase *this, bool __formal)
{
  this->pTexture->pMap = 0;
  this->pTexture = 0;
  this->StartMipLevel = 0;
  this->LevelCount = 0;
}
