void __thiscall Scaleform::GFx::DisplayObjContainer::SetScale9Grid(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::Rect<float> *Scale9Grid; // ecx
  bool v4; // bl
  Scaleform::Render::Rect<float> result; // [esp+10h] [ebp-10h] BYREF

  Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this, &result);
  v4 = Scale9Grid->x1 != rect->x1
    || Scale9Grid->x2 != rect->x2
    || Scale9Grid->y1 != rect->y1
    || Scale9Grid->y2 != rect->y2;
  Scaleform::GFx::DisplayObjectBase::SetScale9Grid(this, rect);
  if ( rect->x2 <= (double)rect->x1 || rect->y2 <= (double)rect->y1 )
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= ~1u;
  else
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 1u;
  if ( v4 )
    this->PropagateScale9GridExists(this);
}
