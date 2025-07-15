const char *__thiscall Scaleform::GFx::SpriteDef::GetFileURL(Scaleform::GFx::SpriteDef *this)
{
  return (const char *)((this->pMovieDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8);
}
