void __thiscall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        const Scaleform::Render::TransformArgs *copy)
{
  const Scaleform::Render::TransformArgs *v2; // eax
  float x2; // [esp+4h] [ebp-8h]
  float v4; // [esp+8h] [ebp-4h]
  float copya; // [esp+10h] [ebp+4h]

  v2 = copy;
  copya = copy->CullRect.y1;
  x2 = v2->CullRect.x2;
  v2 = (const Scaleform::Render::TransformArgs *)((char *)v2 + 80);
  v4 = *((float *)&v2[-1].bRecomputeViewProj + 3);
  this->CullRect.x1 = *(float *)&v2[-1].bRecomputeViewProj;
  this->CullRect.y1 = copya;
  this->CullRect.x2 = x2;
  this->CullRect.y2 = v4;
  this->viewState = (const Scaleform::Render::ViewMatrix3DState *)LODWORD(v2[-1].Cx.M[1][0]);
  this->projState = (const Scaleform::Render::ProjectionMatrix3DState *)LODWORD(v2[-1].Cx.M[1][1]);
  this->bRecomputeViewProj = (bool)v2->viewState;
  memcpy((unsigned __int8 *)&this->ViewProj, (unsigned __int8 *)v2, sizeof(this->ViewProj));
}


void __thiscall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        const Scaleform::Render::TransformArgs *copy,
        const Scaleform::Render::Matrix2x4<float> *mat)
{
  float x2; // [esp+4h] [ebp-8h]
  float y2; // [esp+8h] [ebp-4h]
  float copya; // [esp+10h] [ebp+4h]

  copya = copy->CullRect.y1;
  x2 = copy->CullRect.x2;
  y2 = copy->CullRect.y2;
  this->CullRect.x1 = copy->CullRect.x1;
  this->CullRect.y1 = copya;
  this->CullRect.x2 = x2;
  this->CullRect.y2 = y2;
  this->Mat = *mat;
  qmemcpy(&this->Cx, &copy->Cx, sizeof(this->Cx));
  this->viewState = copy->viewState;
  this->projState = copy->projState;
  this->bRecomputeViewProj = copy->bRecomputeViewProj;
  memcpy((unsigned __int8 *)&this->ViewProj, (unsigned __int8 *)&copy->ViewProj, sizeof(this->ViewProj));
}


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


void __thiscall Scaleform::Render::TransformArgs::TransformArgs(
        Scaleform::Render::TransformArgs *this,
        const Scaleform::Render::Rect<float> *cullRect,
        const Scaleform::Render::Matrix2x4<float> *mat2D,
        Scaleform::Render::Matrix3x4<float> *mat3D,
        const Scaleform::Render::Cxform *cx)
{
  float x2; // [esp+4h] [ebp-8h]
  float y2; // [esp+8h] [ebp-4h]
  float cullRecta; // [esp+10h] [ebp+4h]

  cullRecta = cullRect->y1;
  x2 = cullRect->x2;
  y2 = cullRect->y2;
  this->CullRect.x1 = cullRect->x1;
  this->CullRect.y1 = cullRecta;
  this->CullRect.x2 = x2;
  this->CullRect.y2 = y2;
  memcpy((unsigned __int8 *)&this->Mat3D, (unsigned __int8 *)mat3D, sizeof(this->Mat3D));
  this->viewState = 0;
  this->projState = 0;
  this->bRecomputeViewProj = 0;
  this->Mat = *mat2D;
  qmemcpy(&this->Cx, cx, sizeof(this->Cx));
}
