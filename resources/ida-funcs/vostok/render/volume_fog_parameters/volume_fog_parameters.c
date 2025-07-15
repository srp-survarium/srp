void __usercall vostok::render::volume_fog_parameters::volume_fog_parameters(
        vostok::render::volume_fog_parameters *this@<eax>,
        const vostok::render::volume_fog_parameters *__that@<edx>)
{
  qmemcpy(this, __that, sizeof(vostok::render::volume_fog_parameters));
}


void __thiscall vostok::render::volume_fog_parameters::volume_fog_parameters(
        vostok::render::volume_fog_parameters *this,
        vostok::render::volume_fog_parameters *thisa)
{
  float v2; // xmm0_4
  vostok::math::float4x4 *v3; // eax
  const vostok::math::float4x4 *v4; // xmm0_4
  __int64 v5; // [esp+0h] [ebp-4Ch]
  vostok::math::float4x4 v6; // [esp+Ch] [ebp-40h] BYREF

  v2 = SNaN;
  thisa->direction.x = SNaN;
  thisa->direction.y = v2;
  v3 = vostok::math::float4x4::identity(&v6);
  v4 = clear_value;
  qmemcpy(thisa, v3, 0x40u);
  LODWORD(v5) = v4;
  HIDWORD(v5) = v4;
  *(_QWORD *)&thisa->fog_color.x = v5;
  LODWORD(thisa->fog_color.z) = v4;
  LODWORD(thisa->density) = v4;
  LODWORD(thisa->speed) = v4;
  LODWORD(thisa->noise_scale) = v4;
  LODWORD(thisa->wave_length) = v4;
  thisa->near_density = 0.0;
  thisa->density_offset = 0.0;
  thisa->height_falloff_offset = 0.0;
  LODWORD(thisa->transparency_multiplier) = v4;
  LODWORD(thisa->direction.x) = v4;
  thisa->direction.y = 0.0;
}
