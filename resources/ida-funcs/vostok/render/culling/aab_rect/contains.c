BOOL __usercall vostok::render::culling::aab_rect::contains@<eax>(
        vostok::render::culling::aab_rect *this@<edi>,
        const vostok::render::culling::aab_rect *another@<esi>)
{
  return (another->min.x >= this->min.x
       || vostok::math::is_similar<float>(&this->min.x, &another->min.x, 0.0000099999997))
      && (this->max.x >= another->max.x
       || vostok::math::is_similar<float>(&this->max.x, &another->max.x, 0.0000099999997))
      && (another->min.y >= this->min.y
       || vostok::math::is_similar<float>(&this->min.y, &another->min.y, 0.0000099999997))
      && (this->max.y >= another->max.y
       || vostok::math::is_similar<float>(&this->max.y, &another->max.y, 0.0000099999997));
}
