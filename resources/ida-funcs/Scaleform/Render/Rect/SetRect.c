void __thiscall Scaleform::Render::Rect<int>::SetRect(
        Scaleform::Render::Rect<int> *this,
        const Scaleform::Render::Rect<int> *rc)
{
  int y2; // edx
  int x2; // esi
  int x1; // eax

  y2 = rc->y2;
  x2 = rc->x2;
  x1 = rc->x1;
  this->y1 = rc->y1;
  this->x2 = x2;
  this->x1 = x1;
  this->y2 = y2;
}


void __thiscall Scaleform::Render::Rect<int>::SetRect(
        Scaleform::Render::Rect<int> *this,
        int x,
        int y,
        const Scaleform::Render::Size<int> *sz)
{
  int v4; // edx
  int v5; // eax

  v4 = x + sz->Width;
  v5 = y + sz->Height;
  this->x1 = x;
  this->y1 = y;
  this->x2 = v4;
  this->y2 = v5;
}
