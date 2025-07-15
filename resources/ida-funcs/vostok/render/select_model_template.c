unsigned __int8 __usercall vostok::render::select_model_template@<al>(
        float *values@<esi>,
        unsigned __int8 count@<cl>,
        float sum)
{
  unsigned __int64 v3; // rax
  unsigned __int8 result; // al
  float p; // [esp+8h] [ebp+4h]

  model_index_random.m_seed = 134775813 * model_index_random.m_seed + 1;
  v3 = (unsigned __int64)model_index_random.m_seed << 20;
  result = 0;
  p = (double)HIDWORD(v3) * 0.00000095367432 * sum;
  if ( !count )
    return count - 1;
  while ( values[result] <= p )
  {
    if ( ++result >= count )
      return count - 1;
  }
  return result;
}
