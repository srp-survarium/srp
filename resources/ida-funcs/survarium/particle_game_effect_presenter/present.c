void __thiscall survarium::particle_game_effect_presenter::present(
        survarium::particle_game_effect_presenter *this,
        survarium::base_player *player)
{
  survarium::particle_game_effect_presenter::effect_data *m_end; // esi
  vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *m_begin; // edi
  int v5; // eax
  int v6; // ecx
  vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *p_m_old_effects; // edi
  unsigned int v8; // eax
  survarium::particle_game_effect_presenter::effect_data *v9; // esi
  survarium::particle_game_effect_presenter::effect_data *v10; // ecx
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v11; // ecx
  int v12; // esi
  survarium::particle_game_effect_presenter::effect_data *v13; // esi
  survarium::particle_game_effect_presenter::effect_data *v14; // ecx
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v15; // ecx
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v16; // ecx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v17; // edi
  survarium::pure_game_effect_emitter_base *v18; // ecx
  vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *p_m_new_effects; // esi
  int v20; // eax
  int v21; // eax
  survarium::collision_user *v22; // ecx
  const survarium::base_game_scene *m_scene; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v24; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_m_render_scene; // edx
  survarium::collision_user_vtbl *v26; // eax
  const vostok::math::float4x4 *v27; // eax
  vostok::render::scene_renderer *v28; // ecx
  bool v29; // zf
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v30; // ecx
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> *v31; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v32; // [esp-10h] [ebp-B4h] BYREF
  const vostok::math::float4x4 *v33; // [esp-Ch] [ebp-B0h]
  vostok::math::float4x4 *v34; // [esp-8h] [ebp-ACh]
  survarium::particle_game_effect_presenter::effect_data *v35; // [esp-4h] [ebp-A8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v36; // [esp+0h] [ebp-A4h]
  bool v37; // [esp+4h] [ebp-A0h]
  int v38; // [esp+14h] [ebp-90h]
  stlp_std::less<survarium::particle_game_effect_presenter::effect_data> __comp[4]; // [esp+18h] [ebp-8Ch] BYREF
  vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *v40; // [esp+1Ch] [ebp-88h] BYREF
  survarium::particle_game_effect_presenter::effect_data *end; // [esp+20h] [ebp-84h] BYREF
  survarium::collision_user *v42; // [esp+24h] [ebp-80h]
  vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *v43; // [esp+28h] [ebp-7Ch]
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data> v44; // [esp+2Ch] [ebp-78h] BYREF
  _BYTE v45[48]; // [esp+38h] [ebp-6Ch] BYREF
  survarium::particle_game_effect_presenter::effect_data *begin; // [esp+68h] [ebp-3Ch] BYREF
  survarium::particle_game_effect_presenter::effect_data *v47[2]; // [esp+6Ch] [ebp-38h] BYREF
  _BYTE v48[48]; // [esp+74h] [ebp-30h] BYREF
  char vars0; // [esp+A4h] [ebp+0h] BYREF

  m_end = this->m_new_effects.m_end;
  m_begin = (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this->m_new_effects.m_begin;
  if ( m_begin != (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)m_end )
  {
    v5 = ((char *)m_end - (char *)m_begin) >> 4;
    v6 = 0;
    while ( v5 != 1 )
    {
      ++v6;
      v5 >>= 1;
    }
    stlp_std::priv::__introsort_loop<survarium::particle_game_effect_presenter::effect_data *,survarium::particle_game_effect_presenter::effect_data,int,stlp_std::less<survarium::particle_game_effect_presenter::effect_data>>(
      m_begin,
      m_end,
      0,
      2 * v6,
      *(survarium::loose_ptr_data **)&__comp[0].gap0);
    stlp_std::priv::__final_insertion_sort<survarium::particle_game_effect_presenter::effect_data *,stlp_std::less<survarium::particle_game_effect_presenter::effect_data>>(
      (survarium::particle_game_effect_presenter::effect_data *)m_begin,
      m_end,
      *(survarium::particle_game_effect_presenter::effect_data **)&__comp[0].gap0);
  }
  v44.m_begin = (survarium::particle_game_effect_presenter::effect_data *)v45;
  v44.m_end = (survarium::particle_game_effect_presenter::effect_data *)v45;
  v44.m_max_end = (survarium::particle_game_effect_presenter::effect_data *)&begin;
  p_m_old_effects = &this->m_old_effects;
  v8 = this->m_old_effects.m_end - this->m_old_effects.m_begin;
  v43 = &this->m_old_effects;
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::resize(v8, &v44);
  v36 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v44.m_begin;
  v9 = this->m_old_effects.m_begin;
  v10 = this->m_old_effects.m_end;
  v35 = this->m_new_effects.m_end;
  v40 = (vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *)v44.m_end;
  end = stlp_std::set_difference<survarium::particle_game_effect_presenter::effect_data *,survarium::particle_game_effect_presenter::effect_data *,survarium::particle_game_effect_presenter::effect_data *>(
          v10,
          (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)this->m_new_effects.m_begin,
          v9,
          (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v35,
          v44.m_begin);
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::erase(
    v11,
    &v44.m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&end,
    (survarium::particle_game_effect_presenter::effect_data **)&v40);
  if ( v44.m_end - v44.m_begin )
  {
    v12 = 0;
    v38 = v44.m_end - v44.m_begin;
    do
    {
      vostok::render::scene_renderer::stop_particle_system(
        (vostok::render::scene_renderer *)&v44.m_begin[v12].particle_system,
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_scene->m_game->m_renderer),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene->m_render_scene,
        (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v44.m_begin[v12].particle_system,
        COERCE_INT(v44.m_begin[v12].time_to_finish));
      ++v12;
      --v38;
    }
    while ( v38 );
  }
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::resize(
    this->m_new_effects.m_end - this->m_new_effects.m_begin,
    &v44);
  v36 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v44.m_begin;
  v13 = this->m_new_effects.m_begin;
  v14 = this->m_new_effects.m_end;
  v35 = this->m_old_effects.m_end;
  v40 = (vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *)v44.m_end;
  end = stlp_std::set_difference<survarium::particle_game_effect_presenter::effect_data *,survarium::particle_game_effect_presenter::effect_data *,survarium::particle_game_effect_presenter::effect_data *>(
          v14,
          (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)p_m_old_effects->m_begin,
          v13,
          (stlp_std::less<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *)v35,
          v44.m_begin);
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::erase(
    v15,
    &v44.m_begin,
    (survarium::loose_ptr<survarium::particle_game_effect const ,survarium::loose_ptr_data,vostok::threading::single_threading_policy> **)&end,
    (survarium::particle_game_effect_presenter::effect_data **)&v40);
  if ( v44.m_end - v44.m_begin )
  {
    v38 = 0;
    v42 = (survarium::collision_user *)(v44.m_end - v44.m_begin);
    do
    {
      v17 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)v44.m_begin + v38);
      v36 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)player + (_DWORD)&loc_1119E + 2);
      v35 = (survarium::particle_game_effect_presenter::effect_data *)((char *)&dword_10E78 + (_DWORD)player);
      v34 = (vostok::math::float4x4 *)player->transform(&player->survarium::collision_user);
      v33 = player->transform(&player->survarium::collision_user);
      v32.m_object = v18;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v32,
        v17 + 1);
      vostok::render::scene_renderer::play_particle_system(
        (vostok::render::scene_renderer *)&this->m_scene->m_render_scene,
        *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_scene->m_game->m_renderer),
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene->m_render_scene,
        (const vostok::math::float4x4 *)v32.m_object,
        v33,
        v34,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v35,
        v36);
      v38 += 16;
      v42 = (survarium::collision_user *)((char *)v42 - 1);
    }
    while ( v42 );
    p_m_old_effects = v43;
  }
  p_m_new_effects = &this->m_new_effects;
  v20 = (char *)this->m_new_effects.m_end - (char *)this->m_new_effects.m_begin;
  v40 = &this->m_new_effects;
  v21 = v20 >> 4;
  if ( v21 )
  {
    v22 = &player->survarium::collision_user;
    v38 = 0;
    v42 = &player->survarium::collision_user;
    end = (survarium::particle_game_effect_presenter::effect_data *)v21;
    while ( 1 )
    {
      m_scene = this->m_scene;
      v24 = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)((char *)p_m_new_effects->m_begin + v38);
      p_m_render_scene = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_scene->m_render_scene;
      *(_DWORD *)&__comp[0].gap0 = *(int *)((char *)&dword_200060 + (unsigned int)m_scene->m_game->m_renderer);
      v26 = v22->__vftable;
      v43 = (vostok::fixed_vector<survarium::particle_game_effect_presenter::effect_data,3> *)p_m_render_scene;
      v36 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v26->transform(v22);
      v27 = v42->transform(v42);
      vostok::render::scene_renderer::update_particle_system_instance(
        v28,
        *(boost::_bi::bind_t<void,boost::_mfi::mf6<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &,vostok::math::float4x4 const &,bool,bool>,boost::_bi::list7<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1>,boost::arg<2>,boost::_bi::value<bool>,boost::_bi::value<bool> > > **)&__comp[0].gap0,
        (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v43,
        v24 + 1,
        v27,
        (vostok::math::float4x4 *)v36,
        v37);
      v38 += 16;
      v29 = end == (survarium::particle_game_effect_presenter::effect_data *)1;
      end = (survarium::particle_game_effect_presenter::effect_data *)((char *)end - 1);
      p_m_new_effects = v40;
      if ( v29 )
        break;
      v22 = v42;
    }
  }
  begin = (survarium::particle_game_effect_presenter::effect_data *)v48;
  v47[0] = (survarium::particle_game_effect_presenter::effect_data *)v48;
  v47[1] = (survarium::particle_game_effect_presenter::effect_data *)&vars0;
  *(_DWORD *)&__comp[0].gap0 = p_m_old_effects->m_end;
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::assign<survarium::particle_game_effect_presenter::effect_data const *>(
    v16,
    &begin,
    p_m_old_effects->m_begin,
    (const survarium::particle_game_effect_presenter::effect_data **)__comp);
  *(_DWORD *)&__comp[0].gap0 = p_m_new_effects->m_end;
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::assign<survarium::particle_game_effect_presenter::effect_data const *>(
    v30,
    &p_m_old_effects->m_begin,
    p_m_new_effects->m_begin,
    (const survarium::particle_game_effect_presenter::effect_data **)__comp);
  *(survarium::particle_game_effect_presenter::effect_data **)&__comp[0].gap0 = v47[0];
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::assign<survarium::particle_game_effect_presenter::effect_data const *>(
    v31,
    &p_m_new_effects->m_begin,
    begin,
    (const survarium::particle_game_effect_presenter::effect_data **)__comp);
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(begin, v47);
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(
    p_m_new_effects->m_begin,
    &p_m_new_effects->m_end);
  p_m_new_effects->m_end = p_m_new_effects->m_begin;
  vostok::buffer_vector<survarium::particle_game_effect_presenter::effect_data>::destroy(v44.m_begin, &v44.m_end);
}
