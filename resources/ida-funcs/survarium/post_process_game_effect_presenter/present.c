void __thiscall survarium::post_process_game_effect_presenter::present(
        survarium::post_process_game_effect_presenter *this,
        survarium::base_player *player)
{
  unsigned int num_color_grading_textures; // edx
  float v4; // xmm3_4
  float *color_grading_weights; // eax
  unsigned int v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  unsigned int v9; // ecx
  float v10; // xmm2_4
  float *v11; // eax
  float m_sun_color_weight; // xmm3_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float m_god_rays_color_1_weight; // xmm3_4
  float m_god_rays_color_2_weight; // xmm3_4
  float m_sky_clouds_color_weight; // xmm3_4
  float m_sky_clouds_fog_color_weight; // xmm3_4
  float m_rayleigh_fog_color_weight; // xmm3_4
  float m_mie_fog_color_weight; // xmm3_4
  float m_height_based_ambient_low_color_weight; // xmm3_4
  float m_height_based_ambient_high_color_weight; // xmm3_4
  float m_bloom_color_weight; // xmm2_4
  float v24; // xmm0_4
  vostok::render::environment_properties *v25; // ecx
  int v26; // eax
  vostok::render::environment_properties *v27; // ecx
  vostok::render::environment_properties *v28; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> set_defaults[154]; // [esp+0h] [ebp-268h] BYREF

  num_color_grading_textures = this->m_result.num_color_grading_textures;
  v4 = 0.0;
  if ( num_color_grading_textures )
  {
    color_grading_weights = this->m_result.color_grading_weights;
    v6 = this->m_result.num_color_grading_textures;
    do
    {
      v7 = *color_grading_weights++;
      --v6;
      v4 = v7 + v4;
    }
    while ( v6 );
  }
  v8 = s_bm_current_air_resistance;
  v9 = 0;
  if ( num_color_grading_textures )
  {
    v10 = s_bm_current_air_resistance / v4;
    v11 = this->m_result.color_grading_weights;
    do
    {
      *v11 = v10 * *v11;
      ++v9;
      ++v11;
    }
    while ( v9 < this->m_result.num_color_grading_textures );
  }
  if ( this->m_sun_color_weight == 0.0 )
    m_sun_color_weight = v8;
  else
    m_sun_color_weight = this->m_sun_color_weight;
  this->m_result.sun_color.x = this->m_result.sun_color.x * (float)(v8 / m_sun_color_weight);
  this->m_result.sun_color.y = (float)(v8 / m_sun_color_weight) * this->m_result.sun_color.y;
  v13 = v8 / m_sun_color_weight;
  v14 = v13 * this->m_result.sun_color.w;
  this->m_result.sun_color.z = v13 * this->m_result.sun_color.z;
  this->m_result.sun_color.w = v14;
  if ( this->m_god_rays_color_1_weight == 0.0 )
    m_god_rays_color_1_weight = v8;
  else
    m_god_rays_color_1_weight = this->m_god_rays_color_1_weight;
  this->m_result.god_rays_color_1.x = (float)(v8 / m_god_rays_color_1_weight) * this->m_result.god_rays_color_1.x;
  this->m_result.god_rays_color_1.y = this->m_result.god_rays_color_1.y * (float)(v8 / m_god_rays_color_1_weight);
  this->m_result.god_rays_color_1.z = this->m_result.god_rays_color_1.z * (float)(v8 / m_god_rays_color_1_weight);
  this->m_result.god_rays_color_1.w = this->m_result.god_rays_color_1.w * (float)(v8 / m_god_rays_color_1_weight);
  if ( this->m_god_rays_color_2_weight == 0.0 )
    m_god_rays_color_2_weight = v8;
  else
    m_god_rays_color_2_weight = this->m_god_rays_color_2_weight;
  this->m_result.god_rays_color_2.x = (float)(v8 / m_god_rays_color_2_weight) * this->m_result.god_rays_color_2.x;
  this->m_result.god_rays_color_2.y = this->m_result.god_rays_color_2.y * (float)(v8 / m_god_rays_color_2_weight);
  this->m_result.god_rays_color_2.z = this->m_result.god_rays_color_2.z * (float)(v8 / m_god_rays_color_2_weight);
  this->m_result.god_rays_color_2.w = this->m_result.god_rays_color_2.w * (float)(v8 / m_god_rays_color_2_weight);
  if ( this->m_sky_clouds_color_weight == 0.0 )
    m_sky_clouds_color_weight = v8;
  else
    m_sky_clouds_color_weight = this->m_sky_clouds_color_weight;
  this->m_result.sky_clouds_color.x = (float)(v8 / m_sky_clouds_color_weight) * this->m_result.sky_clouds_color.x;
  this->m_result.sky_clouds_color.y = (float)(v8 / m_sky_clouds_color_weight) * this->m_result.sky_clouds_color.y;
  this->m_result.sky_clouds_color.z = (float)(v8 / m_sky_clouds_color_weight) * this->m_result.sky_clouds_color.z;
  this->m_result.sky_clouds_color.w = (float)(v8 / m_sky_clouds_color_weight) * this->m_result.sky_clouds_color.w;
  if ( this->m_sky_clouds_fog_color_weight == 0.0 )
    m_sky_clouds_fog_color_weight = v8;
  else
    m_sky_clouds_fog_color_weight = this->m_sky_clouds_fog_color_weight;
  this->m_result.sky_clouds_fog_color.x = this->m_result.sky_clouds_fog_color.x
                                        * (float)(v8 / m_sky_clouds_fog_color_weight);
  this->m_result.sky_clouds_fog_color.y = (float)(v8 / m_sky_clouds_fog_color_weight)
                                        * this->m_result.sky_clouds_fog_color.y;
  this->m_result.sky_clouds_fog_color.z = (float)(v8 / m_sky_clouds_fog_color_weight)
                                        * this->m_result.sky_clouds_fog_color.z;
  this->m_result.sky_clouds_fog_color.w = (float)(v8 / m_sky_clouds_fog_color_weight)
                                        * this->m_result.sky_clouds_fog_color.w;
  if ( this->m_rayleigh_fog_color_weight == 0.0 )
    m_rayleigh_fog_color_weight = v8;
  else
    m_rayleigh_fog_color_weight = this->m_rayleigh_fog_color_weight;
  this->m_result.rayleigh_fog_color.x = (float)(v8 / m_rayleigh_fog_color_weight) * this->m_result.rayleigh_fog_color.x;
  this->m_result.rayleigh_fog_color.y = (float)(v8 / m_rayleigh_fog_color_weight) * this->m_result.rayleigh_fog_color.y;
  this->m_result.rayleigh_fog_color.z = (float)(v8 / m_rayleigh_fog_color_weight) * this->m_result.rayleigh_fog_color.z;
  this->m_result.rayleigh_fog_color.w = (float)(v8 / m_rayleigh_fog_color_weight) * this->m_result.rayleigh_fog_color.w;
  if ( this->m_mie_fog_color_weight == 0.0 )
    m_mie_fog_color_weight = v8;
  else
    m_mie_fog_color_weight = this->m_mie_fog_color_weight;
  this->m_result.mie_fog_color.x = (float)(v8 / m_mie_fog_color_weight) * this->m_result.mie_fog_color.x;
  this->m_result.mie_fog_color.y = this->m_result.mie_fog_color.y * (float)(v8 / m_mie_fog_color_weight);
  this->m_result.mie_fog_color.z = this->m_result.mie_fog_color.z * (float)(v8 / m_mie_fog_color_weight);
  this->m_result.mie_fog_color.w = this->m_result.mie_fog_color.w * (float)(v8 / m_mie_fog_color_weight);
  if ( this->m_height_based_ambient_low_color_weight == 0.0 )
    m_height_based_ambient_low_color_weight = v8;
  else
    m_height_based_ambient_low_color_weight = this->m_height_based_ambient_low_color_weight;
  this->m_result.height_based_ambient_low_color.x = (float)(v8 / m_height_based_ambient_low_color_weight)
                                                  * this->m_result.height_based_ambient_low_color.x;
  this->m_result.height_based_ambient_low_color.y = (float)(v8 / m_height_based_ambient_low_color_weight)
                                                  * this->m_result.height_based_ambient_low_color.y;
  this->m_result.height_based_ambient_low_color.z = (float)(v8 / m_height_based_ambient_low_color_weight)
                                                  * this->m_result.height_based_ambient_low_color.z;
  this->m_result.height_based_ambient_low_color.w = (float)(v8 / m_height_based_ambient_low_color_weight)
                                                  * this->m_result.height_based_ambient_low_color.w;
  if ( this->m_height_based_ambient_high_color_weight == 0.0 )
    m_height_based_ambient_high_color_weight = v8;
  else
    m_height_based_ambient_high_color_weight = this->m_height_based_ambient_high_color_weight;
  this->m_result.height_based_ambient_high_color.x = this->m_result.height_based_ambient_high_color.x
                                                   * (float)(v8 / m_height_based_ambient_high_color_weight);
  this->m_result.height_based_ambient_high_color.y = (float)(v8 / m_height_based_ambient_high_color_weight)
                                                   * this->m_result.height_based_ambient_high_color.y;
  this->m_result.height_based_ambient_high_color.z = (float)(v8 / m_height_based_ambient_high_color_weight)
                                                   * this->m_result.height_based_ambient_high_color.z;
  this->m_result.height_based_ambient_high_color.w = (float)(v8 / m_height_based_ambient_high_color_weight)
                                                   * this->m_result.height_based_ambient_high_color.w;
  m_bloom_color_weight = this->m_bloom_color_weight;
  if ( m_bloom_color_weight == 0.0 )
    m_bloom_color_weight = v8;
  v24 = v8 / m_bloom_color_weight;
  this->m_result.bloom_color.x = v24 * this->m_result.bloom_color.x;
  this->m_result.bloom_color.y = v24 * this->m_result.bloom_color.y;
  this->m_result.bloom_color.z = v24 * this->m_result.bloom_color.z;
  this->m_result.bloom_color.w = v24 * this->m_result.bloom_color.w;
  vostok::render::scene_renderer::set_environment_properties(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene->m_render_scene_view,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,vostok::render::environment_properties const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + (unsigned int)this->m_scene->m_game->m_renderer),
    &this->m_result);
  vostok::render::environment_properties::environment_properties(v25, (int)set_defaults, 0);
  vostok::render::environment_properties::operator=(v27, &this->m_result, v26);
  vostok::render::environment_properties::~environment_properties(v28, set_defaults);
  this->m_sun_color_weight = 0.0;
  this->m_god_rays_color_1_weight = 0.0;
  this->m_god_rays_color_2_weight = 0.0;
  this->m_sky_clouds_color_weight = 0.0;
  this->m_sky_clouds_fog_color_weight = 0.0;
  this->m_rayleigh_fog_color_weight = 0.0;
  this->m_mie_fog_color_weight = 0.0;
  this->m_height_based_ambient_low_color_weight = 0.0;
  this->m_height_based_ambient_high_color_weight = 0.0;
  this->m_bloom_color_weight = 0.0;
}
