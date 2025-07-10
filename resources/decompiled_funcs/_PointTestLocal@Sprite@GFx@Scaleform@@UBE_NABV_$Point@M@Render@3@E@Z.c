char __thiscall Scaleform::GFx::Sprite::PointTestLocal(
        Scaleform::GFx::Sprite *this,
        const Scaleform::Render::Point<float> *pt,
        int hitTestMask)
{
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // edx
  Scaleform::Render::Rect<float> *v5; // eax
  int v6; // ebx
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::Render::Rect<float> v9; // [esp+10h] [ebp-30h] BYREF
  float v10[8]; // [esp+20h] [ebp-20h] BYREF

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0 )
    return 0;
  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 1) == 0 )
  {
    GetBounds = this->GetBounds;
    v10[0] = 1.0;
    v10[1] = 0.0;
    v10[2] = 0.0;
    v10[3] = 0.0;
    v10[4] = 0.0;
    v10[6] = 0.0;
    v10[7] = 0.0;
    v10[5] = 1.0;
    v5 = GetBounds(this, &v9, (const Scaleform::Render::Matrix2x4<float> *)v10);
    if ( !Scaleform::Render::Rect<float>::Contains(v5, pt) )
      return 0;
  }
  if ( ((v6 = hitTestMask, (hitTestMask & 2) == 0) || this->GetVisible(this))
    && (Scaleform::GFx::DisplayObjContainer::PointTestLocal(this, pt, hitTestMask)
     || (pObject = this->pDrawingAPI.pObject) != 0
     && (LOBYTE(v6) = hitTestMask & 1,
         Scaleform::GFx::DrawingContext::DefPointTestLocal(pObject, v6, pt, hitTestMask & 1, this))) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
