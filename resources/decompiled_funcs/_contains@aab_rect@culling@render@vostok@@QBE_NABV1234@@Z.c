BOOL __usercall vostok::render::culling::aab_rect::contains@<eax>(
        vostok::render::culling::aab_rect *this@<ecx>,
        const vostok::render::culling::aab_rect *another@<eax>)
{
  float x; // xmm0_4
  float v3; // xmm1_4
  float y; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  BOOL result; // eax

  result = 0;
  if ( another->min.x >= this->min.x || fabs(this->min.x - another->min.x) < 0.0000099999997 )
  {
    x = this->max.x;
    v3 = another->max.x;
    if ( x >= v3 || fabs(x - v3) < 0.0000099999997 )
    {
      y = this->min.y;
      v5 = another->min.y;
      if ( v5 >= y || fabs(y - v5) < 0.0000099999997 )
      {
        v6 = this->max.y;
        v7 = another->max.y;
        if ( v6 >= v7 || fabs(v6 - v7) < 0.0000099999997 )
          return 1;
      }
    }
  }
  return result;
}
