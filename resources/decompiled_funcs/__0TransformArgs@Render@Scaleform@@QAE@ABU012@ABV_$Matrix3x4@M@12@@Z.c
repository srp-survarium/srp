void __thiscall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        const Scaleform::Render::TransformArgs *copy,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  float x2; // [esp+8h] [ebp-8h]
  float y2; // [esp+Ch] [ebp-4h]
  float copya; // [esp+14h] [ebp+4h]

  copya = copy->CullRect.y1;
  x2 = copy->CullRect.x2;
  y2 = copy->CullRect.y2;
  this->CullRect.x1 = copy->CullRect.x1;
  this->CullRect.y1 = copya;
  this->CullRect.x2 = x2;
  this->CullRect.y2 = y2;
  memcpy((unsigned __int8 *)&this->Mat3D, (unsigned __int8 *)mat, sizeof(this->Mat3D));
  this->Mat = Scaleform::Render::Matrix2x4<float>::Identity;
  qmemcpy(&this->Cx, &copy->Cx, sizeof(this->Cx));
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  memcpy((unsigned __int8 *)&this->ViewProj, (unsigned __int8 *)&copy->ViewProj, sizeof(this->ViewProj));
}
