unsigned int __thiscall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::GetHashCode(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        _DWORD *hdata)
{
  return Scaleform::String::BernsteinHashFunction(
           (char *)((hdata[2] & 0xFFFFFFFC) + 8),
           *(_DWORD *)(hdata[2] & 0xFFFFFFFC) & 0x7FFFFFFF,
           0x1505u)
       ^ hdata[3]
       ^ hdata[6]
       ^ hdata[4]
       ^ ((unsigned int)(hdata[3] ^ hdata[6]) >> 7);
}
