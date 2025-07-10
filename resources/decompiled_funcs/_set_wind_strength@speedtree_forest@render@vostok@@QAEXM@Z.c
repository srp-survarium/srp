void __thiscall vostok::render::speedtree_forest::set_wind_strength(
        vostok::render::speedtree_forest *this,
        float wind_strength)
{
  SpeedTree::CWind::SetStrength(&this->m_wind_leader, wind_strength);
}
