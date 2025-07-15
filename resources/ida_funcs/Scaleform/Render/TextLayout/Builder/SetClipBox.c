void __thiscall Scaleform::Render::TextLayout::Builder::SetClipBox(
        Scaleform::Render::TextLayout::Builder *this,
        const Scaleform::Render::Rect<float> *b)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float ba; // [esp+Ch] [ebp+4h]

  ba = b->y1;
  x2 = b->x2;
  y2 = b->y2;
  this->ClipBox.x1 = b->x1;
  this->ClipBox.y1 = ba;
  this->ClipBox.x2 = x2;
  this->ClipBox.y2 = y2;
}
