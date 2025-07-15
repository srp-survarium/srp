vostok::render::gs_data *__usercall vostok::render::gs_data::operator=@<eax>(
        vostok::render::gs_data *this@<esi>,
        const vostok::render::gs_data *__that@<edi>,
        vostok::render::shader_constant_table *a3@<ecx>)
{
  this->instruction_count = __that->instruction_count;
  this->hardware_shader = __that->hardware_shader;
  vostok::render::shader_constant_table::operator=(
    a3,
    &this->constants,
    (const vostok::render::shader_constant *)&__that->constants);
  vostok::fixed_vector<vostok::render::sampler_slot,16>::operator=(&__that->samplers, &this->samplers);
  vostok::fixed_vector<vostok::render::texture_slot,128>::operator=(&__that->textures, &this->textures);
  vostok::fixed_vector<vostok::render::buffer_slot,128>::operator=(&__that->buffers, &this->buffers);
  return this;
}
