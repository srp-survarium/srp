void __usercall vostok::render::scene_manager::scene_manager(
        vostok::render::scene_manager *this@<ecx>,
        vostok::render::scene_manager *a2@<eax>)
{
  a2->m_scenes._M_impl._M_start = 0;
  a2->m_scenes._M_impl._M_finish = 0;
  a2->m_scenes._M_impl._M_end_of_storage._M_data = 0;
  a2->m_views._M_impl._M_start = 0;
  a2->m_views._M_impl._M_finish = 0;
  a2->m_views._M_impl._M_end_of_storage._M_data = 0;
  a2->m_output_windows._M_impl._M_start = 0;
  a2->m_output_windows._M_impl._M_finish = 0;
  vostok::quasi_singleton<vostok::render::scene_manager>::pinst = a2;
  a2->m_output_windows._M_impl._M_end_of_storage._M_data = 0;
}
