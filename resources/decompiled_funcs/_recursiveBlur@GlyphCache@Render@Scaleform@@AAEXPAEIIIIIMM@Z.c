void __thiscall Scaleform::Render::GlyphCache::recursiveBlur(
        Scaleform::Render::GlyphCache *this,
        unsigned __int8 *img,
        unsigned int pitch,
        unsigned int sx,
        unsigned int sy,
        unsigned int w,
        unsigned int h,
        float rx,
        float ry)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_BlurStack; // esi
  Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy> *p_BlurSum; // edi
  Scaleform::Render::ImgBlurWrapperX imgWX; // [esp+1Ch] [ebp-18h] BYREF

  p_BlurStack = &this->BlurStack;
  imgWX.Sx = sx;
  p_BlurSum = &this->BlurSum;
  imgWX.W = w;
  imgWX.Sy = sy;
  imgWX.Img = img;
  imgWX.Pitch = pitch;
  imgWX.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperX,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    &imgWX,
    rx,
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->BlurSum,
    &this->BlurStack);
  imgWX.Sx = sx;
  imgWX.Sy = sy;
  imgWX.Img = img;
  imgWX.Pitch = pitch;
  imgWX.W = w;
  imgWX.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    (Scaleform::Render::ImgBlurWrapperY *)&imgWX,
    ry,
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_BlurSum,
    p_BlurStack);
}
