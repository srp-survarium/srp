bool __usercall vostok::render::stage_visibility::occluded@<al>(
        vostok::render::stage_visibility *this@<ecx>,
        const unsigned int index@<eax>)
{
  return index != -1 && this->m_static_results_array[index] == 0;
}
