void __thiscall vostok::render::stage_visibility::filter_and_sort_particles(
        vostok::render::stage_visibility *this,
        int probes_generate_pass,
        vostok::render::ambient_light **__pred)
{
  vostok::buffer_vector<vostok::render::ambient_light *> *v3; // esi
  vostok::render::ambient_light **v4; // ebx
  vostok::particle::render_particle_emitter_instance **m_begin; // eax
  vostok::render::ambient_light **v6; // eax
  vostok::render::ambient_light **i; // edi
  vostok::render::ambient_light **v8; // ecx
  vostok::render::ambient_light *v9; // eax
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *p_first; // ecx
  vostok::render::ambient_light **v11; // edi
  vostok::particle::render_particle_emitter_instance *v12; // ebx
  float v13; // xmm3_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // ecx
  int v17; // eax
  int v18; // edx
  vostok::render::particle_system_entry *j; // edi
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *v20; // [esp-4h] [ebp-2034h]
  const char *v21; // [esp+0h] [ebp-2030h]
  vostok::render::particle_system_entry *__last; // [esp+14h] [ebp-201Ch]
  vostok::render::particle_system_entry __first; // [esp+1Ch] [ebp-2014h] BYREF
  vostok::render::particle_system_entry v24; // [esp+201Ch] [ebp-14h] BYREF
  float v25; // [esp+2028h] [ebp-8h]
  vostok::render::ambient_light **end; // [esp+202Ch] [ebp-4h] BYREF

  v3 = (vostok::buffer_vector<vostok::render::ambient_light *> *)(*(_DWORD *)(*(_DWORD *)(probes_generate_pass + 4)
                                                                            + 16268)
                                                                + 56568);
  if ( !(_BYTE)__pred )
  {
    v4 = *(vostok::render::ambient_light ***)(*(_DWORD *)(*(_DWORD *)(probes_generate_pass + 4) + 16268) + 56572);
    LOBYTE(__pred) = 0;
    m_begin = (vostok::particle::render_particle_emitter_instance **)v3->m_begin;
    end = v4;
    v6 = (vostok::render::ambient_light **)stlp_std::priv::__find_if<vostok::particle::render_particle_emitter_instance * *,vostok::render::remove_if_occluded_predicate<vostok::particle::render_particle_emitter_instance>>(
                                             m_begin,
                                             (vostok::particle::render_particle_emitter_instance **)v4);
    if ( v6 != v4 )
    {
      __pred = v6;
      for ( i = v6 + 1; i != v4; ++i )
      {
        if ( !(*(unsigned __int8 (__thiscall **)(vostok::render::ambient_light *))((*i)->m_reference_count + 16))(*i) )
        {
          v8 = __pred;
          v9 = *i;
          ++__pred;
          *v8 = v9;
        }
      }
      v6 = __pred;
    }
    __pred = v6;
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(v3, &__pred, &end);
  }
  p_first = (vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *)&__first;
  __last = &__first;
  v11 = v3->m_begin;
  end = v3->m_end;
  if ( v11 != end )
  {
    do
    {
      v12 = (vostok::particle::render_particle_emitter_instance *)*v11;
      v13 = *(float *)(*(_DWORD *)(probes_generate_pass + 4) + 21132)
          - (float)((float)((*v11)->m_help_random_radius_offset + (*v11)[1].m_properties.transform.i.x) * 0.5);
      v14 = *(float *)(*(_DWORD *)(probes_generate_pass + 4) + 21136)
          - (float)((float)(*(float *)&(*v11)->m_occluded + (*v11)[1].m_properties.transform.i.y) * 0.5);
      v15 = *(float *)(*(_DWORD *)(probes_generate_pass + 4) + 21140)
          - (float)((float)(*(float *)&(*v11)[1].m_reference_count + (*v11)[1].m_properties.transform.i.z) * 0.5);
      v25 = (float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v13 * v13);
      if ( __last >= &v24 && !BYTE1(vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.elements[3]) )
      {
        HIBYTE(__pred) = 0;
        vostok::debug::on_error(
          (bool *)&__pred + 3,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct vostok::render::particle_system_entry>::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v21);
        if ( vostok::debug::is_debugger_present() || HIBYTE(__pred) )
          __debugbreak();
      }
      if ( __last )
      {
        v16 = v25;
        __last->instance = v12;
        __last->distance_to_camera = v16;
      }
      ++__last;
      ++v11;
    }
    while ( v11 != end );
    p_first = (vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *> *)&__first;
  }
  LOBYTE(__pred) = 0;
  if ( &__first != __last )
  {
    v17 = __last - &__first;
    v18 = 0;
    while ( v17 != 1 )
    {
      ++v18;
      v17 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::render::particle_system_entry *,vostok::render::particle_system_entry,int,vostok::render::particle_emitter_sort_predicate>(
      &__first,
      __last,
      0,
      2 * v18,
      (vostok::render::particle_system_entry *)__pred);
    stlp_std::priv::__final_insertion_sort<vostok::render::particle_system_entry *,vostok::render::particle_emitter_sort_predicate>(
      &__first,
      __last,
      (vostok::render::particle_emitter_sort_predicate)__pred);
    p_first = v20;
  }
  v3->m_end = v3->m_begin;
  for ( j = &__first; j != __last; ++j )
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::push_back(
      p_first,
      (int)v3,
      &j->instance);
}
