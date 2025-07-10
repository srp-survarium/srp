void __thiscall Scaleform::GFx::DrawTextImpl::SetRect(
        Scaleform::GFx::DrawTextImpl *this,
        const Scaleform::Render::Rect<float> *viewRect)
{
  Scaleform::Render::TreeText *pObject; // ecx
  Scaleform::Render::Rect<float> r; // [esp+0h] [ebp-10h] BYREF

  pObject = this->pTextNode.pObject;
  r.x1 = viewRect->x1 * 20.0;
  r.y1 = viewRect->y1 * 20.0;
  r.x2 = viewRect->x2 * 20.0;
  r.y2 = 20.0 * viewRect->y2;
  Scaleform::Render::TreeText::SetBounds(pObject, &r);
}
