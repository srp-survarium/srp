Scaleform::Render::ImageSwizzler *__thiscall Scaleform::Render::TextureManager::GetImageSwizzler(
        Scaleform::Render::TextureManager *this)
{
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    swizzler.__vftable = (Scaleform::Render::ImageSwizzler_vtbl *)&Scaleform::Render::ImageSwizzler::`vftable';
    atexit(Scaleform::Render::TextureManager::GetImageSwizzler_::_2_::_dynamic_atexit_destructor_for__swizzler__);
  }
  return &swizzler;
}
