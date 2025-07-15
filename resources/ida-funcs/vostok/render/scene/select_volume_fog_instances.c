void __userpurge vostok::render::scene::select_volume_fog_instances(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        const vostok::math::float4x4 *vp,
        vostok::fixed_vector<vostok::render::volume_fog_parameters,32> *out_instances)
{
  stlp_std::priv::_Rb_tree_node_base *v4; // ebx
  vostok::math::aabb_plane *v5; // eax
  vostok::math::cuboid *v6; // ecx
  vostok::render::volume_fog_parameters *m_end; // eax
  const char *v8; // [esp+0h] [ebp-C0h]
  vostok::math::frustum v9; // [esp+10h] [ebp-B0h] BYREF
  vostok::math::aabb v10; // [esp+88h] [ebp-38h] BYREF
  vostok::math::float3 v11; // [esp+A0h] [ebp-20h]
  __int64 v12; // [esp+ACh] [ebp-14h]
  float v13; // [esp+B4h] [ebp-Ch]
  stlp_std::priv::_Rb_tree_node_base *v14; // [esp+B8h] [ebp-8h]
  bool v15; // [esp+BFh] [ebp-1h] BYREF

  v4 = *(stlp_std::priv::_Rb_tree_node_base **)((char *)&loc_1CE1A8 + a2);
  v14 = (stlp_std::priv::_Rb_tree_node_base *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
                                             + a2);
  if ( v4 != (stlp_std::priv::_Rb_tree_node_base *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
                                                  + a2) )
  {
    v11.x = s_bm_current_air_resistance;
    v11.y = s_bm_current_air_resistance;
    v11.z = s_bm_current_air_resistance;
    *(float *)&v12 = FLOAT_N1_0;
    *((float *)&v12 + 1) = FLOAT_N1_0;
    v13 = FLOAT_N1_0;
    do
    {
      vostok::math::frustum::frustum(&v9, vp);
      *(_QWORD *)&v10.min.x = v12;
      v10.min.z = v13;
      v10.max = v11;
      v5 = (vostok::math::aabb_plane *)vostok::math::aabb::modify((vostok::math::aabb *)&v4[1]._M_parent, &v10);
      if ( vostok::math::cuboid::test_inexact(v6, (int)&v9, v5) != 2 )
      {
        if ( out_instances->m_end >= out_instances->m_max_end
          && !`vostok::buffer_vector<vostok::render::volume_fog_parameters>::push_back'::`11'::debug_macro_helper_ignore_always )
        {
          v15 = 0;
          vostok::debug::on_error(
            &v15,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
            "vostok::buffer_vector<struct vostok::render::volume_fog_parameters>::push_back",
            (const char *)0x12E,
            "buffer overflow",
            v8);
          if ( vostok::debug::is_debugger_present() || v15 )
            __debugbreak();
        }
        m_end = out_instances->m_end;
        if ( m_end )
          vostok::render::volume_fog_parameters::volume_fog_parameters(
            m_end,
            (const vostok::render::volume_fog_parameters *)&v4[1]._M_parent);
        ++out_instances->m_end;
      }
      v4 = stlp_std::priv::_Rb_global<bool>::_M_increment(v4);
    }
    while ( v4 != v14 );
  }
}
