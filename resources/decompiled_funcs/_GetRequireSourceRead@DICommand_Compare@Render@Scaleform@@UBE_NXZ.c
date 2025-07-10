BOOL __thiscall Scaleform::Render::DICommand_Compare::GetRequireSourceRead(Scaleform::Render::DICommand_Compare *this)
{
  Scaleform::Render::DrawableImage *pObject; // eax

  pObject = this->pImage.pObject;
  return this->pSource.pObject == pObject || this->pImageCompare1.pObject == pObject;
}
