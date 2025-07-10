void __usercall stlp_std::priv::__ufill<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,int>(
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__first@<ecx>,
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__last@<eax>,
        const stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__x)
{
  int v3; // ebx
  vostok::math::float3 *p_fog_color; // eax

  v3 = __last - __first;
  if ( v3 > 0 )
  {
    p_fog_color = &__first->second.fog_color;
    do
    {
      if ( p_fog_color != (vostok::math::float3 *)68 )
      {
        LODWORD(p_fog_color[-6].y) = __x->first;
        qmemcpy(&p_fog_color[-6].elements[2], &__x->second, 0x48u);
        p_fog_color->z = __x->second.fog_color.z;
        *(vostok::math::float2 *)&p_fog_color[1].x = __x->second.direction;
        p_fog_color[1].z = __x->second.height_falloff_offset;
        p_fog_color[2].x = __x->second.density;
        p_fog_color[2].y = __x->second.speed;
        p_fog_color[2].z = __x->second.noise_scale;
        p_fog_color[3].x = __x->second.wave_length;
        p_fog_color[3].y = __x->second.near_density;
        p_fog_color[3].z = __x->second.transparency_multiplier;
        p_fog_color[4].x = __x->second.density_offset;
      }
      --v3;
      p_fog_color += 10;
    }
    while ( v3 > 0 );
  }
}
