void __userpurge vostok::render::culling::sector_double_query_preventer::add_frustum(
        vostok::render::culling::sector_double_query_preventer *this@<ecx>,
        unsigned int sector_id@<eax>,
        const vostok::math::frustum *f)
{
  vostok::buffer_vector<vostok::math::frustum>::push_back(
    (vostok::buffer_vector<vostok::math::frustum> *)this->m_sectors_max_frustums,
    (const vostok::math::frustum *)&this->m_sectors_max_frustums->m_begin[sector_id],
    f);
}
