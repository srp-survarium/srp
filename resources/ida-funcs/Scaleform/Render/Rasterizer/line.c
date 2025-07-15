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
  int v33; // [esp+10h] [ebp-18h]
  int v34; // [esp+14h] [ebp-14h]
  int y1a; // [esp+18h] [ebp-10h]
  int v36; // [esp+1Ch] [ebp-Ch]
  int y2a; // [esp+20h] [ebp-8h]
  int v38; // [esp+24h] [ebp-4h]
  int v39; // [esp+24h] [ebp-4h]
  int x1a; // [esp+2Ch] [ebp+4h]
  int v41; // [esp+30h] [ebp+8h]
  int v42; // [esp+30h] [ebp+8h]
  int x2a; // [esp+34h] [ebp+Ch]
  int v44; // [esp+38h] [ebp+10h]
  int v45; // [esp+38h] [ebp+10h]

  v38 = x2 - x1;
  v44 = x2 >> 8;
  v8 = y2 - y1;
  v9 = x1 >> 8;
  v10 = y2 >> 8;
  v11 = y1 >> 8;
  v36 = v8;
  v34 = y2 >> 8;
  y1a = (unsigned __int8)y1;
  y2a = (unsigned __int8)y2;
  if ( x1 >> 8 < this->MinX )
    this->MinX = v9;
  if ( v9 > this->MaxX )
    this->MaxX = v9;
  if ( v11 < this->MinY )
    this->MinY = v11;
  if ( v11 > this->MaxY )
    this->MaxY = v11;
  if ( v44 < this->MinX )
    this->MinX = v44;
  if ( v44 > this->MaxX )
    this->MaxX = v44;
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
  if ( v11 == v34 )
  {
    Scaleform::Render::Rasterizer::horLine(this, v11, x1, (unsigned __int8)y1, x2, y2a);
  }
  else
  {
    v33 = 1;
    v45 = 256;
    if ( v38 )
    {
      v21 = v38 * (256 - (unsigned __int8)y1);
      if ( v8 < 0 )
      {
        v21 = v38 * (unsigned __int8)y1;
        v8 = -v8;
        v45 = 0;
        v33 = -1;
        v36 = v8;
      }
      v23 = v21 % v8;
      v22 = v21 / v8;
      v24 = v23;
      v41 = v23;
      if ( v23 < 0 )
      {
        --v22;
        v41 = v8 + v24;
      }
      v25 = v22 + x1;
      Scaleform::Render::Rasterizer::horLine(this, v11, x1, y1a, v22 + x1, v45);
      v26 = v33 + v11;
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
      if ( v26 != v34 )
      {
        v27 = v36;
        v28 = (v38 << 8) / v36;
        v29 = (v38 << 8) % v36;
        x1a = v28;
        v39 = v29;
        if ( v29 < 0 )
        {
          x1a = --v28;
          v39 = v36 + v29;
        }
        v42 = v41 - v36;
        for ( i = 256 - v45; ; i = 256 - v45 )
        {
          v42 += v39;
          if ( v42 >= 0 )
          {
            v42 -= v27;
            ++v28;
          }
          v31 = v28 + v25;
          Scaleform::Render::Rasterizer::horLine(this, v26, v25, i, v28 + v25, v45);
          v26 += v33;
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
          if ( v26 == v34 )
            break;
          v28 = x1a;
          v27 = v36;
        }
      }
      Scaleform::Render::Rasterizer::horLine(this, v26, v25, 256 - v45, x2, y2a);
    }
    else
    {
      x2a = 2 * (x1 - (v9 << 8));
      if ( v8 < 0 )
      {
        v45 = 0;
        v33 = -1;
      }
      v13 = v33 + v11;
      this->CurrCell.Cover += v45 - (unsigned __int8)y1;
      x = p_CurrCell->x;
      y = this->CurrCell.y;
      this->CurrCell.Area += 2 * (x1 - (v9 << 8)) * (v45 - (unsigned __int8)y1);
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
      v16 = 2 * v45 - 256;
      v17 = x2a * v16;
      if ( v13 != v34 )
      {
        while ( 1 )
        {
          v13 += v33;
          v18 = this->CurrCell.y;
          this->CurrCell.Cover = v16;
          v19 = ((v18 - v13) | (LODWORD(p_CurrCell->x) - v9)) == 0;
          this->CurrCell.Area = v17;
          if ( !v19 )
          {
            if ( (2 * v45 - 256) | v17 )
              Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::PushBack(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->Cells,
                p_CurrCell);
            p_CurrCell = (const Scaleform::Render::StrokeSorter::VertexType *)&this->CurrCell;
            this->CurrCell.x = v9;
            this->CurrCell.y = v13;
            this->CurrCell.Cover = 0;
            this->CurrCell.Area = 0;
          }
          if ( v13 == v34 )
            break;
          v16 = 2 * v45 - 256;
        }
      }
      v20 = v45 + y2a - 256;
      this->CurrCell.Cover += v20;
      this->CurrCell.Area += x2a * v20;
    }
  }
}
