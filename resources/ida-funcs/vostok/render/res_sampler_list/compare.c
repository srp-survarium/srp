int __userpurge vostok::render::res_sampler_list::compare@<eax>(
        const vostok::render::res_sampler_list *base@<edi>,
        vostok::render::res_sampler_list *this)
{
  vostok::render::res_sampler_list *v2; // ebx
  unsigned int v3; // ecx
  int v4; // esi
  vostok::render::res_sampler_list **v5; // eax
  vostok::sound::sound_world_vtbl **v6; // ebp
  vostok::sound::sound_world_vtbl **v7; // ebp
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = this;
  v3 = this->m_samplers._M_impl._M_finish - this->m_samplers._M_impl._M_start;
  v4 = 0;
  this = (vostok::render::res_sampler_list *)(base->m_samplers._M_impl._M_finish - base->m_samplers._M_impl._M_start);
  v9 = v3;
  v5 = &this;
  if ( (unsigned int)this >= v3 )
    v5 = (vostok::render::res_sampler_list **)&v9;
  this = *v5;
  if ( this )
  {
    while ( 1 )
    {
      v6 = (vostok::sound::sound_world_vtbl **)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&v2->m_samplers._M_impl._M_start[v4]);
      if ( *v6 < boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&base->m_samplers._M_impl._M_start[v4])->__vftable )
        break;
      v7 = (vostok::sound::sound_world_vtbl **)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&v2->m_samplers._M_impl._M_start[v4]);
      if ( *v7 > boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)&base->m_samplers._M_impl._M_start[v4])->__vftable )
        return 1;
      if ( ++v4 >= (unsigned int)this )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    if ( v2->m_samplers._M_impl._M_finish - v2->m_samplers._M_impl._M_start >= (unsigned int)(base->m_samplers._M_impl._M_finish
                                                                                            - base->m_samplers._M_impl._M_start) )
      return base->m_samplers._M_impl._M_finish - base->m_samplers._M_impl._M_start < (unsigned int)(v2->m_samplers._M_impl._M_finish - v2->m_samplers._M_impl._M_start);
  }
  return -1;
}


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
