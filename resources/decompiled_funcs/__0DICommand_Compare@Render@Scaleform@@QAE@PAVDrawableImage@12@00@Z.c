void __thiscall Scaleform::Render::DICommand_Compare::DICommand_Compare(
        Scaleform::Render::DICommand_Compare *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *cmp0,
        Scaleform::Render::DrawableImage *cmp1)
{
  Scaleform::Render::Size<unsigned long> *v5; // eax
  int Width; // ecx
  Scaleform::Render::Point<long> dp; // [esp+Ch] [ebp-20h] BYREF
  _BYTE v8[8]; // [esp+14h] [ebp-18h] BYREF
  Scaleform::Render::Rect<long> sr; // [esp+1Ch] [ebp-10h] BYREF

  v5 = image->GetSize(image, v8);
  Width = v5->Width;
  sr.y2 = v5->Height;
  sr.x2 = Width;
  dp.x = 0;
  dp.y = 0;
  sr.x1 = 0;
  sr.y1 = 0;
  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, image, cmp0, &sr, &dp);
  this->__vftable = (Scaleform::Render::DICommand_Compare_vtbl *)&Scaleform::Render::DICommand_Compare::`vftable';
  if ( cmp1 )
    cmp1->AddRef(cmp1);
  this->pImageCompare1.pObject = cmp1;
}
