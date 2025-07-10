Scaleform::Render::TreeContainer *__thiscall Scaleform::GFx::Sprite::GetRenderContainer(Scaleform::GFx::Sprite *this)
{
  Scaleform::Render::TreeContainer *result; // eax

  result = Scaleform::GFx::InteractiveObject::GetRenderContainer(this);
  if ( this->pDrawingAPI.pObject )
    return (Scaleform::Render::TreeContainer *)Scaleform::Render::TreeContainer::GetAt(result, 1u);
  return result;
}
