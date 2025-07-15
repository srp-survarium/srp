void __thiscall vostok::render::render_particle_emitter_instance::sort_particles(
        vostok::render::render_particle_emitter_instance *this,
        const vostok::math::float3 *view_location,
        vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *front_to_back)
{
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_first; // ecx
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *v5; // eax
  vostok::particle::base_particle *v6; // esi
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // ecx
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *v10; // esi
  int v11; // eax
  int v12; // edx
  vostok::threading::mutex *v13; // ecx
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *i; // ebx
  vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v15; // [esp-4h] [ebp-2034h]
  const char *v16; // [esp+0h] [ebp-2030h]
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *__last; // [esp+14h] [ebp-201Ch]
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry __first; // [esp+1Ch] [ebp-2014h] BYREF
  vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry v19; // [esp+201Ch] [ebp-14h] BYREF
  float v20; // [esp+2028h] [ebp-8h]
  bool v21; // [esp+202Fh] [ebp-1h] BYREF

  p_first = (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&__first;
  v5 = &__first;
  __last = &__first;
  v6 = *(vostok::particle::base_particle **)(LODWORD(view_location[28].y) + 36);
  if ( v6 )
  {
    do
    {
      v7 = *(float *)&this->m_material_effects.is_use_alpha_test - v6->render_position.z;
      v8 = *(float *)&this->m_material_effects.is_emissive - v6->render_position.y;
      v20 = (float)((float)(v7 * v7) + (float)(v8 * v8))
          + (float)((float)(*(float *)&this->__vftable - v6->render_position.x)
                  * (float)(*(float *)&this->__vftable - v6->render_position.x));
      if ( v5 >= &v19
        && !_debug_macro_helper_ignore_always__L___push_back___buffer_vector_Uparticle_entry__1__sort_particles_render_particle_emitter_instance_render_vostok__QAEXABVfloat3_math_5__N_Z__vostok__QAEXABUparticle_entry__1__sort_particles_render_particle_emitter_instance_render_3_QAEXABVfloat3_math_3__N_Z__Z_4_NA )
      {
        v21 = 0;
        vostok::debug::on_error(
          &v21,
          process_error_true,
          0,
          "assertion_failed",
          "fatal error",
          "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
          "vostok::buffer_vector<struct `public: void __thiscall vostok::render::render_particle_emitter_instance::sort_p"
          "articles(class vostok::math::float3 const &,bool)'::`2'::particle_entry>::push_back",
          (const char *)0x12E,
          "buffer overflow",
          v16);
        if ( vostok::debug::is_debugger_present() || v21 )
          __debugbreak();
      }
      if ( __last )
      {
        v9 = v20;
        __last->particle = v6;
        __last->distance = v9;
      }
      v5 = ++__last;
      v6 = v6->next;
    }
    while ( v6 );
    p_first = (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&__first;
  }
  v10 = v5;
  if ( &__first != v5 )
  {
    v11 = v5 - &__first;
    v12 = 0;
    while ( v11 != 1 )
    {
      ++v12;
      v11 >>= 1;
    }
    _____introsort_loop_PAUparticle_entry__1__sort_particles_render_particle_emitter_instance_render_vostok__QAEXABVfloat3_math_5__N_Z_U1_1__2345_QAEX01_Z_HUparticle_sort_predicate__3__2345_QAEX01_Z__priv_stlp_std__YAXPAUparticle_entry__1__sort_particles_render_particle_emitter_instance_render_vostok__QAEXABVfloat3_math_6__N_Z_22HUparticle_sort_predicate__3__3456_QAEX01_Z__Z(
      &__first,
      __last,
      0,
      2 * v12,
      front_to_back);
    _____final_insertion_sort_PAUparticle_entry__1__sort_particles_render_particle_emitter_instance_render_vostok__QAEXABVfloat3_math_5__N_Z_Uparticle_sort_predicate__3__2345_QAEX01_Z__priv_stlp_std__YAXPAUparticle_entry__1__sort_particles_render_particle_emitter_instance_render_vostok__QAEXABVfloat3_math_6__N_Z_2Uparticle_sort_predicate__3__3456_QAEX01_Z__Z(
      &__first,
      v10,
      (vostok::render::render_particle_emitter_instance::sort_particles::__l4::particle_sort_predicate)front_to_back);
    p_first = v15;
  }
  survarium::player_stamina::clear_subscribers(p_first, (_DWORD *)LODWORD(view_location[28].y));
  for ( i = &__first; i != __last; ++i )
    vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)LODWORD(view_location[28].y),
      i->particle,
      v13);
}
