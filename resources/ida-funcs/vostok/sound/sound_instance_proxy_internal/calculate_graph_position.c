void __thiscall vostok::sound::sound_instance_proxy_internal::calculate_graph_position(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *listener_position,
        vostok::vectora<stlp_std::pair<float,vostok::math::float3> > *results)
{
  vostok::math::float3 other_x; // [esp+0h] [ebp-524h]
  vostok::math::float3 other_xa; // [esp+0h] [ebp-524h]
  unsigned int *jj; // [esp+64h] [ebp-4C0h]
  float v7; // [esp+84h] [ebp-4A0h]
  float v8; // [esp+94h] [ebp-490h]
  float v9; // [esp+98h] [ebp-48Ch]
  float v10; // [esp+9Ch] [ebp-488h]
  vostok::math::float3 *v11; // [esp+C4h] [ebp-460h]
  float v12; // [esp+CCh] [ebp-458h]
  float v13; // [esp+D0h] [ebp-454h]
  _BYTE v14[12]; // [esp+E4h] [ebp-440h]
  float v15; // [esp+F0h] [ebp-434h]
  vostok::math::float3 *portal_center; // [esp+FCh] [ebp-428h]
  float v17; // [esp+104h] [ebp-420h]
  float v18; // [esp+108h] [ebp-41Ch]
  float v19; // [esp+11Ch] [ebp-408h]
  float v20; // [esp+124h] [ebp-400h]
  float v21; // [esp+128h] [ebp-3FCh]
  unsigned int *v22; // [esp+12Ch] [ebp-3F8h]
  unsigned int *n; // [esp+144h] [ebp-3E0h]
  float v24; // [esp+158h] [ebp-3CCh]
  float v25; // [esp+160h] [ebp-3C4h]
  float v26; // [esp+164h] [ebp-3C0h]
  float v27; // [esp+168h] [ebp-3BCh]
  unsigned int *v28; // [esp+17Ch] [ebp-3A8h]
  unsigned int *k; // [esp+194h] [ebp-390h]
  vostok::math::float3 *v30; // [esp+1A8h] [ebp-37Ch]
  float v31; // [esp+1B4h] [ebp-370h]
  float v32; // [esp+1BCh] [ebp-368h]
  unsigned int *j; // [esp+1C4h] [ebp-360h]
  float v34; // [esp+1D8h] [ebp-34Ch]
  vostok::math::float3 v35; // [esp+1ECh] [ebp-338h] BYREF
  vostok::math::half3_pod m_val; // [esp+1F8h] [ebp-32Ch]
  float v37; // [esp+200h] [ebp-324h]
  vostok::resources::unmanaged_resource *m_object; // [esp+208h] [ebp-31Ch]
  vostok::vectora_allocator<void *> allocator; // [esp+20Ch] [ebp-318h] BYREF
  vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3> > v40; // [esp+210h] [ebp-314h] BYREF
  vostok::math::float3 v41; // [esp+214h] [ebp-310h] BYREF
  vostok::math::half3_pod v42; // [esp+220h] [ebp-304h]
  float v43; // [esp+228h] [ebp-2FCh]
  vostok::math::float3 v44; // [esp+230h] [ebp-2F4h]
  int v45; // [esp+23Ch] [ebp-2E8h]
  stlp_std::pair<float,vostok::math::float3> v46; // [esp+240h] [ebp-2E4h] BYREF
  SpeedTree::Vec3 v47; // [esp+250h] [ebp-2D4h] BYREF
  SpeedTree::Vec3 v48; // [esp+25Ch] [ebp-2C8h] BYREF
  float v49; // [esp+268h] [ebp-2BCh]
  float v50; // [esp+26Ch] [ebp-2B8h]
  float v51; // [esp+270h] [ebp-2B4h]
  float v52; // [esp+274h] [ebp-2B0h]
  float v53; // [esp+278h] [ebp-2ACh]
  float v54; // [esp+27Ch] [ebp-2A8h]
  vostok::math::float3_pod v55; // [esp+280h] [ebp-2A4h] BYREF
  SpeedTree::Vec3 v56; // [esp+28Ch] [ebp-298h] BYREF
  vostok::math::float3 v57; // [esp+298h] [ebp-28Ch] BYREF
  SpeedTree::Vec3 v58; // [esp+2A4h] [ebp-280h] BYREF
  vostok::math::float3 v59; // [esp+2B0h] [ebp-274h] BYREF
  stlp_std::pair<float,vostok::math::float3> v60; // [esp+2BCh] [ebp-268h] BYREF
  SpeedTree::Vec3 v61; // [esp+2CCh] [ebp-258h] BYREF
  vostok::math::float3 v62; // [esp+2D8h] [ebp-24Ch] BYREF
  vostok::math::float3 v63; // [esp+2E4h] [ebp-240h] BYREF
  vostok::math::float3 v64; // [esp+2F0h] [ebp-234h] BYREF
  stlp_std::pair<float,vostok::math::float3> v65; // [esp+2FCh] [ebp-228h] BYREF
  vostok::math::float3 v66; // [esp+30Ch] [ebp-218h] BYREF
  vostok::math::float3 v67; // [esp+318h] [ebp-20Ch] BYREF
  vostok::math::float3 v68; // [esp+324h] [ebp-200h] BYREF
  vostok::math::float3 v69; // [esp+330h] [ebp-1F4h] BYREF
  stlp_std::pair<float,vostok::math::float3> v70; // [esp+33Ch] [ebp-1E8h] BYREF
  vostok::math::float3 v71; // [esp+34Ch] [ebp-1D8h] BYREF
  float v72; // [esp+358h] [ebp-1CCh]
  vostok::math::half3_pod v73; // [esp+35Ch] [ebp-1C8h] BYREF
  vostok::math::float3 v74; // [esp+364h] [ebp-1C0h] BYREF
  vostok::math::float3 v75; // [esp+370h] [ebp-1B4h] BYREF
  vostok::math::float3 v76; // [esp+37Ch] [ebp-1A8h]
  stlp_std::pair<float,vostok::math::float3> v77; // [esp+388h] [ebp-19Ch] BYREF
  vostok::math::float3 v78; // [esp+398h] [ebp-18Ch] BYREF
  float v79; // [esp+3A4h] [ebp-180h]
  vostok::math::half3_pod v80; // [esp+3A8h] [ebp-17Ch] BYREF
  vostok::math::float3 object; // [esp+3B0h] [ebp-174h] BYREF
  vostok::math::float3 result; // [esp+3BCh] [ebp-168h] BYREF
  vostok::math::float3 v83; // [esp+3C8h] [ebp-15Ch]
  stlp_std::pair<float,vostok::math::float3> v84; // [esp+3D4h] [ebp-150h] BYREF
  stlp_std::pair<float,vostok::math::float3> __x; // [esp+3E4h] [ebp-140h] BYREF
  vostok::math::float3 v86; // [esp+3F4h] [ebp-130h] BYREF
  unsigned int ii; // [esp+400h] [ebp-124h]
  float v88; // [esp+404h] [ebp-120h]
  vostok::math::float3 v89; // [esp+408h] [ebp-11Ch] BYREF
  vostok::math::float3 end_point; // [esp+414h] [ebp-110h] BYREF
  unsigned int m; // [esp+420h] [ebp-104h]
  float v92; // [esp+424h] [ebp-100h]
  vostok::math::float3 v93; // [esp+428h] [ebp-FCh]
  vostok::math::float3 v94; // [esp+434h] [ebp-F0h]
  float v95; // [esp+440h] [ebp-E4h]
  vostok::math::float3 start_point; // [esp+444h] [ebp-E0h]
  vostok::math::float3 pos; // [esp+450h] [ebp-D4h] BYREF
  float distance_to_sound; // [esp+45Ch] [ebp-C8h]
  vostok::math::float3 nearest_point_on_portal; // [esp+460h] [ebp-C4h] BYREF
  float distance_to_listener; // [esp+46Ch] [ebp-B8h]
  unsigned int path_size; // [esp+470h] [ebp-B4h]
  vostok::fixed_vector<unsigned int,32> current_path; // [esp+474h] [ebp-B0h] BYREF
  unsigned int i; // [esp+500h] [ebp-24h]
  bool use_graph; // [esp+507h] [ebp-1Dh]
  vostok::vectora<vostok::fixed_vector<unsigned int,32> > paths; // [esp+508h] [ebp-1Ch] BYREF
  vostok::math::float3 position; // [esp+518h] [ebp-Ch] BYREF

  if ( this->m_type == hud )
  {
    v44 = *listener_position;
    v45 = *(_DWORD *)&FLOAT_0_0;
    __x.first = *(float *)&FLOAT_0_0;
    __x.second = v44;
    stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
      &results->_M_impl,
      &__x);
  }
  else
  {
    use_graph = 1;
    if ( vostok::sound::sound_scene::graph_exist(this->m_scene) )
    {
      vostok::math::half3_pod::operator vostok::math::float3(&this->m_position.m_data.m_val, &v78);
      position = v78;
      m_object = vostok::sound::g_allocator.m_object;
      allocator.m_allocator = (vostok::memory::base_allocator *)vostok::sound::g_allocator.m_object;
      vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>::vectora_allocator<vostok::fixed_vector<unsigned int,32>>(
        &v40,
        &allocator);
      stlp_std::priv::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::_Vector_base<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(
        &paths._M_impl,
        (const vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32> > *)&v40);
      vostok::sound::sound_scene::find_path(this->m_scene, &position, &paths);
      if ( paths._M_impl._M_start == paths._M_impl._M_finish )
      {
        v76 = *vostok::math::half3_pod::operator vostok::math::float3(&this->m_position.m_data.m_val, &v75);
        vostok::math::float3::float3(
          &v74,
          COERCE_UNSIGNED_INT(v76.x - listener_position->x),
          COERCE_UNSIGNED_INT(v76.y - listener_position->y),
          v76.z - listener_position->z);
        m_val = this->m_position.m_data.m_val;
        v37 = vostok::math::length(&v74);
        v72 = v37;
        v73 = m_val;
        v77.first = v37;
        vostok::math::half3_pod::operator vostok::math::float3(&v73, &v35);
        v77.second = v35;
        stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
          &results->_M_impl,
          &v77);
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::~_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(&paths._M_impl);
      }
      else
      {
        for ( i = 0; i < 4 && i < paths._M_impl._M_finish - paths._M_impl._M_start; ++i )
        {
          vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
            &current_path,
            (unsigned int *)current_path.m_buffer,
            0x20u,
            &paths._M_impl._M_start[i]);
          path_size = current_path.m_end - current_path.m_begin;
          if ( path_size == 1 )
          {
            if ( vostok::sound::sound_scene::is_segment_pass_portal(
                   this->m_scene,
                   *current_path.m_begin,
                   *listener_position,
                   position) )
            {
              vostok::math::float3::float3(
                &v71,
                COERCE_UNSIGNED_INT(position.x - listener_position->x),
                COERCE_UNSIGNED_INT(position.y - listener_position->y),
                position.z - listener_position->z);
              v34 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v71);
              distance_to_listener = fsqrt(v34);
              v70.first = distance_to_listener;
              v70.second = position;
              stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
                &results->_M_impl,
                &v70);
              for ( j = current_path.m_begin; j != current_path.m_end; ++j )
                ;
              current_path.m_end = current_path.m_begin;
            }
            else
            {
              vostok::sound::sound_scene::get_portal_nearest_point(
                this->m_scene,
                &nearest_point_on_portal,
                *current_path.m_begin,
                *listener_position,
                position);
              vostok::math::float3::float3(
                &v69,
                COERCE_UNSIGNED_INT(nearest_point_on_portal.x - listener_position->x),
                COERCE_UNSIGNED_INT(nearest_point_on_portal.y - listener_position->y),
                nearest_point_on_portal.z - listener_position->z);
              v32 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v69);
              vostok::math::float3::float3(
                &v68,
                COERCE_UNSIGNED_INT(position.x - nearest_point_on_portal.x),
                COERCE_UNSIGNED_INT(position.y - nearest_point_on_portal.y),
                position.z - nearest_point_on_portal.z);
              v31 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v68);
              distance_to_sound = fsqrt(v31) + fsqrt(v32);
              vostok::math::float3::float3(
                &v67,
                COERCE_UNSIGNED_INT(nearest_point_on_portal.x - listener_position->x),
                COERCE_UNSIGNED_INT(nearest_point_on_portal.y - listener_position->y),
                nearest_point_on_portal.z - listener_position->z);
              v30 = vostok::math::float3_pod::normalize(&v67);
              vostok::math::float3::float3(
                &v66,
                COERCE_UNSIGNED_INT(v30->x * distance_to_sound),
                COERCE_UNSIGNED_INT(v30->y * distance_to_sound),
                v30->z * distance_to_sound);
              vostok::math::float3::float3(
                &pos,
                COERCE_UNSIGNED_INT(nearest_point_on_portal.x + v66.x),
                COERCE_UNSIGNED_INT(nearest_point_on_portal.y + v66.y),
                nearest_point_on_portal.z + v66.z);
              v65.first = distance_to_sound;
              v65.second = pos;
              stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
                &results->_M_impl,
                &v65);
              for ( k = current_path.m_begin; k != current_path.m_end; ++k )
                ;
              current_path.m_end = current_path.m_begin;
            }
          }
          else
          {
            v28 = &current_path.m_begin[current_path.m_end - current_path.m_begin - 1];
            other_x = *vostok::sound::sound_scene::get_portal_center(
                         this->m_scene,
                         &v64,
                         current_path.m_begin[current_path.m_end - current_path.m_begin - 2]);
            if ( vostok::sound::sound_scene::is_segment_pass_portal(this->m_scene, *v28, *listener_position, other_x) )
            {
              v94 = *vostok::sound::sound_scene::get_portal_center(
                       this->m_scene,
                       &v63,
                       current_path.m_begin[current_path.m_end - current_path.m_begin - 2]);
              v92 = *(float *)&FLOAT_0_0;
              v93 = position;
              for ( m = 0; m < current_path.m_end - current_path.m_begin - 1; ++m )
              {
                vostok::sound::sound_scene::get_portal_center(this->m_scene, &end_point, current_path.m_begin[m]);
                vostok::math::float3::float3(
                  &v62,
                  COERCE_UNSIGNED_INT(v93.x - end_point.x),
                  COERCE_UNSIGNED_INT(v93.y - end_point.y),
                  v93.z - end_point.z);
                v27 = vostok::math::float3_pod::squared_length((SpeedTree::Vec3 *)&v62);
                v92 = fsqrt(v27) + v92;
                v93 = end_point;
              }
              v25 = v93.y - listener_position->y;
              v26 = v93.z - listener_position->z;
              v61.x = v93.x - listener_position->x;
              v61.y = v25;
              v61.z = v26;
              v24 = vostok::math::float3_pod::squared_length(&v61);
              v92 = fsqrt(v24) + v92;
              v60.first = v92;
              v60.second = v94;
              stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
                &results->_M_impl,
                &v60);
              for ( n = current_path.m_begin; n != current_path.m_end; ++n )
                ;
              current_path.m_end = current_path.m_begin;
            }
            else
            {
              v22 = &current_path.m_begin[current_path.m_end - current_path.m_begin - 1];
              other_xa = *vostok::sound::sound_scene::get_portal_center(
                            this->m_scene,
                            &v59,
                            current_path.m_begin[current_path.m_end - current_path.m_begin - 2]);
              vostok::sound::sound_scene::get_portal_nearest_point(
                this->m_scene,
                &v89,
                *v22,
                *listener_position,
                other_xa);
              v20 = v89.y - listener_position->y;
              v21 = v89.z - listener_position->z;
              v58.x = v89.x - listener_position->x;
              v58.y = v20;
              v58.z = v21;
              v19 = vostok::math::float3_pod::squared_length(&v58);
              portal_center = vostok::sound::sound_scene::get_portal_center(
                                this->m_scene,
                                &v57,
                                current_path.m_begin[current_path.m_end - current_path.m_begin - 2]);
              v17 = portal_center->y - v89.y;
              v18 = portal_center->z - v89.z;
              v56.x = portal_center->x - v89.x;
              v56.y = v17;
              v56.z = v18;
              v15 = vostok::math::float3_pod::squared_length(&v56);
              v88 = fsqrt(v15) + fsqrt(v19);
              *(float *)v14 = v89.x - listener_position->x;
              *(float *)&v14[4] = v89.y - listener_position->y;
              *(float *)&v14[8] = v89.z - listener_position->z;
              v55 = *(vostok::math::float3_pod *)v14;
              v11 = vostok::math::float3_pod::normalize(&v55);
              v12 = v11->y * v88;
              v13 = v11->z * v88;
              v52 = v11->x * v88;
              v53 = v12;
              v54 = v13;
              v49 = v89.x + v52;
              v50 = v89.y + v12;
              v51 = v89.z + v13;
              v94.x = v89.x + v52;
              v94.y = v89.y + v12;
              v94.z = v89.z + v13;
              v95 = *(float *)&FLOAT_0_0;
              start_point = position;
              for ( ii = 0; ii < current_path.m_end - current_path.m_begin; ++ii )
              {
                vostok::sound::sound_scene::get_portal_center(this->m_scene, &v86, current_path.m_begin[ii]);
                v48.x = start_point.x - v86.x;
                v48.y = start_point.y - v86.y;
                v48.z = start_point.z - v86.z;
                v10 = vostok::math::float3_pod::squared_length(&v48);
                v95 = fsqrt(v10) + v95;
                start_point = v86;
              }
              v8 = start_point.y - listener_position->y;
              v9 = start_point.z - listener_position->z;
              v47.x = start_point.x - listener_position->x;
              v47.y = v8;
              v47.z = v9;
              v7 = vostok::math::float3_pod::squared_length(&v47);
              v95 = fsqrt(v7) + v95;
              v46.first = v95;
              v46.second = v94;
              stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
                &results->_M_impl,
                &v46);
              for ( jj = current_path.m_begin; jj != current_path.m_end; ++jj )
                ;
              current_path.m_end = current_path.m_begin;
            }
          }
        }
        stlp_std::priv::_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>::~_Impl_vector<vostok::fixed_vector<unsigned int,32>,vostok::vectora_allocator<vostok::fixed_vector<unsigned int,32>>>(&paths._M_impl);
      }
    }
    else
    {
      v83 = *vostok::math::half3_pod::operator vostok::math::float3(&this->m_position.m_data.m_val, &result);
      vostok::math::float3::float3(
        &object,
        COERCE_UNSIGNED_INT(v83.x - listener_position->x),
        COERCE_UNSIGNED_INT(v83.y - listener_position->y),
        v83.z - listener_position->z);
      v42 = this->m_position.m_data.m_val;
      v43 = vostok::math::length(&object);
      v79 = v43;
      v80 = v42;
      v84.first = v43;
      vostok::math::half3_pod::operator vostok::math::float3(&v80, &v41);
      v84.second = v41;
      stlp_std::priv::_Impl_vector<stlp_std::pair<float,vostok::math::float3>,vostok::vectora_allocator<stlp_std::pair<float,vostok::math::float3>>>::push_back(
        &results->_M_impl,
        &v84);
    }
  }
}
