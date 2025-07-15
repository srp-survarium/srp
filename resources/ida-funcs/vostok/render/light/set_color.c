void __userpurge vostok::render::light::set_color(
        vostok::render::light *this@<ecx>,
        int a2@<eax>,
        const vostok::math::color *c,
        const float intensity)
{
  *(float *)(a2 + 132) = (float)LOBYTE(this->m_reference_count);
  *(float *)(a2 + 136) = (float)BYTE1(this->m_reference_count);
  *(float *)(a2 + 140) = (float)BYTE2(this->m_reference_count);
  *(float *)(a2 + 132) = *(float *)(a2 + 132) * 0.0039215689;
  *(float *)(a2 + 136) = *(float *)(a2 + 136) * 0.0039215689;
  *(float *)(a2 + 140) = *(float *)(a2 + 140) * 0.0039215689;
  *(_DWORD *)(a2 + 144) = c;
}
