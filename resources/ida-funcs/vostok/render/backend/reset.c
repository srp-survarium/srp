void __usercall vostok::render::backend::reset(vostok::render::backend *this@<ecx>, int a2@<eax>)
{
  _DWORD *v3; // eax
  bool v4; // zf
  bool v5; // cl
  bool v6; // cl
  vostok::render::backend *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::render::buffers_handler<0> *v9; // ecx
  vostok::render::buffers_handler<0> *v10; // ecx
  vostok::render::buffers_handler<0> *v11; // ecx
  vostok::render::device *v12; // eax
  vostok::render::device *v13; // eax
  unsigned int i; // [esp+10h] [ebp-4h]
  unsigned int j; // [esp+10h] [ebp-4h]
  unsigned int k; // [esp+10h] [ebp-4h]

  v3 = (_DWORD *)(a2 + 340);
  v4 = *v3 == 0;
  *v3 = 0;
  *(_BYTE *)(a2 + 95) |= !v4;
  v5 = *(_DWORD *)(a2 + 344) != -1;
  *(_DWORD *)(a2 + 344) = -1;
  *(_BYTE *)(a2 + 96) |= v5;
  vostok::render::backend::set_declaration((vostok::render::backend *)a2, 0);
  v4 = *(_DWORD *)(a2 + 328) == 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_BYTE *)(a2 + 94) |= !v4;
  v4 = *(_DWORD *)(a2 + 332) == 0;
  *(_DWORD *)(a2 + 332) = 0;
  *(_BYTE *)(a2 + 95) |= !v4;
  v4 = *(_DWORD *)(a2 + 336) == 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(_BYTE *)(a2 + 96) |= !v4;
  vostok::render::backend::set_vs((vostok::render::backend *)a2, 0);
  vostok::render::backend::set_vs_constants((vostok::render::backend *)a2, 0);
  vostok::render::backend::set_vs_samplers((vostok::render::backend *)a2, 0);
  if ( *(_DWORD *)(a2 + 492) )
  {
    ++*(_DWORD *)(a2 + 7568);
    vostok::render::textures_handler<0>::assign((vostok::render::textures_handler<0> *)(a2 + 492), 0);
    *(_BYTE *)(a2 + 99) = 1;
  }
  v4 = *(_DWORD *)(a2 + 420) == 0;
  *(_DWORD *)(a2 + 420) = 0;
  *(_BYTE *)(a2 + 102) |= !v4;
  vostok::render::backend::set_gs_constants((vostok::render::backend *)a2, 0);
  vostok::render::backend::set_gs_samplers((vostok::render::backend *)a2, 0);
  if ( *(_DWORD *)(a2 + 2116) )
  {
    vostok::render::textures_handler<0>::assign((vostok::render::textures_handler<0> *)(a2 + 2116), 0);
    *(_BYTE *)(a2 + 104) = 1;
  }
  v6 = *(_DWORD *)(a2 + 416) != 0;
  v4 = (v6 | *(_BYTE *)(a2 + 107)) == 0;
  *(_BYTE *)(a2 + 107) |= v6;
  if ( !v4 )
    ++*(_DWORD *)(a2 + 7556);
  *(_DWORD *)(a2 + 416) = 0;
  vostok::render::backend::set_ps_constants((vostok::render::backend *)a2, 0);
  vostok::render::backend::set_ps_samplers((vostok::render::backend *)a2, 0);
  if ( *(_DWORD *)(a2 + 3740) )
  {
    ++*(_DWORD *)(a2 + 7580);
    vostok::render::textures_handler<0>::assign((vostok::render::textures_handler<0> *)(a2 + 3740), 0);
    *(_BYTE *)(a2 + 109) = 1;
  }
  vostok::render::backend::set_vs_constants((vostok::render::backend *)a2, 0);
  vostok::render::backend::set_vb((vostok::render::backend *)a2, 0, 0);
  vostok::render::backend::set_ib(0, a2);
  vostok::render::backend::set_render_targets((vostok::render::backend *)a2, 0, 0, 0, 0);
  *(_BYTE *)(a2 + 117) |= *(_DWORD *)(a2 + 7384) != 0;
  *(_DWORD *)(a2 + 7384) = 0;
  vostok::render::backend::flush_rt_shader_resources(v7, a2);
  vostok::render::backend::flush_rt_views(v8);
  memset(a2 + 436, 0, 0x38u);
  *(_DWORD *)(a2 + 424) = 0;
  *(_DWORD *)(a2 + 428) = 0;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 432),
    0);
  memset(a2 + 504, 0, 0x200u);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 492),
    0);
  *(_DWORD *)(a2 + 496) = 0;
  *(_DWORD *)(a2 + 500) = 0;
  for ( i = 0; i < (*(_DWORD *)(a2 + 1028) - *(_DWORD *)(a2 + 1024)) >> 2; ++i )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)(*(_DWORD *)(a2 + 1024) + 4 * i));
  *(_DWORD *)(a2 + 1296) = 0;
  *(_DWORD *)(a2 + 1300) = 0;
  memset(a2 + 1304, 0, 0x40u);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 1368),
    0);
  vostok::render::buffers_handler<0>::reset(v9, a2 + 1376);
  memset(a2 + 2060, 0, 0x38u);
  *(_DWORD *)(a2 + 2048) = 0;
  *(_DWORD *)(a2 + 2052) = 0;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 2056),
    0);
  memset(a2 + 2128, 0, 0x200u);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 2116),
    0);
  *(_DWORD *)(a2 + 2120) = 0;
  *(_DWORD *)(a2 + 2124) = 0;
  for ( j = 0; j < (*(_DWORD *)(a2 + 2652) - *(_DWORD *)(a2 + 2648)) >> 2; ++j )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)(*(_DWORD *)(a2 + 2648) + 4 * j));
  *(_DWORD *)(a2 + 2920) = 0;
  *(_DWORD *)(a2 + 2924) = 0;
  memset(a2 + 2928, 0, 0x40u);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 2992),
    0);
  vostok::render::buffers_handler<0>::reset(v10, a2 + 3000);
  memset(a2 + 3684, 0, 0x38u);
  *(_DWORD *)(a2 + 3672) = 0;
  *(_DWORD *)(a2 + 3676) = 0;
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 3680),
    0);
  memset(a2 + 3752, 0, 0x200u);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 3740),
    0);
  *(_DWORD *)(a2 + 3744) = 0;
  *(_DWORD *)(a2 + 3748) = 0;
  for ( k = 0; k < (*(_DWORD *)(a2 + 4276) - *(_DWORD *)(a2 + 4272)) >> 2; ++k )
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)(*(_DWORD *)(a2 + 4272) + 4 * k));
  *(_DWORD *)(a2 + 4544) = 0;
  *(_DWORD *)(a2 + 4548) = 0;
  memset(a2 + 4552, 0, 0x40u);
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_sampler_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 4616),
    0);
  vostok::render::buffers_handler<0>::reset(v11, a2 + 4624);
  ++*(_DWORD *)(a2 + 7536);
  v12 = vostok::quasi_singleton<vostok::render::device>::pinst;
  *(_DWORD *)(a2 + 7356) = 0;
  v12->m_context->IASetPrimitiveTopology(v12->m_context, D3D_PRIMITIVE_TOPOLOGY_UNDEFINED);
  *(_DWORD *)(a2 + 356) = -1;
  *(_DWORD *)(a2 + 360) = -1;
  *(_DWORD *)(a2 + 368) = -1;
  *(_DWORD *)(a2 + 372) = -1;
  *(_DWORD *)(a2 + 380) = -1;
  *(_DWORD *)(a2 + 384) = -1;
  *(_DWORD *)(a2 + 392) = -1;
  v13 = vostok::quasi_singleton<vostok::render::device>::pinst;
  *(_DWORD *)(a2 + 352) = 0;
  *(_DWORD *)(a2 + 364) = 0;
  *(_DWORD *)(a2 + 376) = 0;
  *(_DWORD *)(a2 + 388) = 0;
  *(_DWORD *)(a2 + 348) = 0;
  v13->m_context->VSSetShader(v13->m_context, 0, 0, 0);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetShader(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    0,
    0);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShader(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    0,
    0);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetIndexBuffer(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    DXGI_FORMAT_R16_UINT,
    0);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11ShaderResourceView_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->DSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11ShaderResourceView_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->HSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11ShaderResourceView_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11ShaderResourceView_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShaderResources(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11ShaderResourceView_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetInputLayout(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetSamplers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11SamplerState_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetSamplers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11SamplerState_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetSamplers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11SamplerState_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->HSSetSamplers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11SamplerState_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->DSSetSamplers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    16u,
    `vostok::render::backend::reset'::`2'::pID3D11SamplerState_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetConstantBuffers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    14u,
    `vostok::render::backend::reset'::`2'::pID3D11Buffer_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetConstantBuffers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    14u,
    `vostok::render::backend::reset'::`2'::pID3D11Buffer_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetConstantBuffers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    14u,
    `vostok::render::backend::reset'::`2'::pID3D11Buffer_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->HSSetConstantBuffers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    14u,
    `vostok::render::backend::reset'::`2'::pID3D11Buffer_temp_1);
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->DSSetConstantBuffers(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    0,
    14u,
    `vostok::render::backend::reset'::`2'::pID3D11Buffer_temp_1);
  memset(a2 + 120, 0, 0xC0u);
  *(_DWORD *)(a2 + 7384) = 0;
  *(_DWORD *)(a2 + 7440) = 0;
  *(_DWORD *)(a2 + 7436) = 0;
  *(_DWORD *)(a2 + 7552) = 0;
  *(_DWORD *)(a2 + 7556) = 0;
  *(_DWORD *)(a2 + 7560) = 0;
  *(_DWORD *)(a2 + 7564) = 0;
  *(_DWORD *)(a2 + 7568) = 0;
  *(_DWORD *)(a2 + 7572) = 0;
  *(_DWORD *)(a2 + 7576) = 0;
  *(_DWORD *)(a2 + 7580) = 0;
  *(_DWORD *)(a2 + 7584) = 0;
}
