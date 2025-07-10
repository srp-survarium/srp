unsigned int __thiscall Scaleform::Render::DICommand_Compare::GetSourceImages(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DISourceImages *ps)
{
  ps->pImages[0] = this->pSource.pObject;
  ps->pImages[1] = this->pImageCompare1.pObject;
  return 2;
}
