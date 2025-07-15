void __thiscall Scaleform::Render::Rect<int>::Clear(Scaleform::Render::Rect<int> *this)
{
  Scaleform::Render::Size<int> sz; // [esp+0h] [ebp-8h] BYREF

  sz.Width = 0;
  sz.Height = 0;
  Scaleform::Render::Rect<int>::SetRect(this, 0, 0, &sz);
}
