void __thiscall Scaleform::Render::Text::CachedValue<Scaleform::Render::Rect<float>>::SetValue(
        Scaleform::Render::Text::CachedValue<Scaleform::Render::Rect<float> > *this,
        const Scaleform::Render::Rect<float> *v,
        unsigned __int16 counter)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float va; // [esp+Ch] [ebp+4h]

  va = v->y1;
  x2 = v->x2;
  y2 = v->y2;
  this->Value.x1 = v->x1;
  this->FormatCounter = counter;
  this->Value.y1 = va;
  this->Value.x2 = x2;
  this->Value.y2 = y2;
}
