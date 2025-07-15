void __userpurge vostok::render::backend::render(
        vostok::render::backend *this@<esi>,
        D3D_PRIMITIVE_TOPOLOGY type@<eax>,
        vostok::render::backend *a3@<ecx>,
        unsigned int vertex_count,
        unsigned int base_vertex)
{
  int v6; // edi
  int v7; // edi

  LOBYTE(a3) = type != this->m_primitive_topology;
  this->m_dirty_objects.primitive_topology = (char)a3;
  if ( (_BYTE)a3 )
    this->m_primitive_topology = type;
  vostok::render::backend::flush(a3, (unsigned int)this);
  if ( this->draw_calls_counting )
    ++this->num_draw_calls;
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Draw(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    vertex_count,
    base_vertex);
  v6 = type - 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      if ( v7 == 2 )
        this->num_total_rendered_triangles += vertex_count / 3;
    }
    else
    {
      this->num_total_rendered_triangles += vertex_count >> 1;
    }
  }
  else
  {
    this->num_total_rendered_points += vertex_count;
  }
}
