void __userpurge vostok::render::scene::update_lines(
        vostok::render::scene *this@<ecx>,
        vostok::render::scene *a2@<eax>,
        unsigned int add_count)
{
  if ( add_count + a2->m_line_indices._M_impl._M_finish - a2->m_line_indices._M_impl._M_start >= (unsigned int)&_sbh_sizeHeaderList )
    vostok::render::scene::render_lines(a2, 0);
}
