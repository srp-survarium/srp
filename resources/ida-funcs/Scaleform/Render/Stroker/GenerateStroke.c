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
  unsigned int v39; // edi
  unsigned int v40; // eax
  unsigned int v41; // eax
  unsigned int v42; // ecx
  unsigned int v43; // edx
  unsigned int v44; // eax
  Scaleform::Render::StrokeVertex **v45; // ebp
  float dist; // [esp+10h] [ebp-20h]
  float v47; // [esp+14h] [ebp-1Ch]
  float v49; // [esp+18h] [ebp-18h]
  float v51; // [esp+20h] [ebp-10h]
  unsigned int v52; // [esp+28h] [ebp-8h]
  int v53; // [esp+28h] [ebp-8h]
  unsigned int v54; // [esp+2Ch] [ebp-4h]
  unsigned int v55; // [esp+34h] [ebp+4h]
  unsigned int v56; // [esp+38h] [ebp+8h]

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
        v52 = v9 + 1;
        if ( v9 + 1 >= v11 )
          v12 -= v11;
        v14 = v9;
        if ( !v9 )
          v14 = this->Path.Path.Size;
        Pages = this->Path.Path.Pages;
        dist = Pages[v13 >> 4][v13 & 0xF].dist;
        v16 = tess;
        Scaleform::Render::Stroker::calcJoin(
          this,
          *(float *)&Pages,
          *(float *)&this,
          tess,
          &Pages[(v14 - 1) >> 4][(v14 - 1) & 0xF],
          &Pages[v9 >> 4][v9 & 0xF],
          COERCE_FLOAT(&Pages[v12 >> 4][v12 & 0xF]),
          dist,
          Pages[v9 >> 4][v9 & 0xF].dist);
        v9 = v52;
      }
      while ( v52 < this->Path.Path.Size );
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, int, int))tess->ClosePath)(tess, LODWORD(a4), a3, a2);
      tess->FinalizePath(tess, 0, 1u, 0, 0);
      v17 = this->Path.Path.Size;
      v55 = v17;
      if ( v17 )
      {
        v18 = v17 - 1;
        v56 = v17 - 1;
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
          v51 = v24[v20 >> 4][v20 & 0xF].dist;
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
            v51);
          v17 = v55 - 1;
          v18 = v56 - 1;
          v55 = v17;
          --v56;
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
        tess,
        *(const Scaleform::Render::StrokeVertex **)this->Path.Path.Pages,
        (const Scaleform::Render::StrokeVertex *)*this->Path.Path.Pages + 1,
        (*this->Path.Path.Pages)->dist,
        this->StartLineCap,
        a4);
      v27 = 2;
      v28 = 1;
      if ( this->Path.Path.Size > 2 )
      {
        v53 = 2;
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
          v47 = v36;
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
            v47);
          v28 = v53;
          v27 = v53 + 1;
          v53 = v27;
        }
        while ( v27 < this->Path.Path.Size );
      }
      v38 = this->Path.Path.Size;
      Scaleform::Render::Stroker::calcCap(
        this,
        v26,
        &this->Path.Path.Pages[(v38 - 1) >> 4][(v38 - 1) & 0xF],
        &this->Path.Path.Pages[(v38 - 2) >> 4][((_BYTE)v38 - 2) & 0xF],
        this->Path.Path.Pages[(v38 - 2) >> 4][((_BYTE)v38 - 2) & 0xF].dist,
        this->EndLineCap,
        v49);
      v39 = this->Path.Path.Size - 2;
      if ( this->Path.Path.Size != 2 )
      {
        do
        {
          v40 = v39;
          if ( !v39 )
            v40 = this->Path.Path.Size;
          v54 = v40 - 1;
          v41 = v39;
          if ( !v39 )
            v41 = this->Path.Path.Size;
          v42 = this->Path.Path.Size;
          v43 = v41 - 1;
          v44 = v39 + 1;
          if ( v39 + 1 >= v42 )
            v44 -= v42;
          v45 = this->Path.Path.Pages;
          v26 = tess;
          Scaleform::Render::Stroker::calcJoin(
            this,
            *(float *)&v45,
            *(float *)&this,
            tess,
            &v45[v44 >> 4][v44 & 0xF],
            &v45[v39 >> 4][v39 & 0xF],
            COERCE_FLOAT(&v45[v43 >> 4][v43 & 0xF]),
            v45[v39 >> 4][v39 & 0xF].dist,
            v45[v54 >> 4][v54 & 0xF].dist);
          --v39;
        }
        while ( v39 );
      }
      v26->ClosePath(v26);
      v26->FinalizePath(v26, 0, 1u, 0, 0);
    }
  }
  this->Closed = 0;
  this->Path.Path.Size = 0;
}
