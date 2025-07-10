void __userpurge vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::resize(
        unsigned int size@<eax>,
        vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *this)
{
  vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *v2; // ebx
  vostok::render::grass_layer_desc::model_desc *m_begin; // esi
  int v4; // ecx
  unsigned int v5; // edi

  v2 = this;
  m_begin = this->m_begin;
  v4 = (char *)this->m_end - (char *)this->m_begin;
  if ( size != v4 / 280 )
  {
    if ( size >= v4 / 280 )
    {
      v5 = size;
      this = (vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc> *)&m_begin[size];
      vostok::buffer_vector<vostok::render::grass_layer_desc::model_desc>::construct(
        &m_begin[v4 / 280],
        (vostok::render::grass_layer_desc::model_desc *const *)&this);
      v2->m_end = &v2->m_begin[v5];
    }
    else
    {
      this->m_end = &m_begin[size];
    }
  }
}
