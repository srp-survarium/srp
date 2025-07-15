void __userpurge vostok::render::backend::render_indexed(
        vostok::render::backend *this@<esi>,
        unsigned int index_count@<eax>,
        vostok::render::backend *a3@<ecx>,
        D3D_PRIMITIVE_TOPOLOGY type,
        unsigned int start_index,
        unsigned int base_vertex)
{
  D3D_PRIMITIVE_TOPOLOGY v6; // ebx
  __int32 v8; // ebx
  __int32 v9; // ebx

  v6 = type;
  LOBYTE(a3) = type != this->m_primitive_topology;
  this->m_dirty_objects.primitive_topology = (char)a3;
  if ( (_BYTE)a3 )
    this->m_primitive_topology = type;
  vostok::render::backend::flush(a3, (unsigned int)this);
  if ( this->draw_calls_counting )
  {
    ++this->num_draw_calls;
    index_count += 3 * s_max_triagles_per_dip_value < index_count ? 3 * s_max_triagles_per_dip_value - index_count : 0;
  }
  if ( !this->disable_DrawIndexed )
  {
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->DrawIndexed(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      index_count,
      start_index + (this->m_ib_offset >> 1),
      base_vertex + this->m_vb_offset / this->m_vb_stride);
    v6 = type;
  }
  v8 = v6 - 1;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 2 )
        this->num_total_rendered_triangles += index_count / 3;
    }
    else
    {
      this->num_total_rendered_triangles += index_count >> 1;
    }
  }
  else
  {
    this->num_total_rendered_points += index_count;
  }
}
