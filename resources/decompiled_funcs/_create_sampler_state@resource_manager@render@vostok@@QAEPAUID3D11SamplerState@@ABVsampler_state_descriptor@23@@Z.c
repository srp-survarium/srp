ID3D11SamplerState *__usercall vostok::render::resource_manager::create_sampler_state@<eax>(
        vostok::render::resource_manager *this@<ecx>,
        const vostok::render::sampler_state_descriptor *sampler_props@<eax>)
{
  return vostok::render::state_cache<ID3D11SamplerState,D3D11_SAMPLER_DESC>::get_state(
           &sampler_props->m_desc,
           &this->m_sampler_cache);
}
