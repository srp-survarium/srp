void __userpurge vostok::render::backend::render_indexed_instanced(
        vostok::render::backend *this@<esi>,
        unsigned int index_count@<eax>,
        vostok::render::backend *a3@<ecx>,
        unsigned int type,
        unsigned int start_index,
        unsigned int base_vertex,
        unsigned int instance_count,
        unsigned int start_instance)
{
  LOBYTE(a3) = this->m_primitive_topology != D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
  this->m_dirty_objects.primitive_topology = (char)a3;
  if ( (_BYTE)a3 )
    this->m_primitive_topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
  vostok::render::backend::flush(a3, (unsigned int)this);
  if ( this->draw_calls_counting )
  {
    ++this->num_draw_calls;
    index_count += 3 * s_max_triagles_per_dip_value < index_count ? 3 * s_max_triagles_per_dip_value - index_count : 0;
  }
  vostok::quasi_singleton<vostok::render::device>::pinst->m_context->DrawIndexedInstanced(
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
    index_count,
    type,
    this->m_ib_offset >> 1,
    0,
    0);
  this->num_total_rendered_triangles += type * index_count / 3;
}
