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
  Scaleform::Render::ImgBlurWrapperX v11; // [esp+1Ch] [ebp-18h] BYREF

  p_BlurStack = &this->BlurStack;
  v11.Sx = sx;
  p_BlurSum = &this->BlurSum;
  v11.W = w;
  v11.Sy = sy;
  v11.Img = img;
  v11.Pitch = pitch;
  v11.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperX,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    &v11,
    rx,
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->BlurSum,
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->BlurStack);
  v11.Sx = sx;
  v11.Sy = sy;
  v11.Img = img;
  v11.Pitch = pitch;
  v11.W = w;
  v11.H = h;
  Scaleform::Render::RecursiveBlur<Scaleform::Render::ImgBlurWrapperY,Scaleform::ArrayLH_POD<float,2,Scaleform::ArrayDefaultPolicy>,Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>(
    (Scaleform::Render::ImgBlurWrapperY *)&v11,
    ry,
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)p_BlurSum,
    (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_BlurStack);
}
