void __usercall vostok::animation::mixing::n_ary_tree_deserializer::decode_floats_impl(
        vostok::animation::mixing::n_ary_tree_deserializer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_deserializer *a2@<edi>)
{
  bool v2; // bl
  int v3; // eax
  vostok::buffer_vector<float> *v4; // ecx
  unsigned int power_of_two; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  void *v8; // esp
  int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebx
  int v14; // eax
  int v15; // [esp+0h] [ebp-18h] BYREF
  int v16; // [esp+Ch] [ebp-Ch]
  vostok::buffer_vector<float> *i; // [esp+10h] [ebp-8h] BYREF
  unsigned int v18; // [esp+14h] [ebp-4h]

  v2 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 1u) == 1;
  v3 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0xAu);
  v16 = v3;
  if ( v2 )
  {
    power_of_two = vostok::round_up_to_the_next_power_of_two((void *)(v3 + 1));
    v6 = vostok::bit_index(power_of_two);
    v7 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v6 > 1 ? 1 - v6 - 1 : -1);
    v8 = alloca(4 * v7);
    v18 = 0;
    for ( i = (vostok::buffer_vector<float> *)&v15; v18 < v7; *((_DWORD *)&i->m_begin + v10) = v9 )
    {
      v9 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0x20u);
      v10 = v18++;
    }
    v11 = vostok::round_up_to_the_next_power_of_two((void *)(v7 + 1));
    v12 = vostok::bit_index(v11);
    v13 = v12 > 1 ? 1 - v12 - 1 : -1;
    if ( v16 )
    {
      v18 = v16;
      do
      {
        v14 = vostok::animation::mixing::n_ary_tree_deserializer::r(a2, v13);
        vostok::buffer_vector<float>::push_back(i, (int)&a2->m_floats, (float *)&i->m_begin + v14);
        --v18;
      }
      while ( v18 );
    }
  }
  else if ( v3 )
  {
    v18 = v3;
    do
    {
      i = (vostok::buffer_vector<float> *)vostok::animation::mixing::n_ary_tree_deserializer::r(a2, 0x20u);
      vostok::buffer_vector<float>::push_back(v4, (int)&a2->m_floats, (float *)&i);
      --v18;
    }
    while ( v18 );
  }
}
