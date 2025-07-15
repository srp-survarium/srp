void __cdecl vostok::render::setup_seed_clk()
{
  point_random_x.m_seed = GetTickCount();
  point_random_z.m_seed = point_random_x.m_seed;
  model_index_random.m_seed = point_random_x.m_seed;
  model_orientation_random.m_seed = point_random_x.m_seed;
  model_density_random.m_seed = point_random_x.m_seed;
  model_scale_random.m_seed = point_random_x.m_seed;
}
