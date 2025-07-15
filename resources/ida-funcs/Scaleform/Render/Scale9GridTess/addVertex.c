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
  Scaleform::Render::Scale9GridTess::TmpVertexType tmpVer; // [esp+4h] [ebp-Ch] BYREF

  tmpVer.Slope = 0.0;
  tmpVer.VerIdx = this->VerCount;
  tmpVer.AreaCode = areaCode;
  Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>::PushBack(ver, &tmpVer);
  p_x = &this->Vertices[this->VerCount].x;
  *p_x = x;
  p_x[1] = y;
  p_x[2] = u;
  p_x[3] = v;
  ++this->VerCount;
}
