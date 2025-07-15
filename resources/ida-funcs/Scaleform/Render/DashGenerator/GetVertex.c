unsigned int __thiscall Scaleform::Render::DashGenerator::GetVertex(
        Scaleform::Render::DashGenerator *this,
        float *x,
        float *y)
{
  Scaleform::Render::DashGenerator::DashStatus Status; // edx
  unsigned int result; // eax
  Scaleform::Render::StrokeSorter::VertexType *Vertices; // eax
  const Scaleform::Render::StrokeSorter::VertexType *Ver1; // eax
  unsigned int CurrDash; // edx
  BOOL v8; // esi
  double v9; // st7
  const Scaleform::Render::StrokeSorter::VertexType *v10; // edx
  const Scaleform::Render::StrokeSorter::VertexType *v11; // eax
  const Scaleform::Render::StrokeSorter::VertexType *Ver2; // edx
  const Scaleform::Render::StrokeSorter::VertexType *v13; // eax
  bool v14; // zf
  unsigned int SrcVertex; // edx
  unsigned int VerCount; // eax
  float v17; // [esp+0h] [ebp-4h]
  float v18; // [esp+0h] [ebp-4h]

  Status = this->Status;
  while ( 1 )
  {
    if ( Status == Status_Ready )
    {
      if ( this->DashCount < 2 || this->VerCount < 2 )
        return 4;
      Vertices = this->Vertices;
      this->Ver1 = Vertices;
      this->Ver2 = Vertices + 1;
      Ver1 = this->Ver1;
      this->Status = Status_Polyline;
      this->SrcVertex = 1;
      this->CurrRest = Ver1->Dist;
      *x = Ver1->x;
      *y = this->Ver1->y;
      return 0;
    }
    if ( Status == Status_Polyline )
      break;
    if ( Status == Status_Stop )
      return 4;
  }
  CurrDash = this->CurrDash;
  v8 = (CurrDash & 1) == 0;
  v17 = (float)this->pDashArray[CurrDash] - this->CurrDashStart;
  if ( v17 >= (double)this->CurrRest )
  {
    Ver2 = this->Ver2;
    this->CurrDashStart = this->CurrDashStart + this->CurrRest;
    *x = Ver2->x;
    *y = this->Ver2->y;
    v13 = this->Ver2;
    ++this->SrcVertex;
    v14 = !this->Closed;
    SrcVertex = this->SrcVertex;
    this->Ver1 = v13;
    this->CurrRest = v13->Dist;
    if ( v14 )
    {
      if ( SrcVertex < this->VerCount )
      {
        result = v8;
        this->Ver2 = &this->Vertices[SrcVertex];
        return result;
      }
    }
    else
    {
      VerCount = this->VerCount;
      if ( SrcVertex <= VerCount )
      {
        this->Ver2 = &this->Vertices[SrcVertex < VerCount ? SrcVertex : 0];
        return v8;
      }
    }
    result = v8;
    this->Status = Status_Stop;
    return result;
  }
  v9 = this->CurrRest - v17;
  this->CurrDash = CurrDash + 1;
  v18 = v9;
  this->CurrRest = v18;
  if ( CurrDash + 1 >= this->DashCount )
    this->CurrDash = 0;
  v10 = this->Ver2;
  v11 = this->Ver1;
  this->CurrDashStart = 0.0;
  *x = v10->x - v18 * (v10->x - v11->x) / v11->Dist;
  *y = this->Ver2->y - (this->Ver2->y - this->Ver1->y) * this->CurrRest / this->Ver1->Dist;
  return v8;
}
