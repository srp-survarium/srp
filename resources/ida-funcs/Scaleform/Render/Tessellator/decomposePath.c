void __thiscall Scaleform::Render::Tessellator::decomposePath(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::Tessellator::PathType *path)
{
  const Scaleform::Render::Tessellator::PathType *v2; // ebx
  int start; // esi
  Scaleform::Render::Tessellator *i; // ebp
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // edx
  signed int v6; // ecx
  unsigned int j; // edx
  Scaleform::Render::Tessellator::SrcVertexType **v8; // eax
  signed int end; // esi
  Scaleform::Render::Tessellator::SrcVertexType **v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  signed int v13; // ecx
  unsigned int v14; // edi
  unsigned int k; // edx
  Scaleform::Render::Tessellator::SrcVertexType **v16; // eax
  float y; // [esp+14h] [ebp-8h]
  unsigned int v19; // [esp+14h] [ebp-8h]
  float v20; // [esp+14h] [ebp-8h]
  signed int v21; // [esp+18h] [ebp-4h]

  v2 = path;
  start = path->start;
  for ( i = this; start < (signed int)path->end; ++start )
  {
    Pages = i->SrcVertices.Pages;
    y = Pages[(unsigned int)start >> 4][start & 0xF].y;
    if ( start > (signed int)path->start )
    {
      if ( y <= (double)Pages[(unsigned int)(start - 1) >> 4][(start - 1) & 0xF].y )
      {
        v6 = start + 1;
        if ( Pages[(unsigned int)(start + 1) >> 4][((_BYTE)start + 1) & 0xF].y > (double)y )
        {
LABEL_7:
          v19 = 1;
          for ( j = v6 + 1; v6 < (signed int)path->end; ++j )
          {
            v8 = i->SrcVertices.Pages;
            i = this;
            if ( v8[(unsigned int)v6 >> 4][v6 & 0xF].y >= (double)v8[j >> 4][j & 0xF].y )
              break;
            ++v19;
            ++v6;
          }
          Scaleform::Render::Tessellator::buildEdgeList(i, start, v19, 1, path->leftStyle, path->rightStyle);
          start = start + v19 - 1;
        }
      }
    }
    else
    {
      v6 = start + 1;
      if ( y < (double)Pages[(unsigned int)(start + 1) >> 4][((_BYTE)start + 1) & 0xF].y )
        goto LABEL_7;
    }
  }
  end = path->end;
  v21 = path->start;
  if ( end > (signed int)path->start )
  {
    do
    {
      v10 = i->SrcVertices.Pages;
      v20 = v10[(unsigned int)end >> 4][end & 0xF].y;
      v11 = (unsigned int)(end - 1) >> 4;
      v12 = (end - 1) & 0xF;
      if ( end < (signed int)v2->end )
      {
        if ( v20 < (double)v10[v11][v12].y && v10[(unsigned int)(end + 1) >> 4][(end + 1) & 0xF].y >= (double)v20 )
        {
LABEL_19:
          v13 = end - 1;
          v14 = 1;
          for ( k = end - 2; v13 > v21; --k )
          {
            v16 = i->SrcVertices.Pages;
            v2 = path;
            i = this;
            if ( v16[(unsigned int)v13 >> 4][v13 & 0xF].y >= (double)v16[k >> 4][k & 0xF].y )
              break;
            ++v14;
            --v13;
          }
          Scaleform::Render::Tessellator::buildEdgeList(i, end, v14, -1, v2->leftStyle, v2->rightStyle);
          end += 1 - v14;
        }
      }
      else if ( v20 < (double)v10[v11][v12].y )
      {
        goto LABEL_19;
      }
      --end;
      v21 = v2->start;
    }
    while ( end > (signed int)v2->start );
  }
}
