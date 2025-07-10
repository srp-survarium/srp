bool __thiscall Scaleform::GFx::ASString::operator>(
        Scaleform::GFx::ASString *this,
        const Scaleform::GFx::ASString *str)
{
  return this->pNode != str->pNode && !Scaleform::GFx::ASString::operator<(this, str);
}
