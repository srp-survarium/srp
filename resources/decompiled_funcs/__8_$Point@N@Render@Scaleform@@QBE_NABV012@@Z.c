BOOL __thiscall Scaleform::Render::Point<double>::operator==(
        Scaleform::Render::Point<double> *this,
        const Scaleform::Render::Point<double> *pt)
{
  return pt->x == this->x && pt->y == this->y;
}
