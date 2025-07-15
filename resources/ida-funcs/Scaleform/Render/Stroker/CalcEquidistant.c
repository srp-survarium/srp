void __thiscall Scaleform::Render::Stroker::CalcEquidistant(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        Scaleform::Render::StrokerTypes::EquidistantDir dir)
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
  float v21; // [esp+0h] [ebp-1Ch]
  float dist; // [esp+4h] [ebp-18h]
  unsigned int v23; // [esp+18h] [ebp-4h]
  unsigned int v24; // [esp+24h] [ebp+8h]
  unsigned int v25; // [esp+24h] [ebp+8h]

  Size = this->Path.Path.Size;
  if ( Size > 2 )
  {
    if ( dir )
    {
      v25 = Size;
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
        dist = Pages[v15 >> 4][v15 & 0xF].dist;
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
          dist);
        Size = v25 - 1;
        v13 = v23 - 1;
        v25 = Size;
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
        v24 = v5 + 1;
        if ( v5 + 1 >= v7 )
          v8 -= v7;
        v10 = v5;
        if ( !v5 )
          v10 = this->Path.Path.Size;
        v11 = this->Path.Path.Pages;
        v21 = v11[v9 >> 4][v9 & 0xF].dist;
        v12 = tess;
        Scaleform::Render::Stroker::calcJoin(
          this,
          *(float *)&v11,
          *(float *)&this,
          tess,
          &v11[(v10 - 1) >> 4][(v10 - 1) & 0xF],
          &v11[v5 >> 4][v5 & 0xF],
          COERCE_FLOAT(&v11[v8 >> 4][v8 & 0xF]),
          v21,
          v11[v5 >> 4][v5 & 0xF].dist);
        v5 = v24;
      }
      while ( v24 < this->Path.Path.Size );
    }
    v12->ClosePath(v12);
    v12->FinalizePath(v12, 0, 1u, 0, 0);
  }
  this->Path.Path.Size = 0;
}
