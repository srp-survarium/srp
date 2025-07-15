void __thiscall Scaleform::GFx::Viewport::Viewport(
        Scaleform::GFx::Viewport *this,
        int bw,
        int bh,
        int left,
        int top,
        int w,
        int h,
        unsigned int flags)
{
  float v9; // xmm0_4

  Scaleform::Render::Viewport::Viewport(this, bw, bh, left, top, w, h, flags);
  v9 = s_bm_current_air_resistance;
  this->AspectRatio = s_bm_current_air_resistance;
  this->Scale = v9;
}
