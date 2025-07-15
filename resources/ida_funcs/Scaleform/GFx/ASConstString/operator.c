bool __thiscall Scaleform::GFx::ASConstString::operator!=(Scaleform::GFx::ASConstString *this, const char *str)
{
  return strcmp(this->pNode->pData, str) != 0;
}
