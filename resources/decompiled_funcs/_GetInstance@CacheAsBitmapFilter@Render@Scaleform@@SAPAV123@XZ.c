Scaleform::Render::CacheAsBitmapFilter *__cdecl Scaleform::Render::CacheAsBitmapFilter::GetInstance()
{
  if ( (`Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::`local static guard' & 1) == 0 )
  {
    `Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::`local static guard' |= 1u;
    `Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::instance.RefCount = 1;
    `Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::instance.Type = Filter_CacheAsBitmap;
    `Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::instance.Frozen = 0;
    `Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::instance.__vftable = (Scaleform::Render::CacheAsBitmapFilter_vtbl *)&Scaleform::Render::CacheAsBitmapFilter::`vftable';
    atexit(`Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::`dynamic atexit destructor for 'instance'');
  }
  return &`Scaleform::Render::CacheAsBitmapFilter::GetInstance'::`2'::instance;
}
