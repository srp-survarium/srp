Scaleform::Render::CacheAsBitmapFilter *__thiscall Scaleform::Render::CacheAsBitmapFilter::Clone(
        Scaleform::Render::CacheAsBitmapFilter *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::CacheAsBitmapFilter *result; // eax
  Scaleform::Render::CacheAsBitmapFilter *v3; // esi

  result = Scaleform::Render::CacheAsBitmapFilter::GetInstance();
  v3 = result;
  if ( result )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)result);
    return v3;
  }
  return result;
}
