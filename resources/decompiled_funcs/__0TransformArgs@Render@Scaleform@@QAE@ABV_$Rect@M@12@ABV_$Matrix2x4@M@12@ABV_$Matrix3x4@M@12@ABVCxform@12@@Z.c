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
