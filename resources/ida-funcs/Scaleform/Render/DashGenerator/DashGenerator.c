void __thiscall Scaleform::Render::DashGenerator::DashGenerator(
        Scaleform::Render::DashGenerator *this,
        const float *dashArray,
        unsigned int dashCount,
        float dashStart,
        Scaleform::Render::StrokeSorter::VertexType *ver,
        unsigned int verCount,
        bool closed)
{
  int v8; // ebp
  double v9; // st6
  unsigned int CurrDash; // ecx
  double v11; // st6
  unsigned int v12; // eax
  int v13; // ebx
  Scaleform::Render::StrokeSorter::VertexType *Vertices; // edi
  bool v15; // zf
  unsigned int v16; // ebx
  Scaleform::Render::StrokeSorter::VertexType *v17; // edi
  Scaleform::Render::StrokeSorter::VertexType *v18; // ebp
  int v19; // eax
  unsigned int v20; // [esp+4h] [ebp+4h]
  float v21; // [esp+4h] [ebp+4h]
  float v22; // [esp+4h] [ebp+4h]
  float v23; // [esp+8h] [ebp+8h]
  float v24; // [esp+8h] [ebp+8h]
  float v25; // [esp+8h] [ebp+8h]
  float v26; // [esp+Ch] [ebp+Ch]
  float v27; // [esp+18h] [ebp+18h]
  unsigned int v28; // [esp+18h] [ebp+18h]
  float v29; // [esp+18h] [ebp+18h]
  float v30; // [esp+18h] [ebp+18h]
  float v31; // [esp+18h] [ebp+18h]
  float v32; // [esp+18h] [ebp+18h]
  float v33; // [esp+18h] [ebp+18h]
  float v34; // [esp+18h] [ebp+18h]

  this->DashStart = dashStart;
  this->Vertices = ver;
  this->CurrRest = 0.0;
  this->CurrDashStart = 0.0;
  v8 = 0;
  this->Closed = closed;
  this->pDashArray = dashArray;
  this->DashCount = dashCount;
  this->CurrDash = 0;
  this->VerCount = verCount;
  this->Ver1 = 0;
  this->Ver2 = 0;
  this->Status = Status_Ready;
  this->SrcVertex = 0;
  if ( dashStart > 0.0 )
  {
    this->CurrDash = 0;
    this->CurrDashStart = 0.0;
    v9 = dashStart;
    while ( 1 )
    {
      CurrDash = this->CurrDash;
      if ( dashArray[CurrDash] >= v9 )
        break;
      v11 = v9 - dashArray[CurrDash];
      this->CurrDash = CurrDash + 1;
      v27 = v11;
      this->CurrDashStart = 0.0;
      if ( CurrDash + 1 >= dashCount )
        this->CurrDash = 0;
      v9 = v27;
      if ( v27 <= 0.0 )
        goto LABEL_7;
    }
    this->CurrDashStart = v9;
  }
LABEL_7:
  v12 = 0;
  v28 = 0;
  v20 = 1;
  if ( this->VerCount > 1 )
  {
    v13 = 1;
    do
    {
      Vertices = this->Vertices;
      v26 = Vertices[v13].x - Vertices[v13 - 1].x;
      v23 = Vertices[v13].y - Vertices[v13 - 1].y;
      v24 = v23 * v23 + v26 * v26;
      v25 = sqrt(v24);
      if ( v25 > 1.000000013351432e-10 )
      {
        if ( v28 < v20 - 1 )
        {
          Vertices[v8].x = Vertices[v13 - 1].x;
          Vertices[v8].y = Vertices[v13 - 1].y;
          Vertices[v8].Dist = Vertices[v13 - 1].Dist;
          *(_DWORD *)&Vertices[v8].segType = *(_DWORD *)&Vertices[v13 - 1].segType;
        }
        ++v28;
        this->Vertices[v8++].Dist = v25;
      }
      ++v13;
      ++v20;
    }
    while ( v20 < this->VerCount );
    v12 = v28;
  }
  this->Vertices[v12].Dist = 1.0e10;
  v15 = !this->Closed;
  v16 = v12 + 1;
  this->VerCount = v12 + 1;
  if ( !v15 && v16 > 2 )
  {
    v17 = this->Vertices;
    v18 = &v17[v16];
    v21 = v18[-1].x - v17->x;
    v29 = v18[-1].y - v17->y;
    v30 = v29 * v29 + v21 * v21;
    v31 = sqrt(v30);
    if ( v31 <= 1.000000013351432e-10 )
    {
      this->VerCount = v12;
      v19 = v12;
      v22 = v17[v19 - 1].x - v17->x;
      v32 = v17[v19 - 1].y - v17->y;
      v33 = v32 * v32 + v22 * v22;
      v34 = sqrt(v33);
      v17[v19 - 1].Dist = v34;
    }
    else
    {
      v18[-1].Dist = v31;
    }
  }
}
