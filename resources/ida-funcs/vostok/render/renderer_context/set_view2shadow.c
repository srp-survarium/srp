void __userpurge vostok::render::renderer_context::set_view2shadow(
        vostok::render::renderer_context *this@<eax>,
        unsigned int index@<ecx>,
        const vostok::math::float4x4 *view2shadow)
{
  switch ( index )
  {
    case 0u:
      qmemcpy((void *)&this->m_v2shadow0, view2shadow, sizeof(this->m_v2shadow0));
      break;
    case 1u:
      qmemcpy((void *)&this->m_v2shadow1, view2shadow, sizeof(this->m_v2shadow1));
      break;
    case 2u:
      qmemcpy((void *)&this->m_v2shadow2, view2shadow, sizeof(this->m_v2shadow2));
      break;
    case 3u:
      qmemcpy((void *)&this->m_v2shadow3, view2shadow, sizeof(this->m_v2shadow3));
      break;
    default:
      return;
  }
}
