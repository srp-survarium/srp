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
