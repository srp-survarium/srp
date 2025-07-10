int __thiscall Scaleform::GFx::AS2::StartOfYear(void *y)
{
  return 365 * ((int)y - 1970) + ((int)y - 1969) / 4 + ((int)y - 1601) / 400 - ((int)y - 1901) / 100;
}
