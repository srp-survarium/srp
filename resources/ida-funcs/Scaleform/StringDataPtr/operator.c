BOOL __thiscall Scaleform::StringDataPtr::operator==(
        Scaleform::StringDataPtr *this,
        const Scaleform::StringDataPtr *other)
{
  const char *pStr; // edx
  const char *v3; // eax

  pStr = this->pStr;
  v3 = other->pStr;
  return other->pStr == this->pStr && other->Size == this->Size || pStr && v3 && !strncmp(pStr, v3, other->Size);
}
