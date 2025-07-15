char __thiscall Scaleform::Render::Font::IsCJK(Scaleform::Render::Font *this, unsigned __int16 code)
{
  int v2; // edx
  unsigned __int16 v3; // ax
  int v4; // ecx

  v2 = 0;
  v3 = 4352;
  v4 = 0;
  while ( code < v3 || code > (unsigned __int16)word_6F06BA[v4] )
  {
    v2 += 2;
    v4 = v2;
    v3 = ranges[v2];
    if ( !v3 )
      return 0;
  }
  return 1;
}
