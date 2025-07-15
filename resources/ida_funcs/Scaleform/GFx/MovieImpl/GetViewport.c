void __thiscall Scaleform::GFx::MovieImpl::GetViewport(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::Viewport *pviewDesc)
{
  qmemcpy(pviewDesc, &this->mViewport, sizeof(Scaleform::GFx::Viewport));
}
