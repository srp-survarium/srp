int __userpurge vostok::render::res_texture_list::compare@<eax>(
        const vostok::render::res_texture_list *base@<edi>,
        vostok::render::res_texture_list *this)
{
  vostok::render::res_texture_list *v2; // ebx
  unsigned int v3; // ecx
  unsigned int v4; // esi
  vostok::render::res_texture_list **v5; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // eax
  char *v7; // ebp
  vostok::render::res_texture *v8; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = this;
  v3 = this->m_container._M_impl._M_finish - this->m_container._M_impl._M_start;
  v4 = 0;
  this = (vostok::render::res_texture_list *)(base->m_container._M_impl._M_finish - base->m_container._M_impl._M_start);
  v10 = v3;
  v5 = &this;
  if ( (unsigned int)this >= v3 )
    v5 = (vostok::render::res_texture_list **)&v10;
  this = *v5;
  if ( this )
  {
    M_start = v2->m_container._M_impl._M_start;
    v7 = (char *)((char *)base->m_container._M_impl._M_start - (char *)M_start);
    while ( 1 )
    {
      v8 = *(vostok::render::res_texture **)&v7[(_DWORD)M_start];
      if ( M_start->m_object < v8 )
        break;
      if ( M_start->m_object > v8 )
        return 1;
      ++v4;
      ++M_start;
      if ( v4 >= (unsigned int)this )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    if ( v2->m_container._M_impl._M_finish - v2->m_container._M_impl._M_start >= (unsigned int)(base->m_container._M_impl._M_finish
                                                                                              - base->m_container._M_impl._M_start) )
      return base->m_container._M_impl._M_finish - base->m_container._M_impl._M_start < (unsigned int)(v2->m_container._M_impl._M_finish - v2->m_container._M_impl._M_start);
  }
  return -1;
}
