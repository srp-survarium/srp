void __thiscall Scaleform::Render::PrimitiveFillManager::removeGradient(
        Scaleform::Render::PrimitiveFillManager *this,
        Scaleform::Render::GradientImage *img)
{
  Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::GradientImage *>(
    &this->Gradients,
    &img);
}
