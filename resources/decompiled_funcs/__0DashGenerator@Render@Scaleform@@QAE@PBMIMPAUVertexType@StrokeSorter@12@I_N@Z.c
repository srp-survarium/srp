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
  unsigned int i1; // [esp+4h] [ebp+4h]
  float i1a; // [esp+4h] [ebp+4h]
  float i1b; // [esp+4h] [ebp+4h]
  float dista; // [esp+8h] [ebp+8h]
  float distb; // [esp+8h] [ebp+8h]
  float dist; // [esp+8h] [ebp+8h]
  float dashStarta; // [esp+Ch] [ebp+Ch]
  float i2; // [esp+18h] [ebp+18h]
  unsigned int i2a; // [esp+18h] [ebp+18h]
  float i2c; // [esp+18h] [ebp+18h]
  float i2d; // [esp+18h] [ebp+18h]
  float i2b; // [esp+18h] [ebp+18h]
  float i2e; // [esp+18h] [ebp+18h]
  float i2f; // [esp+18h] [ebp+18h]
  float i2g; // [esp+18h] [ebp+18h]

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
      i2 = v11;
      this->CurrDashStart = 0.0;
      if ( CurrDash + 1 >= dashCount )
        this->CurrDash = 0;
      v9 = i2;
      if ( i2 <= 0.0 )
        goto LABEL_7;
    }
    this->CurrDashStart = v9;
  }
LABEL_7:
  v12 = 0;
  i2a = 0;
  i1 = 1;
  if ( this->VerCount > 1 )
  {
    v13 = 1;
    do
    {
      Vertices = this->Vertices;
      dashStarta = Vertices[v13].x - Vertices[v13 - 1].x;
      dista = Vertices[v13].y - Vertices[v13 - 1].y;
      distb = dista * dista + dashStarta * dashStarta;
      dist = sqrt(distb);
      if ( dist > 1.000000013351432e-10 )
      {
        if ( i2a < i1 - 1 )
        {
          Vertices[v8].x = Vertices[v13 - 1].x;
          Vertices[v8].y = Vertices[v13 - 1].y;
          Vertices[v8].Dist = Vertices[v13 - 1].Dist;
          *(_DWORD *)&Vertices[v8].segType = *(_DWORD *)&Vertices[v13 - 1].segType;
        }
        ++i2a;
        this->Vertices[v8++].Dist = dist;
      }
      ++v13;
      ++i1;
    }
    while ( i1 < this->VerCount );
    v12 = i2a;
  }
  this->Vertices[v12].Dist = 1.0e10;
  v15 = !this->Closed;
  v16 = v12 + 1;
  this->VerCount = v12 + 1;
  if ( !v15 && v16 > 2 )
  {
    v17 = this->Vertices;
    v18 = &v17[v16];
    i1a = v18[-1].x - v17->x;
    i2c = v18[-1].y - v17->y;
    i2d = i2c * i2c + i1a * i1a;
    i2b = sqrt(i2d);
    if ( i2b <= 1.000000013351432e-10 )
    {
      this->VerCount = v12;
      v19 = v12;
      i1b = v17[v19 - 1].x - v17->x;
      i2e = v17[v19 - 1].y - v17->y;
      i2f = i2e * i2e + i1b * i1b;
      i2g = sqrt(i2f);
      v17[v19 - 1].Dist = i2g;
    }
    else
    {
      v18[-1].Dist = i2b;
    }
  }
}
