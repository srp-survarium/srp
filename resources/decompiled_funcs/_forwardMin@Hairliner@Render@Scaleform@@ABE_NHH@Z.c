int __thiscall Scaleform::Render::Hairliner::forwardMin(
        Scaleform::Render::Hairliner *this,
        unsigned int idx,
        int start)
{
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // edx
  bool v5; // cc
  float y; // [esp+8h] [ebp+4h]

  Pages = this->SrcVertices.Pages;
  v5 = (int)idx <= start;
  y = Pages[idx >> 4][idx & 0xF].y;
  if ( v5 )
  {
    if ( y < (double)Pages[(idx + 1) >> 4][((_BYTE)idx + 1) & 0xF].y )
      return 1;
  }
  else if ( y <= (double)Pages[(idx - 1) >> 4][(idx - 1) & 0xF].y
         && Pages[(idx + 1) >> 4][((_BYTE)idx + 1) & 0xF].y > (double)y )
  {
    return 1;
  }
  return 0;
}
