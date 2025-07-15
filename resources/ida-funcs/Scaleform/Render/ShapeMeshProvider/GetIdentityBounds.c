Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::GetIdentityBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  result->x1 = *((float *)&this->pMorphData + 2);
  result->y1 = *((float *)&this->pMorphData + 3);
  result->x2 = this->IdentityBounds.x1;
  result->y2 = this->IdentityBounds.y1;
  return v2;
}
