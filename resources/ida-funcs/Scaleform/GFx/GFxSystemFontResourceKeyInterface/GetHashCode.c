unsigned int __thiscall Scaleform::GFx::GFxSystemFontResourceKeyInterface::GetHashCode(
        Scaleform::GFx::GFxSystemFontResourceKeyInterface *this,
        _DWORD *hdata)
{
  return Scaleform::String::BernsteinHashFunctionCIS(
           (char *)((hdata[3] & 0xFFFFFFFC) + 8),
           *(_DWORD *)(hdata[3] & 0xFFFFFFFC) & 0x7FFFFFFF,
           0x1505u)
       ^ hdata[2]
       ^ hdata[4]
       ^ (hdata[2] >> 7);
}
