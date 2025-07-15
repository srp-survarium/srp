vostok::render::texture_slot *__usercall vostok::render::texture_slot::operator=@<eax>(
        vostok::render::texture_slot *this@<esi>,
        const vostok::render::texture_slot *__that@<eax>)
{
  if ( this != __that )
    vostok::buffer_string::operator=(&__that->name, &this->name);
  this->slot_id = __that->slot_id;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &__that->texture,
    (vostok::render::res_texture *)&this->texture);
  return this;
}
