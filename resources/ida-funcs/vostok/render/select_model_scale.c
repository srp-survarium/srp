double __cdecl vostok::render::select_model_scale(float delta, float base_scale)
{
  model_scale_random.m_seed = 134775813 * model_scale_random.m_seed + 1;
  return base_scale
       - delta
       + (double)((unsigned __int64)model_scale_random.m_seed >> 12) * 0.00000095367432 * delta
       + (double)((unsigned __int64)model_scale_random.m_seed >> 12) * 0.00000095367432 * delta;
}
