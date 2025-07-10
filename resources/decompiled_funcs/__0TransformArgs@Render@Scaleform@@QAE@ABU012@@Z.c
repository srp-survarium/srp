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
