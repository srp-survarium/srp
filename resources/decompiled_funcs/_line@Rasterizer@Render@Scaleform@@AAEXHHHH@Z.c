void __thiscall Scaleform::Render::Rasterizer::line(
        Scaleform::Render::Rasterizer *this,
        int x1,
        int y1,
        int x2,
        int y2)
{
  int v8; // ebp
  int v9; // ebx
  int v10; // edx
  int v11; // edi
  const Scaleform::Render::StrokeSorter::VertexType *p_CurrCell; // ecx
  int v13; // edi
  float x; // edx
  int y; // ebp
  int v16; // eax
  int v17; // ebp
  int v18; // edx
  bool v19; // zf
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // et2
  int v24; // ecx
  int v25; // ebp
  int v26; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int i; // edx
  int v31; // ebx
  int v32; // ebx
  int incr; // [esp+10h] [ebp-18h]
  int ey2; // [esp+14h] [ebp-14h]
  int fy1; // [esp+18h] [ebp-10h]
  int dy; // [esp+1Ch] [ebp-Ch]
  int fy2; // [esp+20h] [ebp-8h]
  int rem; // [esp+24h] [ebp-4h]
  int rema; // [esp+24h] [ebp-4h]
  int lift; // [esp+2Ch] [ebp+4h]
  int mod; // [esp+30h] [ebp+8h]
  int moda; // [esp+30h] [ebp+8h]
  int twoFx; // [esp+34h] [ebp+Ch]
  int first; // [esp+38h] [ebp+10h]
  int firsta; // [esp+38h] [ebp+10h]

  rem = x2 - x1;
  first = x2 >> 8;
  v8 = y2 - y1;
  v9 = x1 >> 8;
  v10 = y2 >> 8;
  v11 = y1 >> 8;
  dy = v8;
  ey2 = y2 >> 8;
  fy1 = (unsigned __int8)y1;
  fy2 = (unsigned __int8)y2;
  if ( x1 >> 8 < this->MinX )
    this->MinX = v9;
  if ( v9 > this->MaxX )
    this->MaxX = v9;
  if ( v11 < this->MinY )
    this->MinY = v11;
  if ( v11 > this->MaxY )
    this->MaxY = v11;
  if ( first < this->MinX )
    this->MinX = first;
  if ( first > this->MaxX )
    this->MaxX = first;
  if ( v10 < this->MinY )
    this->MinY = v10;
  if ( v10 > this->MaxY )
    this->MaxY = v10;
  p_CurrCell = (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell;
  if ( (this->CurrCell.x - v9) | (this->CurrCell.y - v11) )
  {
    if ( *(_QWORD *)&this->CurrCell.Cover )
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
        (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
    p_CurrCell = (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell;
    this->CurrCell.x = v9;
    this->CurrCell.y = v11;
    this->CurrCell.Cover = 0;
    this->CurrCell.Area = 0;
  }
  if ( v11 == ey2 )
  {
    Scaleform::Render::Rasterizer::horLine(this, v11, x1, (unsigned __int8)y1, x2, fy2);
  }
  else
  {
    incr = 1;
    firsta = 256;
    if ( rem )
    {
      v21 = rem * (256 - (unsigned __int8)y1);
      if ( v8 < 0 )
      {
        v21 = rem * (unsigned __int8)y1;
        v8 = -v8;
        firsta = 0;
        incr = -1;
        dy = v8;
      }
      v23 = v21 % v8;
      v22 = v21 / v8;
      v24 = v23;
      mod = v23;
      if ( v23 < 0 )
      {
        --v22;
        mod = v8 + v24;
      }
      v25 = v22 + x1;
      Scaleform::Render::Rasterizer::horLine(this, v11, x1, fy1, v22 + x1, firsta);
      v26 = incr + v11;
      if ( (this->CurrCell.y - v26) | (this->CurrCell.x - (v25 >> 8)) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
        this->CurrCell.x = v25 >> 8;
        this->CurrCell.y = v26;
        this->CurrCell.Cover = 0;
        this->CurrCell.Area = 0;
      }
      if ( v26 != ey2 )
      {
        v27 = dy;
        v28 = (rem << 8) / dy;
        v29 = (rem << 8) % dy;
        lift = v28;
        rema = v29;
        if ( v29 < 0 )
        {
          lift = --v28;
          rema = dy + v29;
        }
        moda = mod - dy;
        for ( i = 256 - firsta; ; i = 256 - firsta )
        {
          moda += rema;
          if ( moda >= 0 )
          {
            moda -= v27;
            ++v28;
          }
          v31 = v28 + v25;
          Scaleform::Render::Rasterizer::horLine(this, v26, v25, i, v28 + v25, firsta);
          v26 += incr;
          v25 = v31;
          v32 = v31 >> 8;
          if ( (this->CurrCell.y - v26) | (this->CurrCell.x - v32) )
          {
            if ( *(_QWORD *)&this->CurrCell.Cover )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell);
            this->CurrCell.x = v32;
            this->CurrCell.y = v26;
            this->CurrCell.Cover = 0;
            this->CurrCell.Area = 0;
          }
          if ( v26 == ey2 )
            break;
          v28 = lift;
          v27 = dy;
        }
      }
      Scaleform::Render::Rasterizer::horLine(this, v26, v25, 256 - firsta, x2, fy2);
    }
    else
    {
      twoFx = 2 * (x1 - (v9 << 8));
      if ( v8 < 0 )
      {
        firsta = 0;
        incr = -1;
      }
      v13 = incr + v11;
      this->CurrCell.Cover += firsta - (unsigned __int8)y1;
      x = p_CurrCell->x;
      y = this->CurrCell.y;
      this->CurrCell.Area += 2 * (x1 - (v9 << 8)) * (firsta - (unsigned __int8)y1);
      if ( (y - v13) | (LODWORD(x) - v9) )
      {
        if ( *(_QWORD *)&this->CurrCell.Cover )
          Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
            p_CurrCell);
        p_CurrCell = (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell;
        this->CurrCell.x = v9;
        this->CurrCell.y = v13;
        this->CurrCell.Cover = 0;
        this->CurrCell.Area = 0;
      }
      v16 = 2 * firsta - 256;
      v17 = twoFx * v16;
      if ( v13 != ey2 )
      {
        while ( 1 )
        {
          v13 += incr;
          v18 = this->CurrCell.y;
          this->CurrCell.Cover = v16;
          v19 = ((v18 - v13) | (LODWORD(p_CurrCell->x) - v9)) == 0;
          this->CurrCell.Area = v17;
          if ( !v19 )
          {
            if ( (2 * firsta - 256) | v17 )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                p_CurrCell);
            p_CurrCell = (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell;
            this->CurrCell.x = v9;
            this->CurrCell.y = v13;
            this->CurrCell.Cover = 0;
            this->CurrCell.Area = 0;
          }
          if ( v13 == ey2 )
            break;
          v16 = 2 * firsta - 256;
        }
      }
      v20 = firsta + fy2 - 256;
      this->CurrCell.Cover += v20;
      this->CurrCell.Area += twoFx * v20;
    }
  }
}
