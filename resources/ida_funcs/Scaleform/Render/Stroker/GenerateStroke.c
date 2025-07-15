void __userpurge Scaleform::Render::Stroker::GenerateStroke(
        Scaleform::Render::Stroker *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        float a4@<edi>,
        Scaleform::Render::TessBase *tess,
        int a6,
        int a7,
        Scaleform::Render::TessBase *a8)
{
  unsigned int v9; // eax
  unsigned int Size; // edi
  unsigned int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edi
  unsigned int v14; // ecx
  Scaleform::Render::StrokeVertex **Pages; // ebp
  Scaleform::Render::TessBase *v16; // edi
  unsigned int v17; // ecx
  unsigned int v18; // eax
  unsigned int v19; // edi
  unsigned int v20; // edi
  unsigned int v21; // edx
  unsigned int v22; // ebx
  unsigned int v23; // edx
  Scaleform::Render::StrokeVertex **v24; // ebp
  const Scaleform::Render::StrokeVertex *v25; // eax
  Scaleform::Render::TessBase *v26; // ebx
  unsigned int v27; // edx
  unsigned int v28; // ecx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int v31; // edi
  unsigned int v32; // eax
  Scaleform::Render::StrokeVertex **v33; // ebp
  Scaleform::Render::StrokeVertex *v34; // ebx
  int v35; // ecx
  double v36; // st7
  const Scaleform::Render::StrokeVertex *v37; // ecx
  unsigned int v38; // ecx
  Scaleform::Render::StrokeVertex **v39; // edi
  int v40; // ebp
  unsigned int v41; // edi
  unsigned int v42; // eax
  unsigned int v43; // eax
  unsigned int v44; // ecx
  unsigned int v45; // edx
  unsigned int v46; // eax
  Scaleform::Render::StrokeVertex **v47; // ebp
  float len1; // [esp+10h] [ebp-20h]
  float len2; // [esp+14h] [ebp-1Ch]
  float v51; // [esp+18h] [ebp-18h]
  float v53; // [esp+1Ch] [ebp-14h]
  float dist; // [esp+20h] [ebp-10h]
  unsigned int i; // [esp+28h] [ebp-8h]
  unsigned int ia; // [esp+28h] [ebp-8h]
  unsigned int v57; // [esp+2Ch] [ebp-4h]
  Scaleform::Render::TessBase *tessa; // [esp+34h] [ebp+4h]
  unsigned int v59; // [esp+38h] [ebp+8h]

  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  if ( this->Path.Path.Size > 1 )
  {
    if ( this->Closed )
    {
      v9 = 0;
      do
      {
        Size = v9;
        if ( !v9 )
          Size = this->Path.Path.Size;
        v11 = this->Path.Path.Size;
        v12 = v9 + 1;
        v13 = Size - 1;
        i = v9 + 1;
        if ( v9 + 1 >= v11 )
          v12 -= v11;
        v14 = v9;
        if ( !v9 )
          v14 = this->Path.Path.Size;
        Pages = this->Path.Path.Pages;
        len1 = Pages[v13 >> 4][v13 & 0xF].dist;
        v16 = tess;
        Scaleform::Render::Stroker::calcJoin(
          this,
          *(float *)&Pages,
          *(float *)&this,
          tess,
          &Pages[(v14 - 1) >> 4][(v14 - 1) & 0xF],
          &Pages[v9 >> 4][v9 & 0xF],
          COERCE_FLOAT(&Pages[v12 >> 4][v12 & 0xF]),
          len1,
          Pages[v9 >> 4][v9 & 0xF].dist);
        v9 = i;
      }
      while ( i < this->Path.Path.Size );
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, int, int))tess->ClosePath)(tess, LODWORD(a4), a3, a2);
      tess->FinalizePath(tess, 0, 1u, 0, 0);
      v17 = this->Path.Path.Size;
      tessa = (Scaleform::Render::TessBase *)v17;
      if ( v17 )
      {
        v18 = v17 - 1;
        v59 = v17 - 1;
        do
        {
          v19 = v18;
          if ( !v18 )
            v19 = this->Path.Path.Size;
          v20 = v19 - 1;
          v21 = v18;
          if ( !v18 )
            v21 = this->Path.Path.Size;
          v22 = this->Path.Path.Size;
          v23 = v21 - 1;
          if ( v17 >= v22 )
            v17 -= v22;
          v24 = this->Path.Path.Pages;
          v25 = &v24[v18 >> 4][v18 & 0xF];
          dist = v24[v20 >> 4][v20 & 0xF].dist;
          v16 = a8;
          Scaleform::Render::Stroker::calcJoin(
            this,
            *(float *)&v24,
            *(float *)&this,
            a8,
            &v24[v17 >> 4][v17 & 0xF],
            v25,
            COERCE_FLOAT(&v24[v23 >> 4][v23 & 0xF]),
            v25->dist,
            dist);
          v17 = (unsigned int)&tessa[-1].__vftable + 3;
          v18 = v59 - 1;
          tessa = (Scaleform::Render::TessBase *)v17;
          --v59;
        }
        while ( v17 );
      }
      v16->ClosePath(v16);
      v16->FinalizePath(v16, 0, 1u, 0, 0);
    }
    else
    {
      v26 = tess;
      Scaleform::Render::Stroker::calcCap(
        this,
        (int)tess,
        a3,
        tess,
        *(const Scaleform::Render::StrokeVertex **)this->Path.Path.Pages,
        (const Scaleform::Render::StrokeVertex *)*this->Path.Path.Pages + 1,
        (*this->Path.Path.Pages)->dist,
        this->StartLineCap,
        a4,
        *(float *)&a3);
      v27 = 2;
      v28 = 1;
      if ( this->Path.Path.Size > 2 )
      {
        ia = 2;
        do
        {
          v29 = v28;
          if ( !v28 )
            v29 = this->Path.Path.Size;
          v30 = this->Path.Path.Size;
          v31 = v29 - 1;
          if ( v27 >= v30 )
            v27 -= v30;
          v32 = v28;
          if ( !v28 )
            v32 = this->Path.Path.Size;
          v33 = this->Path.Path.Pages;
          v34 = v33[v28 >> 4];
          v35 = v28 & 0xF;
          v36 = v34[v35].dist;
          v37 = &v34[v35];
          len2 = v36;
          v26 = tess;
          Scaleform::Render::Stroker::calcJoin(
            this,
            *(float *)&v33,
            *(float *)&this,
            tess,
            &v33[(v32 - 1) >> 4][(v32 - 1) & 0xF],
            v37,
            COERCE_FLOAT(&v33[v27 >> 4][v27 & 0xF]),
            v33[v31 >> 4][v31 & 0xF].dist,
            len2);
          v28 = ia;
          v27 = ia + 1;
          ia = v27;
        }
        while ( v27 < this->Path.Path.Size );
      }
      v38 = this->Path.Path.Size;
      v39 = this->Path.Path.Pages;
      v40 = (int)v39[(v38 - 2) >> 4];
      Scaleform::Render::Stroker::calcCap(
        this,
        (int)v26,
        v40,
        v26,
        &v39[(v38 - 1) >> 4][(v38 - 1) & 0xF],
        (const Scaleform::Render::StrokeVertex *)(v40 + 12 * (((_BYTE)v38 - 2) & 0xF)),
        *(float *)(v40 + 12 * (((_BYTE)v38 - 2) & 0xF) + 8),
        this->EndLineCap,
        v51,
        v53);
      v41 = this->Path.Path.Size - 2;
      if ( this->Path.Path.Size != 2 )
      {
        do
        {
          v42 = v41;
          if ( !v41 )
            v42 = this->Path.Path.Size;
          v57 = v42 - 1;
          v43 = v41;
          if ( !v41 )
            v43 = this->Path.Path.Size;
          v44 = this->Path.Path.Size;
          v45 = v43 - 1;
          v46 = v41 + 1;
          if ( v41 + 1 >= v44 )
            v46 -= v44;
          v47 = this->Path.Path.Pages;
          v26 = tess;
          Scaleform::Render::Stroker::calcJoin(
            this,
            *(float *)&v47,
            *(float *)&this,
            tess,
            &v47[v46 >> 4][v46 & 0xF],
            &v47[v41 >> 4][v41 & 0xF],
            COERCE_FLOAT(&v47[v45 >> 4][v45 & 0xF]),
            v47[v41 >> 4][v41 & 0xF].dist,
            v47[v57 >> 4][v57 & 0xF].dist);
          --v41;
        }
        while ( v41 );
      }
      v26->ClosePath(v26);
      v26->FinalizePath(v26, 0, 1u, 0, 0);
    }
  }
  this->Closed = 0;
  this->Path.Path.Size = 0;
}
