vostok::render::buffer_slot *__usercall vostok::render::buffer_slot::operator=@<eax>(
        vostok::render::buffer_slot *this@<esi>,
        const vostok::render::buffer_slot *__that@<eax>)
{
  if ( this != __that )
    vostok::buffer_string::operator=(&__that->name, &this->name);
  this->slot_id = __that->slot_id;
  vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &__that->buffer,
    &this->buffer);
  return this;
}
