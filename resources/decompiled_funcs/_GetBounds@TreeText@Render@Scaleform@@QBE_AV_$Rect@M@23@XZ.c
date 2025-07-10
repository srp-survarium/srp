Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::TreeText::GetBounds(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Text::DocView *v2; // ecx
  const Scaleform::Render::Rect<float> *ViewRect; // eax
  double y2; // st7
  Scaleform::Render::Rect<float> *v5; // eax

  v2 = *(Scaleform::Render::Text::DocView **)(*(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                                                        + 4
                                                        * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000))
                                                         / 28)
                                                        + 20)
                                            + 144);
  if ( v2 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(v2);
    result->x1 = ViewRect->x1;
    result->y1 = ViewRect->y1;
    result->x2 = ViewRect->x2;
    y2 = ViewRect->y2;
    v5 = result;
    result->y2 = y2;
  }
  else
  {
    v5 = result;
    result->x1 = 0.0;
    result->y1 = 0.0;
    result->x2 = 0.0;
    result->y2 = 0.0;
  }
  return v5;
}
