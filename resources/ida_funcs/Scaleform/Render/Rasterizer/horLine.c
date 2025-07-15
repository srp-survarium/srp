void __thiscall Scaleform::Render::Rasterizer::horLine(
        Scaleform::Render::Rasterizer *this,
        int ey,
        int x1,
        int y1,
        int x2,
        int y2)
{
  int v7; // ebx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // ebx
  int v15; // edx
  int v16; // ebx
  int v17; // edi
  int x; // edx
  Scaleform::Render::Rasterizer::Cell *p_CurrCell; // ebp
  int v20; // eax
  int v21; // eax
  int v22; // et2
  int v23; // ecx
  int v24; // ebx
  int Cover; // ecx
  int v26; // edx
  int v27; // eax
  int incr; // [esp+10h] [ebp-18h]
  int first; // [esp+14h] [ebp-14h]
  int rem; // [esp+18h] [ebp-10h]
  int lift; // [esp+1Ch] [ebp-Ch]
  int ex2; // [esp+20h] [ebp-8h]
  int fx2; // [esp+24h] [ebp-4h]
  int mod; // [esp+30h] [ebp+8h]
  int moda; // [esp+30h] [ebp+8h]
  int y1a; // [esp+34h] [ebp+Ch]
  int x2a; // [esp+38h] [ebp+10h]

  v7 = x2 >> 8;
  v8 = x1 >> 8;
  v9 = (unsigned __int8)x1;
  ex2 = x2 >> 8;
  fx2 = (unsigned __int8)x2;
  if ( y1 == y2 )
  {
    if ( (this->CurrCell.y - ey) | (this->CurrCell.x - v7) )
    {
      if ( *(_QWORD *)&this->CurrCell.Cover )
        Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
          (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
      this->CurrCell.x = v7;
      this->CurrCell.y = ey;
      this->CurrCell.Cover = 0;
      this->CurrCell.Area = 0;
    }
  }
  else
  {
    v10 = y2 - y1;
    if ( v8 == v7 )
    {
      v11 = (unsigned __int8)x1 + (unsigned __int8)x2;
    }
    else
    {
      v12 = v10 * (256 - (unsigned __int8)x1);
      v13 = x2 - x1;
      first = 256;
      v14 = v13;
      incr = 1;
      x2a = x2 - x1;
      if ( v13 < 0 )
      {
        v14 = -v13;
        v12 = (unsigned __int8)x1 * v10;
        first = 0;
        incr = -1;
        x2a = -v13;
      }
      v15 = v12 % v14;
      v16 = v12 / v14;
      mod = v15;
      if ( v15 < 0 )
      {
        --v16;
        mod = x2a + v15;
      }
      v17 = incr + v8;
      x = this->CurrCell.x;
      this->CurrCell.Cover += v16;
      this->CurrCell.Area += v16 * (v9 + first);
      p_CurrCell = &this->CurrCell;
      if ( (this->CurrCell.y - ey) | (x - v17) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
        p_CurrCell->x = v17;
        this->CurrCell.y = ey;
        this->CurrCell.Cover = 0;
        this->CurrCell.Area = 0;
      }
      y1a = v16 + y1;
      if ( v17 != ex2 )
      {
        v20 = (y2 + v16 - y1a) << 8;
        v22 = v20 % x2a;
        v21 = v20 / x2a;
        v23 = v22;
        lift = v21;
        rem = v22;
        if ( v22 < 0 )
        {
          --v21;
          v23 += x2a;
          lift = v21;
          rem = v23;
        }
        moda = mod - x2a;
        while ( 1 )
        {
          moda += v23;
          if ( moda >= 0 )
          {
            moda -= x2a;
            ++v21;
          }
          this->CurrCell.Cover += v21;
          y1a += v21;
          v17 += incr;
          v24 = this->CurrCell.y - ey;
          Cover = this->CurrCell.Cover;
          v26 = v21;
          v27 = p_CurrCell->x;
          this->CurrCell.Area += v26 << 8;
          if ( v24 | (v27 - v17) )
          {
            if ( __PAIR64__(Cover, this->CurrCell.Area) )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
            p_CurrCell->x = v17;
            this->CurrCell.y = ey;
            this->CurrCell.Cover = 0;
            this->CurrCell.Area = 0;
          }
          if ( v17 == ex2 )
            break;
          v23 = rem;
          v21 = lift;
        }
      }
      v10 = y2 - y1a;
      v11 = fx2 - first + 256;
    }
    this->CurrCell.Cover += v10;
    this->CurrCell.Area += v10 * v11;
  }
}
