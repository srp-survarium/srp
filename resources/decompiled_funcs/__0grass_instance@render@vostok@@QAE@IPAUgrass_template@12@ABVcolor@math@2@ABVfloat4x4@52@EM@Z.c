vostok::math::color *__userpurge vostok::render::grass_instance::grass_instance@<eax>(
        vostok::render::grass_instance *this@<ecx>,
        vostok::math::color *result@<eax>,
        unsigned int a3@<xmm0>,
        unsigned int in_id,
        const vostok::math::color *in_color,
        const vostok::math::float4x4 *in_transform,
        const struct vostok::math::float4x4 *in_layer,
        unsigned __int8 a8,
        float a9)
{
  result->m_value = (unsigned int)this;
  result[1] = *in_color;
  qmemcpy(&result[2], in_transform, 0x40u);
  result[18].m_value = a3;
  result[19].m_value = in_id;
  result[20].r = (unsigned __int8)in_layer;
  return result;
}
