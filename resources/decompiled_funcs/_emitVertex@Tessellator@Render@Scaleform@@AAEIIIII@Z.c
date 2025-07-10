unsigned int __thiscall Scaleform::Render::Tessellator::emitVertex(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned int ver,
        unsigned int style,
        unsigned __int16 flags)
{
  Scaleform::Render::TessVertex **Pages; // esi
  unsigned int result; // eax
  unsigned int v7; // edx
  unsigned int Size; // esi
  Scaleform::Render::TessVertex v2; // [esp+8h] [ebp-14h] BYREF

  Pages = this->MeshVertices.Pages;
  result = ver & 0xFFFFFFF;
  v7 = (unsigned int)&Pages[(ver & 0xFFFFFFF) >> 4][ver & 0xF];
  if ( *(_DWORD *)(v7 + 8) == -1 )
  {
    *(_WORD *)(v7 + 14) = style;
    *(_WORD *)(v7 + 12) = style;
    *(_WORD *)(v7 + 16) = flags;
    *(_DWORD *)(v7 + 8) = result;
    *(_WORD *)(v7 + 18) = meshIdx;
  }
  else if ( *(unsigned __int16 *)(v7 + 18) != meshIdx || *(unsigned __int16 *)(v7 + 12) != style )
  {
    if ( *(_DWORD *)(v7 + 8) == result )
    {
LABEL_9:
      Size = this->MeshVertices.Size;
      *(_DWORD *)(v7 + 8) = Size;
      v2.x = *(float *)v7;
      v2.y = *(float *)(v7 + 4);
      v2.Idx = Size;
      v2.Styles[1] = style;
      v2.Styles[0] = style;
      v2.Flags = flags;
      v2.Mesh = meshIdx;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &v2);
      return Size;
    }
    else
    {
      while ( 1 )
      {
        result = *(_DWORD *)(v7 + 8);
        v7 = (unsigned int)&Pages[result >> 4][result & 0xF];
        if ( *(unsigned __int16 *)(v7 + 18) == meshIdx && *(unsigned __int16 *)(v7 + 12) == style )
          break;
        if ( *(_DWORD *)(v7 + 8) == result )
          goto LABEL_9;
      }
    }
  }
  return result;
}
