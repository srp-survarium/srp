vostok::render::sky_ambient_occlusion_properties *__usercall vostok::render::sky_ambient_occlusion_properties::operator=@<eax>(
        vostok::render::sky_ambient_occlusion_properties *this@<esi>,
        const vostok::render::sky_ambient_occlusion_properties *__that@<edi>)
{
  vostok::render::sky_ambient_occlusion_properties *result; // eax

  vostok::fixed_string<260>::operator=(&this->texture_name, &__that->texture_name);
  this->location = __that->location;
  this->width = __that->width;
  result = this;
  this->height = __that->height;
  this->depth = __that->depth;
  this->enabled = __that->enabled;
  this->texture_invalidated = __that->texture_invalidated;
  return result;
}
