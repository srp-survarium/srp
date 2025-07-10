void __thiscall Scaleform::Render::ContextImpl::Context::ForceUpdateImages(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // eax

  v1 = this->pSnapshots[0];
  if ( v1 )
    v1->ForceUpdateImagesFlag = 1;
}
