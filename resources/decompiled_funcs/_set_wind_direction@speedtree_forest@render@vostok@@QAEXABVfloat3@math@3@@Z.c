void __usercall vostok::render::speedtree_forest::set_wind_direction(
        vostok::render::speedtree_forest *this@<ecx>,
        const vostok::math::float3 *wind_direction@<eax>)
{
  vostok::math::float3 v2; // [esp+0h] [ebp-Ch] BYREF

  v2 = *wind_direction;
  SpeedTree::CWind::SetDirection(&this->m_wind_leader, &v2.x);
}
