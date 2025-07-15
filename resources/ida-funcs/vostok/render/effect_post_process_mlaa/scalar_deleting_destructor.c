vostok::render::effect_exponential_volume_fog *__thiscall vostok::render::effect_post_process_mlaa::`scalar deleting destructor'(
        vostok::render::effect_exponential_volume_fog *this,
        char a2)
{
  this->__vftable = (vostok::render::effect_exponential_volume_fog_vtbl *)&vostok::render::effect_descriptor::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
