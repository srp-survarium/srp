// attributes: thunk
Scaleform::Render::TreeContainer *__thiscall Scaleform::GFx::InteractiveObject::GetRenderContainer(
        Scaleform::GFx::InteractiveObject *this)
{
  return (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
}
