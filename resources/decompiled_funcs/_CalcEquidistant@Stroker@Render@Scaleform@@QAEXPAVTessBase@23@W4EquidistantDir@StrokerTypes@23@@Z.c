void __thiscall Scaleform::Render::Stroker::CalcEquidistant(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        unsigned int dir)
{
  unsigned int Size; // ecx
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // ecx
  Scaleform::Render::StrokeVertex **v11; // ebp
  Scaleform::Render::TessBase *v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // edi
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int v17; // ebx
  unsigned int v18; // edx
  Scaleform::Render::StrokeVertex **Pages; // ebp
  const Scaleform::Render::StrokeVertex *v20; // eax
  float len1; // [esp+0h] [ebp-1Ch]
  float len2; // [esp+4h] [ebp-18h]
  unsigned int v23; // [esp+18h] [ebp-4h]
  unsigned int i; // [esp+24h] [ebp+8h]
  unsigned int ia; // [esp+24h] [ebp+8h]

  Size = this->Path.Path.Size;
  if ( Size > 2 )
  {
    if ( dir )
    {
      ia = Size;
      v13 = Size - 1;
      v23 = Size - 1;
      do
      {
        v14 = v13;
        if ( !v13 )
          v14 = this->Path.Path.Size;
        v15 = v14 - 1;
        v16 = v13;
        if ( !v13 )
          v16 = this->Path.Path.Size;
        v17 = this->Path.Path.Size;
        v18 = v16 - 1;
        if ( Size >= v17 )
          Size -= v17;
        Pages = this->Path.Path.Pages;
        v20 = &Pages[v13 >> 4][v13 & 0xF];
        len2 = Pages[v15 >> 4][v15 & 0xF].dist;
        v12 = tess;
        Scaleform::Render::Stroker::calcJoin(
          this,
          *(float *)&Pages,
          *(float *)&this,
          tess,
          &Pages[Size >> 4][Size & 0xF],
          v20,
          COERCE_FLOAT(&Pages[v18 >> 4][v18 & 0xF]),
          v20->dist,
          len2);
        Size = ia - 1;
        v13 = v23 - 1;
        ia = Size;
        --v23;
      }
      while ( Size );
    }
    else
    {
      v5 = 0;
      do
      {
        v6 = v5;
        if ( !v5 )
          v6 = this->Path.Path.Size;
        v7 = this->Path.Path.Size;
        v8 = v5 + 1;
        v9 = v6 - 1;
        i = v5 + 1;
        if ( v5 + 1 >= v7 )
          v8 -= v7;
        v10 = v5;
        if ( !v5 )
          v10 = this->Path.Path.Size;
        v11 = this->Path.Path.Pages;
        len1 = v11[v9 >> 4][v9 & 0xF].dist;
        v12 = tess;
        Scaleform::Render::Stroker::calcJoin(
          this,
          *(float *)&v11,
          *(float *)&this,
          tess,
          &v11[(v10 - 1) >> 4][(v10 - 1) & 0xF],
          &v11[v5 >> 4][v5 & 0xF],
          COERCE_FLOAT(&v11[v8 >> 4][v8 & 0xF]),
          len1,
          v11[v5 >> 4][v5 & 0xF].dist);
        v5 = i;
      }
      while ( i < this->Path.Path.Size );
    }
    v12->ClosePath(v12);
    v12->FinalizePath(v12, 0, 1u, 0, 0);
  }
  this->Path.Path.Size = 0;
}
