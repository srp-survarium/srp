vostok::math::float3 *__userpurge vostok::sound::sound_scene::get_listenet_position@<eax>(
        vostok::sound::sound_scene *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm0>,
        vostok::math::float3 *result)
{
  int v4; // esi
  vostok::math::half_pod *v5; // ecx
  vostok::math::half_pod *v6; // ecx
  vostok::math::float3 *v7; // eax

  v4 = a2 + 288;
  vostok::math::half_pod::operator float((vostok::math::half_pod *)this, (unsigned __int16 *)(a2 + 288));
  vostok::math::half_pod::operator float(v5, (unsigned __int16 *)(v4 + 2));
  vostok::math::half_pod::operator float(v6, (unsigned __int16 *)(v4 + 4));
  v7 = result;
  result->x = a3;
  result->y = a3;
  result->z = a3;
  return v7;
}
