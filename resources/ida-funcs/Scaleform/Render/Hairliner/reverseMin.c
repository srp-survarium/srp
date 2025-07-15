int __thiscall Scaleform::Render::Hairliner::reverseMin(Scaleform::Render::Hairliner *this, int idx, int end)
{
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // edx
  bool v5; // cc
  unsigned int v6; // eax
  float y; // [esp+8h] [ebp+4h]

  Pages = this->SrcVertices.Pages;
  v5 = idx < end;
  y = Pages[(unsigned int)idx >> 4][idx & 0xF].y;
  v6 = idx - 1;
  if ( v5 )
  {
    if ( y < (double)Pages[v6 >> 4][v6 & 0xF].y
      && Pages[(unsigned int)(idx + 1) >> 4][((_BYTE)idx + 1) & 0xF].y >= (double)y )
    {
      return 1;
    }
  }
  else if ( y < (double)Pages[v6 >> 4][v6 & 0xF].y )
  {
    return 1;
  }
  return 0;
}
