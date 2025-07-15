void __thiscall Scaleform::GFx::ButtonDef::SetScale9Grid(
        Scaleform::GFx::ButtonDef *this,
        const Scaleform::Render::Rect<float> *r)
{
  Scaleform::GFx::Scale9Grid *pScale9Grid; // eax
  Scaleform::GFx::Scale9Grid *v4; // eax
  int v7; // [esp+8h] [ebp-Ch] BYREF
  float y2; // [esp+Ch] [ebp-8h]
  float x2; // [esp+10h] [ebp-4h]
  float v10; // [esp+18h] [ebp+4h]
  float y1; // [esp+18h] [ebp+4h]

  pScale9Grid = this->pScale9Grid;
  if ( pScale9Grid )
  {
    y1 = r->y1;
    x2 = r->x2;
    y2 = r->y2;
    pScale9Grid->Rect.x1 = r->x1;
    pScale9Grid->Rect.y1 = y1;
    pScale9Grid->Rect.x2 = x2;
    pScale9Grid->Rect.y2 = y2;
  }
  else
  {
    v7 = 258;
    v4 = (Scaleform::GFx::Scale9Grid *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         16,
                                         &v7);
    if ( v4 )
    {
      v10 = r->y1;
      y2 = r->x2;
      x2 = r->y2;
      v4->Rect.x1 = r->x1;
      v4->Rect.y1 = v10;
      v4->Rect.x2 = y2;
      v4->Rect.y2 = x2;
      this->pScale9Grid = v4;
    }
    else
    {
      this->pScale9Grid = 0;
    }
  }
}
