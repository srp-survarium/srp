BOOL __thiscall Scaleform::GFx::StaticTextDef::DefPointTestLocal(
        Scaleform::GFx::StaticTextDef *this,
        const Scaleform::Render::Point<float> *pt,
        bool testShape,
        const Scaleform::GFx::DisplayObjectBase *pinst)
{
  return this->TextRect.x2 >= (double)pt->x
      && this->TextRect.x1 <= (double)pt->x
      && this->TextRect.y2 >= (double)pt->y
      && this->TextRect.y1 <= (double)pt->y;
}
