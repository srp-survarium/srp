vostok::render::point_light_effect<0,0> *__thiscall vostok::render::effect_post_process_mlaa::`scalar deleting destructor'(
        vostok::render::point_light_effect<0,0> *this,
        char a2)
{
  this->__vftable = (vostok::render::point_light_effect<0,0>_vtbl *)&vostok::render::effect_descriptor::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
