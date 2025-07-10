bool __thiscall Scaleform::Render::DICommand_PaletteMap::GetRequireSourceRead(
        Scaleform::Render::DICommand_PaletteMap *this)
{
  return this->pImage.pObject == this->pSource.pObject;
}
