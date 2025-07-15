void __thiscall vostok::render::scene::select_volume_fog_instances(
        vostok::render::scene *this,
        vostok::render::scene *vp,
        const vostok::math::float4x4 *out_instances,
        vostok::render::vector<vostok::render::volume_fog_parameters> *out_instancesa)
{
  float v4; // ebx
  vostok::math::aabb *v5; // edi
  const vostok::math::aabb *v6; // eax
  vostok::math::cuboid *v7; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::volume_fog_parameters,vostok::render::std_allocator<vostok::render::volume_fog_parameters> > *v8; // ecx
  vostok::render::volume_fog_parameters *M_finish; // eax
  const vostok::math::float4x4 *v10; // [esp+0h] [ebp-B8h]
  unsigned int v11; // [esp+4h] [ebp-B4h]
  bool v12; // [esp+8h] [ebp-B0h]
  vostok::math::float3 v13; // [esp+10h] [ebp-A8h]
  unsigned __int64 v14; // [esp+1Ch] [ebp-9Ch]
  float v15; // [esp+24h] [ebp-94h]
  vostok::math::aabb bbox; // [esp+28h] [ebp-90h]
  vostok::math::frustum view_frustum; // [esp+40h] [ebp-78h] BYREF

  v4 = *(float *)&vp->m_volume_fogs._M_impl._M_start;
  if ( (stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *)LODWORD(v4) != vp->m_volume_fogs._M_impl._M_finish )
  {
    LODWORD(v13.x) = clear_value;
    LODWORD(v13.y) = clear_value;
    LODWORD(v13.z) = clear_value;
    v14 = 0xBF800000BF800000uLL;
    v15 = -1.0;
    v5 = (vostok::math::aabb *)(LODWORD(v4) + 4);
    do
    {
      vostok::math::frustum::frustum(&view_frustum, out_instances);
      *(_QWORD *)&bbox.min.x = v14;
      bbox.min.z = v15;
      bbox.max = v13;
      v6 = vostok::math::aabb::modify(v5, v10);
      if ( vostok::math::cuboid::test_inexact(v7, v6) != intersection_outside )
      {
        M_finish = out_instancesa->_M_impl._M_finish;
        if ( M_finish == out_instancesa->_M_impl._M_end_of_storage._M_data )
        {
          stlp_std::priv::_Impl_vector<vostok::render::volume_fog_parameters,vostok::render::std_allocator<vostok::render::volume_fog_parameters>>::_M_insert_overflow(
            M_finish,
            v8,
            &out_instancesa->_M_impl,
            (const vostok::render::volume_fog_parameters *)v5,
            (const stlp_std::__true_type *)v10,
            v11,
            v12);
        }
        else
        {
          if ( M_finish )
            vostok::render::volume_fog_parameters::volume_fog_parameters(
              M_finish,
              (const vostok::render::volume_fog_parameters *)v5);
          ++out_instancesa->_M_impl._M_finish;
        }
      }
      LODWORD(v4) += 120;
      v5 += 5;
    }
    while ( (stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *)LODWORD(v4) != vp->m_volume_fogs._M_impl._M_finish );
  }
}
