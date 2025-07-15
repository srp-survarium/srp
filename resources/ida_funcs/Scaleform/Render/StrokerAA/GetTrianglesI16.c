void __thiscall Scaleform::Render::StrokerAA::GetTrianglesI16(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        unsigned __int16 *idx,
        unsigned int start,
        unsigned int num)
{
  unsigned int i; // edi
  unsigned __int16 *v8; // edx
  unsigned __int16 *v9; // eax

  for ( i = num; i; --i )
  {
    v8 = (unsigned __int16 *)&this->Triangles.Pages[start >> 4][start & 0xF];
    *idx = *v8;
    v9 = idx + 1;
    *v9++ = v8[2];
    *v9 = v8[4];
    idx = v9 + 1;
    ++start;
  }
}
