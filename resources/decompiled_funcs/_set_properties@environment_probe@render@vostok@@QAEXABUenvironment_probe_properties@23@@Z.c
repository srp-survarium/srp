void __thiscall vostok::render::environment_probe::set_properties(
        vostok::render::environment_probe *this,
        vostok::render::environment_probe *in_properties,
        vostok::render::environment_probe_properties *in_propertiesa)
{
  vostok::render::res_texture *v3; // ecx
  const vostok::render::res_texture *m_object; // esi
  bool v5; // zf
  const vostok::render::res_texture *v6; // esi
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v8; // ecx
  const vostok::render::res_texture *v9; // esi
  stlp_std::priv::_Rb_tree_node_base *v10; // eax
  const vostok::render::res_texture *v11; // esi
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // eax
  int v13; // eax
  vostok::collision::geometry_instance *v14; // edi
  int v15; // eax
  vostok::collision::object *v16; // ecx
  vostok::collision::object *v17; // esi
  vostok::math::float4x4 *v18; // esi
  float radius; // xmm0_4
  const vostok::math::float4x4 *v20; // esi
  vostok::collision::box_geometry_instance *v21; // eax
  int v22; // ecx
  vostok::collision::geometry_instance *v23; // eax
  vostok::collision::geometry_instance *v24; // edi
  int v25; // eax
  vostok::collision::object *v26; // ecx
  vostok::collision::object *v27; // esi
  vostok::collision::object *v28; // eax
  vostok::collision::space_partitioning_tree *m_collision_tree; // ecx
  long double v30; // st7
  float z; // xmm0_4
  float v32; // ecx
  __int64 v33; // xmm0_8
  const vostok::math::float4x4 *_X_4; // [esp+14h] [ebp-1C0h]
  vostok::math::float3 probe_scale3; // [esp+20h] [ebp-1B4h] BYREF
  __int128 v36; // [esp+34h] [ebp-1A0h]
  vostok::math::float4x4 dst; // [esp+44h] [ebp-190h] BYREF
  vostok::math::float4x4 new_transform; // [esp+84h] [ebp-150h] BYREF
  vostok::fixed_string<260> depth_texture_name; // [esp+C4h] [ebp-110h] BYREF
  char vars0; // [esp+1D4h] [ebp+0h] BYREF

  vostok::render::environment_probe_properties::operator=(
    (vostok::render::environment_probe_properties *)this,
    &in_properties->m_properties,
    in_propertiesa);
  in_properties->m_num_mips = vostok::render::calc_mip_map_count(in_propertiesa->cubemap_resolution);
  if ( in_propertiesa->texture_invalidated )
  {
    m_object = in_properties->m_texture.m_object;
    in_properties->m_texture.m_object = 0;
    if ( m_object )
    {
      v5 = m_object->m_reference_count-- == 1;
      if ( v5 )
        vostok::render::res_texture::destroy_impl(v3, m_object);
    }
    v6 = in_properties->m_texture_depth.m_object;
    in_properties->m_texture_depth.m_object = 0;
    if ( v6 )
    {
      v5 = v6->m_reference_count-- == 1;
      if ( v5 )
        vostok::render::res_texture::destroy_impl(v3, v6);
    }
    texture = vostok::render::resource_manager::create_texture(
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                in_properties->m_properties.texture_name.m_buffer,
                0,
                0,
                0,
                1,
                1,
                0xFFFFFFFF);
    v8 = 0;
    if ( texture )
    {
      ++texture->_M_parent;
      v8 = (vostok::render::res_texture *)texture;
    }
    v9 = in_properties->m_texture.m_object;
    in_properties->m_texture.m_object = v8;
    if ( v9 )
    {
      v5 = v9->m_reference_count-- == 1;
      if ( v5 )
        vostok::render::res_texture::destroy_impl(v8, v9);
    }
    v3 = (vostok::render::res_texture *)in_propertiesa;
    if ( in_propertiesa->with_shadows )
    {
      depth_texture_name.m_begin = depth_texture_name.m_buffer;
      depth_texture_name.m_end = depth_texture_name.m_buffer;
      depth_texture_name.m_max_end = &vars0;
      depth_texture_name.m_buffer[0] = 0;
      vostok::buffer_string::assignf(&depth_texture_name, "%s_depth", in_properties->m_properties.texture_name.m_buffer);
      v10 = vostok::render::resource_manager::create_texture(
              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
              depth_texture_name.m_buffer,
              0,
              0,
              0,
              1,
              1,
              0xFFFFFFFF);
      v3 = 0;
      if ( v10 )
      {
        ++v10->_M_parent;
        v3 = (vostok::render::res_texture *)v10;
      }
      v11 = in_properties->m_texture_depth.m_object;
      in_properties->m_texture_depth.m_object = v3;
      if ( v11 )
      {
        v5 = v11->m_reference_count-- == 1;
        if ( v5 )
          vostok::render::res_texture::destroy_impl(v3, v11);
      }
    }
  }
  vostok::render::environment_probe::remove_collision((vostok::render::environment_probe *)v3, (int)in_properties);
  if ( in_properties->m_properties.geometry )
  {
    v20 = vostok::math::float4x4::identity(&dst);
    v21 = (vostok::collision::box_geometry_instance *)((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
                                                        vostok::render::g_allocator.m_object,
                                                        136);
    if ( v21 )
    {
      vostok::collision::box_geometry_instance::box_geometry_instance(v22, v20, v21);
      v24 = v23;
    }
    else
    {
      v24 = 0;
    }
    in_properties->m_collision_geometry = v24;
    v25 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
            vostok::render::g_allocator.m_object,
            52);
    v27 = (vostok::collision::object *)v25;
    if ( v25 )
    {
      vostok::collision::object::object(v26, v25);
      v27->__vftable = (vostok::collision::object_vtbl *)&vostok::collision::collision_object::`vftable';
      v27[1].__vftable = (vostok::collision::object_vtbl *)v24;
      v27->m_user_data = in_properties;
      v27->m_type = 1;
      v28 = v27;
    }
    else
    {
      v28 = 0;
    }
    qmemcpy((void *)&new_transform, &in_properties->m_properties.transform, sizeof(new_transform));
    m_collision_tree = in_properties->m_collision_tree;
    in_properties->m_collision_object = v28;
    m_collision_tree->insert(m_collision_tree, v28, &new_transform);
    probe_scale3.x = sqrtf(
                       (float)((float)(in_properties->m_properties.transform.i.z
                                     * in_properties->m_properties.transform.i.z)
                             + (float)(in_properties->m_properties.transform.i.x
                                     * in_properties->m_properties.transform.i.x))
                     + (float)(in_properties->m_properties.transform.i.y * in_properties->m_properties.transform.i.y));
    probe_scale3.y = sqrtf(
                       (float)((float)(in_properties->m_properties.transform.j.y
                                     * in_properties->m_properties.transform.j.y)
                             + (float)(in_properties->m_properties.transform.j.z
                                     * in_properties->m_properties.transform.j.z))
                     + (float)(in_properties->m_properties.transform.j.x * in_properties->m_properties.transform.j.x));
    v30 = sqrtf(
            (float)((float)(in_properties->m_properties.transform.k.x * in_properties->m_properties.transform.k.x)
                  + (float)(in_properties->m_properties.transform.k.y * in_properties->m_properties.transform.k.y))
          + (float)(in_properties->m_properties.transform.k.z * in_properties->m_properties.transform.k.z));
    probe_scale3.z = v30;
    if ( probe_scale3.y <= v30 )
      z = probe_scale3.z;
    else
      z = probe_scale3.y;
    if ( probe_scale3.x > z )
      z = probe_scale3.x;
    v32 = in_properties->m_properties.transform.c.z;
    *(_QWORD *)&in_properties->m_properties.location.x = *(_QWORD *)&in_properties->m_properties.transform.lines[3].x;
    in_properties->m_properties.location.z = v32;
    in_properties->m_properties.radius = z * 0.75;
  }
  else
  {
    memset((int)&dst, 0, sizeof(dst));
    decrease_quality = vostok::render::g_allocator.m_object->decrease_quality;
    LODWORD(dst.i.x) = clear_value;
    LODWORD(dst.j.y) = clear_value;
    LODWORD(dst.k.z) = clear_value;
    LODWORD(dst.c.w) = clear_value;
    v13 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))decrease_quality)(
            vostok::render::g_allocator.m_object,
            72);
    if ( v13 )
    {
      qmemcpy((void *)(v13 + 8), &dst, 0x40u);
      *(_BYTE *)(v13 + 4) = 1;
      *(_DWORD *)v13 = &vostok::collision::sphere_geometry_instance::`vftable';
      v14 = (vostok::collision::geometry_instance *)v13;
    }
    else
    {
      v14 = 0;
    }
    in_properties->m_collision_geometry = v14;
    v15 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
            vostok::render::g_allocator.m_object,
            52);
    v17 = (vostok::collision::object *)v15;
    if ( v15 )
    {
      vostok::collision::object::object(v16, v15);
      v17->__vftable = (vostok::collision::object_vtbl *)&vostok::collision::collision_object::`vftable';
      v17[1].__vftable = (vostok::collision::object_vtbl *)v14;
      v17->m_user_data = in_properties;
      v17->m_type = 1;
    }
    else
    {
      v17 = 0;
    }
    in_properties->m_collision_object = v17;
    v18 = vostok::math::create_translation(&dst, &in_propertiesa->location);
    radius = in_propertiesa->radius;
    qmemcpy((void *)&new_transform, v18, sizeof(new_transform));
    probe_scale3.x = radius;
    probe_scale3.y = radius;
    probe_scale3.z = radius;
    vostok::math::float4x4::set_scale(&new_transform, &probe_scale3);
    in_properties->m_collision_tree->insert(
      in_properties->m_collision_tree,
      in_properties->m_collision_object,
      &new_transform);
  }
  LODWORD(probe_scale3.z) = clear_value;
  LODWORD(probe_scale3.x) = clear_value;
  LODWORD(probe_scale3.y) = clear_value;
  HIDWORD(v36) = clear_value;
  *(_QWORD *)((char *)&v36 + 4) = *(_QWORD *)&probe_scale3.x;
  LODWORD(v36) = -1082130432;
  v33 = v36;
  *(_QWORD *)&in_properties->m_aabb.min.x = 0xBF800000BF800000uLL;
  *(_QWORD *)&in_properties->m_aabb.min.elements[2] = v33;
  *(_QWORD *)&in_properties->m_aabb.max.elements[1] = *((_QWORD *)&v36 + 1);
  vostok::math::aabb::modify((vostok::math::aabb *)&new_transform, _X_4);
}
