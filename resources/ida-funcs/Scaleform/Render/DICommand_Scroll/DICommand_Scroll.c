void __thiscall Scaleform::Render::DICommand_Scroll::DICommand_Scroll(
        Scaleform::Render::DICommand_Scroll *this,
        Scaleform::Render::DrawableImage *image,
        int x,
        int y)
{
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(struct Scaleform::Render::DrawableImage *, Scaleform::Render::Size<unsigned long> *); // edx
  int v7; // eax
  Scaleform::Render::Size<unsigned long> *(__thiscall *v8)(struct Scaleform::Render::DrawableImage *, Scaleform::Render::Size<unsigned long> *); // edx
  Scaleform::Render::Point<long> dp; // [esp+10h] [ebp-28h] BYREF
  Scaleform::Render::Size<unsigned long> v10; // [esp+18h] [ebp-20h] BYREF
  Scaleform::Render::Size<unsigned long> v11; // [esp+20h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> sr; // [esp+28h] [ebp-10h] BYREF
  int v13; // [esp+40h] [ebp+8h]

  GetSize = image->GetSize;
  dp.x = x;
  dp.y = y;
  v7 = (int)GetSize(image, &v10);
  v8 = image->GetSize;
  v13 = *(_DWORD *)(v7 + 4);
  sr.x1 = 0;
  sr.y1 = 0;
  sr.x2 = v8(image, &v11)->Width;
  sr.y2 = v13;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, image, image, &sr, &dp);
  this->X = x;
  this->Y = y;
  this->__vftable = (Scaleform::Render::DICommand_Scroll_vtbl *)&Scaleform::Render::DICommand_Scroll::`vftable';
}
