unsigned int __thiscall Scaleform::GFx::SpriteDef::GetFileBytes(Scaleform::GFx::SpriteDef *this)
{
  return this->pMovieDef->pData.pObject->Header.FileLength;
}
