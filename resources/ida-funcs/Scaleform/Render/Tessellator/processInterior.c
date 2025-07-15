void __thiscall Scaleform::Render::Tessellator::processInterior(
        Scaleform::Render::Tessellator *this,
        float yb,
        float yTop,
        unsigned int perceiveFlag)
{
  double v4; // st7
  Scaleform::Render::Tessellator *v5; // ebp
  signed int Size; // ebx
  unsigned int v7; // esi
  Scaleform::Render::Tessellator::IntersectionType **Pages; // edx
  unsigned int v10; // ecx
  double v11; // st6
  double v12; // st7
  Scaleform::Render::Tessellator *v13; // ecx
  unsigned int v14; // edi
  Scaleform::Render::Tessellator::IntersectionType **v15; // edx
  unsigned int v16; // ecx
  float y; // [esp+14h] [ebp-8h]
  Scaleform::Render::Tessellator *v19; // [esp+18h] [ebp-4h]
  float v20; // [esp+28h] [ebp+Ch]

  v4 = yb;
  y = yb;
  v5 = this;
  Size = this->Intersections.Size;
  v7 = 0;
  if ( Size < 4 )
  {
    v11 = yb;
LABEL_9:
    while ( v7 < Size )
    {
      y = v5->Intersections.Pages[v7 >> 4][v7 & 0xF].y;
      v11 = y;
      if ( y > v4 )
        break;
      ++v7;
      perceiveFlag = 1;
    }
  }
  else
  {
    Pages = this->Intersections.Pages;
    v10 = 2;
    while ( 1 )
    {
      y = Pages[v7 >> 4][v7 & 0xF].y;
      v11 = y;
      if ( y > v4 )
        break;
      perceiveFlag = 1;
      y = Pages[(v10 - 1) >> 4][((_BYTE)v10 - 1) & 0xF].y;
      v11 = y;
      if ( y > v4 )
      {
        ++v7;
        break;
      }
      y = Pages[v10 >> 4][v10 & 0xF].y;
      v11 = y;
      if ( y > v4 )
      {
        v7 += 2;
        break;
      }
      y = Pages[(v10 + 1) >> 4][(v10 + 1) & 0xF].y;
      v11 = y;
      if ( y > v4 )
      {
        v7 += 3;
        break;
      }
      v7 += 4;
      v10 += 4;
      if ( v7 >= Size - 3 )
      {
        v5 = this;
        goto LABEL_9;
      }
    }
    v5 = this;
  }
  v12 = v11;
  Scaleform::Render::Tessellator::swapChains(v5, 0, v7);
  if ( perceiveFlag )
  {
    Scaleform::Render::Tessellator::perceiveStyles(v13, &v5->InteriorChains);
    v12 = y;
  }
  v14 = v5->Intersections.Size;
  if ( v7 < v14 )
  {
    while ( 1 )
    {
      v20 = v12;
      v19 = (Scaleform::Render::Tessellator *)v7;
      if ( v7 < v14 )
      {
        if ( (int)(v14 - v7) < 4 )
        {
LABEL_32:
          while ( v7 < v14 )
          {
            v20 = v5->Intersections.Pages[v7 >> 4][v7 & 0xF].y;
            if ( v20 > v12 )
              break;
            ++v7;
          }
        }
        else
        {
          v15 = v5->Intersections.Pages;
          v16 = v7 + 2;
          while ( 1 )
          {
            v20 = v15[v7 >> 4][v7 & 0xF].y;
            if ( v20 > v12 )
              break;
            v20 = v15[(v16 - 1) >> 4][((_BYTE)v16 - 1) & 0xF].y;
            if ( v20 > v12 )
            {
              ++v7;
              break;
            }
            v20 = v15[v16 >> 4][v16 & 0xF].y;
            if ( v20 > v12 )
            {
              v7 += 2;
              break;
            }
            v20 = v15[(v16 + 1) >> 4][(v16 + 1) & 0xF].y;
            if ( v20 > v12 )
            {
              v7 += 3;
              break;
            }
            v7 += 4;
            v16 += 4;
            if ( v7 >= v14 - 3 )
              goto LABEL_32;
          }
        }
      }
      Scaleform::Render::Tessellator::perceiveStyles(v5, &v5->InteriorChains);
      Scaleform::Render::Tessellator::sweepScanbeam(v5, &v5->InteriorChains, yb);
      Scaleform::Render::Tessellator::swapChains(v5, (unsigned int)v19, v7);
      v14 = v5->Intersections.Size;
      yb = y;
      y = v20;
      if ( v7 >= v14 )
        break;
      v12 = v20;
    }
  }
  Scaleform::Render::Tessellator::perceiveStyles(v5, &v5->ActiveChains);
  if ( yTop > (double)y )
    Scaleform::Render::Tessellator::sweepScanbeam(v5, &v5->ActiveChains, y);
}
