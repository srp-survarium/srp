Scaleform::Render::TreeContainer *__thiscall Scaleform::Render::TreeContainer::NodeData::CloneCreate(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeContainer::NodeData> source; // [esp+0h] [ebp-4h] BYREF

  source.pC = this;
  return Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer,Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeContainer::NodeData>>(
           context,
           &source);
}
