void __cdecl stlp_std::_Param_Construct_aux<vostok::fixed_vector<unsigned int,32>,vostok::fixed_vector<unsigned int,32>>(
        vostok::fixed_vector<unsigned int,32> *__p,
        const vostok::fixed_vector<unsigned int,32> *__val)
{
  unsigned int *end; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int *v3; // [esp+20h] [ebp-8h]
  vostok::buffer_vector<unsigned int> *v4; // [esp+24h] [ebp-4h]

  v4 = __p;
  if ( __p )
  {
    v3 = (unsigned int *)&v4[1];
    v4->m_begin = (unsigned int *)&v4[1];
    v4->m_end = v3;
    end = __val->m_end;
    vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
      v4,
      __val->m_begin,
      (const unsigned int *const *)&end);
  }
}
