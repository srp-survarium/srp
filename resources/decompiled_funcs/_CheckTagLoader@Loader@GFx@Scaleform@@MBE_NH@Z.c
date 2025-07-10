BOOL __thiscall Scaleform::GFx::Loader::CheckTagLoader(Scaleform::GFx::Loader *this, unsigned int tagType)
{
  return this->pImpl
      && Scaleform::GFx::LoaderImpl::GetTagLoader(
           tagType,
           (void (__stdcall **)(Scaleform::GFx::LoadProcess *, const Scaleform::GFx::TagInfo *))&tagType);
}
