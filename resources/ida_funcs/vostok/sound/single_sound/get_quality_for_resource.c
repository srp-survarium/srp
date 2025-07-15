const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::single_sound::get_quality_for_resource(
        vostok::sound::single_sound *this)
{
  return vostok::sound::encoded_sound_with_qualities::get_encoded_sound((vostok::sound::encoded_sound_with_qualities *)this->type);
}
