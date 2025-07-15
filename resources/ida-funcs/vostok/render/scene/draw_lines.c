void __userpurge vostok::render::scene::draw_lines(
        vostok::render::scene *this@<ecx>,
        const vostok::buffer_vector<unsigned short> *indices@<eax>,
        vostok::render::vertex_colored *vertices)
{
  vostok::render::vertex_colored *v3; // ebx
  vostok::render::scene *v6; // ecx
  vostok::buffer_vector<unsigned short> *v7; // ecx
  unsigned __int16 *m_begin; // ebx
  unsigned __int16 *m_end; // edi
  const vostok::render::vertex_colored *x_low; // [esp-4h] [ebp-1Ch]
  char *v11; // [esp+Ch] [ebp-Ch]
  __int16 v12; // [esp+10h] [ebp-8h]
  vostok::render::vertex_colored *end; // [esp+14h] [ebp-4h] BYREF

  v3 = vertices;
  v11 = (char *)&loc_6534C8 + (_DWORD)this;
  v6 = (vostok::render::scene *)(indices->m_end
                               - indices->m_begin
                               + ((*(_DWORD *)((char *)&loc_6534C8 + (_DWORD)this + 4)
                                 - *(_DWORD *)((char *)&loc_6534C8 + (_DWORD)this)) >> 1));
  if ( v6 >= (vostok::render::scene *)&_sbh_sizeHeaderList )
    vostok::render::scene::render_lines(v6, (int)this, 0);
  x_low = (const vostok::render::vertex_colored *)LODWORD(v3->position.x);
  v12 = (*(_DWORD *)((char *)&loc_5534BC + (_DWORD)this + 4) - *(_DWORD *)((char *)&loc_5534BC + (_DWORD)this)) >> 4;
  end = (vostok::render::vertex_colored *)LODWORD(v3->position.y);
  vertices = *(vostok::render::vertex_colored **)((char *)&this->__vftable + (_DWORD)&loc_5534BE + 2);
  vostok::buffer_vector<vostok::render::vertex_colored>::insert<vostok::render::vertex_colored const *>(
    (const vostok::render::vertex_colored *const *)&end,
    (vostok::buffer_vector<vostok::render::vertex_colored> *)((char *)&loc_5534BC + (_DWORD)this),
    &vertices,
    x_low);
  m_begin = indices->m_begin;
  m_end = indices->m_end;
  while ( m_begin != m_end )
  {
    vertices = (vostok::render::vertex_colored *)(unsigned __int16)(v12 + *m_begin);
    vostok::buffer_vector<unsigned short>::push_back(v7, (int)v11, (const unsigned __int16 *)&vertices);
    ++m_begin;
  }
}
