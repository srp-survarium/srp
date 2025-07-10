bool __thiscall Scaleform::GFx::ASString::operator==(Scaleform::GFx::ASString *this, const char *str)
{
  return strcmp(this->pNode->pData, str) == 0;
}
