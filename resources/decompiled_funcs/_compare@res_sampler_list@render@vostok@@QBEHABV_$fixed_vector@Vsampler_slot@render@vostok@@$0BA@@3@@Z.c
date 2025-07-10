int __thiscall vostok::render::res_sampler_list::compare(
        vostok::render::res_sampler_list *this,
        const vostok::render::res_sampler_list *base,
        int *count)
{
  int v4; // ecx
  unsigned int v5; // ebx
  const vostok::fixed_vector<vostok::render::sampler_slot,16> *v6; // edx
  unsigned int v7; // eax
  unsigned int v8; // esi
  int v9; // edi
  vostok::sound::sound_world *v10; // eax
  unsigned int counta; // [esp+18h] [ebp+8h]

  v4 = *count;
  v5 = (count[1] - *count) / 84;
  v6 = (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)base;
  v7 = base->m_samplers._M_impl._M_finish - base->m_samplers._M_impl._M_start;
  v8 = 0;
  counta = v7;
  if ( !v5 )
    return 0;
  v9 = 0;
  while ( v8 >= v7 )
  {
    if ( *(_DWORD *)(v9 + v4 + 76) != -1 )
      return -1;
LABEL_8:
    ++v8;
    v9 += 84;
    if ( v8 >= v5 )
      return 0;
  }
  if ( boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)(&v6->m_end->name.vostok::buffer_vector<vostok::render::sampler_slot>::m_begin
                                                                                   + v8))->__vftable < (vostok::sound::sound_world_vtbl *)*(_DWORD *)(v9 + *count + 80) )
    return -1;
  v10 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&base->m_samplers._M_impl._M_start[v8]);
  v4 = *count;
  if ( v10->__vftable <= (vostok::sound::sound_world_vtbl *)*(_DWORD *)(v9 + *count + 80) )
  {
    v6 = (const vostok::fixed_vector<vostok::render::sampler_slot,16> *)base;
    v7 = counta;
    goto LABEL_8;
  }
  return 1;
}
