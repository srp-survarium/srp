void __fastcall vostok::render::stage_shadow_direct::end_gather_stats(
        int a1,
        const unsigned int cascade_index,
        vostok::render::stage_shadow_direct *this)
{
  unsigned int v3; // ecx
  vostok::render::statistics *v4; // eax
  int v5; // edx
  int v6; // edx

  v3 = *(_DWORD *)(LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z) + 7428)
     - this->m_current_num_dips;
  v4 = vostok::quasi_singleton<vostok::render::statistics>::pinst;
  if ( cascade_index )
  {
    v5 = cascade_index - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
          vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_4.value += v3;
      }
      else
      {
        vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_3.value += v3;
      }
    }
    else
    {
      vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_2.value += v3;
    }
  }
  else
  {
    vostok::quasi_singleton<vostok::render::statistics>::pinst->cascaded_sun_shadow_stat_group.num_dips_cascade_1.value += v3;
  }
  v4->cascaded_sun_shadow_stat_group.num_dips.value += v3;
}
