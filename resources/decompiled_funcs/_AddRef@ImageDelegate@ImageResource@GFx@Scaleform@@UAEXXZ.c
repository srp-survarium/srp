void __thiscall Scaleform::GFx::ImageResource::ImageDelegate::AddRef(
        Scaleform::GFx::ImageResource::ImageDelegate *this)
{
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)&this[-1].pTexture);
}
