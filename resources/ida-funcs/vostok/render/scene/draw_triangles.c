void __userpurge vostok::render::scene::draw_triangles(
        const vostok::buffer_vector<unsigned short> *indices@<eax>,
        int this,
        vostok::render::vertex_colored *vertices)
{
  vostok::render::vertex_colored *v3; // ebx
  int v5; // eax
  vostok::buffer_vector<vostok::render::vertex_colored> *v6; // esi
  vostok::render::scene *v7; // ecx
  int v8; // ecx
  vostok::buffer_vector<unsigned short> *v9; // ecx
  unsigned __int16 *m_begin; // ebx
  unsigned __int16 *m_end; // edi
  vostok::fixed_vector<unsigned short,327680> *v12; // esi
  const vostok::render::vertex_colored *x_low; // [esp-4h] [ebp-18h]
  __int16 v14; // [esp+Ch] [ebp-8h]
  vostok::render::vertex_colored *end; // [esp+10h] [ebp-4h] BYREF

  v3 = vertices;
  v5 = this;
  v6 = (vostok::buffer_vector<vostok::render::vertex_colored> *)((char *)&off_6F34D4 + this);
  v7 = (vostok::render::scene *)(indices->m_end
                               - indices->m_begin
                               + ((*(_UNKNOWN **)((char *)&off_6F34D4 + this + 4)
                                 - *(_UNKNOWN **)((char *)&off_6F34D4 + this)) >> 4));
  if ( v7 >= (vostok::render::scene *)&_sbh_sizeHeaderList )
  {
    vostok::render::scene::render_triangles(v7, this, 0);
    v5 = this;
  }
  x_low = (const vostok::render::vertex_colored *)LODWORD(v3->position.x);
  v8 = v6->m_end - v6->m_begin;
  vertices = *(vostok::render::vertex_colored **)&aSpltChunkTooLo[v5];
  v14 = v8;
  end = (vostok::render::vertex_colored *)LODWORD(v3->position.y);
  vostok::buffer_vector<vostok::render::vertex_colored>::insert<vostok::render::vertex_colored const *>(
    (const vostok::render::vertex_colored *const *)&end,
    v6,
    &vertices,
    x_low);
  m_begin = indices->m_begin;
  m_end = indices->m_end;
  if ( m_begin != m_end )
  {
    v12 = (vostok::fixed_vector<unsigned short,327680> *)(this + 8336608);
    do
    {
      this = (unsigned __int16)(v14 + *m_begin);
      vostok::buffer_vector<unsigned short>::push_back(v9, (int)v12, (const unsigned __int16 *)&this);
      ++m_begin;
    }
    while ( m_begin != m_end );
  }
}
