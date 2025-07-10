void __thiscall Scaleform::GFx::ASString::operator+=(Scaleform::GFx::ASString *this, char *str)
{
  Scaleform::GFx::ASString::Append(this, str, (Scaleform::GFx::ASStringNode *)strlen(str));
}
