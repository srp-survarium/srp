void __usercall vostok::animation::mixing::n_ary_tree_node_cloner::initialize(
        vostok::animation::mixing::n_ary_tree_node_cloner *this@<esi>,
        const vostok::animation::mixing::n_ary_tree *from@<edx>,
        const vostok::animation::mixing::n_ary_tree *to@<ecx>)
{
  unsigned int m_interpolators_count; // eax
  const vostok::animation::base_interpolator **m_interpolators; // ecx
  unsigned int v5; // ebx
  const vostok::animation::base_interpolator **v6; // edx
  void *v7; // esp
  const vostok::animation::base_interpolator **v8; // eax
  const vostok::animation::base_interpolator **v9; // ebx
  unsigned int v10; // eax
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *m_constructor; // ecx
  unsigned int v12; // edx
  vostok::mutable_buffer *m_buffer; // eax
  const vostok::animation::base_interpolator **v14; // edi
  const vostok::animation::base_interpolator *v15[2]; // [esp+0h] [ebp-20h] BYREF
  const vostok::animation::base_interpolator **v16; // [esp+8h] [ebp-18h]
  unsigned int v17; // [esp+Ch] [ebp-14h]
  const vostok::animation::base_interpolator **v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+18h] [ebp-8h]
  const vostok::animation::base_interpolator **v21; // [esp+1Ch] [ebp-4h]

  m_interpolators_count = to->m_interpolators_count;
  m_interpolators = to->m_interpolators;
  v5 = from->m_interpolators_count;
  v6 = from->m_interpolators;
  v17 = m_interpolators_count;
  v16 = v6;
  v18 = m_interpolators;
  v7 = alloca(4 * (v5 + m_interpolators_count));
  v21 = v15;
  LOBYTE(v20) = 0;
  LOBYTE(v19) = 0;
  v8 = stlp_std::merge<vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * const *,vostok::animation::base_interpolator const * *,vostok::animation::merge_interpolators_predicate>(
         v16,
         v18,
         &v16[v5],
         &v18[m_interpolators_count],
         v15);
  v9 = v21;
  v21 = stlp_std::unique<vostok::animation::base_interpolator const * *,vostok::animation::unique_interpolators_predicate>(
          v21,
          v8);
  v10 = v21 - v9;
  this->m_interpolators_count = v10;
  m_constructor = this->m_constructor;
  this->m_interpolators = (const vostok::animation::base_interpolator **)m_constructor->m_buffer->m_data;
  v12 = v10;
  m_buffer = m_constructor->m_buffer;
  v12 *= 4;
  m_buffer->m_data += v12;
  m_buffer->m_size -= v12;
  v14 = this->m_interpolators;
  while ( v9 != v21 )
  {
    *v14 = (*v9)->clone(*v9, this->m_constructor);
    ++v9;
    ++v14;
  }
}
