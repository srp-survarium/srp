void __thiscall vostok::animation::mixing::n_ary_tree_deserializer::decode_times_in_ms_impl(
        vostok::animation::mixing::n_ary_tree_deserializer *this,
        vostok::animation::mixing::n_ary_tree_deserializer *a2)
{
  bool v3; // bl
  vostok::buffer_vector<unsigned int> *v4; // ecx
  vostok::buffer_vector<unsigned int> *v5; // ecx
  unsigned int power_of_two; // eax
  unsigned int v7; // eax
  unsigned int v8; // edi
  void *v9; // esp
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // edi
  int v15; // eax
  vostok::buffer_vector<unsigned int> *v16; // ecx
  _DWORD v17[4]; // [esp+0h] [ebp-1Ch] BYREF
  unsigned int v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h] BYREF
  int v21; // [esp+24h] [ebp+8h]

  v20 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0xAu);
  if ( v20 )
  {
    v3 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 1u) == 1;
    v19 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0x20u);
    if ( v20 == 1 )
    {
      vostok::buffer_vector<unsigned int>::push_back(v4, (int)&a2->m_times_in_ms, (const unsigned int *)&v19);
    }
    else
    {
      v18 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 5u);
      if ( v3 )
      {
        power_of_two = vostok::round_up_to_the_next_power_of_two((void *)(v20 + 1));
        v7 = vostok::bit_index(power_of_two);
        v8 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v7 > 1 ? 1 - v7 - 1 : -1);
        v9 = alloca(4 * v8);
        v17[0] = v19;
        v19 = 1;
        if ( v8 > 1 )
        {
          do
          {
            v10 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v18);
            v11 = v19;
            v17[v19] = v10 + v17[v19 - 1] + 1;
            v19 = v11 + 1;
          }
          while ( v11 + 1 < v8 );
        }
        v12 = vostok::round_up_to_the_next_power_of_two((void *)(v8 + 1));
        v13 = vostok::bit_index(v12);
        v14 = v13 > 1 ? 1 - v13 - 1 : -1;
        if ( v20 )
        {
          v18 = v20;
          do
          {
            v15 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v14);
            vostok::buffer_vector<unsigned int>::push_back(v16, (int)&a2->m_times_in_ms, &v17[v15]);
            --v18;
          }
          while ( v18 );
        }
      }
      else
      {
        v21 = v20;
        do
        {
          v20 = v19 + vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v18);
          vostok::buffer_vector<unsigned int>::push_back(v5, (int)&a2->m_times_in_ms, (const unsigned int *)&v20);
          --v21;
        }
        while ( v21 );
      }
    }
  }
}
