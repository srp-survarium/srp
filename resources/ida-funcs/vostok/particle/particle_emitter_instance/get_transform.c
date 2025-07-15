vostok::math::float4x4 *__userpurge vostok::particle::particle_emitter_instance::get_transform@<eax>(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        _BYTE *a2@<eax>,
        vostok::math::float4x4 *result)
{
  _BYTE *v3; // esi
  vostok::math::float4x4 *v4; // eax

  v3 = a2 + 140;
  if ( !a2[8] )
    v3 = a2 + 12;
  v4 = result;
  qmemcpy(result, v3, sizeof(vostok::math::float4x4));
  return v4;
}
