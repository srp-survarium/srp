void __userpurge vostok::render::lpv_batched_geometry::add_vertex(
        vostok::render::lpv_batched_geometry *this@<ecx>,
        const stlp_std::__true_type *a2@<edi>,
        const vostok::render::batched_vertex_source *in_vertex,
        const vostok::math::float3 *__formal)
{
  __int64 v4; // xmm0_8
  unsigned int m_value; // edx
  vostok::render::lpv_vertex *M_finish; // eax
  vostok::render::lpv_vertex vertex; // [esp+0h] [ebp-14h] BYREF

  v4 = *(_QWORD *)&in_vertex->position.x;
  vertex.position.z = in_vertex->position.z;
  vertex.normal.m_value = in_vertex->normal.m_value;
  m_value = in_vertex->clr.m_value;
  M_finish = this->m_vertices._M_impl._M_finish;
  *(_QWORD *)&vertex.position.x = v4;
  vertex.clr.m_value = m_value;
  if ( M_finish == this->m_vertices._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::render::lpv_vertex,vostok::render::std_allocator<vostok::render::lpv_vertex>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)&this->m_vertices,
      (const vostok::render::trample_desc *)&vertex,
      (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)this,
      (vostok::render::trample_desc *)M_finish,
      a2,
      LODWORD(vertex.position.x),
      SLOBYTE(vertex.position.elements[1]));
  }
  else
  {
    *(_QWORD *)&M_finish->position.x = v4;
    *(_QWORD *)&M_finish->position.elements[2] = *(_QWORD *)&vertex.position.elements[2];
    M_finish->clr.m_value = m_value;
    ++this->m_vertices._M_impl._M_finish;
  }
}
