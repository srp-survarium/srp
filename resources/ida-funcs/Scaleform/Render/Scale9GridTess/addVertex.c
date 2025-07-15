void __thiscall Scaleform::Render::Scale9GridTess::addVertex(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        float x,
        float y,
        float u,
        float v,
        unsigned int areaCode)
{
  float *p_x; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType val; // [esp+4h] [ebp-Ch] BYREF

  val.Slope = 0.0;
  val.VerIdx = this->VerCount;
  val.AreaCode = areaCode;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &val);
  p_x = &this->Vertices[this->VerCount].x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = u;
  p_x[3] = v;
  ++this->VerCount;
}
