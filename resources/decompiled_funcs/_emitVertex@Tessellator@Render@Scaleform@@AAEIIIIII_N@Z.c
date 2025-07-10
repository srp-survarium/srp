unsigned int __thiscall Scaleform::Render::Tessellator::emitVertex(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        unsigned int ver,
        unsigned int style1,
        unsigned int style2,
        unsigned int flags,
        bool strictStyle)
{
  unsigned int result; // eax
  Scaleform::Render::TessVertex **Pages; // esi
  unsigned int v10; // edx
  unsigned int Size; // esi
  float v12; // ecx
  Scaleform::Render::TessVertex v2; // [esp+8h] [ebp-14h] BYREF

  result = ver & 0xFFFFFFF;
  Pages = this->MeshVertices.Pages;
  v10 = (unsigned int)&Pages[(ver & 0xFFFFFFF) >> 4][ver & 0xF];
  if ( *(_DWORD *)(v10 + 8) == -1 )
  {
    *(_WORD *)(v10 + 12) = style1;
    *(_WORD *)(v10 + 14) = style2;
    *(_WORD *)(v10 + 16) = flags;
    *(_DWORD *)(v10 + 8) = result;
    *(_WORD *)(v10 + 18) = meshIdx;
  }
  else if ( *(unsigned __int16 *)(v10 + 18) != meshIdx
         || *(unsigned __int16 *)(v10 + 12) != style1
         || *(unsigned __int16 *)(v10 + 14) != style2
         || strictStyle && *(unsigned __int16 *)(v10 + 16) != flags )
  {
    if ( *(_DWORD *)(v10 + 8) == result )
    {
LABEL_15:
      Size = this->MeshVertices.Size;
      *(_DWORD *)(v10 + 8) = Size;
      v12 = *(float *)(v10 + 4);
      v2.x = *(float *)v10;
      v2.y = v12;
      v2.Styles[0] = style1;
      v2.Styles[1] = style2;
      v2.Idx = Size;
      v2.Flags = flags;
      v2.Mesh = meshIdx;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &v2);
      return Size;
    }
    else
    {
      while ( 1 )
      {
        result = *(_DWORD *)(v10 + 8);
        v10 = (unsigned int)&Pages[result >> 4][result & 0xF];
        if ( *(unsigned __int16 *)(v10 + 18) == meshIdx
          && *(unsigned __int16 *)(v10 + 12) == style1
          && *(unsigned __int16 *)(v10 + 14) == style2
          && (!strictStyle || *(unsigned __int16 *)(v10 + 16) == flags) )
        {
          break;
        }
        if ( *(_DWORD *)(v10 + 8) == result )
          goto LABEL_15;
      }
    }
  }
  return result;
}
