void __thiscall Scaleform::GFx::SpriteDef::SetScale9Grid(
        Scaleform::GFx::SpriteDef *this,
        const Scaleform::Render::Rect<float> *r)
{
  Scaleform::GFx::Scale9Grid *v3; // eax
  Scaleform::GFx::Scale9Grid *pScale9Grid; // eax
  float x2; // [esp+Ch] [ebp-8h] BYREF
  float y2; // [esp+10h] [ebp-4h]
  float y1; // [esp+18h] [ebp+4h]

  if ( !this->pScale9Grid )
  {
    LODWORD(x2) = 258;
    v3 = (Scaleform::GFx::Scale9Grid *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         16,
                                         &x2);
    if ( v3 )
    {
      v3->Rect.x1 = 0.0;
      v3->Rect.y1 = 0.0;
      v3->Rect.x2 = 0.0;
      v3->Rect.y2 = 0.0;
    }
    else
    {
      v3 = 0;
    }
    this->pScale9Grid = v3;
  }
  pScale9Grid = this->pScale9Grid;
  y1 = r->y1;
  x2 = r->x2;
  y2 = r->y2;
  pScale9Grid->Rect.x1 = r->x1;
  pScale9Grid->Rect.y1 = y1;
  pScale9Grid->Rect.x2 = x2;
  pScale9Grid->Rect.y2 = y2;
}
