void __thiscall Scaleform::Render::HAL::GetStats(
        Scaleform::Render::HAL *this,
        Scaleform::Render::HAL::Stats *pstats,
        bool clear)
{
  *pstats = this->AccumulatedStats;
  if ( clear )
  {
    this->AccumulatedStats.Filters = 0;
    this->AccumulatedStats.RTChanges = 0;
    this->AccumulatedStats.Masks = 0;
    this->AccumulatedStats.Triangles = 0;
    this->AccumulatedStats.Meshes = 0;
    this->AccumulatedStats.Primitives = 0;
  }
}
