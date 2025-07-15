void __userpurge vostok::render::stage_visibility::filter_and_sort_env_probes(
        vostok::render::stage_visibility *this@<ecx>,
        int a2@<eax>,
        vostok::render::environment_probe **probes_generate_pass)
{
  vostok::buffer_vector<vostok::render::ambient_light *> *v4; // esi
  vostok::render::ambient_light **v5; // ebx
  vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> **m_begin; // eax
  vostok::render::ambient_light **v7; // eax
  vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> **i; // edi
  vostok::render::environment_probe **v9; // ecx
  vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> *v10; // eax
  vostok::render::environment_probe **m_end; // edi
  vostok::render::environment_probe *v12; // esi
  int v13; // eax
  int v14; // ecx
  vostok::render::ambient_light **end; // [esp+8h] [ebp-4h] BYREF

  v4 = (vostok::buffer_vector<vostok::render::ambient_light *> *)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 52460);
  if ( !(_BYTE)probes_generate_pass )
  {
    v5 = *(vostok::render::ambient_light ***)(*(_DWORD *)(*(_DWORD *)(a2 + 4) + 16268) + 52464);
    LOBYTE(probes_generate_pass) = 0;
    m_begin = (vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> **)v4->m_begin;
    end = v5;
    v7 = (vostok::render::ambient_light **)stlp_std::priv::__find_if<vostok::render::environment_probe * *,vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe>>(
                                             m_begin,
                                             (vostok::render::environment_probe **)v5);
    if ( v7 != v5 )
    {
      probes_generate_pass = (vostok::render::environment_probe **)v7;
      for ( i = (vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> **)(v7 + 1);
            i != (vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> **)v5;
            ++i )
      {
        if ( !vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe>::operator()(*i) )
        {
          v9 = probes_generate_pass;
          v10 = *i;
          ++probes_generate_pass;
          *v9 = (vostok::render::environment_probe *)v10;
        }
      }
      v7 = (vostok::render::ambient_light **)probes_generate_pass;
    }
    probes_generate_pass = (vostok::render::environment_probe **)v7;
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      v4,
      (vostok::render::ambient_light ***)&probes_generate_pass,
      &end);
  }
  LOBYTE(probes_generate_pass) = 0;
  m_end = (vostok::render::environment_probe **)v4->m_end;
  v12 = (vostok::render::environment_probe *)v4->m_begin;
  if ( v12 != (vostok::render::environment_probe *)m_end )
  {
    v13 = ((char *)m_end - (char *)v12) >> 2;
    v14 = 0;
    while ( v13 != 1 )
    {
      ++v14;
      v13 >>= 1;
    }
    _____introsort_loop_PAPAUenvironment_probe_render_vostok__PAU123_HUsort_by_size_predicate__3__filter_and_sort_env_probes_stage_visibility_23_AAEX_N_Z__priv_stlp_std__YAXPAPAUenvironment_probe_render_vostok__00HUsort_by_size_predicate__3__filter_and_sort_env_probes_stage_visibility_34_AAEX_N_Z__Z(
      v12,
      (vostok::render::environment_probe **)v12,
      m_end,
      0,
      2 * v14,
      probes_generate_pass);
    _____final_insertion_sort_PAPAUenvironment_probe_render_vostok__Usort_by_size_predicate__3__filter_and_sort_env_probes_stage_visibility_23_AAEX_N_Z__priv_stlp_std__YAXPAPAUenvironment_probe_render_vostok__0Usort_by_size_predicate__3__filter_and_sort_env_probes_stage_visibility_34_AAEX_N_Z__Z(
      (vostok::render::environment_probe **)v12,
      m_end,
      (vostok::render::environment_probe *)probes_generate_pass);
  }
}
