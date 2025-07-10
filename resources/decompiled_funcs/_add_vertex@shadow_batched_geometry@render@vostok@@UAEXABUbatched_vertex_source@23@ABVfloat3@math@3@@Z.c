void __userpurge vostok::render::shadow_batched_geometry::add_vertex(
        vostok::render::shadow_batched_geometry *this@<ecx>,
        const stlp_std::__true_type *a2@<edi>,
        unsigned int a3@<esi>,
        const vostok::render::batched_vertex_source *in_vertex,
        const vostok::math::float3 *not_modified_position)
{
  __int64 v5; // xmm0_8
  float z; // edx
  float x; // esi
  __int64 v8; // xmm1_8
  float v9; // esi
  vostok::render::shadow_vertex *M_finish; // eax
  float v11; // xmm0_4
  vostok::render::shadow_vertex vertex; // [esp+0h] [ebp-20h] BYREF

  v5 = *(_QWORD *)&in_vertex->position.x;
  z = in_vertex->position.z;
  x = in_vertex->uv.x;
  vertex.uv.y = in_vertex->uv.y;
  v8 = *(_QWORD *)&not_modified_position->x;
  vertex.uv.x = x;
  v9 = not_modified_position->z;
  M_finish = this->m_vertices._M_impl._M_finish;
  *(_QWORD *)&vertex.position.x = v5;
  vertex.position.z = z;
  *(_QWORD *)&vertex.object_position.x = v8;
  vertex.object_position.z = v9;
  if ( M_finish == this->m_vertices._M_impl._M_end_of_storage._M_data )
  {
    stlp_std::priv::_Impl_vector<vostok::render::shadow_vertex,vostok::render::std_allocator<vostok::render::shadow_vertex>>::_M_insert_overflow(
      &this->m_vertices._M_impl,
      &vertex,
      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)this,
      M_finish,
      a2,
      a3,
      SLOBYTE(vertex.position.x));
  }
  else
  {
    if ( M_finish )
    {
      *(_QWORD *)&M_finish->position.x = v5;
      v11 = vertex.uv.x;
      *(_QWORD *)&M_finish->object_position.x = v8;
      M_finish->position.z = z;
      M_finish->object_position.z = v9;
      M_finish->uv = (vostok::math::float2)__PAIR64__(LODWORD(vertex.uv.y), LODWORD(v11));
    }
    ++this->m_vertices._M_impl._M_finish;
  }
}
